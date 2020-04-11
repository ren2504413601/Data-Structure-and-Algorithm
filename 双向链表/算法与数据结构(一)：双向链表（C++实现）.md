# 算法与数据结构(一)：双向链表（C++实现）

链表是一组数据元素的集合，其中每个数据元素都是一个节点，节点的数据部分称作数据域。为了能够对整个链表进行访问和操作，链表的每个节点至少还应该包含一个指向后继元素在物理内存中的位置信息（称作指针域）。当然，一个节点同样还可以包含指向前继元素在内存中的位置信息。一个链表的最后一个节点的指针域可以为空，表示整个链表结束。也可以指向链表的第一个节点，这是整个链表形成一个回路，我们称其为循环链表

对于顺序表可以执行很多操作。下面主要介绍用于数组描述的顺序表所进行的空间分配、元素插入、元素删除等操作。

#### 主函数

```c++
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
```

程序定义了节点Node。包含两个指针分别指向前继和后继节点。还包含几个常用的操作函数：创建节点、插入节点函数、删除节点、可视化节点。程序运行结果如下图所示：

![双向链表](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\双向链表\双向链表1.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著