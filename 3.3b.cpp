//在线编译一直RE，自己的计算机编译运行没啥问题，唯一有问题的是
//那个不能输入n，必须要弄成常数才可以，还有最后的那个地方不知道为什么改一下就对了？？？
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
	int element;
	Position next;
	Position prev;
};
void Insert(int x,List L,Position p){
	/*Position tmpCell;
	tmpCell = (struct Node*)malloc(sizeof(struct Node));
	if(tmpCell == NULL)
		cout << "Out of space!!!";
	tmpCell->element = x;
	tmpCell->next = p->next;
	p->next = tmpCell;*/
	Position tmpCell;
	if(p->next == NULL){
		tmpCell->element = x;
		tmpCell->next = p->next;
		p->next = tmpCell;
		tmpCell->prev = p;
	}
	else{
	tmpCell = (struct Node*)malloc(sizeof(struct Node));
	tmpCell->element = x;
	tmpCell->next = p->next;
	p->next->prev = tmpCell; 
	p->next = tmpCell;
	tmpCell->prev = p;
}
}
void exchange(Position M,List L){
	Position beforeM,afterM;
	beforeM = M->prev;
	afterM = M->next;
	M->next = afterM->next;
	beforeM->next = afterM;
	afterM->next = M;

	M->next->prev = M;
	M->prev = afterM;
	afterM->prev = beforeM;
}
int main(){
	List L;
	Position head;
	//List head;

	int i;
	Position tmp;
	head = (struct Node*)malloc(sizeof(struct Node));
	//tmp = (struct Node*)malloc(sizeof(struct Node));
	head->next= NULL;
	head->prev = NULL;
	tmp = head;//保存头结点的初始位置，所以需要个临时变量
	int n;
	//cin >> n;
	for(i = 0;i < 20;i++){
		Insert(i + 2 + 1,L,tmp);
		if(tmp->next != NULL)
			tmp = tmp->next;
	}
	Position s;
	s = tmp->next;
	for(i = 0;i < 20;i++){
		cout << s->element <<" ";
		s = s->next;
	}
	cout << endl;

	Position m;
	m = head;
	for(i = 0;i < 4;i++)
		m = m->next;

	exchange(m,L);

	Position l;
	l = head;//为什么这里改一下就对了呢？
	for(i = 0;i < 20;i++){
		cout << l->element << " ";
		l = l->next;
	}
	return 0;
}