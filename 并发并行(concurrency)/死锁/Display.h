#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>
#include<sstream>
#include"zthread/Mutex.h"
#include"zthread/Guard.h"

class Display{
	ZThread::Mutex iolock;
public:
	void output(std::ostringstream &os){
	/*����Ϣд��һ��ostringstream�� Ȼ����һ������
    �������Ķ�����Ϊ�����̵߳�����㣬 �Է�����߳�
	ͬʱд������*/
		ZThread::Guard<ZThread::Mutex> g(iolock);
		std::cout << os.str();
	}
};
#endif