#include<iostream>
using namespace std;
const int MAXN = 100000;
int main(){
	int n,i,j;
	int num[MAXN];
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> num[i];
	int mul = -100000,thismul = 1;
	for(i = 0;i < n;i++){
		thismul = 1;
		for(j = i;j < n;j++){
			thismul *= num[j];
			if(thismul > mul)
				mul = thismul;
		}
	}
	cout << mul << endl;
	return 0;
}