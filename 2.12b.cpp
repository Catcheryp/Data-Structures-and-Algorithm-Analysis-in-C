#include<iostream>
using namespace std;
const int MAXN = 100000;
int main(){
	int n,i,j;
	int num[MAXN];
	cin >> n;
	for(i = 0;i < n;i++){
		cin >> num[i];
	}
	int minSum = 100000,thisSum = 0;
	for(i = 0;i < n;i++){
		thisSum = 0;
		for(j = i;j < n;j++){
			thisSum += num[j];
			if(minSum > thisSum&&thisSum > 0){
				minSum = thisSum;
			}
		}
	}
	cout << minSum << endl;
	return 0;
}