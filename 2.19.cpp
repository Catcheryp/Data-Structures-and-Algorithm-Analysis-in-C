#include<iostream>
using namespace std;
const int MAXN = 100000;
int record[MAXN];
int l = 0;
int selCandidate(int n[],int size){
	if(size == 1)
		return n[0];
	else if(size == 2)
		return -1;
	else{
		if(size % 2 == 1){
			record[l++] = n[size - 1];
			size--;
		}
		for(int i = 0,j = 0;i < size;i += 2){//这里复制的时候的时间复杂度好像没怎么改进
			if(n[i] == n[i + 1])			//我似乎没有按照题意来做
				n[j++] = n[i];
		}
		selCandidate(n,j);
	}
}
int main(){
	int m,i,j;
	int num[MAXN];
	int fb[MAXN];
	int candidate;
	int c;
	int flag = 0;
	cin >> m;
	for(i = 0;i < m;i++){
		cin >> num[i];
		fb[i] = num[i];
	}

	candidate = selCandidate(num,m);
	int count = 0;
	if(candidate == -1){
		for(i = 0;i < l;i++){
			for(j = 0;j < m;j++){
				if(record[i] == fb[j]){
					count++;
				}
			}
			if(count > m / 2){
				cout << record[i] << endl;
				flag = 1;
				break;
			}
		}
	}else{
		flag = 1;
		cout << candidate << endl;
	}
	if(flag == 0) 
		cout << "we don't have this number!!!" << endl;
	return 0;
}
//在这里我狠狠地想了一下，为什么只有初始数组的最后一个元素可能为候选元
//假设有103个元素，我们去掉最后一个，还有102，此时除以2，为51，可能为51么？
//如果为51，则最后一个就是候选元,如果不是51
//上面的分析是没有根据的扯淡，比如2 2 1 1 1 1 1 1 2 2 2 2 1 1 5，主元素为1，
//就是在递归期间被舍去的元素

//有没有觉得你的程序写的跟狗屎一样，结果还是如果每次为奇数时都要记录一下最后那个被舍掉的元素，
//,只要是奇数那么最后的那个元素都是候选的元素，然后最后验证是不是主元素