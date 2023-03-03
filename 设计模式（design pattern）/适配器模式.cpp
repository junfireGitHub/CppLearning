#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*客户需要的接口*/
class Target{
public :
	virtual void request(){ cout << "request" << endl; }
};

/*实际接口*/
class Adaptee{
public:
	void specificRequest(){ cout << "specificRequest" << endl; }
};

/*适配器*/
class Adapter:public Target{
	Adaptee *adaptee;
public:
	Adapter() :adaptee(new Adaptee){}
	void request(){ adaptee->specificRequest(); }
	~Adapter(){ delete adaptee; }
};

/*//Adapter类也可以写成如下形式
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