#include<iostream>

using namespace std;

/*单件通过将构造函数声明为私有，使得不能在类外部创建对象，同时设置一个本类的静态对象变量
在自己类内部创建一个对象，但由于是静态变量，只能创建一个，同时拷贝构造和赋值运算符声明为
私有，且不定义（因为根本不会被调用），以防止任何这类的复制动作产生。
  同时公有函数返回该唯一对象的引用，使得外部能够声明该类的引用，并有一些接口（setValue（）、
  getValue（）来处理该类，但无论有多少引用，都只是在处理一个类。）
*/
class Singleton{
	static Singleton s;
	int i;
	Singleton(int x):i(x){}
	Singleton(const Singleton&)  /*Disallowed，故意不定义它们是因为，如果有函数访问这些函数（通过成员函数或者友好类）
                                   在链接的时候会导致没有定义而触发的错误*/
	Singleton& operator = (const Singleton&)  //Disallowed
public:
	static Singleton& instance(){ return s; } //返回一个单例的引用
	int getValue(){ return i; }
	void setValue(int val){ i = val; }
};

Singleton Singleton::s(47);

int main()
{
	//只能创建单件的引用，且不能声明另外一个类的实例
	Singleton& s = Singleton::instance();
	cout << s.getValue() << endl;
	Singleton& s2 = Singleton::instance();
	s2.setValue(9);
	cout << s.getValue() << endl;
	//Singleton s3;// wrong,disallowed.
	return 0;
}