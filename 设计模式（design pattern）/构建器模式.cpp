/*
1. 建造者模式包含如下角色：
	Builder：抽象建造者
	ConcreteBuilder：具体建造者
	Director：指挥者
	Product：产品角色
	
2. 建造者模式是通过组合得到产品
   这里是生产电脑产品， thinkPad和yoga只是配置不同，通过组合不同的配置得到这两个产品。
   最终的产品是在Builder手中
*/

// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

// 电脑
class Computer
{
public:
    void SetmCpu(string cpu) { m_strCpu = cpu;}
    void SetmMainboard(string mainboard) { m_strMainboard = mainboard; }
    void SetmRam(string ram) { m_strRam = ram; }
    void SetVideoCard(string videoCard) { m_strVideoCard = videoCard; }

    string GetCPU() { return m_strCpu; }
    string GetMainboard()  { return m_strMainboard; }
    string GetRam() { return m_strRam; }
    string GetVideoCard() { return m_strVideoCard; }

private:
    string m_strCpu;  // CPU
    string m_strMainboard;  // 主板
    string m_strRam;  // 内存
    string m_strVideoCard;  // 显卡
};

#endif // PRODUCT_H


// builder.h
#ifndef BUILDER_H
#define BUILDER_H

#include "product.h"

// 建造者接口，组装流程
class IBuilder
{
public:
    virtual void BuildCpu() = 0;  // 创建 CPU
    virtual void BuildMainboard() = 0;  // 创建主板
    virtual void BuildRam() = 0;  // 创建内存
    virtual void BuildVideoCard() = 0;  // 创建显卡
    virtual Computer* GetResult() = 0;  // 获取建造后的产品
};

#endif // BUILDER_H


// concrete_bulider.h
#ifndef CONCRETE_BULIDER_H
#define CONCRETE_BULIDER_H

#include "builder.h"

// ThinkPad 系列
class ThinkPadBuilder : public IBuilder
{
public:
    ThinkPadBuilder() { m_pComputer = new Computer(); }
    void BuildCpu() { m_pComputer->SetmCpu("i5-6200U"); }
    void BuildMainboard() { m_pComputer->SetmMainboard("Intel DH57DD"); }
    void BuildRam() { m_pComputer->SetmRam("DDR4"); }
    void BuildVideoCard()  { m_pComputer->SetVideoCard("NVIDIA Geforce 920MX"); }
    Computer* GetResult() { return m_pComputer; }

private:
    Computer *m_pComputer;
};

// Yoga 系列
class YogaBuilder : public IBuilder
{
public:
    YogaBuilder() { m_pComputer = new Computer(); }
    void BuildCpu() { m_pComputer->SetmCpu("i7-7500U"); }
    void BuildMainboard() { m_pComputer->SetmMainboard("Intel DP55KG"); }
    void BuildRam() { m_pComputer->SetmRam("DDR5"); }
    void BuildVideoCard()  { m_pComputer->SetVideoCard("NVIDIA GeForce 940MX"); }
    Computer* GetResult() { return m_pComputer; }

private:
    Computer *m_pComputer;
};

#endif // CONCRETE_BULIDER_H


// director.h
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"

// 指挥者
class Direcror
{
public:
    void Create(IBuilder *builder) {
        builder->BuildCpu();
        builder->BuildMainboard();
        builder->BuildRam();
        builder->BuildVideoCard();
    }
};

#endif // DIRECTOR_H



// main.cpp
#include "concrete_bulider.h"
#include "director.h"
#include <string>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
    Direcror *pDirecror = new Direcror();
    ThinkPadBuilder *pTPBuilder = new ThinkPadBuilder();
    YogaBuilder *pYogaBuilder = new YogaBuilder();

    // 组装 ThinkPad、Yoga
    pDirecror->Create(pTPBuilder);
    pDirecror->Create(pYogaBuilder);

    // 获取组装后的电脑
    Computer *pThinkPadComputer = pTPBuilder->GetResult();
    Computer *pYogaComputer = pYogaBuilder->GetResult();

    // 测试输出
    cout << "-----ThinkPad-----" << endl;
    cout << "CPU: " << pThinkPadComputer->GetCPU() << endl;
    cout << "Mainboard: " << pThinkPadComputer->GetMainboard() << endl;
    cout << "Ram: " << pThinkPadComputer->GetRam() << endl;
    cout << "VideoCard: " << pThinkPadComputer->GetVideoCard() << endl;

    cout << "-----Yoga-----" << endl;
    cout << "CPU: " << pYogaComputer->GetCPU() << endl;
    cout << "Mainboard: " << pYogaComputer->GetMainboard() << endl;
    cout << "Ram: " << pYogaComputer->GetRam() << endl;
    cout << "VideoCard: " << pYogaComputer->GetVideoCard() << endl;

    SAFE_DELETE(pThinkPadComputer);
    SAFE_DELETE(pYogaComputer);
    SAFE_DELETE(pTPBuilder);
    SAFE_DELETE(pYogaBuilder);
    SAFE_DELETE(pDirecror);

    getchar();

    return 0;
}

/*
输出如下：

	—–ThinkPad—– 
	CPU: i5-6200U 
	Mainboard: Intel DH57DD 
	Ram: DDR4 
	VideoCard: NVIDIA Geforce 920MX 
	—–Yoga—– 
	CPU: i7-7500U 
	Mainboard: Intel DP55KG 
	Ram: DDR5 
	VideoCard: NVIDIA GeForce 940MX
*/


