#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<ctype.h>
#include<string>
using namespace std;

map<string, int>varMap;

unsigned char processPriority(char op1, char op2){

	//char OPSET[5] = { '+', '-', '*', '(', ')', };

	unsigned char prior[6][6] =
	{ // 运算符优先级表   
		//     '+'  '-'  '*'  '('  ')'   '#'
		/*'+'*/'>', '>', '<', '<', '>', '>',
		/*'-'*/'>', '>', '<', '<', '>', '>',
		/*'*'*/'>', '>', '>', '<', '>', '>',
		/*'('*/'<', '<', '<', '<', '=', ' ',
		/*')'*/'>', '>', '>', ' ', '>', '>',
		/*'#'*/'<', '<', '<', '<', ' ', '='
	};
	map<char, int> mp;
	mp['+'] = 0;
	mp['-'] = 1;
	mp['*'] = 2;
	mp['('] = 3;
	mp[')'] = 4;
	mp['#'] = 5;
	return prior[ mp[op1] ][ mp[op2] ];
}

bool isOp(unsigned char ch){
	return ch == '+' || ch == '-' || ch == '*' || ch == '(' || ch == ')';
}

int operate(char ch, int x, int y){

	if (ch == '-') return (x - y);
	if (ch == '+') return (x + y);
	if (ch == '*') return (x*y);
}


int computeExpVal(string str){

	stack<int> numStk;
	stack<char> opStk;
	bool negFlag = false;
	int si = 0;
	opStk.push('#');
	str += '#';

	while (str[si] != '#' || opStk.top() != '#'){
		if (isdigit(str[si])){
			char *pc = &str[si];
			int val = atoi(pc);
			if (negFlag) {
				val = -val;
				negFlag = false;
			}
			numStk.push(val);
			while (isdigit(str[si])){
				si++;
			}
			//continue;
		}
		else if (isalpha(str[si])){
			int st = si;
			while (isalpha(str[si])){
				si++;
			}
			string valName = str.substr(st, si - st);
			int val = varMap[valName];
			if (negFlag) {
				val = -val;
				negFlag = false;
			}
			numStk.push(val);
		}
		else{
			char op = str[si];
			//negFlag = false;
			if (op == '-'){
				if (si == 0 || str[si - 1] == '(') {
					negFlag = true;
					si++; continue;
				}
				/*else if (str[si - 1] == '('){
					negFlag = true;
					si++; continue;
				}*/
			}
			switch (processPriority(opStk.top(), op)){
			case'<':
				opStk.push(op); si++; break;
			case'=':
				opStk.pop(); si++; break;
			case'>':
				char op = opStk.top(); opStk.pop();
				int y = numStk.top(); numStk.pop();
				int x = numStk.top(); numStk.pop();
				numStk.push(operate(op, x, y));
				break;
			}
		}
	}
	return numStk.top();
}

int processExp(string str){

	int assignPos = str.find('=');
	string varName = str.substr(0, assignPos);
	string rightExp = str.substr(assignPos + 1);
	varMap[varName] = computeExpVal(rightExp);
	return varMap[varName];
}
//void processPrint(string _str){
//
//	string str = _str.substr(6);
//	int si = 0;
//	while (si < str.size()){
//		if (isdigit(str[si])){
//			char *pc = &str[si];
//			cout<< atoi(pc);
//			while (isdigit(str[si])){
//				si++;
//			}
//			if (str[si]==')')
//				cout << endl;
//			else
//				cout << " ";
//		}
//		else if (isalpha(str[si])){
//			char st = si;
//			while (isalpha(str[si])){
//				si++;
//			}
//			string valName = str.substr(st, si - st);
//			cout << varMap[valName];
//			if (str[si] == ')')
//				cout << endl;
//			else
//				cout << " ";
//		}
//		else{
//			si++;
//		}
//	}
//}

void processPrint(string _str){

	string str = _str.substr(6,_str.size()-7);
	int si = 0;
	while (si < str.size()){
		int pos = str.find(",", si);
		if (pos != std::string::npos){
			string s = str.substr(si, pos - si);
			if (s.find("=") == std::string::npos){
				cout << computeExpVal(s);
			}
			else{
				cout << processExp(s);
			}
			cout << " ";
			si = pos + 1;
		}
		else{
			string s = str.substr(si);
			//s = s.substr(0, s.size() - 1);
			if (s.find("=") == std::string::npos){
				cout << computeExpVal(s);
			}
			else{
				cout << processExp(s);
			}
			cout << endl;
			break;
		}
	}

}

int main(){

	freopen("input.txt", "r", stdin);
	string str = "a=-1+(-1)";

	while (cin >> str){

		if (str.size() >= 5 && str.substr(0, 5) == "print"){
			processPrint(str);
		}
		else{
			processExp(str);
		}
		//cout << varMap["a"] << endl;
	}
	fclose(stdin);
	return 0;
}

/*测试数据
afdafdfdsfsdafdsfdsfdsfdsfdsfads=1+2+3+4*0+3+2+1+456
print(afdafdfdsfsdafdsfdsfdsfdsfdsfads,afdafdfdsfsdafdsfdsfdsfdsfdsfads+23)
a=5+7+9
b=3+(5-7)*2
print(a,b)
a=a+a+a
print(a)
a=-1+(-1)
b=-1
print(a,b)
print(a-b,a+b)
print(a=a*b,a*b)
c=344*0+34*((3*2+3))
print(c,c+1)
print(a)
c=(-c)*(-1)-1*a-2*(-2-2)
print(c)
c=-c-(-(-5))
print(c)
print(a,b)
a=a*b*b*c+1*2*(12*1)
print(a,a=1,a)
print(a=b=1)
print(b)
a=b=10
print(a,b)*/