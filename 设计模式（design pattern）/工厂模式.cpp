#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*http://blog.csdn.net/wuzhekai1985/article/details/6660462*/

#define SIMPLE 0         //��ʾ�򵥹���ģʽ
#define FACTORY_WAY 1    //��ʾ��������ģʽ
#define ABSTRACT 2       //��ʾ���󹤳�ģʽ
#define PATTERN_CHOOSE ABSTRACT  

#if (PATTERN_CHOOSE==SIMPLE) 

/*�򵥹���ģʽ*/
/* ������Ƶ���Ҫȱ��֮ǰҲ�ᵽ��������Ҫ�����µĺ�����ʱ������Ҫ�޸Ĺ����ࡣ
���Υ���˿��ŷ��ԭ�����ʵ�壨�ࡢģ�顢������������չ�����ǲ����޸�*/
enum CTYPE { COREA, COREB };
class SingleCore{
public:
	virtual void make()=0;
};
class SingleCoreA:public SingleCore{
public:
	void make(){ cout << "SingleCoreA is made"<<endl; }
};

class SingleCoreB:public SingleCore{
public:
	void make(){ cout << "SingleCoreB is made"<<endl; }
};

class Factory{
public:
	SingleCore *createSingleCore(CTYPE type){
		if (type == COREA){ return new SingleCoreA; }
		else if (type == COREB){ return new SingleCoreB; }
		else{ cout << "erro parameter" << endl; return nullptr; }
	}
};

#elif(PATTERN_CHOOSE == FACTORY_WAY)

/*��������ģʽ*/ 
/*��������ģʽҲ��ȱ�㣬ÿ����һ�ֲ�Ʒ������Ҫ����һ������Ĺ�����
�����ҹ�˾��չѸ�٣��Ƴ��˺ܶ��µĴ������ˣ���ô��Ҫ������Ӧ���¹�����
��C++ʵ���У�����Ҫ����һ�����Ĺ����ࡣ��Ȼ����ȼ򵥹���ģʽ����������ģʽ��Ҫ������ඨ�塣*/
class SingleCore    
{    
public:    
	virtual void Show() = 0;  
};    
//����A    
class SingleCoreA : public SingleCore
{
public:
	void Show() { cout << "SingleCore A" << endl; }
};
//����B    
class SingleCoreB : public SingleCore
{
public:
	void Show() { cout << "SingleCore B" << endl; }
};
class Factory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
};
//����A�˵Ĺ���    
class FactoryA : public Factory
{
public:
	SingleCoreA* CreateSingleCore() { return new SingleCoreA; }
};
//����B�˵Ĺ���    
class FactoryB : public Factory
{
public:
	SingleCoreB* CreateSingleCore() { return new SingleCoreB; }
};


#else

/*���󷽷�ģʽ*/
/* ��Ȼ���˼򵥹���ģʽ�͹�������ģʽ��Ϊʲô��Ҫ�г��󹤳�ģʽ�أ�
��������ʲô�����أ����Ǿ�������ӣ���ҹ�˾�ļ������Ͻ��������������������˴�������
Ҳ��������˴����������ڼ򵥹���ģʽ�͹�������ģʽ���޳�Ī����
���󹤳�ģʽ�ǳ��ˡ����Ķ���Ϊ�ṩһ������һϵ����ػ��໥��������Ľӿڣ�
������ָ�����Ǿ�����ࡣ��������Ӧ�ã���ҹ�˾���ǿ�������������
һ��ר����������A�ͺŵĵ��˶�˴�������
����һ������ר����������B�ͺŵĵ��˶�˴��������������ʵ�ֵĴ��롣*/
class SingleCore     
{    
public:    
	virtual void Show() = 0;  
};    
class SingleCoreA: public SingleCore      
{    
public:    
	void Show() { cout<<"Single Core A"<<endl; }    
};    
class SingleCoreB :public SingleCore    
{
public:
	void Show() { cout << "Single Core B" << endl; }
};
//���    
class MultiCore
{
public:
	virtual void Show() = 0;
};
class MultiCoreA : public MultiCore
{
public:
	void Show() { cout << "Multi Core A" << endl; }

};
class MultiCoreB : public MultiCore
{
public:
	void Show() { cout << "Multi Core B" << endl; }
};
//����    
class CoreFactory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
	virtual MultiCore* CreateMultiCore() = 0;
};
//����A��ר����������A�ͺŵĴ�����    
class FactoryA :public CoreFactory
{
public:
	SingleCore* CreateSingleCore() { return new SingleCoreA(); }
	MultiCore* CreateMultiCore() { return new MultiCoreA(); }
};
//����B��ר����������B�ͺŵĴ�����    
class FactoryB : public CoreFactory
{
public:
	SingleCore* CreateSingleCore() { return new SingleCoreB(); }
	MultiCore* CreateMultiCore() { return new MultiCoreB(); }
};
#endif
int main()
{
	
#if (PATTERN_CHOOSE==SIMPLE) 
	/*�򵥹���ģʽ*/
	Factory factory;
	SingleCore* pSingleCore = nullptr;
	pSingleCore = factory.createSingleCore(COREA);
	if (pSingleCore != nullptr)
		pSingleCore->make();
	delete pSingleCore;

	pSingleCore = factory.createSingleCore(COREB);
	if (pSingleCore != nullptr)
		pSingleCore->make();
	delete pSingleCore;
#elif(PATTERN_CHOOSE == FACTORY_WAY)
	/*��������ģʽ*/
	SingleCore *pSingleCore;
	FactoryA factoryA;
	FactoryB factoryB;
	pSingleCore = factoryA.CreateSingleCore();
	pSingleCore->Show();
	delete pSingleCore;
	pSingleCore = factoryB.CreateSingleCore();
	pSingleCore->Show();
	delete pSingleCore;
#else
	/*���󹤳�*/
	/*��*/
#endif
	system("pause");
	return 0;
}