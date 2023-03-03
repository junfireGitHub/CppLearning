#include"iostream"
using std::cout;
using std::endl;

class complex
{
public:
	complex(double r,double i):real(r),imag(i){}
	complex(){}    //这里写成complex()则不行，main中c会调用这个构造函数，但这个构造函数却没有函数体，则链接会出错
	~complex(){}   //析构函数如声明，则必须有函数体（类内外均可）

	void display(){cout<<real<<','<<imag<<endl;}

	complex operator -(complex c2); // 双目运算符重载
    complex& operator ++();   // 前置单目运算符++重载
	complex operator ++(int); // 后置单目运算符++重载
private:
	double real;
	double imag;

};



complex complex::operator - (complex c2)// 双目运算符重载
{
	return complex(real-c2.real, imag-c2.imag);
}

complex& complex::operator ++()// 前置单目运算符++重载
{
	real++;
	imag++;
	return *this;
}//这里只可以用complex或complex&，因为返回的必须是对象或对象的引用
 //返回引用比对象更有效率，因为返回临时对象就会带来临时对象的构造等
 //操作，所以在可以的情况下都使用引用，而且可避免在某些极端情况下出问题
 
 //下面的后置运算符++和双目运算符是由于不可使用引用（因为局部对象随函数调用结束而消亡）只好返回对象。
complex complex::operator ++(int)  // 后置单目运算符++重载
{
	complex old=*this;
	++(*this);
	return old;
}//后置单目，应该返回++之前的值

int main()
{
	complex a(3,4),b(3,4),c,d,e;
	c=a-b;
    c.display();
	d=a++;
	e=++b;
	d.display();
	a.display();
	e.display();
	b.display();
	return 0;
}