#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*�ͻ���Ҫ�Ľӿ�*/
class Target{
public :
	virtual void request(){ cout << "request" << endl; }
};

/*ʵ�ʽӿ�*/
class Adaptee{
public:
	void specificRequest(){ cout << "specificRequest" << endl; }
};

/*������*/
class Adapter:public Target{
	Adaptee *adaptee;
public:
	Adapter() :adaptee(new Adaptee){}
	void request(){ adaptee->specificRequest(); }
	~Adapter(){ delete adaptee; }
};

/*//Adapter��Ҳ����д��������ʽ
class Adapter : public Adaptee, public Target  
{  
public:  
    // Implements ITarget interface  
    void Request()  
    {  
        // Possibly do some data manipulation  
        // and then call SpecificRequest    
        this->SpecificRequest();  
    }  
};  */
int main()
{
	Target *t = new Adapter();
	t->request();
	system("pause");
	return 0;
}