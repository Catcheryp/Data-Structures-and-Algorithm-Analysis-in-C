//第一种算法
/*#include<iostream>
using namespace std;
const int max = 100000;
int main(){
	int num[max];
	int i,j,n;
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> num[i];
	int minSum = 1000000;
	for(i = 0;i < n;i++){
		int thisSum = 0;
		for(j = i;j < n;j++){
			thisSum += num[j];
			if(minSum > thisSum)
				minSum = thisSum;
		}
	}
	cout << minSum << endl;
	return 0;
}*/
//第二种解法，其实我就是想试一下我的想法对不对
#include<iostream>
using namespace std;
const int max = 100000;
int main(){
	int num[max];
	int i,j,n;
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> num[i];
	int thisSum = 0,minSum = 1000000,min = 1000000;
	for(j = 0;j < n;j++){//这里我们得分情况讨论，当数组中有负数时为这样，			
		thisSum += num[j];//当数组没有负数时则返回最小值即可(也可以这样想：
		if(thisSum < minSum)//不考虑数组元素的情况，最后将得到的那个值与数组的最小元素比较大小，
			minSum = thisSum;//返回较小的即可,在这里还是要小心为0这种情况；如果数组中最小的元素大于0，
		else if(thisSum > 0)//则直接返回最小的元素，因为此时thisSum为0，所以不能比较)<-我想太多了，直接用就好了
			thisSum = 0;
	}
	/*for(j = 0;j < n;j++){
		if(min > num[j])
			min = num[j];
	}
	if(min >= 0)
		cout << min;
	else{
		cout << minSum;
	}*/
		cout << minSum;
	return 0;
}