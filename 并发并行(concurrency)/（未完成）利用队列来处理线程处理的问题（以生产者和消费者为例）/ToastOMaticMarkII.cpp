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
#include"TQueue.h"
using namespace ZThread;
using namespace std;

class Toast{
	enum Status{DRY,BUTTERED,JAMMED};
	Status status;
	int id;
public:
	Toast(int idn) :id(idn){ status = DRY; }
	void buttered(){ status = BUTTERED; }
	void jammed(){ status = JAMMED; }
	string getStatus(){
		switch (status)
		{
		case DRY:return "dry";
		case BUTTERED: return "buttered";
		case JAMMED:return "jammed";
		default:return "error";
		}
	}
	int getId(){ return id; }
	friend ostream& operator<<(ostream &os, Toast &t){
		return os << "Toast" << t.id << ":" << t.getStatus();
	}
};

typedef CountedPtr<TQueue<Toast>> ToastQueue;

class Toaster :public Runnable{
	//Mutex lock;不需要互斥锁是由于没有需要共享的资源
	ToastQueue toastQueue;
	int count;
public:
	Toaster(ToastQueue &q) :toastQueue(q),count(0){}
	void run(){
		try{
			while (!Thread::interrupted()){
				//make toast
				int delay = rand() / (RAND_MAX / 5) * 100;
				Thread::sleep(delay);
				Toast t(count++);
				cout << t << endl;
				// insert into queue
				toastQueue->put(t);
			}
		}
		catch (Interrupted_Exception&){/*Exit*/ }
		cout << "Toasted off" << endl;
	}
};

//Apply butter to toast
class Butterer :public Runnable{
	ToastQueue dryQueue, butterQueue;
public:
	Butterer(ToastQueue &dq, ToastQueue &bq) :
		dryQueue(dq), butterQueue(bq){}
	void run(){
		try{
			while (!Thread::interrupted()){	
				Toast t = dryQueue->get();
				//// applay butter to toast
				t.buttered();
				cout << t << endl;
				butterQueue->put(t);
			}
		}
		catch (Interrupted_Exception&){/*Exit*/ }
		cout << "Butterer off" << endl;
	}
};
class Jammer :public Runnable{
	ToastQueue butterQueue;
public:
	Jammer(ToastQueue bq) :butterQueue(bq){}
	void run(){
		try{
			while (!Thread::interrupted()){
				Toast t = butterQueue->get();
				t.jammed();
				cout << t << endl;
			}
		}
		catch (Interrupted_Exception){/*Exit*/ }
		cout << "Jammer off" << endl;
	}
};
/*在这个解决方案中， 两件事情会马上变得很明显： 第一， 在每个Runnable类中代码的数
量和复杂性通过队列TQueue的使用会显著减少， 因为进行保护、 通信， 以及
wait（ ） /signal（ ） 操作现在都由TQueue来维护。 Runnable类不再拥有任何Mutex或Condition
对象。 第二， 类之间的耦合被消除了， 因为每个类只与它的TQueue通信。 注意， 现在类的定
义次序是独立的。 较少的代码和较少的耦合总归是一件好事， 这暗示着在这里TQueue的使用
有积极作用， 就像在大多数问题中它所做的那样。*/
int main(){

	srand(time(0));
	try{
		ToastQueue dryQueue(new TQueue<Toast>),
			butterQueue(new TQueue<Toast>);
		cout << "press Enter to quit" << endl;
		ThreadedExecutor executor;
		executor.execute(new Toaster(dryQueue));
		executor.execute(new Butterer(dryQueue,butterQueue));
		executor.execute(new Jammer(butterQueue));
		cin.get();
		executor.interrupt();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}