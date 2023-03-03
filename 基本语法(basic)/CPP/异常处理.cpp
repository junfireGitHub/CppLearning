#include"iostream"
#include"cmath"
#include"string"
#include"cstdlib"
#include"cassert"
using std::cin;
using std::cout;
using std::endl;


int main()
{
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		try
		{
			if(i<1)
				throw i;
			cout<<"i not throw - value is "<<i<<endl;

			if(i>1)
				throw "here is another";
			cout<<"End of the try block"<<endl;
		}
		catch(const int i)
		{
			cout<<"i caught - value is "<<i<<endl;
		}
		catch(const char* pmessage)
		{
			cout<<"\""<<pmessage<<"\"caught"<<endl;
		}

		cout<<"End of the for loop (after the catch blocks)-i is "
			<<i<<endl;
	}

	return 0 ;
}