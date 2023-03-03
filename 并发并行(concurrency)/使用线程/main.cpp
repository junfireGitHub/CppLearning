#include "zthread/Thread.h"
#include <iostream>
#include"LiftOff.h"

using namespace ZThread;
using namespace std;

/*通过结果可以看到线程按照非固定的顺序执行着，并且当mian（）函数结束
后仍旧执行着，因为现在main和main里调用的线程成了两个线程。
在for中创建了Thread t，按照C++语法，当执行完for语句后，对象不存在了
但线程仍旧运行直道其相关联的任务完成。*/
int main() {
	const int SZ = 5;
	try{
		for (int i = 0; i < SZ; i++)
			Thread t(new LiftOff(10, i));
		cout << "Waiting for LiftOff" << endl;
	}catch (Synchronization_Exception& e) {
		std::cerr << e.what() << std::endl;
	}
	system("pause");
	return 0;
}