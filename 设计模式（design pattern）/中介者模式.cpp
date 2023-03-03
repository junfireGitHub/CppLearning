//代码有缩减，这个模式感觉不重要

#include "ConcreteColleagueB.h"
#include "Mediator.h"
#include "ConcreteColleagueA.h"
#include <map>
using namespace std;
class ConcreteMediator : public Mediator
{

public:
	ConcreteMediator();
	virtual ~ConcreteMediator();

	virtual void operation(int nWho,string str);
	virtual void registered(int nWho, Colleague * aColleague);
private:
	map<int,Colleague*> m_mpColleague;
};


ConcreteMediator::ConcreteMediator(){

}

ConcreteMediator::~ConcreteMediator(){

}

void ConcreteMediator::operation(int nWho,string str){
	map<int,Colleague*>::const_iterator itr = m_mpColleague.find(nWho);
	if(itr == m_mpColleague.end())
	{
		cout << "not found this colleague!" << endl;
		return;
	}
	
	Colleague* pc = itr->second;
	pc->receivemsg(str);
}


void ConcreteMediator::registered(int nWho,Colleague * aColleague){
	map<int,Colleague*>::const_iterator itr = m_mpColleague.find(nWho);
	if(itr == m_mpColleague.end())
	{
		m_mpColleague.insert(make_pair(nWho,aColleague));
		//同时将中介类暴露给colleague 
		aColleague->setMediator(this);
	}
}


class ConcreteColleagueA : public Colleague
{

public:
	ConcreteColleagueA();
	virtual ~ConcreteColleagueA();

	virtual void sendmsg(int toWho,string str);
	virtual void receivemsg(string str);

};


ConcreteColleagueA::ConcreteColleagueA(){
}

ConcreteColleagueA::~ConcreteColleagueA(){
}

void ConcreteColleagueA::sendmsg(int toWho,string str){
	cout << "send msg from colleagueA,to:" << toWho << endl;
	m_pMediator->operation(toWho,str);
}

void ConcreteColleagueA::receivemsg(string str){
	cout << "ConcreteColleagueA reveivemsg:" << str <<endl;
}