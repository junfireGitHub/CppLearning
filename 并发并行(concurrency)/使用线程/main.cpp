#include "zthread/Thread.h"
#include <iostream>
#include"LiftOff.h"

using namespace ZThread;
using namespace std;

/*ͨ��������Կ����̰߳��շǹ̶���˳��ִ���ţ����ҵ�mian������������
���Ծ�ִ���ţ���Ϊ����main��main����õ��̳߳��������̡߳�
��for�д�����Thread t������C++�﷨����ִ����for���󣬶��󲻴�����
���߳��Ծ�����ֱ�����������������ɡ�*/
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