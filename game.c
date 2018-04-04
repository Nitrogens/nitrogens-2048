#include "headers/game.h"

extern unsigned int matrix[4][4];

void initializeGame()
{
	memset(matrix, 0, sizeof(matrix));	//清空矩阵数组并将每个元素初始化为0 
	generateNumber(2);	//在随机位置生成两次数字 
}

void generateNumber(int frequency)
{
	int i;
	unsigned int x, y, number;
	
	srand(time(NULL));	//设置随机数种子
	
	for(i=0; i<frequency; i++)
	{
		x = rand() % 3;	//生成0~3的随机数 
		y = rand() % 3;
		number = (rand() % 10 <= 7)?2:4;	//随机生成2或4，设定生成2的概率为0.7 
		
		if(matrix[x][y] != 0)
		{
			i--;	//实际上是抵消了后续的i++运算，也就是说再次开始本回合循环 
			continue;
		} 
		
		matrix[x][y] = number; 
	}
}
