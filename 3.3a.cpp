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
void exchange(Position beforeM,List L){//Fuck，抄特么都能抄错，我真的很欠扁
	Position M,afterM;
	M = beforeM->next;
	afterM = M->next;
	M->next = afterM->next;
	beforeM->next = afterM;
	afterM->next = M;
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
		Insert(i,L,tmp);
		if(tmp->next != NULL)//因为每次都从头结点后面插入，所以我就从头结点开始每次向后移一位
			tmp = tmp->next;
	}
	/*Position s;
	s = tmp->next;
	for(i = 0;i < n;i++){
		cout << s->element <<" ";
		s = s->next;
	}
	cout << endl;*/

	Position m;
	m = head;
	for(i = 0;i < 4;i++)
		m = m->next;

	exchange(m,L);

	Position l;
	l = head->next;
	for(i = 0;i < n;i++){
		cout << l->element << " ";
		l = l->next;
	}
	return 0;
}