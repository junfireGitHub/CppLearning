#include <stdio.h>
#include<stdlib.h>

// �ַ���д����fgetc and fputc

int main(){
	FILE *fp;
	char ch;
	if((fp=fopen("c:\\zhe.txt","w"))==NULL){  // check whether open file successfully
		printf("cannot not open file\n");
		exit(0);                         //exit program
	}
/*  ʹ�øöζ�������Ҫ��w��Ϊr
	ch=fgetc(fp);
	while(!feof(fp)){     //feof()�ļ�״̬�Ƿ��ļ�����
	printf("%c",ch);
	ch=fgetc(fp); //after calling function fgetch,position pointer will point next byte-
	}                 //-so it can read all chars
*/
	ch=getchar();
	while(ch!='#'){
	fputc(ch,fp);
	ch=getchar();
	}
	fclose(fp);   //���ַ�д���ļ���
//	printf("\n");
}
