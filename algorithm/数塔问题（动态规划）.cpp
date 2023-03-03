#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100;
// �����������ʵ�ֵ��Ǹ������ֵ��o��ֵΪo��x�����ֵ
template <class T>
T updateMax(T& o, const T& x) {
	T temp;
    temp = (o > x) ? o : x;
	return temp;
}

// f����Ϊ��̬�滮��״̬����
// num����Ϊ���������
// nΪ����������߶�
int f[N][N], num[N][N], n;

int main() {
    // ����n����������num
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    // step 1 begin: ������ʵ�ֶ�̬�滮�㷨�߼�
    for(int ii = n; ii >=1; ii--)
        for (int jj = 1; jj <= ii; ++jj)
            {
                if(ii == n)
                    f[n][jj] = num[n][jj];
                else
                    f[ii][jj] = num[ii][jj] + updateMax(f[ii+1][jj],f[ii+1][jj+1]); 
            }
    // step 1 end.

    // �������ս������result����Ϊ�Ǽ������ֵ�����Գ�ʼ��Ϊ0
    int result = f[1][1];
 
    // ����������Ȩֵ��result
    printf("%d\n", result);
    return 0;
}