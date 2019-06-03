#include"标头.h"
void foundfile()
{
	FILE *file1;
	if((file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat","r"))==NULL)
	{
		file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat","w");
		fclose(file1);
		file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat", "a");
		putw(0,file1);
		putw(0,file1);
	}
	fclose(file1);
}
void holdmain(BiTree T)
{
	FILE *file1;
	file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat","w");
	fclose(file1);
	hold(T);
	file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat", "a");
	putw(0,file1);
	putw(0,file1);
	fclose(file1);
	cout<<"储存成功！"<<endl;
	fclose(file1);
}
void hold(BiTree T)
{
	if(T)
    {
        hold(T->lchild);
        hold(T->rchild);
		FILE *file1;
		file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat", "a");
		putw(T->data,file1);
		putw(T->count,file1);
		fclose(file1);
	}
}
BiTree readdata()
{
	BiTree T2;
	BiTree T=(BiTree)malloc(sizeof(BiTNode));
	int i(0),j(0);
	FILE *file1;
	BiTree T1=(BiTNode *)malloc(sizeof(BiTNode));
	T->rchild=NULL;
	file1=fopen("G:\\学习\\数据结构\\课设\\ConsoleApplication8\\file1.dat","r");
	for (;T->count!=0;i++)
	{
		T=T1;
		T->data=getw(file1);
		T->count=getw(file1);
		T->lchild=NULL;
		T1=(BiTNode *)malloc(sizeof(BiTNode));
		T1->rchild=T;
	}
	if (i==1)
		T=NULL;
	else
		T=T->rchild;
	for (T1=T;j<i-1;j++)
	{
		T2=T1;
		T1=T1->rchild;
	}
	if (T!=NULL)
		T2->rchild=NULL;
	fclose(file1);
	return T;
}