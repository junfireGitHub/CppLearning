#include"HeaderLib.h"

using namespace std;

class String{
public:
	String(const char*str=NULL);
	String(const String &another);
	~String();
	String& operator =(const String& rhs); //凡是最终的返回值是本身的，返回类型都设置为引用类型，否则不可使用引用
	String operator +(const String& rhs);
	int Compare(const String &another);
	void printStr(){ printf("%s", m_data); }
private:
	char *m_data;
};

String::String(const char* str){
	if (str == NULL) {
		m_data = NULL;
		return;
	}
	int len = strlen(str) + 1;
	m_data = new char[len];
	memcpy(m_data, str, len);
}

String::String(const String &another){
	int len = strlen(another.m_data)+1;
	m_data = new char[len];
	memcpy(m_data, another.m_data, len);
}

String& String::operator =(const String& rhs){
	int len = strlen(rhs.m_data)+1;
	memcpy(m_data, rhs.m_data, len);
	return *this;
}

String String::operator +(const String& rhs){
	return String(strcat(m_data, rhs.m_data));
}

String::~String(){
	//if (m_data!=NULL)
	delete m_data;
}

int String::Compare(const String &another){
	return strcmp(m_data, another.m_data);
}

int main()
{
	String s1;
	s1.printStr();
	char *str = "I'm fine";
	char *str2 = ",and you";
	String *ps = new String(str2);
	String s4= *ps;	
	String s5(str);
	cout << s4.Compare(s5) << endl;
	s5 = *ps;
	delete ps;
	String s6 = s4 + s5;
	cout << "s4: "; s4.printStr(); cout << endl;
	cout << "s5: "; s5.printStr(); cout << endl;
	cout << "s6: "; s6.printStr(); cout << endl;
	
	system("pause");
	return 0;
}