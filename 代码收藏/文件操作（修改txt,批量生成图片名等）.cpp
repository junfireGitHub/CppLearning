#include"iostream"
#include"fstream"
#include"cmath"
#include"string"
#include"cstdlib"
#include"cassert"

using namespace std;


void modifyTxtContent(){
/* 
	FUNCTION: �޸�txt�ı����ݣ����޸ĺ���������뵽һ�������ɵ��ı���
*/
	string fileInName = "biaotu.txt", fileOutName = "biaotu_out.txt";
	ifstream fin(fileInName); ofstream fout(fileOutName, ios_base::out);
	if (!fin || !fout)  exit(2);
	string str;
	while (getline(fin, str)){
		int si = str.find("IMG");
		if (str[0] == 'E') fout << str.substr(si) << endl;
		else fout << str << endl;
	}
	fin.close(); fout.close();
}

void generateBatchImageName(){
/*
	FUNCTION: ͨ���ض���ķ�ʽ��������ͼƬ������
*/
	freopen("val.txt", "w", stdout);

	for (int i = 0; i <= 613; i++)
		printf("I%05d\n", i);
	fclose(stdout);
}

void generateBatchImageName2(){
	/*
	FUNCTION: ͨ���ļ�������������ͼƬ������
	*/
	ofstream fout("pos.txt", ios_base::out);
	if (!fout)
		exit(1);

	for (int i = 1; i <= 2416; i++)
		fout << "pos" << i << ".png" << endl;
	fout.close();
}

int main()
{
	generateBatchImageName2();
	return 0;
}