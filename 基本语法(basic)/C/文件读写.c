#include <stdio.h>
#include<stdlib.h>

// 字符读写函数fgetc and fputc

int main(){
	FILE *fp;
	char ch;
	if((fp=fopen("c:\\zhe.txt","w"))==NULL){  // check whether open file successfully
		printf("cannot not open file\n");
		exit(0);                         //exit program
	}
/*  使用该段读程序，需要将w改为r
	ch=fgetc(fp);
	while(!feof(fp)){     //feof()文件状态是否文件结束
	printf("%c",ch);
	ch=fgetc(fp); //after calling function fgetch,position pointer will point next byte-
	}                 //-so it can read all chars
*/
	ch=getchar();
	while(ch!='#'){
	fputc(ch,fp);
	ch=getchar();
	}
	fclose(fp);   //将字符写入文件。
//	printf("\n");
}
