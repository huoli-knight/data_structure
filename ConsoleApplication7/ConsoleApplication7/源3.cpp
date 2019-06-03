#include"标头.h"
void invisit(const BiTree &T, int *List, int &i)
{
	if (T)
	{
		invisit(T->lchild, List, i);
		for (int j = 0; j<T->count; j++)
		{
			List[i] = T->data;
			i++;
		}
		invisit(T->rchild, List, i);
	}
}
void Print(const BiTree &T)
{
	int List[200], i = 0, f;
	double p;
	invisit(T, List, i);
	List[i] = -1;
	int unpas, pas, med, gre, exc;
	for (i = 0; List[i] != -1; i++)
	{
		if (List[i] >= 0 && List[i]<60);
		else break;
	}
	unpas = i;
	for (; List[i] != -1; i++)
	{
		if (List[i] >= 60 && List[i]<70);
		else break;
	}
	pas = i - unpas;
	for (; List[i] != -1; i++)
	{
		if (List[i] >= 70 && List[i]<80);
		else break;
	}
	med = i - unpas - pas;
	for (; List[i] != -1; i++)
	{
		if (List[i] >= 80 && List[i]<90);
		else break;
	}
	gre = i - med - pas - unpas;
	for (; List[i] != -1; i++)
	{
		if (List[i] >= 90 && List[i] <= 100);
		else break;
	}
	exc = i - gre - pas - unpas - med;
	cout << "学生总人数：" << i << endl << "学生成绩条形统计图：" << endl;
	p = exc*1.0 / i;
	f = 100 * p;
	cout << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << "  优秀:" << setprecision(3) << p;
	for (int j = 0; j<f; j++)cout << " ";
	if (f == 0 || p == 1)cout << "    ";
	cout << "|" << endl << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << endl;

	p = gre*1.0 / i;
	f = 100 * p;
	cout << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << "  良好:" << setprecision(3) << p;
	for (int j = 0; j<f; j++)cout << " ";
	if (f == 0 || p == 1)cout << "    ";
	cout << "|" << endl << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << endl;

	p = med*1.0 / i;
	f = 100 * p;
	cout << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << "  中等:" << setprecision(3) << p;
	for (int j = 0; j<f; j++)cout << " ";
	if (f == 0 || p == 1)cout << "    ";
	cout << "|" << endl << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << endl;

	p = pas*1.0 / i;
	f = 100 * p;
	cout << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << "  及格:" << setprecision(3) << p;
	for (int j = 0; j<f; j++)cout << " ";
	if (f == 0 || p == 1)cout << "    ";
	cout << "|" << endl << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << endl;

	p = unpas*1.0 / i;
	f = 100 * p;
	cout << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << "不及格:" << setprecision(3) << p;
	for (int j = 0; j<f; j++)cout << " ";
	if (f == 0 || p == 1)cout << "    ";
	cout << "|" << endl << "           |";
	for (int j = 0; j<f; j++)cout << "-";
	cout << "*" << endl << endl;

	cout << "各成绩分布如下：" << endl;
	for (int j = 0, i = 1; List[j] != -1; j++)
	{
		if (List[j] != List[j + 1])
		{
			cout << List[j] << ":" << i << endl;
			i = 1;
		}
		else i++;
	}
}
