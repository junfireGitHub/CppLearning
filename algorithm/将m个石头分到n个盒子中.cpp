

/*
���㽫m��ʯͷ�ֵ�n���������ܹ��ж���
�ַַ�������ͬ��ʾͬһ�ַַ�����1 0 3 3�� 1 3 0 3
��ͬһ�ַַ���
*/
#include"iostream"

using std::cin;
using std::cout;
using std::endl;


int cal_sum(int m, int n);

int main()
{
	int t,m,n,sum=0;
    cout<<"please input the number of test times"<<endl; // t is the number of test times
	cin>>t;    
	while(t--)
	{
		cout<<"please input the num of stone and box"<<endl; // m is the num of stone,n is the num of box
		cin>>m>>n;
		for(int i=1;i<=n;i++)
			sum += cal_sum(m,i);
		cout<<sum<<endl;
		sum=0;
	}
    
	return 0;
}

int cal_sum(int m, int n)
{	
	if( m<n || m<=0 || n<=0 )
		return 0;
	else if( m==1 || n==1 || m==n )
		return 1;
	else
	{
		int k =0;
		for(int i=1;i<=n;i++)
			k+=cal_sum(m-n,i);
		return k;
	}
}