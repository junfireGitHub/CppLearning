#include"iostream"
using namespace std;

class Point
{
public:
	~Point()
	{cout<<"Destructor called."<<endl;}
	int GetX(){return X;}
	int GetY(){return Y;}
	void Move(int x,int y)
	{X=x;Y=y;}
private:
	int X,Y;
};

class ArrayOfPoints
{
public:
	ArrayOfPoints(int n)
	{numberOfPoints=n;points=new Point[n];}
	~ArrayOfPoints()
	{numberOfPoints=0;delete[]points;}
	Point& Element(int n)
	{return points[n];}
private:
	Point *points;
	int numberOfPoints;
};

int main()
{
	ArrayOfPoints pointsArray1(1);     /*创建对象*/
	pointsArray1.Element(0).Move(5,10);
    ArrayOfPoints pointsArray2(pointsArray1);/*将上述对象赋值给pointsArray2*/
	cout<<"Point_0 of array1:"
		<<pointsArray1.Element(0).GetX()<<","
		<<pointsArray1.Element(0).GetY()<<endl; /*结果为5，10*/
	cout<<"Point_0 of array2:"
		<<pointsArray2.Element(0).GetX()<<","
		<<pointsArray2.Element(0).GetY()<<endl; /*结果为5，10*/
    pointsArray2.Element(0).Move(25,40);
	cout<<"Point_0 of array1:"
		<<pointsArray1.Element(0).GetX()<<","
		<<pointsArray1.Element(0).GetY()<<endl; 
	/*结果为25，40  可见对array2的赋值引起了array1的值的改变          */
    /*原因在于系统默认拷贝构造函数在调用时只实现了浅拷贝，所谓        */
    /*浅拷贝就是笨拷贝，它使array2的指针值等于array1的指针值，从而    */
    /*使两者指向同一地址，从而对方值的改变会引起另一方的改变，并且由于*/
    /*两个对象共用同一块内存空间，因此空间被两次释放，会导致运行错误。*/

    /*解决这一问题的方法是编写拷贝构造函数，实现“深拷贝”，代码如下：*/
	
	/*
	ArrayOfPoints::ArrayOfPoints(ArrayOfPoints& pointsArray)
	{
	  numberOfPoints=pointsArray.numberOfPoints;
	  points=new Point[numberOfPoints];  /*弄懂为何这里要用到动态内存分配new
	  for(int i=0;i<numberOfPoints;i++)
	    points[i].Move(pointsArray.Element(i).GetX(),pointsArray.Element(i).GetY());
	}
	*/

	cout<<"Point_0 of array2:"
		<<pointsArray2.Element(0).GetX()<<","
		<<pointsArray2.Element(0).GetY()<<endl; /*结果为25，40*/
	return 0 ;
}