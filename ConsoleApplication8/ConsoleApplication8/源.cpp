#include"БъЭЗ.h"
bool Delete(BiTree &T, int key)
{
	BiTree T1;
	T1=T;
	BiTree sign = NULL, sign2 = NULL;
	for (; T != NULL;)
	{
		if (T->data == key)
		{
			if (!(--T->count))
			{
				if (T->lchild != NULL&&T->rchild != NULL&&sign != NULL&&sign->lchild == T)
				{
					sign->lchild = T->lchild;
					sign = T->lchild;
					sign2 = sign->rchild;
					sign->rchild = T->rchild;
					T = T->rchild;
					for (; T->lchild != NULL; T = T->lchild);
					T->lchild = sign2;
					T=T1;
					return 1;
				}
				else if (T->lchild != NULL&&T->rchild != NULL&&sign != NULL&&sign->rchild == T)
				{
					sign->rchild = T->rchild;
					sign = T->rchild;
					sign2 = sign->lchild;
					sign->lchild = T->lchild;
					T = T->lchild;
					for (; T->rchild != NULL; T = T->rchild);
					T->rchild = sign2;
					T=T1;
					return 1;
				}
				else if (sign == NULL&&T->lchild != NULL&&T->rchild != NULL)
				{
					T1= T->lchild;
					sign = T->lchild;
					sign2 = sign->rchild;
					sign->rchild = T->rchild;
					T = T->rchild;
					for (; T->lchild != NULL; T = T->lchild);
					T->lchild = sign2;
					T=T1;
					return 1;
				}
				else if(sign == NULL&&T->lchild == NULL&&T->rchild != NULL)
				{
					T=T->rchild;
					return 1;
				}
				else if (sign == NULL&&T->lchild != NULL&&T->rchild == NULL)
				{
					T=T->lchild;
					return 1;
				}
				else if(sign == NULL&&T->lchild == NULL&&T->rchild == NULL)
				{
					T=NULL;
					return 1;
				}
				else if (T->lchild == NULL&&T->rchild != NULL&&sign->lchild == T)
				{
					sign->lchild = T->rchild;
					T=T1;
					return 1;
				}
				else if (T->lchild == NULL&&T->rchild != NULL&&sign->rchild == T)
				{
					sign->rchild = T->rchild;
					T=T1;
					return 1;
				}
				else if (T->lchild != NULL&&T->rchild == NULL&&sign->lchild == T)
				{
					sign->lchild = T->lchild;
					T=T1;
					return 1;
				}
				else if (T->lchild != NULL&&T->rchild == NULL&&sign->rchild == T)
				{
					sign->rchild = T->lchild;
					T=T1;
					return 1;
				}
				else if (sign->lchild == T)
				{
					sign->lchild = NULL;
					T=T1;
					return 1;
				}
				else
				{
					sign->rchild = NULL;
					T=T1;
					return 1;
				}
			}
			else
			{
				T=T1;
				return 1;
			}
		}
		if (T->data>key)
		{
			sign = T;
			T = T->lchild;
		}
		else
		{
			sign = T;
			T = T->rchild;
		}
	}
	if (T == NULL)
	{
		T=T1;
		return 0;
	}
}