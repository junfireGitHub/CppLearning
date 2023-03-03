#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

/*http://blog.csdn.net/wuzhekai1985/article/details/6660462*/

#define SIMPLE 0         //表示简单工厂模式
#define FACTORY_WAY 1    //表示工厂方法模式
#define ABSTRACT 2       //表示抽象工厂模式
#define PATTERN_CHOOSE ABSTRACT  

#if (PATTERN_CHOOSE==SIMPLE) 

/*简单工厂模式*/
/* 这样设计的主要缺点之前也提到过，就是要增加新的核类型时，就需要修改工厂类。
这就违反了开放封闭原则：软件实体（类、模块、函数）可以扩展，但是不可修改*/
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

/*工厂方法模式*/ 
/*工厂方法模式也有缺点，每增加一种产品，就需要增加一个对象的工厂。
如果这家公司发展迅速，推出了很多新的处理器核，那么就要开设相应的新工厂。
在C++实现中，就是要定义一个个的工厂类。显然，相比简单工厂模式，工厂方法模式需要更多的类定义。*/
class SingleCore    
{    
public:    
	virtual void Show() = 0;  
};    
//单核A    
class SingleCoreA : public SingleCore
{
public:
	void Show() { cout << "SingleCore A" << endl; }
};
//单核B    
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
//生产A核的工厂    
class FactoryA : public Factory
{
public:
	SingleCoreA* CreateSingleCore() { return new SingleCoreA; }
};
//生产B核的工厂    
class FactoryB : public Factory
{
public:
	SingleCoreB* CreateSingleCore() { return new SingleCoreB; }
};


#else

/*抽象方法模式*/
/* 既然有了简单工厂模式和工厂方法模式，为什么还要有抽象工厂模式呢？
它到底有什么作用呢？还是举这个例子，这家公司的技术不断进步，不仅可以生产单核处理器，
也能生产多核处理器。现在简单工厂模式和工厂方法模式都鞭长莫及。
抽象工厂模式登场了。它的定义为提供一个创建一系列相关或相互依赖对象的接口，
而无需指定它们具体的类。具体这样应用，这家公司还是开设两个工厂，
一个专门用来生产A型号的单核多核处理器，
而另一个工厂专门用来生产B型号的单核多核处理器，下面给出实现的代码。*/
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
//多核    
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
//工厂    
class CoreFactory
{
public:
	virtual SingleCore* CreateSingleCore() = 0;
	virtual MultiCore* CreateMultiCore() = 0;
};
//工厂A，专门用来生产A型号的处理器    
class FactoryA :public CoreFactory
{
public:
	SingleCore* CreateSingleCore() { return new SingleCoreA(); }
	MultiCore* CreateMultiCore() { return new MultiCoreA(); }
};
//工厂B，专门用来生产B型号的处理器    
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
	/*简单工厂模式*/
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
	/*工厂方法模式*/
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
	/*抽象工厂*/
	/*略*/
#endif
	system("pause");
	return 0;
}