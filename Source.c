#include <stdio.h>
#include <malloc.h>
#include <windows.h>
int IntegerValue();
void DisplayOnTheScreen(int n, int** array);
int main()
{
	int n;
	printf("Enter a size of massive: ");
	n = IntegerValue();
	int** A = (int**)malloc(n * sizeof(int*));
	printf("Enter values: \n");

	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			A[i][j] = IntegerValue();
		}
	}

	DisplayOnTheScreen(n, A);

	printf("\n");

	//for (int i = 0; i < n; i++) 
	//{
	//	for (int j = 0; j < n; j++) 
	//	{
	//		printf("%5d", A[i][j]);
	//	}
	//	printf("\n");
	//}

	int* B;
	int k = 0;
	printf("Enter values: \n");

	for (int i = 0; i < n; i++)
	{
		if (A[i] != NULL)
		{
			B = (int*)realloc(A[i], (n + 1) * sizeof(int));
			if (B != NULL)
			{

				A[i] = B;
				A[i][n] = IntegerValue();
			}
			else
				printf("You have some problems");
		}
		else
			printf("You have some problems");
	}

	for (int i = 0; i < n; i++)
	{
		k = A[i][n - 1];
		A[i][n - 1] = A[i][n];
		A[i][n] = k;
	}
	printf("\n");


	//DisplayOnTheScreen(n, A);
	printf("\n");


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%5d", A[i][j]);
		}

		printf("\n");

	}

	for (int i = 0; i < n; i++)
	{
		free(A[i]);
	}

	return 0;
}

void DisplayOnTheScreen(int n, int** A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", A[i][j]);
		}

		printf("\n");

	}
}

int IntegerValue() {
	char c;
	int n;
	while (scanf_s("%d%c", &n, &c) != 2 && (n < 0 || n > 10) || c != '\n') {
		printf("You entered incorrect integer value. Please try again: \n");
		rewind(stdin);
	}
	return n;
}