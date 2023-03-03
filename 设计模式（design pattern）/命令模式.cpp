#include <iostream>
using namespace std;


class Receiver
{

public:
	Receiver();
	virtual ~Receiver();

	void action()
	{
        cout << "receiver action." << endl;		
	}

};


class ConcreteCommand : public Command
{

public:
	ConcreteCommand(Receiver * pReceiver): m_pReceiver(pReceiver){}
	virtual ~ConcreteCommand();
	virtual void execute()
	{
        cout << "ConcreteCommand::execute"  << endl;
	    m_pReceiver->action();		
	}
private:
	Receiver *m_pReceiver;
};


class Invoker
{

public:
	Invoker(Command * pCommand): m_pCommand(pCommand){}
	virtual ~Invoker();
	void call()
	{
	    cout << "invoker calling" << endl;
	    m_pCommand->execute();		
	}

private:
	Command *m_pCommand;
};

int main(int argc, char *argv[])
{
	Receiver * pReceiver = new Receiver();
	ConcreteCommand * pCommand = new ConcreteCommand(pReceiver);
	Invoker * pInvoker = new Invoker(pCommand);
	pInvoker->call();
	
	delete pReceiver;
	delete pCommand;
	delete pInvoker;
	return 0;
}

/*Êä³öÎª£º

invoker calling 
ConcreteCommand:excute
receiver action

*/