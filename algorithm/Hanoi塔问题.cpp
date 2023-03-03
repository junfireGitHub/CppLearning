#include"stdio.h"

//Hanoi塔问题,A针上有n个圆盘，大的在下，小的在上，要求借助B针
//移到C阵上,移动过程中任何阵上都要保持大的在下，小的在上。
//n>=2时分解为如下三步
//step1:把A上的n-1个圆盘移到B上
//step2:把A上的1个圆盘移到C上
//step3:把B上的n-1个圆盘移到C上

//这是一个函数递归问题，好处在于找到关系式即可。具体实现过程无需
//知道。
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