
// ��Ŀ��Դ�����ݽṹ����ε����P49

#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>

#include"stack.h"


int main()
{
	SqStack S;
	SElemType sVal,c,tmp;
	InitStack(&S);
	
	while (scanf("%c", &c)!=EOF)
	{
		if (c == '\n') break; //�������ʾ�������
		if (S.top == S.base)
		{
			Push(&S, c);
			continue;
		}
		GetTop(&S, &sVal);
		if (sVal == '('&& c == ')' || sVal == '['&& c == ']' ||
			sVal == '{'&& c == '}')
			Pop(&S, &tmp);//���õķ�������if(Pop(&S, &tmp))
		else
			Push(&S, c);
	}
	S.top == S.base ? printf("MATCH\n") : printf("DON'T MATCH\n");
	system("pause");
	return 0;
}

