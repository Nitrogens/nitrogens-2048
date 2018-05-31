#include "headers/file.h"

extern unsigned int matrix[4][4];
extern unsigned int score, delta, status;

void saveGame()
{
	FILE *fp;
	fp = fopen("data/save", "wb+");
	
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
	fp = fopen("data/save", "rb+");
	
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
