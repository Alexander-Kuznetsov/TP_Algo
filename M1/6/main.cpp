/* Задание 6.2
Дано N кубиков. 
Требуется определить каким количеством способов можно 
выстроить из этих кубиков пирамиду.
Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.
*/

#include <iostream>
#include <cmath>

unsigned long long **create_table(int size) {
	unsigned long long **arr = new unsigned long long *[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new unsigned long long[size];
        for (int j = 0; j < size; ++j) {
            arr[i][j] = 0;
        }
    }
	return arr;
}

void del_table(unsigned long long **arr, int size) {
	for (int i = 0; i < size; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void print_table(unsigned long long **arr, int size) {
	for (int i = 1; i < size; ++i) {
		std::cout << i << ") ";
		for (int j = 1; j < size; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

unsigned long long getCount(unsigned long long **arr, int size) {
	if (size > 301 || size < 2) {
        return 0;
    }
	///Заполнение размещений по главной диагонали
	for (int i = 1; i < size; ++i) {
		arr[i][i] = 1;
	}
	//i - количество всех камней; j - количество камней в основании
	for (int i = 1; i < size; ++i) {
		for (int j = 1; j < i; ++j) {
			//Если количество камней в основании не превышает количества всех камней
			if ((j <= i) && (i <= j * (j + 1) / 2)) { 
				for (int k = 1; k < j; ++k) {
					arr[i][j] += arr[i - j][k]; //Сумма размещение камней выше основания
				}
			}
		}		
	}
	//Сумма всевозможных размещений с size элементами
	unsigned long long count = 0;
	for (int i = 1; i < size; i++) {	
		count += arr[size - 1][i];
	}
	
    return count;
}

int main() {
    int size = 0;
    std::cin >> size;
    
	unsigned long long **arr = create_table(size + 1);
	std::cout << getCount(arr, size + 1);
	del_table(arr, size + 1);

    return 0;
}