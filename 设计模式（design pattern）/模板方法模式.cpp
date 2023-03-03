#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;
/*
模板方法模式：
从一个或一组类中继承以便创建一个新的类，
重用基类中几乎所有的代码，并且覆盖其中的
一个或多个函数以便定义所需要的应用程序

在模板模式（Template Pattern）中，一个抽象类公开定义了执行它的方法的方式/模板。
它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式(即templateMethod不变)进行。
这种类型的设计模式属于行为型模式。

*/

class ApplicationFramework{
	virtual void customize1() = 0;
	virtual void customize2() = 0;
public:
	void templateMethod(){
		for (int i = 0; i < 5; i++){
			customize1();
			customize2();
		}
	}
};

class MyApp :public ApplicationFramework{
protected:
	void customize1(){ cout << "MyApp::customize1()" << endl; }
	void customize2(){ cout << "MyApp::customize2()" << endl; }
};
int main()
{
	MyApp myapp;
	myapp.templateMethod();
	system("pause");
	return 0;
}