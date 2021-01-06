//Написать программу, которая в матрце чисел A(N, M) находит все элементы, равные числу, введенному с клавиатуры.
//Подсчитать число таких элементов.
//Lab5 #15 

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main() {
	int num = 0, count = 0;
	int matrix[SIZE][SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 90 + 10;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Enter number from 10 to 100: ");
	while (!scanf_s("%d", &num));

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] == num) { count++; }
		}
	}

	printf("Count of equal numbers in matrix: %d", count);
	return 0;
}