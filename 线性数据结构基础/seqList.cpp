#include"seqList.h"
using namespace std;
/*构造函数*/
SqList::SqList()
{
	elem=new ElemType(initsize);
	length=0;
	listsize=initsize;
}
/*判断是否满*/
bool SqList::isFull()const
{
	return length==listsize;
}
/*是否为空*/
bool SqList::isEmpty()const
{
	return length==0;
}
ElemType SqList::getElem(int i)const
{
	if(i>length||i<1)
	{
		cout<<"i-value is illegal!";
		return 0;
	}
	else
	{
		return elem[i-1];
	}
}
bool SqList::insert(int i,ElemType e)
{
	if(i>length+1||i<1)
	{
		cout<<"i-value is illeagal!";
		return false;
	}
	if(isFull())//表满重新分配内存
	{
		ElemType *newBase=new ElemType[listsize+increment];
		for(int j=0;j<listsize;i++)
		{
			newBase[j]=elem[j];
			delete[]elem;//释放动态类对象数组
			elem=newBase;
			listsize+=increment;
		}
		ElemType *p=&(elem[i-1]);
		ElemType *q=&(elem[length-1]);
		for(;q>=p;--q)
			*(q+1)=*(q);
		*p=e;
		++length;
		return true;
	}
}
bool SqList::insert(ElemType e)
{
	if(isFull())//表满重新分配内存
	{
		ElemType *newBase=new ElemType[listsize+increment];
		for(int i=0;i<listsize;i++)
			newBase[i]=elem[i];
		delete []elem;
		elem=newBase;
		listsize+=increment;
	}
	ElemType *p=&(elem[length]);
	*p=e;
	++length;
	return true;
}
void SqList::creat()
{
	cout<<"为表添加元素(输入0退出!)"<<endl;
	while(true)
	{
		int elem;
		cin>>elem;
		if(elem!=0)
		{
			insert(elem);
		}
		else
		{
			cout<<"表创建完成，大小为："<<listsize<<","<<endl;
			cout<<"表现有"<<length<<"个元素："<<endl;
			for(int i=1;i<=length;i++)
				cout<<getElem(i)<<",";
			cout<<endl;
			break;
		}
	}
}
void SqList::merge(SqList &La,SqList &Lb)
{
	int i=1,j=1,k=0;
	while(i<=La.length&&j<=Lb.length)
	{
		if(La.getElem(i)<=Lb.getElem(j))
		{
			insert(++k,La.getElem(i));
			++i;
		}
		else
		{
			insert(++k,Lb.getElem(j));
			++j;
		}
	}
	while(i<La.length)
	{
		insert(++k,La.getElem(i));
		++i;
	}
	while(j<Lb.length)
	{
		insert(++k,Lb.getElem(j));
		++j;
	}
	cout<<"合并后元素为："<<endl;
	for(int m=1;m<length;m++)
	{
		cout<<getElem(m)<<endl;
	}
}
//删除第i个元素
bool SqList::del(int i)
{
	if(i>length||i<1)
	{
		cout<<"i-value is illegal!";
		return false;
	}
	ElemType *p=&(elem[i-1]);
	ElemType *q=&(elem[length-1]);
	for(++p;p<=q;++p)
		*(p-1)=*p;		
	--length;		
	return true;

}
void SqList::displayElem()
{
	cout<<"表的大小为："<<listsize<<"."<<endl;
	cout<<"表现有"<<length<<"个元素"<<endl;
	for(int i=1;i<=length;i++)
	{
		cout<<getElem(i)<<",";
	}
	cout<<endl;
}
SqList::~SqList()
{
	delete[]elem;
}
