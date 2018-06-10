#include "headers/linkedList.h"

extern Node *head, *last;

void linkedListInit()
{
    //Ϊͷָ������ڴ�ռ�
    head = (Node *)malloc(sizeof(Node));
    //����ǰ�����ӹ�ϵ
    head->next = head;
    head->prev = head;
    last = head;
}

void linkedListInsert(dataType value, Node * position)
{
    //�����ڴ�ռ�
    Node *x = (Node *)malloc(sizeof(Node));
    x->value = value;
    //����ǰ�����ӹ�ϵ
    x->next = position->next;
    x->prev = position;
    position->next->prev = x;
    position->next = x;
    //����ĩ��ָ��
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
        //�ڽڵ㱻ɾ��֮ǰ��Ҫ�Ȱѽڵ����һ���ڵ��¼����
        iterator = iterator->next;
        linkedListDelete(iterator->prev);
    }
    linkedListDelete(head);
}

Node *linkedListSearch(int value)
{
    Node *iterator = head->next;
    //iterator == head������ѭ����ͷ�ڵ㣬˵��������ɲ���δ�ҵ���Ҫ�ҵ�Ԫ�أ�����head
    while(iterator != head && iterator->value.score > value)
    {
        iterator = iterator->next;
    }
    return iterator;
}
