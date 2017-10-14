/* Задание 4.3
Реализовать очередь с помощью двух стеков. 
Использовать стек, реализованный с помощью динамического буфера.
*/

#include <iostream>

enum Errors {
	EMPTY = -1,
	OK 	= 	 0
};

class Stack {
	private:
		size_t size, count;
		int *arr;

		void resize() {
			int *tmp = new int[size *= 2];
			for (unsigned i = 0; i < count; ++i) {
				tmp[i] = arr[i];
			}
			delete[] arr;
			
			arr = tmp;
		}
	public:
		Stack(): size(8), count(0) {
			arr = new int[size];
		}

		Stack(size_t size): size(size), count(0) {
			arr = new int[size];
		}

		~Stack() { 
			delete[] arr; 
		}

		void push(int value) {
			if (count == size) {
				this->resize();
			}
			arr[count] = value;
			++count;
		}

		int pop() {
			if (count > 0) {
				--count;
				return arr[count];	
			}
			else {
				return EMPTY;
			}
		}

		int get_count() const {
			return count;
		}
};

class Queue {
	private:
		Stack stack1, stack2;
	public:
		Queue() {}
		~Queue() {}

		void push(int value) {
			stack1.push(value);
		}

		int pop() {
			//Заполнение 2го стека, если он пуст
			if (stack2.get_count() == 0) {
				if (stack1.get_count() == 0) {
					return EMPTY;
				}
				size_t count = stack1.get_count();
				for (unsigned i = 0; i < count; ++i) {
					stack2.push(stack1.pop());
				}
			}
			return stack2.pop();
		}
};


//выборка команды 2 - pop, 3 - push
bool handler(Queue &queue, int cmd, int value) {
	switch(cmd) {
		case 2:
			return (queue.pop() == value);
		case 3:
			queue.push(value);
			return true;;
		default:
			return false;
	}
}

//Обработка команд в очереди
bool queueCmd(Queue &queue, int countCmd) {
	for (int i = 0; i < countCmd; ++i) {
		int cmd, value;
		std::cin >> cmd >> value;
		if (!handler(queue, cmd, value)) {
			return false;
		}
	}
	return true;
}

int main() {
	Queue queue;
	int countCmd = 0;
	std::cin >> countCmd;

	//Проверка правильности работы
	if (queueCmd(queue, countCmd)) {
		std::cout << "YES";
	}
	else { 
		std::cout << "NO";
	}

	return OK;
}