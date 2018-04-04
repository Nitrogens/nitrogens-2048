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

void moveNumber(enum directions direction)
{
	int container[4];	//存放数字的队列数组 
	unsigned int i, j, k, flag;	//flag表示队列中下一个数的位置 
	
	switch(direction)
	{
		case up:	//键盘按 上方向键 
			for(j=0; j<4; j++)	//从左到右遍历每一列 
			{
				flag = 0;	//队列中下一个数的位置归零 
				memset(container, 0, sizeof(container));	//清空队列数组 
				for(i=0; i<4; i++)	//从上到下 
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//重新生成该列 
				for(i=0; i<flag; i++)
				{
					matrix[i][j] = container[i];
				}
				for(i=flag; i<4; i++)
				{
					matrix[i][j] = 0;
				}
			}
			break; 
			
		case down:	//键盘按 下方向键 
			for(j=0; j<4; j++)	//从左到右遍历每一列 
			{
				flag = 0;	//队列中下一个数的位置归零 
				memset(container, 0, sizeof(container));	//清空队列数组 
				for(i=0; i<4; i++)	//从上到下 
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//重新生成该列 
				for(i=0; i<=3-flag; i++)
				{
					matrix[i][j] = 0;
				}
				for(i=4-flag; i<4; i++)
				{
					matrix[i][j] = container[i-4+flag];
				}
			}
			break; 
			
			case left:	//键盘按 左方向键 
			for(i=0; i<4; i++)	//从上到下遍历每一行 
			{
				flag = 0;	//队列中下一个数的位置归零 
				memset(container, 0, sizeof(container));	//清空队列数组 
				for(j=0; j<4; j++)	//从左到右 
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//重新生成该行 
				for(j=0; j<flag; j++)
				{
					matrix[i][j] = container[j];
				}
				for(j=flag; j<4; j++)
				{
					matrix[i][j] = 0;
				}
			}
			break; 
			
			case right:	//键盘按 右方向键 
			for(i=0; i<4; i++)	//从上到下遍历每一行 
			{
				flag = 0;	//队列中下一个数的位置归零 
				memset(container, 0, sizeof(container));	//清空队列数组 
				for(j=0; j<4; j++)	//从左到右 
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//重新生成该行 
				for(j=0; j<=3-flag; j++)
				{
					matrix[i][j] = 0;
				}
				for(j=4-flag; j<4; j++)
				{
					matrix[i][j] = container[j-4+flag];
				}
			}
			break; 
	}
	
} 
