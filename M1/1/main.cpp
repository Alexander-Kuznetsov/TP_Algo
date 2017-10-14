#include <iostream>

/* Задание 1.6
Дан массив целых чисел A[0..n). 
Не используя других массивов переставить 
элементы массива A  в обратном порядке за O(n).
n ≤ 10000

*/

void print_mas(int *mas, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << mas[i] << " ";
	}
}

void reverse_mas(int *mas, int n) {
	int len = n / 2;
	for (int i = 0; i < len; i++) {
		const int swap_ind = n - (i + 1);
		const int tmp = mas[i];
		mas[i] = mas[swap_ind];
		mas[swap_ind] = tmp;
	}
}

//Инициализация массива
int* init_mas(int n) {
	int *mas = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> mas[i];
	}

	return mas;
}

int main() {
	int n;
	std::cin >> n;

	int *mas = init_mas(n);
	reverse_mas(mas, n);
	print_mas(mas, n);
	delete[] mas;

	return 0;
}