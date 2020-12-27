#include <stdio.h>
#include <malloc.h>
void sort(int m, int n, int** ms);
int IntegerValue();
int main() {
	int n, m, c = 0;
	printf("Enter a value: ");
	//n, m = IntegerValue();
	scanf_s("%d%d", &n, &m);
	int** A = (int**)malloc(n * sizeof(int*));
	printf("Enter values: \n");
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d", A[i][j]);
#include <stdio.h>
#include <malloc.h>
			void sort(int m, int n, int** ms);
			int IntegerValue();
			int main() {
				int m, n;
				printf("Enter a value: ");
				m = IntegerValue();
				printf("Enter a value: ");
				n = IntegerValue();
				//scanf_s("%d%d", &n, &m);
				int** A = (int**)malloc(n * sizeof(int*));
				printf("Enter values: \n");
				for (int i = 0; i < n; i++) {
					A[i] = (int*)malloc(m * sizeof(int));
					for (int j = 0; j < m; j++) {
						//scanf_s("%d", &A[i][j]);
						A[i][j] = IntegerValue();
					}
				}

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%5d", A[i][j]);
					}
					printf("\n");
				}
				printf("\n");

				sort(n, m, A);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%5d", A[i][j]);
					}
					printf("\n");
				}

				for (int i = 0; i < n; i++)
					free(A[i]);

				free(A);


				return 0;
			}

			void sort(int m, int n, int** ms) {
				int tmp;

				for (int k = 0; k < m * n; k++)
					for (int j = 0; j < n; j++)
						for (int i = 0; i < (m - 1); i++)
						{
							if (ms[i][j] < 0) {
								if ((ms[i][j] > ms[i + 1][j]) && (i != m - 1) && ms[i + 1][j])
								{
									tmp = ms[i][j];
									ms[i][j] = ms[i + 1][j];
									ms[i + 1][j] = tmp;
								}


							}
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