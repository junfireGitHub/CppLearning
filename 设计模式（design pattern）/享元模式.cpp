#include <iostream>
#include "ConcreteFlyweight.h"
#include "FlyweightFactory.h"
#include "Flyweight.h"
using namespace std;

int main(int argc, char *argv[])
{
	FlyweightFactory factory;
	Flyweight * fw = factory.getFlyweight("one");
	fw->operation();
	
	Flyweight * fw2 = factory.getFlyweight("two");
	fw2->operation();
	//aready exist in pool
	Flyweight * fw3 = factory.getFlyweight("one");
	fw3->operation();
	return 0;
}
///////////////////////////////////////////////////////////
//  FlyweightFactory.cpp
//  Implementation of the Class FlyweightFactory
//  Created on:      06-十月-2014 20:10:42
//  Original author: colin
///////////////////////////////////////////////////////////

#include "FlyweightFactory.h"
#include "ConcreteFlyweight.h"
#include <iostream>
using namespace std;

FlyweightFactory::FlyweightFactory(){

}



FlyweightFactory::~FlyweightFactory(){

}

Flyweight* FlyweightFactory::getFlyweight(string str){
	map<string,Flyweight*>::iterator itr = m_mpFlyweight.find(str);
	if(itr == m_mpFlyweight.end())
	{
		Flyweight * fw = new ConcreteFlyweight(str);
		m_mpFlyweight.insert(make_pair(str,fw));
		return fw;	
	}
	else
	{
		cout << "aready in the pool,use the exist one:" << endl;
		return itr->second;
	}		
}
///////////////////////////////////////////////////////////
//  ConcreteFlyweight.h
//  Implementation of the Class ConcreteFlyweight
//  Created on:      06-十月-2014 20:10:42
//  Original author: colin
///////////////////////////////////////////////////////////

#if !defined(EA_C0AF438E_96E4_46f1_ADEC_308EF16E11D1__INCLUDED_)
#define EA_C0AF438E_96E4_46f1_ADEC_308EF16E11D1__INCLUDED_

#include "Flyweight.h"
#include <string>
using namespace std;

class ConcreteFlyweight : public Flyweight
{

public:
	ConcreteFlyweight(string str);
	virtual ~ConcreteFlyweight();

	virtual void operation();

private:
	string intrinsicState;

};
#endif // !defined(EA_C0AF438E_96E4_46f1_ADEC_308EF16E11D1__INCLUDED_)
///////////////////////////////////////////////////////////
//  ConcreteFlyweight.cpp
//  Implementation of the Class ConcreteFlyweight
//  Created on:      06-十月-2014 20:10:42
//  Original author: colin
///////////////////////////////////////////////////////////

#include "ConcreteFlyweight.h"
#include <iostream>
using namespace std;


ConcreteFlyweight::ConcreteFlyweight(string str){
	intrinsicState = str;
}

ConcreteFlyweight::~ConcreteFlyweight(){

}

void ConcreteFlyweight::operation(){
	cout << "Flyweight[" << intrinsicState << "] do operation." << endl; 
}