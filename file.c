#include "headers/file.h"

extern unsigned int matrix[4][4];
extern unsigned int score, delta, status;

void saveGame()
{
	FILE *fp;
	fp = fopen("data/save", "wb+");
	
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
	fp = fopen("data/save", "rb+");
	
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
