#include"标头.h"
bool Search(BiTree&T, int key, BiTree f, BiTree&p)
{
	if (!T)
	{
		p = f;
		return 0;
	}
	else if (key == T->data)
	{
		p = T;
		return 1;
	}
	else if (key < T->data)
		Search(T->lchild, key, T, p);
	else
		Search(T->rchild, key, T, p);
}
void Insert(BiTree&T, int key)
{
	BiTree p, s;
	if (!Search(T, key, NULL, p))//没找到
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;
		s->count = 1;
		if (!p)
			T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
	}
	else
		++p->count;
}

void menu(BiTree &T)
{
	cout << "1-插入，2-多次插入，3-删除，4-统计\n";
	cout<<"5-储存\n";
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "输入分数\n";
		int key1;
		cin >> key1;
		Insert(T, key1);
		cout << "插入成功\n";
		system("pause");
		system("cls");
		break;
	case 2:
		cout << "输入插入成绩的个数\n";
		int j;
		cin >> j;
		for (int i = 0; i < j; ++i)
		{
			int key2;
			cin >> key2;
			Insert(T, key2);
		}
		cout << "插入成功\n";
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "每次删除只删除该成绩的一次记录，当记录为0时，改成绩将完全被删除\n";
		int key3;
		cout << "输入要删除的成绩的值\n";
		cin >> key3;
		if (Delete(T, key3))
			cout << "删除成功\n";
		else
			cout << "删除失败\n";
		system("pause");
		system("cls");
		break;
	case 4:
		Print(T);
		system("pause");
		system("cls");
		break;
	case 5:
		holdmain(T);
		system("pause");
		system("cls");
		break;
	}
}