#include<iostream>
using namespace std;
int N = 10;
class Node
{
public:
	char name[20];
	Node *llink, *rlink;//llink和rlink分别指向前驱和后驱
};
/*创建双向循环链表*/
Node *Create(int n)
{
	Node *h, *p, *s;//h:头结点，p:下一节点，s:当前节点
	int i;
	if ((h = new Node) == NULL)
	{
		cout << "内存分配失败!" << endl;
	}
	h->name[0] = 0;
	h->llink = NULL;
	h->rlink = NULL;
	p = h;
	for (i = 0; i != n; ++i)
	{
		if ((s = new Node) == NULL)
		{
			cout << "内存分配失败!" << endl;
		}
		p->rlink = s;
		cout << "输入第"<<i+1<<"个人的名字:" ;
		cin >> s->name;
		s->llink = p;
		s->rlink = NULL;
		p = s;
	}
	p->rlink = h;
	h->llink = p;
	return h;
}
/*在h为开头的链表中查找值为name的节点*/
Node *Search(Node *h, const char *name)
{
	Node *p = h->rlink;
	for (int i = 0; i != N; ++i)
	{
		if (strcmp(p->name, name) == 0)
			return p;
		p = p->rlink;
	}
	return p;
}
/*在节点p后面插入节点s*/
void Insert(Node *p)
{
	Node *s = new Node;
	cout << "输入要插入的姓名:";
	cin >> s->name;
	Node *r = p->rlink;//节点示意p->s->r(s是要插入的节点)
	r->llink = s;
	s->rlink = r;
	s->llink = p;
	p->rlink = s;
	++N;
}
/*删除节点p*/
void Delete(Node *p)
{
	Node *l = p->llink;//节点示意l->p->r(p是要删除的节点)
	Node *r = p->rlink;
	l->rlink = r;
	r->llink = l;
	delete p;
	--N;
}
/*可视化以h为起点的链表*/
void Display(Node *h)
{
	Node *p=h->rlink;
	for (int i = 0; i != N; ++i)
	{
		cout << "第" << i + 1 << "个人的姓名:" << p->name << endl;
		p=p->rlink;
	}
}
int main()
{
	Node *head, *pSearch;
	int number = N;
	char strName[20];
	head = Create(number);
	cout << endl << "创建的表结构如下:" << endl;
	Display(head);
	cout << endl;
	//查找并插入...
	cout << "请输入要查找的人的姓名:";
	cin >> strName;
	pSearch=Search(head, strName);
	cout << "你所要查找的人的姓名为:" << pSearch->name << endl;
	cout << endl;
	Insert(pSearch);
	cout << "插入后的结果如下:" << endl;
	Display(head);
	cout << endl;
	//查找并删除...
	cout << "请输入要删除的人的姓名:";
	cin >> strName;
	pSearch = Search(head, strName);
	Delete(pSearch);
	cout << "删除后的结果如下:"<< endl;
	Display(head);
	cout << endl;
	return 0;
}