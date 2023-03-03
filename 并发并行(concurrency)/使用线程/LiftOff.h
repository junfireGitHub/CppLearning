#pragma once
#include<iostream>
#include"zthread/Runnable.h"

class LiftOff :public ZThread::Runnable{
	int countDown;
	int id;
public:
	LiftOff(int count, int num = 0) :
		countDown(count), id(num){}
	~LiftOff(){
		std::cout << id << " completed" << std::endl;
	}
	void run(){
		while (countDown--)
			std::cout << id << ":" << countDown << std::endl;
		std::cout << "Liftoff!" << std::endl;
	}
};

