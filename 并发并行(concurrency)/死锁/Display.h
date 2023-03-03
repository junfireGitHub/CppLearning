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
	/*将信息写入一个ostringstream， 然后用一个带有
    互斥锁的对象作为所有线程的输出点， 以防多个线程
	同时写入数据*/
		ZThread::Guard<ZThread::Mutex> g(iolock);
		std::cout << os.str();
	}
};
#endif