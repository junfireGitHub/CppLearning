#include <iostream>
#include "Facade.h"
using namespace std;

int main(int argc, char *argv[])
{
	Facade fa;
	fa.wrapOpration();
	
	return 0;
}
///////////////////////////////////////////////////////////
//  Facade.h
//  Implementation of the Class Facade
//  Created on:      06-十月-2014 19:10:44
//  Original author: colin
///////////////////////////////////////////////////////////

#if !defined(EA_FD130A87_92A9_4168_9B33_7A925C47AFD5__INCLUDED_)
#define EA_FD130A87_92A9_4168_9B33_7A925C47AFD5__INCLUDED_

#include "SystemC.h"
#include "SystemA.h"
#include "SystemB.h"

class Facade
{

public:
	Facade();
	virtual ~Facade();

	void wrapOpration();

private:
	SystemC *m_SystemC;
	SystemA *m_SystemA;
	SystemB *m_SystemB;
};
#endif // !defined(EA_FD130A87_92A9_4168_9B33_7A925C47AFD5__INCLUDED_)
///////////////////////////////////////////////////////////
//  Facade.cpp
//  Implementation of the Class Facade
//  Created on:      06-十月-2014 19:10:44
//  Original author: colin
///////////////////////////////////////////////////////////

#include "Facade.h"


Facade::Facade(){
	m_SystemA  = new SystemA();
	m_SystemB = new SystemB();
	m_SystemC = new SystemC();
}



Facade::~Facade(){
	delete m_SystemA;
	delete m_SystemB;
	delete m_SystemC;
}

void Facade::wrapOpration(){
	m_SystemA->operationA();
	m_SystemB->operationB();
	m_SystemC->opeartionC();
}