//–ассортировать одномерный массив по возрастанию (убыванию) элементов (метод пузырька).
//Lab4 #9 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bubble(int*, int);

int main() {
	int mas[SIZE];

	srand(time(NULL));
	printf("Array:\n");
	for (int i = 0; i < SIZE; i++) {
		mas[i] = rand() % 90 + 10;
		printf("%d ", mas[i]);
	}
	printf("\nSorted array:\n");

	bubble(mas, SIZE);

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", mas[i]);
	}
	return 0;
}

void bubble(int* mas, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = (size - 1); j > i; j--) {
			if (mas[j - 1] > mas[j]) {
				int temp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = temp;
			}
		}
	}
}