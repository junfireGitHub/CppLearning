#include"iostream"
#include"cmath"
using namespace std;   //�����ռ䣬���������������ԱΪͬһ�����͹��̵Ĳ�ͬ����
                       //...�������ͻ���Ǳ�ڵ����Ƴ�ͻ�������ռ���Խ��������⣬���൱�����ϵ����á�
                       //�����Զ��������ռ�
class Point                    /*Point ��Ķ���*/
{
public:                        /*�ⲿ�ӿ�*/
	Point(int xx=0,int yy=1);  /*���캯�������ڶԶ�����г�ʼ����������*/
	Point(Point &p);           /*�������캯��*/
	int GetX(){return X;}
	int GetY();
	~Point(){};                /*������������������ɶ���ɾ�� ǰ ��һЩ��������ע�⣺�����������ɾ����������*/
	                           /*�κβ������������麯����������ʾ˵������£�ϵͳ������һ�������κ��µ�Ĭ����������*/
	friend double dist(Point a,Point b); /*��Ԫ�������������������ľ���*/
    /*������Ԫ��ĸ�ʽΪ friend clsaa A*/
private:                       /*˽�����ݣ�˽�г�Աֻ�ܱ�����ĳ�Ա�������ʡ�*/
	int X,Y;                   /*˽�����ݣ�ֻ�ܶ�������ܸ���ֵ*/ 
};                             /*don't foget the ; */

/*��Ա������ʵ��*/
Point::Point(int xx,int yy)    /*���캯����ʵ��*/
{
	X=xx;
	Y=yy;
} 
/*���캯��������һ��д����Ч�ʸ��ߡ�
Point::Point(int xx,int yy):X(xx),Y(yy)
{}  /*X��Y�ĳ�ʼ��Ҳ����ʹ��xx��yy��ص�ĳ����ʽ*/

Point::Point(Point &p)         /*�������캯����ʵ��*/
{
	X=p.X;
	Y=p.Y;
	cout<<"�������캯��������"<<endl;
}

int Point::GetY()              /*�빹��Ϳ������춨�岻ͬ*/
{
	return Y;
}

/*�β�ΪPoint�����ĺ���*/
void fun(Point p)
{
	cout<<p.GetX()<<endl;
}

/*����ֵΪPoint��Ķ���*/
Point fun1()
{
	Point A(1,2);
	return A; 
}
double dist(Point a,Point b)
{
	return sqrt(pow(a.X-b.X,2)+pow(a.Y-b.Y,2)); 
}
/*������*/
int main()
{
	Point A(4,5);
	Point B(A);               /*��A��ʼ��B���������캯��������*/
	cout<<B.GetX()<<endl;
	fun(B);                   /*����Ϊ�βΣ��������캯���ᱻ����*/
	B=fun1();                 /*����Ϊ����ֵ���������캯���ᱻ����*/
                              /*��������������£��������캯���ᱻ����*/
	Point C(1,2),D(4,6);
	cout<<"����֮��ľ���Ϊ��"<<dist(C,D)<<endl; /*������Ԫ����*/

	int *p;  /*����new �� delete*/
	p=new int[10]; /*��ά����Ļ���p���������Ϊ int (*p)[25][10]*/
	p[5]=100;
	cout<<p[5]<<endl;
	delete []p;

	return 0 ;
}