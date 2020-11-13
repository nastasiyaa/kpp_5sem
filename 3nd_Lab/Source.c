#include <stdio.h>
#include <stdbool.h>
bool vys(int year)
{
	bool res = false;
	if (year % 4 == 0)
		res = true;
	if (year % 100 == 0)
		res = false;
	if (year % 400 == 0)
		res = true;
	return res;
}
int date(int d, int m, int y)
{
	int k = d;
	if (vys(y) && (m > 2))
		k += y * 366;
	else k += y * 365;
	switch (m - 1)
	{
	case 12:
		k += 31;
		break;
	case 11:
		k += 30;
		break;
	case 10: k += 31;
		break;
	case 9: k += 30;
		break;
	case 8: k += 31;
		break;
	case 7:
		k += 31;
		break;
	case 6: k += 30;
		break;
	case 5: k += 31;
		break;
	case 4: k += 30;
		break;
	case 3: k += 31;
		break;
	case 2:
		k += 28;
		break;
	case 1: k += 31;
		break;

	}

	return k;
}
int difference(int d1, int d2, int m1, int m2, int y1, int y2)
{
	int k = date(d2, m2, y2) - date(d1, m1, y1);
	return k;
}
int main()
{
	int d1, d2, m1, m2, y1, y2;
	printf("Input first day: _");
	scanf_s("%d", &d2);
	printf("\n");
	printf("Input first month: ");
	scanf_s("%d", &m2);
	printf("\n");
	printf("Input first year: ");
	scanf_s("%d", &y2);
	printf("\n");
	printf("Input second day: ");
	scanf_s("%d", &d1);
	printf("\n");
	printf("Input second month: ");
	scanf_s("%d", &m1);
	printf("Input second year: ");
	scanf_s("%d", &y1);
	printf("\n");
	printf("Between these two dates are %d %d %d %d %d %d days", d1, d2, m1, m2, y1, y2);
	
	return 0;
}