#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct BiTNode
{
	int data;
	int count;//ͬ������
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
bool Search(BiTree&T, int key, BiTree f, BiTree&p);//keyΪ���ҵ�ֵ��fָ��ԭ�ȶԱȵĽ��
void Insert(BiTree&T, int key);
void menu(BiTree &T);
bool Delete(BiTree&T, int key);//ɾ������1������0
void Print(const BiTree&T);//�ֲ����䣬���и��������Ƶ�ʣ�����ÿ�������count��ӡ������ͼ
void invisit(const BiTree &T, int **List, int &i);//���������������ȡ��������