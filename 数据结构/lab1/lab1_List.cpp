#include<iostream>

typedef struct Lnode {
    int value;
    struct Lnode *next;
}LinkNode, LinkList;

LinkList* InitList() {
    LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode)); //初始化头节点
    if (head == NULL) {
        printf("内存分配失败\n"); 
    }
    head->next = NULL; //头节点的下一个节点为空
    return head;
}

void AddNode(LinkList *head, int val) {
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode)); //创建新节点
    LinkNode *p = head;
    new_node->value = val;
    new_node->next = NULL; //新节点指向空
    while (p->next) {
        p = p->next;
    } //找到尾节点
    p->next = new_node;
}

LinkNode* SearchNode(LinkList *head, int val) {
    LinkNode *p = head;
    while (p) {
        if (p->value == val) { //判断该节点是否为所寻找的节点
            return p;
        }
        p = p->next;
    }
    return NULL; //该链表无所寻找的节点，返回空值
}

int ListLength(LinkList *head) {
    LinkNode *p = head->next;
    int length = 0;
    while (p) { //假如指针存在
        length++;
        p = p->next; //p向后移一位
    }
    return length;
}

void InsertNode(LinkList *head, int val1, int val2) {
    LinkNode *p = SearchNode(head, val1); //找到需要插入的位置（前一位）
    LinkNode *q = p->next;
    LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode)); //创建新节点
    new_node->value = val2;
    new_node->next = q; //new_node的下一位指向q
    p->next = new_node; //p的下一位指向new_node
}

int DeleteNode(LinkList *head, int val) {
    LinkNode *to_delete = SearchNode(head, val); //找到需要删除的位置
    if (to_delete == NULL) { //假如不存在则返回0
        return 0;
    }
    LinkNode *pre = head; 
    while (pre->next != to_delete) {
        pre = pre->next;
    } //找到需要删除的位置的前一位
    pre->next = to_delete->next; //在链表里删除该指针
    free(to_delete); //释放空间
    return 1;
}

void PrintList(LinkList *head) {
    LinkNode *p = head->next; //由于head无数据，从第二位起开始遍历链表
    while (p) {
        printf("%d ", p->value);
        p = p->next;
    }
}

int main() {
    LinkList *head = InitList(); //初始化链表的头节点
    for (int i = 0; i < 10; i++) {
        AddNode(head, i); //向链表依次添加数据
    }
    PrintList(head);  //打印链表
    LinkNode *p = SearchNode(head, 3); //实验SearchNode功能
    if (p) {
        printf("\n%d\n", p->value);
    }
    else {
        printf("error");
    }
    LinkNode *q = SearchNode(head, 10); //实验SearchNode功能
    if (q) {
        printf("\n%d\n", q->value);
    }
    else {
        printf("error\n");
    }
    InsertNode(head, 3, 10); //在3后面添加10，实验InsertNode功能
    PrintList(head);
    printf("\n");
    if (DeleteNode(head,3) == 1) { //删除链表的3，实验DeleteNode功能
        PrintList(head);
    }
    else {
        printf("error");
    }
    printf("\n");
    printf("%d", ListLength(head)); //实验Listlength功能
    return 0;
}