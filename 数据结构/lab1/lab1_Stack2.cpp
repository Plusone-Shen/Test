#include<iostream>

#define ElemType int

typedef struct stack{
    size_t size;
    size_t capacity;
    ElemType *arr;
}Stack; //建立栈结构体

Stack *InitStack() {
    Stack *array = (Stack*)malloc(sizeof(Stack));
    array->size = 0;  //初始化栈的长度为0
    array->capacity = 1; //初始化栈的数组容量
    array->arr = new ElemType[array->capacity];
    return array;
} //初始化栈

void Push(Stack *array, int val) {
    if (array->size < array->capacity) { //假如目前栈的长度小于容量，则增加栈的长度，并填充数据
        array->arr[array->size++] = val;  
    }
    else { //否则，增加栈的容量
        array->capacity <<= 1; 
        ElemType *arr2 = new ElemType[array->capacity]; //建立容量为原数组两倍的新数组
        for (size_t i = 0; i < array->size; i++) {
            arr2[i] = array->arr[i]; //将原数组的数据依次填入新数组
        }
        arr2[array->size++] = val; //填入新数据
        delete[] array->arr; //删除原数组
        array->arr = arr2; //将结构体的指针指向新数组
    }
}

void Pop(Stack *array) {
    if (array->size == 0) //如果数组无数据，直接返回
        return;
    array->size--;  //使数组长度减1
}

void Print(Stack *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->arr[i]); //依次打印数组的元素
    }
    printf("\n");
}

Stack *Copy(Stack *array) { //复制栈
    Stack *new_array = (Stack*)malloc(sizeof(Stack));  //新创建结构体
    new_array->size = array->size;  
    new_array->capacity = array->capacity;
    new_array->arr = new ElemType[array->capacity];
    for (int i =0; i < new_array->size; i++) {
        new_array->arr[i] = array->arr[i];  //将原栈的数据依次传入复制栈
    }
    return new_array;
}

Stack *TurnToStack(ElemType *arr, size_t size) { //将数组转为栈结构
    Stack *new_array = InitStack();
    for (int i =0; i < size; i++) {
        Push(new_array, arr[i]); //挨个进行push操作
    }
    return new_array;
}

int GetSize(Stack *array) {
    return array->size;
}

int main() {
    Stack *array = InitStack();
    for (int i = 0; i < 9; i++) {
        Push(array, i);
    }
    Print(array);
    Stack *array2 = Copy(array);
    Pop(array2);
    Print(array2);
    ElemType arr[] = {1, 2, 3, 4, 5};
    Stack *array3 = TurnToStack(arr, 5);
    Print(array3);
    return 0;
}

