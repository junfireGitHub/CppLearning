#include"stdio.h"

//Hanoi������,A������n��Բ�̣�������£�С�����ϣ�Ҫ�����B��
//�Ƶ�C����,�ƶ��������κ����϶�Ҫ���ִ�����£�С�����ϡ�
//n>=2ʱ�ֽ�Ϊ��������
//step1:��A�ϵ�n-1��Բ���Ƶ�B��
//step2:��A�ϵ�1��Բ���Ƶ�C��
//step3:��B�ϵ�n-1��Բ���Ƶ�C��

//����һ�������ݹ����⣬�ô������ҵ���ϵʽ���ɡ�����ʵ�ֹ�������
//֪����
void move(int n,char x,char y,char z){
if(n==1)
printf("%c-->%c\n",x,z);
else{
move(n-1,x,z,y);//step1
printf("%c-->%c\n",x,z);//step2
move(n-1,y,x,z);//step2
}
}
void main(){
int h;
printf("\ninput number:\n");
scanf("%d",&h);
printf("the step to moving %2d diskes:\n",h);
move(h,'a','b','c');
}