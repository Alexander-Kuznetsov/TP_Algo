/* A-1. Задача о поиске максимума
Составить программу поиска M наибольших чисел 
в заданном массиве целых (типа int) чисел A длины N. 
Числа M, N и элементы массива A 
подаются на стандартный ввод программы в следующем порядке: 
N 
A1 A2 ... AN 
M 
*/

#include <stdio.h>
#include <stdlib.h>

#define BAD_ALLOC	0
#define ERR_DATA	0
#define OK			0

int cmp(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

void print_mas(int *mas, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", mas[i]);
	}
	printf("\n");
}

int* init_mas(int n) {
	int *mas = (int*) malloc(sizeof(int) * n);
	if (mas == NULL) {
		return BAD_ALLOC;
	}

	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &mas[i]) != 1) {
			free(mas);
			return ERR_DATA;
		}
	}

	return mas;
}

int* search_max(int *mas, int n, int m) {
	if (mas == NULL || n < m) {
		return ERR_DATA;
	}
	
	int *new_mas = (int*) malloc(sizeof(int) * m);
	if (new_mas == NULL) {
		return BAD_ALLOC;
	}

	qsort(mas, n, sizeof(int), cmp);
	for (int i = 0; i < m; ++i) {
		new_mas[i] = mas[i];
	}

	return new_mas;
}

int main() {
	int n;
	if ((scanf("%d", &n) != 1) || (n < 0)) {
		printf("[error]");
		return ERR_DATA;
	}

	int *mas = init_mas(n);
	if (mas == NULL) {
		printf("[error]");
		return BAD_ALLOC;
	}

	int m;
	if ((scanf("%d", &m) != 1) || (m > n) || (m < 0)) {
		printf("[error]");
		free(mas);
		return ERR_DATA;
	}

	int *max_mas = search_max(mas, n, m);
	if (max_mas == NULL) {
		printf("[error]");
		free(mas);
		return BAD_ALLOC;
	}
	print_mas(max_mas, m);

	free(mas);
	free(max_mas);

	return OK;
}