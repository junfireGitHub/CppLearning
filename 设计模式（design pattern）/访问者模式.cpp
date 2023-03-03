/**
VISITOR模式：将操作独立于类之外，类根据自己需要的操作而接受相应的访问者。
这样做的好处是如果需要实现一个新操作，类的结构不用变，特别是整个类层次的操作，如果要变，代价是比较大的。
使用Visitor模式就可以保证增加操作非常简单方便，并且符合OCP了。

*/

// 程序无法编译通过，需要将两个类写在不同的文件中才行？ 理解就好。

#include <iostream>
#include <string>
using namespace std;

//定义访问者的基类：


class IMonster;
class SmallMonster;
class BossMonster;

class IMonsterVisitor {
public:
	IMonsterVisitor(){}
	virtual ~IMonsterVisitor(){}

	virtual void visit(IMonster* m){}
	virtual void visit(SmallMonster* m){}
	virtual void visit(BossMonster* m){}
};


class MonsterVisitor :public IMonsterVisitor {
public:
	void visit(IMonster* m)
	{
		printf("普通怪物:%s  生命值:%d  攻击力:%d  防御力:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
	
	void visit(SmallMonster* m)
	{
		printf("小怪:%s  生命值:%d  攻击力:%d  防御力:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
	
	void visit(BossMonster* m)
	{
		printf("终极大怪:%s  生命值:%d  攻击力:%d  防御力:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
};


//怪物基类
class IMonster {
public:
	IMonster(std::string name){
		_name = name;
		_life = 100;
		_atk = 100;
		_def = 100;
	}
	virtual ~IMonster();

	std::string getName() { return _name; }

	void setLife(int l){_life = l;}
	int getLife(){return _life;}

	void setATK(int a){ _atk = a; }
	int getATK(){ return _atk; }

	void setDEF(int d){ _def = d;}
	int getDEF(){ return _def; }

	virtual void prinfInfo(IMonsterVisitor* v){};

protected:
	std::string _name; //怪物名称
	int _life;         //生命值 0 - 100
	int _atk;          //攻击力 0 - 100
	int _def;          //防御力 0 - 100
};


//小怪
class SmallMonster :public IMonster {
public:
	SmallMonster(std::string n):IMonster(n){}
	void prinfInfo(IMonsterVisitor* v){ v->visit(this); }
};

//终极大怪
class BossMonster :public IMonster {
public:
	BossMonster(std::string n):IMonster(n) {
		_life = 1000;
		_atk = 1000;
		_def = 1000;
	}
	void prinfInfo(IMonsterVisitor* v){ v->visit(this); }
};


int main() {

	IMonster* s1 = new SmallMonster("虾兵");
	IMonster* s2 = new SmallMonster("蟹将");
	IMonster* b = new BossMonster("龙王怪");
	
	IMonsterVisitor* visitor = new MonsterVisitor();

	//游戏玩家遭遇龙王带领的虾兵蟹将的进攻，查看一下它们初始状态
	s1->prinfInfo(visitor);
	s2->prinfInfo(visitor);
	b->prinfInfo(visitor);
	
	//经过一番搏斗后，打退了龙王的进攻
	s1->setLife(50);
	s2->setLife(40);
	b->setLife(500);
	
	s1->prinfInfo(visitor);  //这里其实就是accept
	s2->prinfInfo(visitor);
	b->prinfInfo(visitor);

	return 0;
}

/* 输出结果为:
    小怪：虾兵  生命值：100  攻击力：100  防御力：100
	小怪：蟹将  生命值：100  攻击力：100  防御力：100
	终极大怪：龙王怪  生命值：1000  攻击力：1000   防御力：1000

*/