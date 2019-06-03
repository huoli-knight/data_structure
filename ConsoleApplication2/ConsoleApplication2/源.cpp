#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<string>
#define MAXSIZE 1000

using namespace std;

typedef struct BtreeNode{
     char data[2][8];
     struct BtreeNode *lchild;
     struct BtreeNode *rchild;
}BtreeNode,*Btree;

typedef struct SqStack{
	double (*base)[2];
    double (*top)[2];
    int Size;
}SqStack;

//�������ʽת��������
/*
   afaΪָ����ʽ�ַ�����ָ��
   sΪҪת���ı��ʽ�ַ�������ʼλ��
   eΪҪת���ı��ʽ�ַ����Ľ���λ�õĺ�һ��
*/
BtreeNode* afaToBtree(char (*afa)[2][8],int s,int e)
{
	int j=0;
    //���ֻ��һ�����Ǿ���Ҷ�ӽ����
    if(e-s==1)
    {
         BtreeNode* bn=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
		 if (afa[s][0][0]!='\0')
		 {
			for (j=0;afa[s][0][j]!='\0';j++)
				bn->data[0][j]=afa[s][0][j];
			bn->data[0][j]='\0';
			bn->data[1][0]='\0';
		 }
		 else
		 {
			 for (j=0;afa[s][0][j]!='\0';j++)
				bn->data[1][j]=afa[s][1][j];
			 bn->data[1][j]='\0';
			 bn->data[0][0]='\0';
		 }
         bn->lchild=NULL;
         bn->rchild=NULL;
         return bn;
    }
    /*
       local_r��¼��ǰҪת���ı��ʽ���ɶ������ĸ��ڵ��������λ��
       flag��¼�Ƿ�ǰ��������������
       m_m_p��¼��ǰ���ʽ�������������ұߵ�+��-λ��
       a_s_p��¼��ǰ���ʽ�������������ұߵ�*��/λ��
    */
     int local_r=0,flag=0;
     int m_m_p=0,a_s_p=0;
     for(int i=s;i<e;i++)
     {
        if(afa[i][0][0]=='(')flag++;
        else if(afa[i][0][0]==')')flag--;
        if(flag==0){
            if(afa[i][0][0]=='*'||afa[i][0][0]=='/')
                m_m_p=i;
            else if(afa[i][0][0]=='+'||afa[i][0][0]=='-')
                a_s_p=i;
        }
     }
     if((m_m_p==0)&&(a_s_p==0))
         //���ʽ��������������(5-2*3+7)������������û�в���������ȥ�������Ҷ�����
         afaToBtree(afa,s+1,e-1);
     else
     {
        //�����+����-������ڵ�Ϊ���ұߵ�+��-�����������ұߵ�*��/
        if(a_s_p>0)local_r=a_s_p;
        else if(m_m_p>0)local_r=m_m_p;
        //ȷ�����ڵ�͸��ڵ�����Ӻ��Һ���
        BtreeNode* b=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
		 if (afa[local_r][0][0]!='\0')
		 {
			for (j=0;afa[local_r][0][j]!='\0';j++)
				b->data[0][j]=afa[e/2][0][j];
			b->data[0][j]='\0';
			b->data[1][0]='\0';
		 }
		 else
		 {
			 for (j=0;afa[local_r][0][j]!='\0';j++)
				b->data[1][j]=afa[local_r][1][j];
			 b->data[1][j]='\0';
			 b->data[0][0]='\0';
		 }
        b->lchild=afaToBtree(afa,s,local_r);
        b->rchild=afaToBtree(afa,local_r+1,e);
        return b;
     }
}

