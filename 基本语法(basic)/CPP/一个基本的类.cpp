#include"iostream"
#include"cmath"
using namespace std;   //命名空间，如果两个或多个程序员为同一个大型工程的不同部分
                       //...工作，就会有潜在的名称冲突。命名空间可以解决这个问题，它相当于姓氏的作用。
                       //可以自定义命名空间
class Point                    /*Point 类的定义*/
{
public:                        /*外部接口*/
	Point(int xx=0,int yy=1);  /*构造函数，用于对对象进行初始化，可重载*/
	Point(Point &p);           /*拷贝构造函数*/
	int GetX(){return X;}
	int GetY();
	~Point(){};                /*析构函数，作用是完成对象删除 前 的一些清理工作，注意：它不负责对象删除。不接受*/
	                           /*任何参数，可以是虚函数，不做显示说明情况下，系统会生成一个不做任何事的默认析构函数*/
	friend double dist(Point a,Point b); /*友元函数，用来计算亮点间的距离*/
    /*声明友元类的格式为 friend clsaa A*/
private:                       /*私有数据，私有成员只能被本类的成员函数访问。*/
	int X,Y;                   /*私有数据，只能定义而不能赋初值*/ 
};                             /*don't foget the ; */

/*成员函数的实现*/
Point::Point(int xx,int yy)    /*构造函数的实现*/
{
	X=xx;
	Y=yy;
} 
/*构造函数的另外一种写法，效率更高。
Point::Point(int xx,int yy):X(xx),Y(yy)
{}  /*X与Y的初始化也可以使与xx，yy相关的某个公式*/

Point::Point(Point &p)         /*拷贝构造函数的实现*/
{
	X=p.X;
	Y=p.Y;
	cout<<"拷贝构造函数被调用"<<endl;
}

int Point::GetY()              /*与构造和拷贝构造定义不同*/
{
	return Y;
}

/*形参为Point类对象的函数*/
void fun(Point p)
{
	cout<<p.GetX()<<endl;
}

/*返回值为Point类的对象*/
Point fun1()
{
	Point A(1,2);
	return A; 
}
double dist(Point a,Point b)
{
	return sqrt(pow(a.X-b.X,2)+pow(a.Y-b.Y,2)); 
}
/*主函数*/
int main()
{
	Point A(4,5);
	Point B(A);               /*用A初始化B，拷贝构造函数被调用*/
	cout<<B.GetX()<<endl;
	fun(B);                   /*类作为形参，拷贝构造函数会被调用*/
	B=fun1();                 /*类作为返回值，拷贝构造函数会被调用*/
                              /*在以上三种情况下，拷贝构造函数会被调用*/
	Point C(1,2),D(4,6);
	cout<<"两点之间的距离为："<<dist(C,D)<<endl; /*测试友元函数*/

	int *p;  /*测试new 和 delete*/
	p=new int[10]; /*二维数组的话，p的声明需改为 int (*p)[25][10]*/
	p[5]=100;
	cout<<p[5]<<endl;
	delete []p;

	return 0 ;
}