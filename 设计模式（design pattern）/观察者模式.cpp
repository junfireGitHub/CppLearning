#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>

using namespace std;

/*观察者模式：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，
所有依赖于它的对象都得到通知并被自动更新。它还有两个别名，依赖(Dependents)，
发布-订阅(Publish-Subsrcibe)。可以举个博客订阅的例子，当博主发表新文章的时候，
即博主状态发生了改变，那些订阅的读者就会收到通知，然后进行相应的动作，
比如去看文章，或者收藏起来。博主与读者之间存在种一对多的依赖关系*/

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
	string m_name; //观察者姓名
	Blog *m_blog;//观察的博客
public:
	BlogObserver(string name,Blog *blog) :m_name(name),m_blog(blog){}
	void update(){
		m_status = m_blog->getStatus();
		cout << m_name << "'s status is " << m_status << endl;
	}
};

class CsdnBlog :public Blog{
private:
	string m_name; //博主名
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