void cal(char (*exp)[2][8])
{
    int i;
	double a[2]={0,0},b[2]={0,0};
    SqStack S;
	S.base=(double (*)[2])malloc(MAXSIZE*2*sizeof(double));
    S.top=S.base;
    S.Size=MAXSIZE;
    for(i=0;exp[i][0][0]!='\0'||exp[i][1][0]!='\0';i++)
    {
        if(exp[i][0][0]=='+')
        {
            S.top--;
			b[1]=*(S.top)[1];
            b[0]=*(S.top)[0];
            S.top--;
			*(S.top)[1]=0;
            a[0]=*(S.top)[0];
			a[1]=*(S.top)[1];
            *(S.top)[0]=a[0]+b[0];
			*(S.top)[1]=a[1]+b[1];
            S.top++;
        }
        else if(exp[i][0][0]=='-')
        {
            S.top--;
            b[0]=*(S.top)[0];
			b[1]=*(S.top)[1];
            S.top--;
            a[0]=*(S.top)[0];
			a[1]=*(S.top)[1];
            *(S.top)[0]=a[0]-b[0];
			*(S.top)[1]=a[1]-b[1];
            S.top++;
        }
        else if(exp[i][0][0]=='*')
        {
            S.top--;
            b[0]=*(S.top)[0];
			b[1]=*(S.top)[1];
            S.top--;
            a[0]=*(S.top)[0];
			a[1]=*(S.top)[1];
            *(S.top)[0]=(a[0]*b[0])-(a[1]*b[1]);
			*(S.top)[1]=(a[0]*b[1])+(a[1]*b[0]);
            S.top++;
        }
        else if(exp[i][0][0]=='/')
        {
            S.top--;
            b[0]=*(S.top)[0];
			b[1]=*(S.top)[1];
            S.top--;
            a[0]=*(S.top)[0];
			a[1]=*(S.top)[1];
            *(S.top)[0]=(a[0]*b[0]+a[1]*b[1])/(b[0]*b[0]+b[1]*b[1]);
			*(S.top)[1]=(-1*a[0]*b[1]+a[1]*b[0])/(b[0]*b[0]+b[1]*b[1]);
            S.top++;
        }
        else
        {
			*(S.top)[0]=0;
			*(S.top)[1]=0;
			if (exp[i][0][0]!='\0')
				for(int j=0;exp[i][0][j]!='\0';j++)
					*(S.top)[0]=*(S.top)[0]*10+(double)(exp[i][0][j]-48);
			else if (exp[i][1][0]!='\0')
				for(int j=0;exp[i][1][j]!='\0';j++)
					*(S.top)[1]=*(S.top)[1]*10+(double)(exp[i][1][j]-48);
            S.top++;
        }
    }
	S.top--;
	printf("%f+%fj\n",*(S.top)[0],*(S.top)[1]);
    free(S.base);
}

void postvisit(Btree T,char (*exp)[2][8],int &i)
{
	int j=0;
    if(T)
    {
        postvisit(T->lchild,exp,i);
        postvisit(T->rchild,exp,i);
		if (T->data[0][0]!='\0')
		{
			for (j=0;T->data[0][j]!='\0';j++)
			 {
				*(exp+i)[0][j]=T->data[0][j];
				printf("%c",T->data[0][j]);
			 }
			printf("\n");
			*(exp+i)[0][j]='\0';
			*(exp+i)[1][0]='\0';
		}
		else
		{
			 for (j=0;T->data[0][j]!='\0';j++)
			 {
				*(exp+i)[1][j]=T->data[1][j];
				printf("%cj",T->data[1][j]);
			 }
			 printf("\n");
			 *(exp+i)[1][j]='\0';
			 *(exp+i)[0][0]='\0';
		}
        i+=1;
    }
}

int main()
{
	char input[MAXSIZE][2][8],exp[MAXSIZE][2][8],c[MAXSIZE];
    int i=0,j=0;
    memset(input,'\0',sizeof(input));
    memset(exp,'\0',sizeof(exp));
	cin>>c;
    for(;c[j]!='\0';j++,i++)
    {
        if(c[j]=='-')
        {
            if((j!=0)||(c[j-1]>='0'&&c[j-1]<='9'||c[j-1]=='('))
            {
                input[i][0][0]=c[j];
				input[i][1][0]='\0';
            }
            else
			{
                input[i][0][0]='0';
				input[i][1][0]='\0';
                input[i+1][0][0]='-';
				input[i+1][1][0]='\0';
				i++;
            }
        }
		else if(c[j]=='j'&&c[j-1]>='0'&&c[j-1]<='9')
		{
			strcpy(input[i-1][1],input[i-1][0]);
			input[i-1][0][0]='\0';
			i--;
		}
		else if(c[j]=='j'&&!(c[j-1]>='0'&&c[j-1]<='9'))
		{
			input[i][0][0]='\0';
			input[i][1][0]='1';
		}
        else
		{
			if(c[j-1]>='0'&&c[j-1]<='9'&&c[j]>='0'&&c[j]<='9')
			{
				for(int m=0;;m++)
					if(input[i-1][0][m]=='\0')
					{
						input[i-1][0][m]=c[j];
						break;
					}
				i--;
			}
			else
			{
				input[i][0][0]=c[j];
				input[i][1][0]='\0';
			}
        }
    }
    BtreeNode* myBtree=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    myBtree=afaToBtree(input,0,i);
	i=0;
    postvisit(myBtree,exp,i);
    printf("������Ϊ��");
	cal(exp);
    return 0;
}