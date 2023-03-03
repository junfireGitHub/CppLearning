#include"stdio.h"

void main(){
int f1=1,f2=1,f3,i;
printf("%d\t%d\n",f1,f2);
for(i=3;i<=12;i++){
f3=f1+f2;
printf("%d%c",f3,i%2?'\t':'\n');
f1=f2;
f2=f3;
}
}