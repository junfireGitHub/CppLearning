/*C++�汾*/
int **p;
p = new int*[10];    //ע�⣬int*[10]��ʾһ����10��Ԫ�ص�ָ������
for (int i = 0; i != 10; ++i)
{
    p[i] = new int[5];
}
for(int i = 0; i != 5; i++)
{
    delete[] p[i];
}
delete[] p;

/*C�汾*/
double **data;

data = (double **)malloc(m*sizeof(double *));
for(int j=0;j<m;j++)
{
	data[j] = (double*)malloc(n*sizeof(double));  //���ָ�������ÿ��ָ��Ԫ����ָ��һ�����顣
}
for (int i=0;i<m;i++)
{
	for (int j=0;j<n;j++)
	{
		data[i][j]=i*n+j;//��ʼ������Ԫ��
	}
}
for (i=0;i<m;i++)
{
	free(data[i]); //�ȳ���ָ��Ԫ����ָ�������
}              
free(data);