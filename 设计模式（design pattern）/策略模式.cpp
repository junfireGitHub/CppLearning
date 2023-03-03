//代码有删减，自行脑补。

#include <iostream>
#include "Context.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Strategy.h"
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	Strategy * s1 = new ConcreteStrategyA();
	Context * cxt = new Context();
	cxt->setStrategy(s1);
	cxt->algorithm();

	Strategy *s2 = new ConcreteStrategyB();
	cxt->setStrategy(s2);
	cxt->algorithm();
	
	delete s1;
	delete s2;
	delete cxt;
	
	return 0;
}


class Context
{

public:
	Context();
	virtual ~Context();
	

	void algorithm(){
		m_pStrategy->algorithm();
	}
	
	void setStrategy(Strategy* st){
		m_pStrategy = st;
	}
	
private:
	Strategy *m_pStrategy;
};


class ConcreteStrategyA : public Strategy
{

public:
	ConcreteStrategyA();
	virtual ~ConcreteStrategyA();

	virtual void algorithm(){
		cout << "use algorithm A" << endl;
	}
};