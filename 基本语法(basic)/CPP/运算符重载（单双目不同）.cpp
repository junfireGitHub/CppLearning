#include"iostream"
using std::cout;
using std::endl;

class complex
{
public:
	complex(double r,double i):real(r),imag(i){}
	complex(){}    //����д��complex()���У�main��c�����������캯������������캯��ȴû�к����壬�����ӻ����
	~complex(){}   //����������������������к����壨��������ɣ�

	void display(){cout<<real<<','<<imag<<endl;}

	complex operator -(complex c2); // ˫Ŀ���������
    complex& operator ++();   // ǰ�õ�Ŀ�����++����
	complex operator ++(int); // ���õ�Ŀ�����++����
private:
	double real;
	double imag;

};



complex complex::operator - (complex c2)// ˫Ŀ���������
{
	return complex(real-c2.real, imag-c2.imag);
}

complex& complex::operator ++()// ǰ�õ�Ŀ�����++����
{
	real++;
	imag++;
	return *this;
}//����ֻ������complex��complex&����Ϊ���صı����Ƕ������������
 //�������ñȶ������Ч�ʣ���Ϊ������ʱ����ͻ������ʱ����Ĺ����
 //�����������ڿ��Ե�����¶�ʹ�����ã����ҿɱ�����ĳЩ��������³�����
 
 //����ĺ��������++��˫Ŀ����������ڲ���ʹ�����ã���Ϊ�ֲ������溯�����ý�����������ֻ�÷��ض���
complex complex::operator ++(int)  // ���õ�Ŀ�����++����
{
	complex old=*this;
	++(*this);
	return old;
}//���õ�Ŀ��Ӧ�÷���++֮ǰ��ֵ

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