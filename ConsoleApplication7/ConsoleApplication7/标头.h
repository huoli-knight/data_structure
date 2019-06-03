#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct BiTNode
{
	int data;
	int count;//同分数量
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
bool Search(BiTree&T, int key, BiTree f, BiTree&p);//key为查找的值，f指向原先对比的结点
void Insert(BiTree&T, int key);
void menu(BiTree &T);
bool Delete(BiTree&T, int key);//删除返回1，否则0
void Print(const BiTree&T);//分布区间，还有各个区间的频率，根据每个结点中count打印出条形图
void invisit(const BiTree &T, int **List, int &i);//中序遍历排序树获取递增数列