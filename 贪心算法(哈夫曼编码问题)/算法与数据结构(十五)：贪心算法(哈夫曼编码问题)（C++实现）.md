# 算法与数据结构(十五)：贪心算法(哈夫曼编码问题)（C++实现）

[**哈夫曼**](https://baike.baidu.com/item/哈夫曼)编码(Huffman Coding)，又称霍夫曼编码，是一种编码方式，哈夫曼编码是可变[字长](https://baike.baidu.com/item/字长/97660)编码(VLC)的一种。Huffman于1952年提出一种编码方法，该方法完全依据[字符](https://baike.baidu.com/item/字符/4768913)出现概率来构造异字头的平均长度最短的码字，有时称之为最佳编码，一般就叫做Huffman编码（有时也称为霍夫曼编码）

#### 哈夫曼编码基本思想

1.每个字符用一个0，1串作为其代码，并要求任意一个字符的代码都不是其他字符代码的前缀。

2.用字符在文件中出现的频率表来建立一个用0，1串表示个字符的最佳表示方式，即使出现频率高的字符获得较短的编码，出现频率较低的字符获得较长的编码。

3.将字符在文件中出现的频度值作为一颗二叉树的叶子节点的权值，并通过构造一颗哈夫曼树得到最优前缀码。

#### 哈夫曼树的构建

步骤如下：

1.用给定的n个权值{w1,w2,...,wn}对应的n个节点构成n棵二叉树的森林F={T1,T2,...,Tn}，其中每一棵树Ti（1<=i<=n）都只有一个权值为wi的根节点，其左右子树为空。

2.在森林F中选择两个根节点数最小的二叉树，作为一颗新二叉树的左右子树，标记新二叉树的根节点权值为其左右子树的根节点的权值之和。

3.从F中删除被选中的那两棵二叉树，同时把新构成的二叉树加入到森林F中。

4.重复2、3操作，直到森林中只含一颗二叉树为止，此时得到的这颗二叉树就是哈夫曼树。

#### 主函数

```c++
/*哈夫曼编码问题
* HuffMan.cpp
*/
#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	int weight;
	int flag;
	int parent;
	int lchild;
	int rchild;
}hnodetype;//哈夫曼树结构
typedef struct
{
	int bit[10];
	int start;
	char leaf;
}hcodetype;//编码记录
void huf(char cha[], int m[], int n)
//cha:当前输入字符，m:每种字符出现的次数,n:字符总个数
{
	int c,i,j,m1,m2,x1,x2,p;
	hnodetype *huffnode = new hnodetype[2 * n - 1];
	hcodetype *huffcode = new hcodetype[n],cd;
	//初始化哈夫曼书
	for (i = 0; i < 2 * n - 1; i++)
	{
		huffnode[i].flag = 0;
		huffnode[i].lchild = -1;
		huffnode[i].rchild = -1;
		huffnode[i].parent= 0;
		huffnode[i].weight = 0;
	}
	for (i = 0; i < n; i++)
	{
		huffnode[i].weight=m[i];
		huffcode[i].leaf = cha[i];
	}
	for (i = 0; i < n - 1; i++)//遍历寻找左右子树,用x1,x2记录
	{
		m1 = m2 = INT_MAX;
		x1 = x2 = 0;
		for (j = 0; j < n+i; j++)
		{
			if (huffnode[j].weight <= m1 && huffnode[j].flag == 0)
			{
				x2 = x1;
				x1 = j;
				m2 = m1;
				m1 = huffnode[j].weight;
			}
			else if (huffnode[j].weight <= m2 && huffnode[j].flag == 0)
			{
				x2 = j;
				m2 = huffnode[j].weight;
			}
		}
		huffnode[x1].parent = n + i;
		huffnode[x2].parent = n + i;
		huffnode[x1].flag = 1;
		huffnode[x2].flag = 1;
		huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
		huffnode[n + i].lchild = x1;
		huffnode[n + i].rchild = x2;
	}
	//生成哈夫曼树的编码
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p=huffnode[c].parent;
		while (p != 0)
		{
			if (huffnode[p].lchild == c) cd.bit[cd.start] = 0;
			else cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = huffnode[c].parent;
		}
		cout << huffcode[i].leaf << ":";
		for (j = cd.start + 1; j < n; j++)
		{
			huffcode[i].bit[j] = cd.bit[j];
			cout << cd.bit[j];
		}
		cout << endl;
		huffcode[i].start = cd.start;
	}
	delete[] huffcode;
	delete[] huffnode;
}
void main()
{
	string str;
	int i = 0, j, n, m[100], h, k = 0;
	char cha[100];
	cout << "输入一个字符串!" << endl;
	cin >> str;
	n=str.length();
	cout << "字符串共有" << n << "个字符" << endl;
	//对输入的字符扫描，统计出每个字符出现的次数
	for (i = 0; i < n; i++)
	{
		j = 0;
		h = 0;
		while (str[j] != str[i]) j++;
		if (i == j)
		{
			cout << "字符" << str[i] << "出现";
			cha[k] = str[i];
		}
		else continue;
		for (j = i; j < n; j++)
		{
			if (str[i] == str[j])
				h++;
		}
		cout << h << "次"<<endl;
		m[k] = h;
		k++;
	}
	cout << "每个字符的哈夫曼编码是:" << endl;
	huf(cha, m, k);
}
```

首先对输入的字符串扫描统计出现的字符以及每个字符出现的频率。程序运行结果如下图所示：

![二叉树](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\贪心算法(哈夫曼编码问题)\贪心算法(哈夫曼编码问题).JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著