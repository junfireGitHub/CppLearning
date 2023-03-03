
/*���ö��߳�������һ������Ӧ���û�����*/

/*������enterʱ�������ִ�е�dt->quit();
���ú�����ʹ�߳��˳������ʹ��һ���߳���
��ͣ��������ݵ����ƽ��棬��ͬʱ����enter
������˳�*/
#include<iostream>
#include<fstream>
#include<string>
#include"zthread/Thread.h"
using namespace ZThread;
using namespace std;

class DisplayTask :public Runnable{
	ifstream in;
	string line;
	bool quitFlag;
public:
	DisplayTask(const string &file) :quitFlag(false){
		in.open(file.c_str());
	}
	~DisplayTask(){ in.close(); }
	void run(){
		while (getline(in, line) && !quitFlag){
			cout << line << endl;
			Thread::sleep(1000);
		}
	}
	void quit(){ quitFlag = true; }
};


int main(){
	try{
		cout << "Press <Enter> to quit:" << endl;
		DisplayTask *dt = new DisplayTask("Responsive.cpp");
		Thread t(dt);/*�̴߳�����᲻ͣ�������Ϣ������̨������*/
		/*������enterʱ�������ִ�е�dt->quit();
		���ú�����ʹ�߳��˳����൱�ڰ���Enter���˳�*/
		cin.get();//�����س��ͽ������൱�ڰ��»س���ִ����һ����䡣
		dt->quit();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	cout << "Shutting Down..." << endl;
	return 0;

}