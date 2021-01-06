#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	printf("Введите размерность матрицы : ");
	while ((!scanf_s("%d", &n)) || n <= 0)
	{
		printf("Данные введены неверно. Введите повторно : ");
		rewind(stdin);
	}
	system("cls");
	int** mx;
	mx = (int**)malloc(n * sizeof(int*));
	if (!mx)
	{
		printf_s("Недрстаточно памяти");
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		*(mx + i) = (int*)malloc(n * sizeof(int));
		if (!(mx + i))
		{
			if (i == 0)
			{
				free(mx);
				printf_s("Недостаточно памяти");
				exit(2);
			}
			for (int j = i - 1; j >= 0; j--)
			{
				free(mx[j]);
			}
			free(mx);
			printf_s("Недостаточно памяти");
			exit(2);
		}
	}
	int x = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			mx[i][j] = 1 + x;
			x++;
		}
	printf("Исходная матрица : \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s(" %d", mx[i][j]);
		}
		printf_s("\n");
	}
	int top = 0, left = 0, right = n, bot = n;
	char c = 't';
	for (int i = 0; i < 2 * n - 1; i++)
	{
		switch (c)
		{
		case 't':
			for (int j = left; j < right; j++)
			{
				for (int k = j; k < right; k++)
				{
					if (mx[top][k] < mx[top][j])
					{
						mx[top][k] += mx[top][j];
						mx[top][j] = mx[top][k] - mx[top][j];
						mx[top][k] -= mx[top][j];
					}
				}
				for (int i = top + 1; i < bot; i++)
					for (int k = left; k < right; k++)
					{
						if (mx[i][k] < mx[top][j])
						{
							mx[i][k] += mx[top][j];
							mx[top][j] = mx[i][k] - mx[top][j];
							mx[i][k] -= mx[top][j];
						}
					}
			}
			top++;
			c = 'r';
			break;
		case 'r':
			for (int i = top; i < bot; i++)
			{
				for (int k = i; k < bot; k++)
				{
					if (mx[k][right - 1] < mx[i][right - 1])
					{
						mx[k][right - 1] += mx[i][right - 1];
						mx[i][right - 1] = mx[k][right - 1] - mx[i][right - 1];
						mx[k][right - 1] -= mx[i][right - 1];
					}
				}
				for (int k = top; k < bot; k++)
					for (int j = left; j < right - 1; j++)
					{
						if (mx[k][j] < mx[i][right - 1])
						{
							mx[k][j] += mx[i][right - 1];
							mx[i][right - 1] = mx[k][j] - mx[i][right - 1];
							mx[k][j] -= mx[i][right - 1];
						}
					}
			}
			right--;
			c = 'b';
			break;
		case 'b':
			for (int j = right - 1; j >= left; j--)
			{
				for (int k = j; k > left; k--)
				{
					if (mx[bot - 1][k] < mx[bot - 1][j])
					{
						mx[bot - 1][k] += mx[bot - 1][j];
						mx[bot - 1][j] = mx[bot - 1][k] - mx[bot - 1][j];
						mx[bot - 1][k] -= mx[bot - 1][j];
					}
				}
				for (int i = top; i < bot - 1; i++)
					for (int k = left; k < right; k++)
					{
						if (mx[i][k] < mx[bot - 1][j])
						{
							mx[i][k] += mx[bot - 1][j];
							mx[bot - 1][j] = mx[i][k] - mx[bot - 1][j];
							mx[i][k] -= mx[bot - 1][j];
						}
					}
			}
			bot--;
			c = 'l';
			break;
		case 'l':
			for (int i = bot - 1; i >= top; i--)
			{
				for (int k = i; k > top; k--)
				{
					if (mx[k][left] < mx[i][left])
					{
						mx[k][left] += mx[i][left];
						mx[i][left] = mx[k][left] - mx[i][left];
						mx[k][left] -= mx[i][left];
					}
				}
				for (int k = top; k < bot; k++)
					for (int j = left + 1; j < right; j++)
					{
						if (mx[k][j] < mx[i][left])
						{
							mx[k][j] += mx[i][left];
							mx[i][left] = mx[k][j] - mx[i][left];
							mx[k][j] -= mx[i][left];
						}
					}
			}
			left++;
			c = 't';
			break;
		}
	}
	printf("Итоговая матрица : \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s(" %d", mx[i][j]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < n; i++)
		free(mx[i]);
	free(mx);
}