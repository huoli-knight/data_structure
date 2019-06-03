#include"БъЭЗ.h"
int main()
{
	int i;
	BiTree T = NULL;
	foundfile();
	T=readdata();
	menu(T);
	while (1)
	{
		menu(T);
	}
	system("pause");
	return 0;
}