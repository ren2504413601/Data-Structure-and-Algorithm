//完整二叉树例子
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class BTNode//节点类
{
public:
	T data;
	BTNode<T> *lchild, *rchild;
	BTNode();
	BTNode(const T &val, BTNode<T> *childl = NULL, BTNode<T> *childr = NULL)
	{
		data = val;
		lchild = childl;
		rchild = childr;
	}
	BTNode<T>*copyTree()
	{
		BTNode<T> *nl, *nr, *nn;
		if (&data = NULL)
			return NULL;
		nl = lchild->copyTree();//递归
		nr = rchild->copyTree();
		nn = new BTNode<T>(data, nl, nr);
		return nn;
	}
};
template <class T>
BTNode<T>::BTNode()//定义构造函数
{
	lchild = rchild = NULL;
}
template <class T>
class BinaryTree//二叉树类
{
public:
	BTNode<T> *root;
	BinaryTree();
	~BinaryTree();
	void Pre_Order();
	void In_Order();
	void Post_Order();
	int TreeHeight()const;
	int TreeNodeCount()const;
	void DestroyTree();
	BTNode<T>* MakeTree(const T &element, BTNode<T> *l, BTNode<T> *r)
	{
		root = new BTNode<T>(element, l, r);
		if (root == NULL)
		{
			cout << "申请内存失败!";
			exit(1);
		}
		return root;
	}
private:
	void Destroy(BTNode<T> *&r);
	void PreOrder(BTNode<T> *r);
	void InOrder(BTNode<T> *r);
	void PostOrder(BTNode<T> *r);
	int Height(const BTNode<T> *r)const;
	int NodeCount(const BTNode<T> *r)const;
};
template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
	DestroyTree();
}
template <class T>
void BinaryTree<T>::Pre_Order()
{
	PreOrder(root);
}
template <class T>
void BinaryTree<T>::In_Order()
{
	InOrder(root);
}
template <class T>
void BinaryTree<T>::Post_Order()
{
	PostOrder(root);
}
template <class T>
int BinaryTree<T>::TreeHeight()const
{
	return Height(root);
}
template <class T>
int BinaryTree<T>::TreeNodeCount()const
{
	return NodeCount(root);
}
template <class T>
void BinaryTree<T>::DestroyTree()
{
	Destroy(root);
}

template <class T>
void BinaryTree<T>::PreOrder(BTNode<T> *r)
{
	if (r != NULL)
	{
		cout << r->data << ' ';
		PreOrder(r->lchild);
		PreOrder(r->rchild);
	}
}
template <class T>
void BinaryTree<T>::InOrder(BTNode<T> *r)
{
	if (r != NULL)
	{
		cout << r->data << ' ';
		InOrder(r->lchild);
		InOrder(r->rchild);
	}
}
template <class T>
void BinaryTree<T>::PostOrder(BTNode<T> *r)
{
	if (r != NULL)
	{
		cout << r->data << ' ';
		PostOrder(r->lchild);
		PostOrder(r->rchild);
	}
}
template <class T>
int BinaryTree<T>::NodeCount(const BTNode<T> *r)const
{
	if (r == NULL)
		return 0;
	else
		return 1 + NodeCount(r->lchild) + NodeCount(r->rchild);
}
template <class T>
int BinaryTree<T>::Height(const BTNode<T> *r)const
{
	if (r == NULL)
		return 0;
	else
		return 1 + (Height(r->lchild) > Height(r->rchild) ? Height(r->lchild) : Height(r->rchild));
}
template <class T>
void BinaryTree<T>::Destroy(BTNode<T> *&r)
{
	if (r != NULL)
	{
		Destroy(r->lchild);
		Destroy(r->rchild);
		delete r;
		r = NULL;
	}
}
/*将二叉树bt的左右子树互换*/
template <class T>
void Change(BTNode<T> *r)
{
	BTNode<T> *p;
	if (r)
	{
		p = r->lchild;
		r->lchild = r->rchild;
		r->rchild = p;//左右子树互换
		Change(r->lchild);//递归
		Change(r->rchild);
	}
}

void main()
{
	BTNode<char> *b, *c, *d, *e, *f, *g;
	BinaryTree<char> a;
	b = a.MakeTree('B', NULL, NULL);
	c = a.MakeTree('C', NULL, NULL);
	d = a.MakeTree('D', NULL, NULL);
	e = a.MakeTree('E', b, NULL);
	f = a.MakeTree('F', d, c);
	g = a.MakeTree('G', f, e);
	cout << "先序遍历:";
	a.Pre_Order();
	cout << endl;
	cout << "中序遍历:";
	a.In_Order();
	cout << endl;
	cout << "后序遍历:";
	a.Post_Order();
	cout << endl;
	cout << "树的高度是:";
	a.TreeHeight();
	cout << endl;
	cout << "树的节点个数:";
	a.TreeNodeCount();
	cout << endl<<endl;

	cout << "交换左右子树后重新操作结果是:"<<endl;

	cout << "先序遍历:";
	a.Pre_Order();
	cout << endl;
	cout << "中序遍历:";
	a.In_Order();
	cout << endl;
	cout << "后序遍历:";
	a.Post_Order();
	cout << endl;
	cout << "树的高度是:";
	a.TreeHeight();
	cout << endl;
	cout << "树的节点个数:";
	a.TreeNodeCount();
	cout << endl << endl;
}