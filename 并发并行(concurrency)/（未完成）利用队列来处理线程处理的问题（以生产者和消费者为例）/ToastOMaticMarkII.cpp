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
	//Mutex lock;����Ҫ������������û����Ҫ�������Դ
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
/*�������������У� ������������ϱ�ú����ԣ� ��һ�� ��ÿ��Runnable���д������
���͸�����ͨ������TQueue��ʹ�û��������٣� ��Ϊ���б����� ͨ�ţ� �Լ�
wait�� �� /signal�� �� �������ڶ���TQueue��ά���� Runnable�಻��ӵ���κ�Mutex��Condition
���� �ڶ��� ��֮�����ϱ������ˣ� ��Ϊÿ����ֻ������TQueueͨ�š� ע�⣬ ������Ķ�
������Ƕ����ġ� ���ٵĴ���ͽ��ٵ�����ܹ���һ�����£� �ⰵʾ��������TQueue��ʹ��
�л������ã� �����ڴ������������������������*/
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