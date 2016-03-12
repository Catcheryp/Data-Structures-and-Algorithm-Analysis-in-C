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
};
void Insert(int x,List L,Position p){
	Position tmpCell;
	tmpCell = (struct Node*)malloc(sizeof(struct Node));
	if(tmpCell == NULL)
		cout << "Out of space!!!";
	tmpCell->element = x;
	tmpCell->next = p->next;
	p->next = tmpCell;
}
int main(){
	List L;
	Position head;
	//List head;

	int i;
	Position tmp;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->next= NULL;
	tmp = head;//保存头结点的初始位置，所以需要个临时变量
	int n;
	cin >> n;
	for(i = 0;i < n;i++){
		Insert(i,L,head);
		if(head->next != NULL)//因为每次都从头结点后面插入，所以我就每次将头结点向后移一位
			head = head->next;
	}
	Position s;
	s = tmp->next;
	for(i = 0;i < n;i++){
		cout << s->element << endl;
		s = s->next;
	}
	return 0;
}