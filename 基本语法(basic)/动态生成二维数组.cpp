/*C++版本*/
int **p;
p = new int*[10];    //注意，int*[10]表示一个有10个元素的指针数组
for (int i = 0; i != 10; ++i)
{
    p[i] = new int[5];
}
for(int i = 0; i != 5; i++)
{
    delete[] p[i];
}
delete[] p;

/*C版本*/
double **data;

data = (double **)malloc(m*sizeof(double *));
for(int j=0;j<m;j++)
{
	data[j] = (double*)malloc(n*sizeof(double));  //这个指针数组的每个指针元素又指向一个数组。
}
for (int i=0;i<m;i++)
{
	for (int j=0;j<n;j++)
	{
		data[i][j]=i*n+j;//初始化数组元素
	}
}
for (i=0;i<m;i++)
{
	free(data[i]); //先撤销指针元素所指向的数组
}              
free(data);