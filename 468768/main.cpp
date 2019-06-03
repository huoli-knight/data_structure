#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<string>
#define MAXSIZE 1000
using namespace std;

typedef struct dat{
     char real[8];
	 char imaginary[8];
     struct dat *next;
}dat,*dat1;

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
BtreeNode* afaToBtree(char (*afa)[2][8],int s,int e)
{
	int j=0;
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
			 for (j=0;afa[s][1][j]!='\0';j++)
				bn->data[1][j]=afa[s][1][j];
			 bn->data[1][j]='\0';
			 bn->data[0][0]='\0';
		 }
         bn->lchild=NULL;
         bn->rchild=NULL;
         return bn;
    }
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
         afaToBtree(afa,s+1,e-1);
     else
     {
        if(a_s_p>0)local_r=a_s_p;
        else if(m_m_p>0)local_r=m_m_p;
        BtreeNode* b=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
		 if (afa[local_r][0][0]!='\0')
		 {
			for (j=0;afa[local_r][0][j]!='\0';j++)
				b->data[0][j]=afa[local_r][0][j];
			b->data[0][j]='\0';
			b->data[1][0]='\0';
		 }
		 else
		 {
			 for (j=0;afa[local_r][1][j]!='\0';j++)
				b->data[1][j]=afa[local_r][1][j];
			 b->data[1][j]='\0';
			 b->data[0][0]='\0';
		 }
        b->lchild=afaToBtree(afa,s,local_r);
        b->rchild=afaToBtree(afa,local_r+1,e);
        return b;
     }
}

void cal(dat1 E)
{
	double a[2]={0,0},b[2]={0,0};
    SqStack S;
	S.base=(double (*)[2])malloc(MAXSIZE*2*sizeof(double));
    S.top=S.base;
    S.Size=MAXSIZE;
	for(;E->real[0]!='\0'||E->imaginary[0]!='\0';)
    {
        if(E->real[0]=='+')
        {
            S.top--;
			b[1]=*(S.top)[1];
            b[0]=*(S.top)[0];
            S.top--;
            a[0]=*(S.top)[0];
			a[1]=*(S.top)[1];
            *(S.top)[0]=a[0]+b[0];
			*(S.top)[1]=a[1]+b[1];
            S.top++;
        }
        else if(E->real[0]=='-')
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
        else if(E->real[0]=='*')
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
        else if(E->real[0]=='/')
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
			if (E->real[0]!='\0')
				for(int j=0;E->real[j]!='\0';j++)
					*(S.top)[0]=*(S.top)[0]*10+(double)(E->real[j]-48);
			else
				for(int j=0;E->imaginary[j]!='\0';j++)
					*(S.top)[1]=*(S.top)[1]*10+(double)(E->imaginary[j]-48);
            S.top++;
        }
		E=E->next;
    }
	S.top--;
	printf("%f+%fj\n",*(S.top)[0],*(S.top)[1]);
    free(S.base);
}
void postvisit(Btree T,dat1 &E,int &i)
{
	int j=0;
    if(T)
    {
        postvisit(T->lchild,E,i);
        postvisit(T->rchild,E,i);
		if (T->data[0][0]!='\0')
		{
			for (j=0;T->data[0][j]!='\0';j++)
			 {
				 E->real[j]=T->data[0][j];
				 printf("%c",T->data[0][j]);
			 }
			E->real[j]='\0';
			E->imaginary[0]='\0';
			printf("\n");
		}
		else
		{
			 for (j=0;T->data[1][j]!='\0';j++)
			 {
				 E->imaginary[j]=T->data[1][j];
				printf("%cj",T->data[1][j]);
			 }
			 E->imaginary[j]='\0';
			 E->real[0]='\0';
			 printf("\n");
		}
		dat* W=(struct dat*)malloc(sizeof(struct dat));
		E->next=W;
		E=E->next;
    }
}
int main()
{
	char input[MAXSIZE][2][8],c[MAXSIZE];
	dat* W=(struct dat*)malloc(sizeof(struct dat));
	dat1 E=W,F=W;
    int i=0,j=0;
    memset(input,'\0',sizeof(input));
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
		else if (c[j]=='j'&&j==0)
		{
			input[i][0][0]='\0';
			input[i][1][0]='1';
		}
		else if(c[j]=='j'&&c[j-1]>='0'&&c[j-1]<='9')
		{
			strcpy(input[i-1][1],input[i-1][0]);
			input[i-1][0][0]='\0';
			i--;
		}
		else if(c[j]=='j'&&!(c[j-1]>='0'&&c[j-1]<='9')&&j!=0)
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
    postvisit(myBtree,E,i);
	E->imaginary[0]='\0';
	E->real[0]='\0';
	E->next=NULL;
	E=F;
    printf("safasfasf£º");
	cal(E);
    return 0;
}
