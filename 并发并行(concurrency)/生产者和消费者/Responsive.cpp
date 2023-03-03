#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include"zthread/Thread.h"
#include"zthread/Mutex.h"
#include"zthread/Guard.h"
#include"zthread/Condition.h"
#include"zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

/*下面是一个有三个任务的机器，一个任务是制作烤面包，一个任务
是往烤面包上抹黄油，还有一个任务是往抹好的黄油的烤面包上抹果酱
*/

//Apply butter to toast
class Butterer :public Runnable{
	/*ZThread库包括一个名叫CountedPtr的模板， 
	它自动执行引用计数并在引用计数归零时用
	delete删除一个对象。之所以要这么做是由于
	必须确保非任务对象在任务需要它们的时候
	长期保留在活动状态，否则当那些被任务使用的对象
	在任务完成之前离开作用域， 如果这种情况发生， 
	任务将尝试访问非法的存储单元， 并将引起程序错误。 */
	/*ps:主函数中的jammer应声明为CountedPtr模版类型*/
	CountedPtr<Jammer> jammer;
	Mutex lock;
	Condition toastReady;
	bool gotToast;
	int buttered;
public:
	Butterer(CountedPtr<Jammer> &j) :jammer(j), toastReady(lock){
		gotToast = false;
		buttered = 0;
	}
	void moreToastReady(){
		Guard<Mutex> g(lock);
		gotToast = true;
		toastReady.signal();
	}
	void run(){
		try{
			while (!Thread::interrupted()){
				{
					Guard<Mutex> g(lock);
					while (!gotToast)
						toastReady.wait();
					++buttered;
				}
				cout << "Buttering toast" << buttered << endl;
				jammer->moreButteredToastReady();
				{
					Guard<Mutex> g(lock);
					gotToast = false;
				}
			}
		}
		catch (Interrupted_Exception&){/*Exit*/ }
		cout << "Butterer off" << endl;
	}
};

//Applay jam（果酱） to buttered toast
class Jammer :public Runnable{
	Mutex lock;
	Condition butteredToastReady;
	bool gotButteredToast;
	int jammed;
public:
	Jammer():butteredToastReady(lock){
		gotButteredToast = false;
		jammed = 0;
	}
	void moreButteredToastReady(){
		Guard<Mutex> g(lock);
		gotButteredToast = true;
		butteredToastReady.signal();//发给同一个类里的run()里的wait()
	}
	void run(){
		try{
			/*这里的Thread::interrupted()以及主函数里面的
			interrupt()的目的是为了当主函数里执行interrupt()时
			线程run()能够被终止，interrupt()只能在阻塞的时候中断
			，非阻塞时则不能，但一旦调用interruptr(),将会设置中断
			状态Thread::interrupted()，这样即使线程没有被阻塞情况下，也
			可以通过检测Thread::interrupted()的状态来确定是否要中断，
			并通过相应程序（这里是while）来中断线程。*/
			while (!Thread::interrupted()){
				{
					/*这里g是一个互斥锁（使得｛｝的区域只能被进入｛｝的线程访问），如果按照它所定义的方式来
					写的话，应该是Mutex g ； g.acquire();...;g.release();
					但是这样的话，假如在中途过程因异常线程退出，不一定能够
					保证互斥锁被释放（除非每个可能的异常路径都包含release()函数的调用）
					，所以这里使用Guard，当它声明时自动获得一个
					互斥锁，它基于栈的对象自动有一个析构函数，不管是什么方式退出，
					都会调用release()；*/
					Guard<Mutex> g(lock);//这里的lock是Jammer的私有数据Mutex lock;
					while (!gotButteredToast)
						butteredToastReady.wait();
					++jammed;
				}
				cout << "Putting jam on toast" << jammed << endl;
				{
					Guard<Mutex> g(lock);
					gotButteredToast = false;
				}
			}
		}
		catch (Interrupted_Exception){/*Exit*/ }
		cout << "Jammer off" << endl;
	}
};

class Toaster :public Runnable{
	CountedPtr<Butterer> butterer;
	//Mutex lock;
	//Condition toasted;
	int toasted;
public:
	Toaster(CountedPtr<Butterer> &b) :butterer(b){
		toasted = 0;
	}
	void run(){
		try{
			while (!Thread::interrupted()){
				Thread::sleep(rand() / (RAND_MAX / 5) * 100);
				//...
				//create new toast
				//...
				cout << "New toast" << ++toasted << endl;
				butterer->moreToastReady();
			}
		}
		catch (Interrupted_Exception&){/*Exit*/ }
		cout << "Toaster off" << endl;
	}
};
int main(){
	/*
	使用ZThread的执行器（ Executor） 可以减少编码的工作量。 
	执行器在客户和任务的执行之间提供了一个间接层； 客户不再
	直接执行任务， 而是由一个中间的对象来执行该任务。
	*/
	srand(time(0));
	try{
		cout << "press<Return> to quit" << endl;
		CountedPtr<Jammer> jammer(new Jammer);
		CountedPtr<Butterer> butterer(new Butterer(jammer));
		ThreadedExecutor executor;
		executor.execute(new Toaster(butterer));
		executor.execute(butterer);
		executor.execute(jammer);
		cin.get();//按下enter退出
		executor.interrupt();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	/*但是运行程序后发现很多烤面包掉在了地上——没抹
	黄油，也没抹果酱。这个问题可用队列进行处理详见另一个
	例子*/
	return 0;
}