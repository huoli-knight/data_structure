#pragma once
#include<iostream>
using namespace std;
typedef struct BiTNode
{
	int data;
	int count;//同分数量
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
bool Delete(BiTree &T, int key)
{
	BiTree sign=NULL,sign2=NULL;
	for (;T!=NULL;)
	{
		if (T->data==key)
		{
			if 	(--T->count)
			{
				if (T->lchild!=NULL&&T->rchild!=NULL&&sign!=NULL&&sign->lchild==T)
				{
					sign->lchild=T->lchild;
					sign=T->lchild;
					sign2=sign->rchild;
					sign->rchild=T->rchild;
					T=T->rchild;
					for (;T->lchild!=NULL;T=T->lchild);
					T->lchild=sign2;
					return 1;
				}
				else if (T->lchild!=NULL&&T->rchild!=NULL&&sign!=NULL&&sign->rchild==T)
				{
					sign->rchild=T->rchild;
					sign=T->rchild;
					sign2=sign->lchild;
					sign->lchild=T->lchild;
					T=T->lchild;
					for (;T->rchild!=NULL;T=T->rchild);
					T->rchild=sign2;
					return 1;
				}
				else if (sign==NULL)
				{
					sign=T->lchild;
					sign2=sign->rchild;
					sign->rchild=T->rchild;
					T=T->rchild;
					for (;T->lchild!=NULL;T=T->lchild);
					T->lchild=sign2;
					return 1;
				}
				else if (T->lchild==NULL&&T->rchild!=NULL&&sign->lchild==T)
				{
					sign->lchild=T->rchild;
					return 1;
				}
				else if (T->lchild==NULL&&T->rchild!=NULL&&sign->rchild==T)
				{
					sign->rchild=T->rchild;
					return 1;
				}
				else if (T->lchild!=NULL&&T->rchild==NULL&&sign->lchild==T)
				{
					sign->lchild=T->lchild;
					return 1;
				}
				else if (T->lchild!=NULL&&T->rchild==NULL&&sign->rchild==T)
				{
					sign->rchild=T->lchild;
					return 1;
				}
				else if (sign->lchild==T)
				{
					sign->lchild=NULL;
					return 1;
				}
				else
				{
					sign->rchild=NULL;
					return 1;
				}
			}
			else
				return 1;
		}
		else if (T->data>key)
		{
			sign=T;
			T=T->lchild;
		}
		else
		{
			sign=T;
			T=T->rchild;
		}
	}
	if (T==NULL)
		return 0;
}