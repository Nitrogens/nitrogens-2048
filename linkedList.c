#include "headers/linkedList.h"

extern Node *head, *last;

void linkedListInit()
{
    //为头指针分配内存空间
    head = (Node *)malloc(sizeof(Node));
    //处理前后连接关系
    head->next = head;
    head->prev = head;
    last = head;
}

void linkedListInsert(dataType value, Node * position)
{
    //分配内存空间
    Node *x = (Node *)malloc(sizeof(Node));
    x->value = value;
    //处理前后连接关系
    x->next = position->next;
    x->prev = position;
    position->next->prev = x;
    position->next = x;
    //更新末端指针
    if(position == last)
    {
        last = x;
        head->prev = last;
    }
}

void linkedListDelete(Node *target)
{
    if(target == last)
    {
        last = target->prev;
        head->prev = last;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

void linkedListClear()
{
    Node * iterator = head->next;
    while(iterator != head)
    {
        //在节点被删除之前需要先把节点的下一个节点记录下来
        iterator = iterator->next;
        linkedListDelete(iterator->prev);
    }
    linkedListDelete(head);
}

Node *linkedListSearch(int value)
{
    Node *iterator = head->next;
    //iterator == head表明已循环到头节点，说明遍历完成并且未找到所要找的元素，返回head
    while(iterator != head && iterator->value.score > value)
    {
        iterator = iterator->next;
    }
    return iterator;
}
