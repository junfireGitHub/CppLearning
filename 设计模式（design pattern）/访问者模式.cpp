/**
VISITORģʽ����������������֮�⣬������Լ���Ҫ�Ĳ�����������Ӧ�ķ����ߡ�
�������ĺô��������Ҫʵ��һ���²�������Ľṹ���ñ䣬�ر����������εĲ��������Ҫ�䣬�����ǱȽϴ�ġ�
ʹ��Visitorģʽ�Ϳ��Ա�֤���Ӳ����ǳ��򵥷��㣬���ҷ���OCP�ˡ�

*/

// �����޷�����ͨ������Ҫ��������д�ڲ�ͬ���ļ��в��У� ���ͺá�

#include <iostream>
#include <string>
using namespace std;

//��������ߵĻ��ࣺ


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
		printf("��ͨ����:%s  ����ֵ:%d  ������:%d  ������:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
	
	void visit(SmallMonster* m)
	{
		printf("С��:%s  ����ֵ:%d  ������:%d  ������:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
	
	void visit(BossMonster* m)
	{
		printf("�ռ����:%s  ����ֵ:%d  ������:%d  ������:%d\n"
			   , m->getName().c_str(), m->getLife(), m->getATK(), m->getDEF());
	}
};


//�������
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
	std::string _name; //��������
	int _life;         //����ֵ 0 - 100
	int _atk;          //������ 0 - 100
	int _def;          //������ 0 - 100
};


//С��
class SmallMonster :public IMonster {
public:
	SmallMonster(std::string n):IMonster(n){}
	void prinfInfo(IMonsterVisitor* v){ v->visit(this); }
};

//�ռ����
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

	IMonster* s1 = new SmallMonster("Ϻ��");
	IMonster* s2 = new SmallMonster("з��");
	IMonster* b = new BossMonster("������");
	
	IMonsterVisitor* visitor = new MonsterVisitor();

	//��Ϸ����������������Ϻ��з���Ľ������鿴һ�����ǳ�ʼ״̬
	s1->prinfInfo(visitor);
	s2->prinfInfo(visitor);
	b->prinfInfo(visitor);
	
	//����һ�������󣬴����������Ľ���
	s1->setLife(50);
	s2->setLife(40);
	b->setLife(500);
	
	s1->prinfInfo(visitor);  //������ʵ����accept
	s2->prinfInfo(visitor);
	b->prinfInfo(visitor);

	return 0;
}

/* ������Ϊ:
    С�֣�Ϻ��  ����ֵ��100  ��������100  ��������100
	С�֣�з��  ����ֵ��100  ��������100  ��������100
	�ռ���֣�������  ����ֵ��1000  ��������1000   ��������1000

*/