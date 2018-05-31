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
        printf("�浵ʧ�ܣ�\n");
        return;
    }

	//����ǰ�ľ���д���ļ�
	fwrite(matrix, sizeof(matrix), 1, fp);
	//����ǰ�ĵ÷�д���ļ�
	fwrite(&score, sizeof(score), 1, fp);
	//����һ�ε÷ֵı仯���д���ļ�
	fwrite(&delta, sizeof(delta), 1, fp);
	//����ǰ��״̬����ĳ�������Ƿ���Բ�����д���ļ�
	fwrite(&status, sizeof(status), 1, fp);

	fclose(fp);
}

void readGame()
{
	FILE *fp;
	fp = fopen("data/save", "rb");

	if(fp == NULL)
    {
        printf("����ʧ�ܣ�\n");
        return;
    }

	//�����ļ��д洢�ľ���
	fread(matrix, sizeof(matrix), 1, fp);
	//�����ļ��д洢�ĵ÷�
	fread(&score, sizeof(score), 1, fp);
	//�����ļ��д洢����һ�ε÷ֵı仯���
	fread(&delta, sizeof(delta), 1, fp);
	//�����ļ��д洢��״̬����ĳ�������Ƿ���Բ�����
	fread(&status, sizeof(status), 1, fp);

	fclose(fp);
}

void getRankList()
{
    FILE *fp;
    //�洢���а�һ�����ݵĽṹ��
    rankListLine line;

    //������������������ԭ������
    if(isLinkedListInited)
        linkedListClear();
    else
        isLinkedListInited = true;

    linkedListInit();

    fp = fopen("data/ranklist", "r");

    //���ж�ȡ������Ϣ
    while(fscanf(fp, "%d%s%d", &line.rank, line.name, &line.score) != EOF)
    {
        linkedListInsert(line, last);
    }

    fclose(fp);
}

void updateRankList(rankListLine data)
{
    /*
        target���ڴ洢�������в���ڵ��λ��
        iterator������������ʱ�ĵ�����
        cnt���ڴ洢����
    */
    Node *target, *iterator;
    FILE *fp;
    int cnt = 1;

    getRankList();

    //�����а������������λ��
    target = linkedListSearch(data.score);

    //����ڵ�
    linkedListInsert(data, target->prev);

    //�����а�д���ļ�
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
