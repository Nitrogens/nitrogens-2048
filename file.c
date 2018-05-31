#include "headers/file.h"

extern unsigned int matrix[4][4];
extern unsigned int score, delta, status;
Node *head, *last;

bool isLinkedListInited = false;

void saveGame()
{
	FILE *fp;
	fp = fopen("data/save", "wb");

	if(fp == NULL)
    {
        printf("存档失败！\n");
        return;
    }

	//将当前的矩阵写入文件
	fwrite(matrix, sizeof(matrix), 1, fp);
	//将当前的得分写入文件
	fwrite(&score, sizeof(score), 1, fp);
	//将上一次得分的变化情况写入文件
	fwrite(&delta, sizeof(delta), 1, fp);
	//将当前的状态（即某个方向是否可以操作）写入文件
	fwrite(&status, sizeof(status), 1, fp);

	fclose(fp);
}

void readGame()
{
	FILE *fp;
	fp = fopen("data/save", "rb");

	if(fp == NULL)
    {
        printf("读档失败！\n");
        return;
    }

	//读入文件中存储的矩阵
	fread(matrix, sizeof(matrix), 1, fp);
	//读入文件中存储的得分
	fread(&score, sizeof(score), 1, fp);
	//读入文件中存储的上一次得分的变化情况
	fread(&delta, sizeof(delta), 1, fp);
	//读入文件中存储的状态（即某个方向是否可以操作）
	fread(&status, sizeof(status), 1, fp);

	fclose(fp);
}

void getRankList()
{
    FILE *fp;
    //存储排行榜一行数据的结构体
    rankListLine line;

    //如果创建过链表，则清空原有链表
    if(isLinkedListInited)
        linkedListClear();
    else
        isLinkedListInited = true;

    linkedListInit();

    fp = fopen("data/ranklist", "r");

    //逐行读取排行信息
    while(fscanf(fp, "%d%s%d", &line.rank, line.name, &line.score) != EOF)
    {
        linkedListInsert(line, last);
    }

    fclose(fp);
}

void updateRankList(rankListLine data)
{
    /*
        target用于存储在链表中插入节点的位置
        iterator用作遍历链表时的迭代器
        cnt用于存储排名
    */
    Node *target, *iterator;
    FILE *fp;
    int cnt = 1;

    getRankList();

    //在排行榜中搜索插入的位置
    target = linkedListSearch(data.score);

    //插入节点
    linkedListInsert(data, target->prev);

    //将排行榜写入文件
    fp = fopen("data/ranklist", "w");

    iterator = head->next;

    while(iterator != head)
    {
        fprintf(fp, "%d %s %d\n", cnt, iterator->value.name, iterator->value.score);
        iterator = iterator->next;
        cnt++;
    }

    fclose(fp);
}
