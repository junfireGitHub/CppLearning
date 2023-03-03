#include<iostream>

using namespace std;

/*����ͨ�������캯������Ϊ˽�У�ʹ�ò��������ⲿ��������ͬʱ����һ������ľ�̬�������
���Լ����ڲ�����һ�����󣬵������Ǿ�̬������ֻ�ܴ���һ����ͬʱ��������͸�ֵ���������Ϊ
˽�У��Ҳ����壨��Ϊ�������ᱻ���ã����Է�ֹ�κ�����ĸ��ƶ���������
  ͬʱ���к������ظ�Ψһ��������ã�ʹ���ⲿ�ܹ�������������ã�����һЩ�ӿڣ�setValue������
  getValue������������࣬�������ж������ã���ֻ���ڴ���һ���ࡣ��
*/
class Singleton{
	static Singleton s;
	int i;
	Singleton(int x):i(x){}
	Singleton(const Singleton&)  /*Disallowed�����ⲻ������������Ϊ������к���������Щ������ͨ����Ա���������Ѻ��ࣩ
                                   �����ӵ�ʱ��ᵼ��û�ж���������Ĵ���*/
	Singleton& operator = (const Singleton&)  //Disallowed
public:
	static Singleton& instance(){ return s; } //����һ������������
	int getValue(){ return i; }
	void setValue(int val){ i = val; }
};

Singleton Singleton::s(47);

int main()
{
	//ֻ�ܴ������������ã��Ҳ�����������һ�����ʵ��
	Singleton& s = Singleton::instance();
	cout << s.getValue() << endl;
	Singleton& s2 = Singleton::instance();
	s2.setValue(9);
	cout << s.getValue() << endl;
	//Singleton s3;// wrong,disallowed.
	return 0;
}