#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int flag = 1;
	if(n == 1)
		flag = 0;
	if(n == 2)
		flag = 1;
	for(int i = 3,j = 2;i * i <= n;i = 2 * j + 1,j++){
		if(n % 2 == 0||n % i == 0){
			flag = 0;
			break;
		}
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
//2.13b:本程序的时间复杂度就为O(N^0.5)