/* ������� 5.3
���� ������������������ N ��������������� ��������� 
������ � ������ (wi, hi). �������������� �����������, 
������� � ����� (0, 0), �� ��� �� �������� ���� �� ������ (������).
��������� ����� M - ������� ������������� ��������������
(������������� ���� ���������), ������� ����� �������� �� ���� ������.
*/

#include <iostream>

struct Rectangle {
	unsigned width, height;
};

class Stack {
	private:
		void resize() {
			Rectangle *tmp = new Rectangle[size *= 2];
			for (unsigned i = 0; i < count; ++i) {
				tmp[i] = arr[i];
			}

			delete[] arr;
			arr = tmp;
		}

		size_t size, count;
		Rectangle *arr;
	public:
		Stack(): size(8), count(0) {
			arr = new Rectangle[size];
		}

		Stack(size_t size): size(size), count(0) {
			arr = new Rectangle[size];
		}

		~Stack() { 
			delete[] arr; 
		}

		void push(Rectangle value) {
			if (count == size) {
				this->resize();
			}
			arr[count] = value;
			++count;
		}

		Rectangle pop() {
			--count;
			return arr[count];	
		}

		int get_count() const {
			return count;
		}

		bool is_empty() const {
			return count <= 0;
		}

		Rectangle peek() {
			return arr[count - 1];
		}
};

int getMaxArea(Stack &stack, unsigned count) {
	size_t max_area = 0;
    size_t curr_height = 0;

    for (size_t i = 0; i < count; ++i) {
        Rectangle rectangle;
        std::cin >> rectangle.width >> rectangle.height;
		//�������� � ����, ���� ������ �������������� �� ������� ����� ������ ������
        if (rectangle.height >= curr_height) {
            stack.push(rectangle);
            curr_height = rectangle.height;
        }
        else { //����� ��������� �� �����, ���� ������ �� ������� ����� > ������
            size_t joint_width = 0; //������ ��������������, ������� ��������
            Rectangle top_rect = stack.peek();

            while ((top_rect.height >= rectangle.height) && !stack.is_empty()) {
                top_rect = stack.pop();
                joint_width += top_rect.width;
				//������� �������
                size_t rect_area = top_rect.height * joint_width;
                if (rect_area > max_area) {
                    max_area = rect_area;
                }
				//�������� �������������� �� ������� �����
                if (!stack.is_empty()) {
                    top_rect = stack.peek();
                }
            }
			//��������� ����������� ����������� � ���� � ������� ������ ��������������
            rectangle.width += joint_width;
            curr_height = rectangle.height; 
            stack.push(rectangle);
        }
    }
	//������ �� ����� � ������� �������
    size_t joint_width = 0;
    while (!stack.is_empty()) {
        Rectangle top_rect = stack.pop();
        joint_width += top_rect.width;
        size_t rect_area = top_rect.height * joint_width;
        if (rect_area > max_area) {
            max_area = rect_area;
        }
    }

    return max_area;
}

int main() {
    size_t count = 0;
    std::cin >> count;
    Stack stack;

	std::cout << getMaxArea(stack, count);

	return 0;
}