#include"iostream"
#include"fstream"
#include"cmath"
#include"string"
#include"cstdlib"
#include"cassert"

using namespace std;

/*ofstream and ifstream ������ namespac std�е�*/

int main()
{
	/*string filename;
	cout<<"Enter name for new file: ��for example: data.txt�� ";
	cin>>filename;*/

    //create output stream object for new file and call it fout
	//ofstream fout(filename.c_str()); //д���ļ����൱��cout��ֻ����Ļ������ļ�
	ofstream fout("data.txt",ios_base::out);//ios_base::out�൱��C�����е�"w"
	/* Ҳ����ͨ�� ofstream fout ; fout.open("data.txt");��ʵ��*/
	/*
	if(!fout)
	{
	   add code here
	   exit(1) //�������˳�����
	}
	if(!fin.is_open())
	{
	}//���õļ�鷽������ʽC++��֧��
	*/
	int age = 18 ;
    fout<<"your age is: "<<age<<endl; //write to file
    fout.close();  //close file

	//create input stream object for new file and call it fin
	//ifstream fin(filename.c_str());  //��ȡ�ļ�
    ifstream fin("data.txt",ios_base::in);  // ���ļ�������ݸ������������൱��cin
	char ch; 
	while(fin.get(ch))
		cout<<ch;
	fin.close();

	//fin.clear();//reset fin 

	//ios_base::ate��ios_base:app �����ļ�ָ��ָ��򿪵��ļ�β��ǰ��ֻ����������ӵ��ļ�β��
	//���߽�ָ��ŵ��ļ�β
	return 0 ;
}