#include<iostream>
using namespace std;
const int MAXN = 10000;
int main(){
	int x,n,i,j;
	cin >> x >> n;
	int num[MAXN] = {0};
	int binary[MAXN] = {0};
	int count = 0;
	for(i = 1,j = 1;i <= n;i = 2 * i,j++){
		num[j] = x;
		x = x * x;
		count++;
	}
	for(i = 1;n != 0;i++){
		binary[i] = n % 2;
		n = n / 2;
	}
	int mul = 1;

	for(i = 1;i < count + 2;i++){
		if(binary[i] == 1){
			mul *= num[i];
		}
	}
	cout << mul << endl;
	return 0;
}

/* eg:3 ^ 999
= 3 ^ (512 + 256 + 128 + 64 + 32 + 4 + 2 + 1)
= (3 ^ 512) * (3 ^ 256) * (3 ^ 128) * (3 ^ 64) * (3 ^ 32) * (3 ^ 4) * (3 ^ 2) * 3

这样只要做16次乘法。即使加上一些辅助的存储和运算，也比直接乘高效得多（尤其如果这里底数是成百上千位的大数字的话）。

我们发现，把999转为2进制数：1   1   1   1  1  0  0  1  1  1，其各位就是要乘的数，这个算法好像很屌的样子
---------------------------512-256-128-64-32--0--0--4--2--1
*/