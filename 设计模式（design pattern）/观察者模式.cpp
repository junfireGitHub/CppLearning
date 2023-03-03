#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>

using namespace std;

/*�۲���ģʽ�����������һ��һ�Զ��������ϵ����һ�������״̬�����ı�ʱ��
�������������Ķ��󶼵õ�֪ͨ�����Զ����¡���������������������(Dependents)��
����-����(Publish-Subsrcibe)�����Ծٸ����Ͷ��ĵ����ӣ����������������µ�ʱ��
������״̬�����˸ı䣬��Щ���ĵĶ��߾ͻ��յ�֪ͨ��Ȼ�������Ӧ�Ķ�����
����ȥ�����£������ղ����������������֮�������һ�Զ��������ϵ*/

class Observer{
public:
	virtual void update(){};
	virtual ~Observer(){};
};



class Blog{
protected :
	string m_status;
	list<Observer*> observer;
public:
	void attach(Observer* obser){ observer.push_back(obser); }
	void remove(Observer* obser){ observer.remove(obser); }
	virtual void setStatus(string status){ m_status = status; }
	string getStatus(){ return m_status; }
	void notify(){
		list<Observer*>::iterator it = observer.begin();
		while (it != observer.end()){
			(*it)->update();
			it++;
		}
	}
};

class BlogObserver :public Observer{
private:
	string m_status;
	string m_name; //�۲�������
	Blog *m_blog;//�۲�Ĳ���
public:
	BlogObserver(string name,Blog *blog) :m_name(name),m_blog(blog){}
	void update(){
		m_status = m_blog->getStatus();
		cout << m_name << "'s status is " << m_status << endl;
	}
};

class CsdnBlog :public Blog{
private:
	string m_name; //������
public:
	CsdnBlog(string name) :m_name(name){}
	void setStatus(string status){ m_status = m_name +" "+ status; }
	//string getStatus(){ return m_status; }
};


int main()
{
	Blog *blog = new CsdnBlog("junfire");
	Blog *blog2 = new CsdnBlog("wedgen");
	Observer *obser = new BlogObserver("reader1",blog );
	Observer *obser2 = new BlogObserver("reader2",blog2);

	blog->attach(obser);
	blog2->attach(obser2);

	blog->setStatus("busy");
	blog->notify();
	
	blog2->setStatus("free");
	blog2->notify();
	
	system("pause");
	return 0;
}