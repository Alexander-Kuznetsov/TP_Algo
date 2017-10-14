/* Задание 3.3
Даны два массива неповторяющихся целых чисел, 
упорядоченные по возрастанию. 
A[0..n-1] и B[0..m-1]. n >> m. 
Найдите их пересечение. 
Требуемое время работы: O(m * log k), 
где k - позиция элемента B[m-1] в массиве A.. 
В процессе поиска очередного элемента B[i] 
в массиве A пользуйтесь результатом поиска элемента B[i-1].
n, k ≤ 10000.


*/

#include <iostream>

void initArr(int *arr, size_t size) {
	for (unsigned i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
}

//бинарный поиск, возвращающий индекс найденного эл-та
//если эл-т не найден, возвращает индекс предыдущего найденного эл-та
int binSearch(int *arr, int right, int left, size_t size, int value) {
	int right = size, mid = 0, tmp = left;

	if (!size) {
		return -1;
	}

	while (!(left >= right)) {
		mid = left + (right - left) / 2;

		if (arr[mid] == value) {
			std::cout << value << " ";
			return mid;
		}
		if (arr[mid] > value) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return tmp;
}

int main() {
	size_t size1 = 0, size2 = 0, left = 0, right = 0;
	std::cin >> size1 >> size2;

	if (!size1 || !size2) {
		return 0;
	}

	int *array1 = new int[size1];
	int *array2 = new int[size2];

	initArr(array1, size1);
	initArr(array2, size2);

	for (unsigned i = 0; i < size1; ++i) {
		
		left = binSearch(array2, right, left, size2, array1[i]);
	}

	return 0;
}