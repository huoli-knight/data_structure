#include"��ͷ.h"
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
	if (!Search(T, key, NULL, p))//û�ҵ�
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
	cout << "1-���룬2-��β��룬3-ɾ����4-ͳ��\n";
	cout<<"5-����\n";
	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "�������\n";
		int key1;
		cin >> key1;
		Insert(T, key1);
		cout << "����ɹ�\n";
		system("pause");
		system("cls");
		break;
	case 2:
		cout << "�������ɼ��ĸ���\n";
		int j;
		cin >> j;
		for (int i = 0; i < j; ++i)
		{
			int key2;
			cin >> key2;
			Insert(T, key2);
		}
		cout << "����ɹ�\n";
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "ÿ��ɾ��ֻɾ���óɼ���һ�μ�¼������¼Ϊ0ʱ���ĳɼ�����ȫ��ɾ��\n";
		int key3;
		cout << "����Ҫɾ���ĳɼ���ֵ\n";
		cin >> key3;
		if (Delete(T, key3))
			cout << "ɾ���ɹ�\n";
		else
			cout << "ɾ��ʧ��\n";
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