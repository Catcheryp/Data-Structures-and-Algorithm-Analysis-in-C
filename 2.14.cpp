//这个是算法大全里面的筛法
/*#include<iostream>
using namespace std;
const int MAXN = 100000;
int main(){
	int n,i,j;
	int prime[MAXN] = {0};
	cin >> n;
	for(i = 2;i <= n;i++){
		prime[i] = 1;
	}
	for(i = 0;i * i <= n;i++){
		if(prime[i] == 1){
			for(j = 2 * i;j <= n;j++){
				if(j % i == 0)
					prime[j] = 0;
			}
		}
	}
	for(i = 2;i < n;i++){
		if(prime[i] == 1)
			cout << i << " ";
	}
	return 0;
}*/
//这个是根据书里面的说法写的筛法，其实本质都一样
	#include<iostream>
	using namespace std;
	const int MAXN = 100000;
	int main(){
		int n,i,j;
		int prime[MAXN] = {0};
		cin >> n;
		for(i = 2;i <= n;i++)
			prime[i] = 1;
		for(i = 2;i * i <= n;i++){
			if(prime[i] == 1){
				int count = 1;
				for(j = i;j <= n;count++,j = count * i){
					prime[j] = 0;
				}
			}
		}
		for(i = 0;i < n;i++)
			if(prime[i] == 1)
			cout << i << " ";
		return 0;
	}
	//答案说时间复杂度为O(NloglogN)
