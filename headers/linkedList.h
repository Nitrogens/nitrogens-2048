#include "standard.h"

//用于存储排行榜中每一行数据的结构体
struct rankListLine
{
    int rank;
    int score;
    char name[35];
};

//这样的话，在后续的代码中使用结构体的话，不需要再输入struct了
typedef struct rankListLine rankListLine;

//这样的话可以灵活改变链表中 值的数据类型
typedef rankListLine dataType;

//双向链表节点结构体
struct Node
{
    //值
    dataType value;
    //前后节点指针
    struct Node *prev, *next;
};

//这样的话，在后续的代码中使用结构体的话，不需要再输入struct了
typedef struct Node Node;

/*
	*
	* Function linkedListInit
	* 用于初始化双向链表

	* @return void

*/

void linkedListInit();

/*
	*
	* Function linkedListInsert
	* 用于向链表末端插入元素

	* @param dataType value 要插入的值
	* @param Node * 要插入的位置（在其后）

	* @return void

*/

void linkedListInsert(dataType value, Node * position);

/*
	*
	* Function linkedListDelete
	* 用于删除链表中的元素

	* @param Node * target 要搜索的节点所在的位置

	* @return void

*/

void linkedListDelete(Node *target);

/*
	*
	* Function linkedListClear
	* 用于清空链表中的元素

	* @return void

*/

void linkedListClear();

/*
	*
	* Function linkedListSearch
	* 用于在链表中搜索比给定分数高的结构体元素

	* @param int value 要查找的分数

	* @return Node * 返回结构体指针

*/

Node *linkedListSearch(int value);
