#include<iostream>
using namespace std;
int N = 10;
class Node
{
public:
	char name[20];
	Node *llink, *rlink;//llink��rlink�ֱ�ָ��ǰ���ͺ���
};
/*����˫��ѭ������*/
Node *Create(int n)
{
	Node *h, *p, *s;//h:ͷ��㣬p:��һ�ڵ㣬s:��ǰ�ڵ�
	int i;
	if ((h = new Node) == NULL)
	{
		cout << "�ڴ����ʧ��!" << endl;
	}
	h->name[0] = 0;
	h->llink = NULL;
	h->rlink = NULL;
	p = h;
	for (i = 0; i != n; ++i)
	{
		if ((s = new Node) == NULL)
		{
			cout << "�ڴ����ʧ��!" << endl;
		}
		p->rlink = s;
		cout << "�����"<<i+1<<"���˵�����:" ;
		cin >> s->name;
		s->llink = p;
		s->rlink = NULL;
		p = s;
	}
	p->rlink = h;
	h->llink = p;
	return h;
}
/*��hΪ��ͷ�������в���ֵΪname�Ľڵ�*/
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
/*�ڽڵ�p�������ڵ�s*/
void Insert(Node *p)
{
	Node *s = new Node;
	cout << "����Ҫ���������:";
	cin >> s->name;
	Node *r = p->rlink;//�ڵ�ʾ��p->s->r(s��Ҫ����Ľڵ�)
	r->llink = s;
	s->rlink = r;
	s->llink = p;
	p->rlink = s;
	++N;
}
/*ɾ���ڵ�p*/
void Delete(Node *p)
{
	Node *l = p->llink;//�ڵ�ʾ��l->p->r(p��Ҫɾ���Ľڵ�)
	Node *r = p->rlink;
	l->rlink = r;
	r->llink = l;
	delete p;
	--N;
}
/*���ӻ���hΪ��������*/
void Display(Node *h)
{
	Node *p=h->rlink;
	for (int i = 0; i != N; ++i)
	{
		cout << "��" << i + 1 << "���˵�����:" << p->name << endl;
		p=p->rlink;
	}
}
int main()
{
	Node *head, *pSearch;
	int number = N;
	char strName[20];
	head = Create(number);
	cout << endl << "�����ı�ṹ����:" << endl;
	Display(head);
	cout << endl;
	//���Ҳ�����...
	cout << "������Ҫ���ҵ��˵�����:";
	cin >> strName;
	pSearch=Search(head, strName);
	cout << "����Ҫ���ҵ��˵�����Ϊ:" << pSearch->name << endl;
	cout << endl;
	Insert(pSearch);
	cout << "�����Ľ������:" << endl;
	Display(head);
	cout << endl;
	//���Ҳ�ɾ��...
	cout << "������Ҫɾ�����˵�����:";
	cin >> strName;
	pSearch = Search(head, strName);
	Delete(pSearch);
	cout << "ɾ����Ľ������:"<< endl;
	Display(head);
	cout << endl;
	return 0;
}