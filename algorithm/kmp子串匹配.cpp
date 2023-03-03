#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void gennext(string str, int next[]){

	next[0] = -1;
	int pos = 0;
	for (int i = str.size() - 1; i >= 1; i--){

		int max_size = i / 2;
		for (int j = 1; j <= max_size; j++){
			string ls = str.substr(0, j);
			string rs = str.substr(i - j, j);
			if (str.substr(0, j) == str.substr(i - j, j))
				next[i] = j;
		}
	}
}

int main(){

	int next[8] = { 0 };
	gennext("abaabcac", next);
	for (int i = 0; i < 8; ++i)
		cout << next[i] << " ";
	return 0;
}