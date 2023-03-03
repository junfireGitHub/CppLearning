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
	ArrayOfPoints pointsArray1(1);     /*��������*/
	pointsArray1.Element(0).Move(5,10);
    ArrayOfPoints pointsArray2(pointsArray1);/*����������ֵ��pointsArray2*/
	cout<<"Point_0 of array1:"
		<<pointsArray1.Element(0).GetX()<<","
		<<pointsArray1.Element(0).GetY()<<endl; /*���Ϊ5��10*/
	cout<<"Point_0 of array2:"
		<<pointsArray2.Element(0).GetX()<<","
		<<pointsArray2.Element(0).GetY()<<endl; /*���Ϊ5��10*/
    pointsArray2.Element(0).Move(25,40);
	cout<<"Point_0 of array1:"
		<<pointsArray1.Element(0).GetX()<<","
		<<pointsArray1.Element(0).GetY()<<endl; 
	/*���Ϊ25��40  �ɼ���array2�ĸ�ֵ������array1��ֵ�ĸı�          */
    /*ԭ������ϵͳĬ�Ͽ������캯���ڵ���ʱֻʵ����ǳ��������ν        */
    /*ǳ�������Ǳ���������ʹarray2��ָ��ֵ����array1��ָ��ֵ���Ӷ�    */
    /*ʹ����ָ��ͬһ��ַ���Ӷ��Է�ֵ�ĸı��������һ���ĸı䣬��������*/
    /*����������ͬһ���ڴ�ռ䣬��˿ռ䱻�����ͷţ��ᵼ�����д���*/

    /*�����һ����ķ����Ǳ�д�������캯����ʵ�֡���������������£�*/
	
	/*
	ArrayOfPoints::ArrayOfPoints(ArrayOfPoints& pointsArray)
	{
	  numberOfPoints=pointsArray.numberOfPoints;
	  points=new Point[numberOfPoints];  /*Ū��Ϊ������Ҫ�õ���̬�ڴ����new
	  for(int i=0;i<numberOfPoints;i++)
	    points[i].Move(pointsArray.Element(i).GetX(),pointsArray.Element(i).GetY());
	}
	*/

	cout<<"Point_0 of array2:"
		<<pointsArray2.Element(0).GetX()<<","
		<<pointsArray2.Element(0).GetY()<<endl; /*���Ϊ25��40*/
	return 0 ;
}