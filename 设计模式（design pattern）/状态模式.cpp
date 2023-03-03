#include <iostream>
#include "Facade.h"
using namespace std;

// 交通信号灯
class TrafficLights
{
public:
    TrafficLights() { m_pState = new RedLight(this); }
    void SetState(IState* state) { m_pState = state; }
    void Request() { m_pState->Handle(); }

private:
    IState* m_pState;
};


// 信号灯的状态
class IState
{
public:
    virtual void Handle() = 0;
};


// 红灯
class RedLight : public IState
{
public:
    RedLight(TrafficLights* context): m_pContext(context) {}
    virtual void Handle()
	{
		std::cout << "Red Light" << std::endl;
		m_pContext->SetState(new GreenLight(m_pContext));
		delete this;
	}		

private:
    TrafficLights* m_pContext;
};

// 绿灯
class GreenLight : public IState
{
public:
    GreenLight(TrafficLights* context): m_pContext(context) {}
    virtual void Handle()
	{
		std::cout << "Green Light" << std::endl;
		m_pContext->SetState(new YellowLight(m_pContext));
		delete this;
	}	

private:
    TrafficLights* m_pContext;
};

// 黄灯
class YellowLight : public IState
{
public:
    YellowLight(TrafficLights* context): m_pContext(context) {}
    virtual void Handle()
	{
		std::cout << "Yellow Light" << std::endl;
		m_pContext->SetState(new RedLight(m_pContext));
		delete this;
	}	

private:
    TrafficLights* m_pContext;
};


int main()
{
    TrafficLights tl;
    enum TLState {Red, Green, Yellow};
    TLState state = Red;  // 初始状态为红灯
    int i = 0;  // 总次数
    int seconds;  // 秒数

    while (true) {
        // 表示一个完整的状态流（红灯->绿灯->黄灯）已经完成
        if (i % 3 == 0)
            std::cout << "**********" << "Session " << ((i+1)/3)+1 << "**********" << std::endl;

        // 休眠
        sleep(3);

        tl.Request();
        i++;
    }
    return 0;
}

/*
输出如下：
*****Session 1***** 
Red Light 
Green Light 
Yellow Light 
*****Session 2***** 
Red Light 
Green Light 
Yellow Light 
*****Session 3***** 
Red Light 
Green Light 
Yellow Light 
*****Session n***** 
…
*/
