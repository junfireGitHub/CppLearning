#include<ctime>
#include"DiningPhilosopher.h"
#include"zthread/ThreadedExecutor.h"
using namespace std;
using namespace ZThread;

int main(){
	srand(time(0));
	/*˼������ponderFactor���ں���һ��Philosopher
	������˼���ͽ����ϵ�ʱ�䳤�����ơ� һ����С��
	ponderFactor�����������Ŀ�����(����0��1)��*/
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