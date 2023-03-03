#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;
/*
ģ�巽��ģʽ��
��һ����һ�����м̳��Ա㴴��һ���µ��࣬
���û����м������еĴ��룬���Ҹ������е�
һ�����������Ա㶨������Ҫ��Ӧ�ó���

��ģ��ģʽ��Template Pattern���У�һ�������๫��������ִ�����ķ����ķ�ʽ/ģ�塣
����������԰���Ҫ��д����ʵ�֣������ý��Գ������ж���ķ�ʽ(��templateMethod����)���С�
�������͵����ģʽ������Ϊ��ģʽ��

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