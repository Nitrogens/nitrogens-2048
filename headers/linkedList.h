#include "standard.h"

//���ڴ洢���а���ÿһ�����ݵĽṹ��
struct rankListLine
{
    int rank;
    int score;
    char name[35];
};

//�����Ļ����ں����Ĵ�����ʹ�ýṹ��Ļ�������Ҫ������struct��
typedef struct rankListLine rankListLine;

//�����Ļ��������ı������� ֵ����������
typedef rankListLine dataType;

//˫������ڵ�ṹ��
struct Node
{
    //ֵ
    dataType value;
    //ǰ��ڵ�ָ��
    struct Node *prev, *next;
};

//�����Ļ����ں����Ĵ�����ʹ�ýṹ��Ļ�������Ҫ������struct��
typedef struct Node Node;

/*
	*
	* Function linkedListInit
	* ���ڳ�ʼ��˫������

	* @return void

*/

void linkedListInit();

/*
	*
	* Function linkedListInsert
	* ����������ĩ�˲���Ԫ��

	* @param dataType value Ҫ�����ֵ
	* @param Node * Ҫ�����λ�ã������

	* @return void

*/

void linkedListInsert(dataType value, Node * position);

/*
	*
	* Function linkedListDelete
	* ����ɾ�������е�Ԫ��

	* @param Node * target Ҫ�����Ľڵ����ڵ�λ��

	* @return void

*/

void linkedListDelete(Node *target);

/*
	*
	* Function linkedListClear
	* ������������е�Ԫ��

	* @return void

*/

void linkedListClear();

/*
	*
	* Function linkedListSearch
	* �����������������ȸ��������ߵĽṹ��Ԫ��

	* @param int value Ҫ���ҵķ���

	* @return Node * ���ؽṹ��ָ��

*/

Node *linkedListSearch(int value);
