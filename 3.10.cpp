#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node *link;//指向链表的指针
//创建链表
struct node
{
	int item;
	link next;
};

int main()
{
	while(1)
	{
		link t = (link)malloc(sizeof * t);//先创建一个节点
		link x = t;
		t->item = 1;
		t->next = t;
		int m,n,i;
		scanf("%d%d", &m, &n);
		if(m <= -1)
			break;
		for(i = 2; i <= n; ++i)
		{
			x->next = (link)malloc(sizeof * x);
			x = x->next;
			x->item = i;
			x->next = t;
		}
		if(m != 0)
			x = x->next;
		while(x != x->next)//剩下的节点不止一个时
		{
			if(m != 0)
			{
				for(i = 1; i < m; ++i)//跳过m-1个节点
					x = x->next;
				//开始踢人
				x->next = x->next->next;
				x = x->next;
			}
			else
			{
				x->next = x->next->next;
			}
		}
		printf("%d\n", x->item);
	}
	return 0;
}