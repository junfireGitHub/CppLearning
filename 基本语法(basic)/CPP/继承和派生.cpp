#include"iostream"
#include"cmath"
using namespace std;

class Point                    /*Point ��Ķ���*/
{
public:                        
    void init_point(int xx,int yy){X=xx;Y=yy;}
	void move(int x,int y){X+=x;Y+=y;}
	int getX(){return X;}
	int getY(){return Y;}
	void get(){cout<<"��������get����������"<<endl;}
private:                       
	int X,Y;                   
};


class Rectangle: public Point   /*˽�м̳�*/
{
public:
	void init_rec(int x, int y, int w, int h)
	{	init_point(x,y); W=w; H=h;}   /**/
	void move(int x, int y) {Point::move(x,y);}
	int getX(){return Point::getX();}  /*�������û��point��������������λ���*/
	int getY(){return Point::getY();}
	int getH(){return H;}
	int getW(){return W;}
    void get(){cout<<"����������get����������"<<endl;}
private:
	int H;
	int W;
};


int main()
{
	Rectangle rect;
	rect.init_rec(2,3,20,10);
	rect.move(3,2);
	cout<<"the data of rect(x,y,w,h):"<<endl;
	cout<<rect.getX()<<","
		<<rect.getY()<<","
		<<rect.getW()<<","
		<<rect.getH()<<endl;
    Point *p;
	p=&rect;
	p->get(); /*����ֻ�ܷ��ʴӻ���̳�����get���������ͼ��ݹ���*/
	return 0;
} 

