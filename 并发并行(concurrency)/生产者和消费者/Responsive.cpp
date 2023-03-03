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

/*������һ������������Ļ�����һ�������������������һ������
�����������Ĩ���ͣ�����һ����������Ĩ�õĻ��͵Ŀ������Ĩ����
*/

//Apply butter to toast
class Butterer :public Runnable{
	/*ZThread�����һ������CountedPtr��ģ�壬 
	���Զ�ִ�����ü����������ü�������ʱ��
	deleteɾ��һ������֮����Ҫ��ô��������
	����ȷ�������������������Ҫ���ǵ�ʱ��
	���ڱ����ڻ״̬��������Щ������ʹ�õĶ���
	���������֮ǰ�뿪������ ���������������� 
	���񽫳��Է��ʷǷ��Ĵ洢��Ԫ�� �������������� */
	/*ps:�������е�jammerӦ����ΪCountedPtrģ������*/
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

//Applay jam�������� to buttered toast
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
		butteredToastReady.signal();//����ͬһ�������run()���wait()
	}
	void run(){
		try{
			/*�����Thread::interrupted()�Լ������������
			interrupt()��Ŀ����Ϊ�˵���������ִ��interrupt()ʱ
			�߳�run()�ܹ�����ֹ��interrupt()ֻ����������ʱ���ж�
			��������ʱ���ܣ���һ������interruptr(),���������ж�
			״̬Thread::interrupted()��������ʹ�߳�û�б���������£�Ҳ
			����ͨ�����Thread::interrupted()��״̬��ȷ���Ƿ�Ҫ�жϣ�
			��ͨ����Ӧ����������while�����ж��̡߳�*/
			while (!Thread::interrupted()){
				{
					/*����g��һ����������ʹ�ã���������ֻ�ܱ�����������̷߳��ʣ������������������ķ�ʽ��
					д�Ļ���Ӧ����Mutex g �� g.acquire();...;g.release();
					���������Ļ�����������;�������쳣�߳��˳�����һ���ܹ�
					��֤���������ͷţ�����ÿ�����ܵ��쳣·��������release()�����ĵ��ã�
					����������ʹ��Guard����������ʱ�Զ����һ��
					��������������ջ�Ķ����Զ���һ������������������ʲô��ʽ�˳���
					�������release()��*/
					Guard<Mutex> g(lock);//�����lock��Jammer��˽������Mutex lock;
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
	ʹ��ZThread��ִ������ Executor�� ���Լ��ٱ���Ĺ������� 
	ִ�����ڿͻ��������ִ��֮���ṩ��һ����Ӳ㣻 �ͻ�����
	ֱ��ִ������ ������һ���м�Ķ�����ִ�и�����
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
		cin.get();//����enter�˳�
		executor.interrupt();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	/*�������г�����ֺܶ࿾��������˵��ϡ���ûĨ
	���ͣ�ҲûĨ���������������ö��н��д��������һ��
	����*/
	return 0;
}