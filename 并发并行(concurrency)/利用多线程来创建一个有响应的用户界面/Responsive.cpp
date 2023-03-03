
/*利用多线程来创建一个有响应的用户界面*/

/*当按下enter时，程序会执行到dt->quit();
而该函数会使线程退出，这就使得一个线程在
不停的输出数据到控制界面，而同时按下enter
后则会退出*/
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
		Thread t(dt);/*线程创建后会不停的输出信息到控制台界面上*/
		/*当按下enter时，程序会执行到dt->quit();
		而该函数会使线程退出，相当于按下Enter会退出*/
		cin.get();//遇到回车就结束，相当于按下回车就执行下一条语句。
		dt->quit();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	cout << "Shutting Down..." << endl;
	return 0;

}