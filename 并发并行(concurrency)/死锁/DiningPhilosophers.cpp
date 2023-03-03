#include<ctime>
#include"DiningPhilosopher.h"
#include"zthread/ThreadedExecutor.h"
using namespace std;
using namespace ZThread;

int main(){
	srand(time(0));
	/*思考算子ponderFactor用于衡量一个Philosopher
	花费在思考和进餐上的时间长度趋势。 一个较小的
	ponderFactor将增加死锁的可能性(比如0或1)。*/
	int ponder = 5;	
	cout << "Press <Enter> to quit" << endl;
	enum{SZ = 5};
	try{
		CountedPtr<Display> d(new Display);
		ThreadedExecutor executor;
		Chopstick c[SZ];
		for (int i = 0; i < SZ; i++){
			executor.execute(new Philosopher(c[i], c[(i + 1) % SZ], d, i, ponder));
		}
		cin.get();
		executor.interrupt();
		executor.wait();
	}
	catch (Synchronization_Exception&e){
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}