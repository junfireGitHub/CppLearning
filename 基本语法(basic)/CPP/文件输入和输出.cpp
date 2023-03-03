#include"iostream"
#include"fstream"
#include"cmath"
#include"string"
#include"cstdlib"
#include"cassert"

using namespace std;

/*ofstream and ifstream 都是在 namespac std中的*/

int main()
{
	/*string filename;
	cout<<"Enter name for new file: （for example: data.txt） ";
	cin>>filename;*/

    //create output stream object for new file and call it fout
	//ofstream fout(filename.c_str()); //写入文件，相当于cout，只是屏幕变成了文件
	ofstream fout("data.txt",ios_base::out);//ios_base::out相当于C语言中的"w"
	/* 也可以通过 ofstream fout ; fout.open("data.txt");来实现*/
	/*
	if(!fout)
	{
	   add code here
	   exit(1) //非正常退出程序
	}
	if(!fin.is_open())
	{
	}//更好的检查方法，老式C++不支持
	*/
	int age = 18 ;
    fout<<"your age is: "<<age<<endl; //write to file
    fout.close();  //close file

	//create input stream object for new file and call it fin
	//ifstream fin(filename.c_str());  //读取文件
    ifstream fin("data.txt",ios_base::in);  // 把文件里的数据给其他变量，相当于cin
	char ch; 
	while(fin.get(ch))
		cout<<ch;
	fin.close();

	//fin.clear();//reset fin 

	//ios_base::ate和ios_base:app 都将文件指针指向打开的文件尾，前者只允许将数据添加到文件尾，
	//后者将指针放到文件尾
	return 0 ;
}