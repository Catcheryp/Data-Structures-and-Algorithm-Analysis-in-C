#include<iostream>
using namespace std;
const int max = 100000;
int main(){
	int n,i;
	int num[max];
	cin >> n;
	for(i = 0;i < n;i++){
		cin >> num[i];
	}
	int low = 0;
	int high = n - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(num[mid] < mid)
			  low = mid + 1;//这里值得想一下，在这里中间的数小于其所对应的下标时，应该查找右边，因为左边最多
		else if(num[mid] > mid) //每次递增1，不可能找出对应的数，所以只有向右查找，好好想想，反正我现在是想通的
			  high = mid - 1;
		else{
			cout << mid << endl;//在这里判断是否存在，因为基于二分查找，所以找到的第一个元素不是下标最小的
			break;              //如果这里改为找出所有的则要好好想想了
		}
	}
	return 0;
}