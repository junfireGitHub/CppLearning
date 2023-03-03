/*??????
?????????????????????????????????"?"????
"?"???????????????????????????????????????*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

const int SIZE = 100005;
struct Point
{
	char index = 'N';
	double x;
	double y;
}coord[SIZE], cp[SIZE];
inline double GetDist(Point pa, Point pb)
{
	return sqrt(pow(pa.x - pb.x, 2.0) + pow(pa.y - pb.y, 2.0));
}

inline double Min(double x, double y){
	return x < y ? x : y;
}

bool cmpx(Point bi1, Point bi2){
	if (bi1.x == bi1.x)
		return bi1.y < bi2.y;
	else
		return bi1.x < bi2.x;
}

bool cmpy(Point bi1, Point bi2){
	if (bi1.y == bi2.y)
		return bi1.x < bi2.x;
	else
		return bi1.y < bi2.y;
}
double DivideConquer(int low, int high)
//·ÖÖÎ·¨
{
if (high - low == 1)
return GetDist(coord[low], coord[high]);
else if (high - low == 2){
	double x = GetDist(coord[low], coord[low + 1]);
	double y = GetDist(coord[low], coord[low + 2]);
	double z = GetDist(coord[low + 1], coord[low + 2]);
	return Min(x, Min(y, z));
}
else{
	int mid = (low + high) / 2;
	double lval = DivideConquer(low, mid);
	double rval = DivideConquer(mid + 1, high);
	double dist = Min(lval, rval);
	int count = 0;
	for (int i = low; i <= mid; i++){
		if (coord[i].x > coord[mid].x - dist){
			cp[count].index = 'L';
			cp[count].x = coord[i].x;
			cp[count].y = coord[i].y;
			count++;
		}
	}
	for (int i = mid + 1; i <= high; i++){
		if (coord[i].x < coord[mid].x + dist){
			cp[count].index = 'R';
			cp[count].x = coord[i].x;
			cp[count].y = coord[i].y;
			count++;
		}
	}
	count;
	sort(cp, cp + count, cmpy);
	for (int i = 0; i < count; i++){
		for (int j = 1; j <= 7 && i + j < count; j++){
			if (cp[i].index != cp[i + j].index){
				double val = GetDist(cp[i], cp[i + j]);
				dist = val < dist ? val : dist;
			}
		}
	}

	return dist;
}
}
int main(){
	int n;
	double radius;
	while (cin >> n&&n != 0){
		for (int i = 0; i < n; i++)
			cin >> coord[i].x >> coord[i].y;
		sort(coord, coord + n, cmpx);
		radius = DivideConquer(0, n - 1) / 2;
		//printf("%.2lfn", radius);
		cout << setiosflags(ios::fixed) << setprecision(2) << radius << endl;
	}
	return 0;
}