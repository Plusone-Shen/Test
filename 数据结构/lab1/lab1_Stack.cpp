#include <iostream>

template<class T>
class Stack {
private:
    size_t size;
    size_t capacity;
    T* stack;
public:
    Stack(size_t capacity = 1) {
        this->size = 0;
        this->capacity = capacity;
        this->stack = new T[capacity];
    }

    Stack(size_t size, T val) {
        // TODO: Implement the constructor
        this->size = size;
        size_t capacity = 1;
        while (capacity < size) {
            capacity <<= 1;
        }
        this->capacity = capacity;
        this->stack = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->stack[i] = val;
        }
    }

    Stack(T* stack, size_t size) {
        // TODO: Implement the constructor
        this->size = size;
        size_t capacity = 1;
        while (capacity < size) {
            capacity <<= 1;
        }
        this->capacity = capacity;
        this->stack = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            this->stack[i] = stack[i];
        }
    }

    Stack(const Stack& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->stack = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            this->stack[i] = other.stack[i];
        }
    }

    Stack& operator=(const Stack& other) { // copy assignment
        if (this == &other) {
            return *this;
        }
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] this->stack;
        this->stack = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            this->stack[i] = other.stack[i];
        }
        return *this;
    }

    T& operator[](size_t index) {
        return stack[index];
    }

    void push(T val) {
        // TODO: Implement the push function
        if (size < capacity) {
            stack[size++] = val;  
        }
        else {
            capacity <<= 1; 
            T *stack2 = new T[capacity];
            for (size_t i = 0; i < size; i++) {
                stack2[i] = stack[i];
            }
            stack2[size++] = val;
            delete[] stack;
            stack = stack2;
        }
    }

    void pop() {
        // TODO: Implement the pop function
        if (size == 0)
            return;
        size--;
    }

    size_t getSize() {
        return size;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
};

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    Stack<int> stack2 = stack;
    stack2.pop();
    std::cout << stack.getSize() << std::endl;
    std::cout << stack2.getSize() << std::endl;
    stack.print();
    stack2.print();
    Stack<int> stack3(5, 10);
    stack3.print();
    int arr[] = {1, 2, 3, 4, 5};
    Stack<int> stack4(arr, 5);
    stack4.print();
}