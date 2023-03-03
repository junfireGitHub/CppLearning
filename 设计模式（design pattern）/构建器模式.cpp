/*
1. ������ģʽ�������½�ɫ��
	Builder����������
	ConcreteBuilder�����彨����
	Director��ָ����
	Product����Ʒ��ɫ
	
2. ������ģʽ��ͨ����ϵõ���Ʒ
   �������������Բ�Ʒ�� thinkPad��yogaֻ�����ò�ͬ��ͨ����ϲ�ͬ�����õõ���������Ʒ��
   ���յĲ�Ʒ����Builder����
*/

// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

using namespace std;

// ����
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
    string m_strMainboard;  // ����
    string m_strRam;  // �ڴ�
    string m_strVideoCard;  // �Կ�
};

#endif // PRODUCT_H


// builder.h
#ifndef BUILDER_H
#define BUILDER_H

#include "product.h"

// �����߽ӿڣ���װ����
class IBuilder
{
public:
    virtual void BuildCpu() = 0;  // ���� CPU
    virtual void BuildMainboard() = 0;  // ��������
    virtual void BuildRam() = 0;  // �����ڴ�
    virtual void BuildVideoCard() = 0;  // �����Կ�
    virtual Computer* GetResult() = 0;  // ��ȡ�����Ĳ�Ʒ
};

#endif // BUILDER_H


// concrete_bulider.h
#ifndef CONCRETE_BULIDER_H
#define CONCRETE_BULIDER_H

#include "builder.h"

// ThinkPad ϵ��
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

// Yoga ϵ��
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

// ָ����
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

    // ��װ ThinkPad��Yoga
    pDirecror->Create(pTPBuilder);
    pDirecror->Create(pYogaBuilder);

    // ��ȡ��װ��ĵ���
    Computer *pThinkPadComputer = pTPBuilder->GetResult();
    Computer *pYogaComputer = pYogaBuilder->GetResult();

    // �������
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
������£�

	���CThinkPad���C 
	CPU: i5-6200U 
	Mainboard: Intel DH57DD 
	Ram: DDR4 
	VideoCard: NVIDIA Geforce 920MX 
	���CYoga���C 
	CPU: i7-7500U 
	Mainboard: Intel DP55KG 
	Ram: DDR5 
	VideoCard: NVIDIA GeForce 940MX
*/


