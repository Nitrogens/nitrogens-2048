#include "headers/game.h"

extern unsigned int matrix[4][4];
extern unsigned int score, delta, status;
extern bool isWin;

void initializeGame()
{
	memset(matrix, 0, sizeof(matrix));	//清空矩阵数组并将每个元素初始化为0
	generateNumber(2);	//在随机位置生成两次数字
	status = 0;
	score = 0;
	delta = 0;
}

void generateNumber(int frequency)
{
	int i;
	unsigned int x, y, number;

	srand(time(NULL));	//设置随机数种子

	for(i = 0; i < frequency; i++)
	{
		x = rand() % 4;	//生成0~3的随机数
		y = rand() % 4;
		number = (rand() % 10 <= 6)?2:4;	//随机生成2或4，设定生成2的概率为0.7

		if(matrix[x][y] != 0)
		{
			i--;	//实际上是抵消了后续的i++运算，也就是说再次开始本回合循环
			continue;
		}

		matrix[x][y] = number;
	}
}

void moveAndMergeNumber(enum directions direction)
{
	int container[4];	//存放移动后数字的队列数组
	int containerAfterMerge[4];	//存放合并后数字的队列数组
	int i, j, flag, flagAfterMerge;	//flag和flagAfterMerge分别表示 移动后数字的队列 和 合并后数字的队列 中下一个数的位置
	bool isFail = true;	//标记是否任何方块都未合成

	delta = 0;

	switch(direction)
	{
		case up:	//键盘按 上方向键
			for(j = 0; j < 4; j++)	//从左到右遍历每一列
			{
				flag = 0;	//队列中下一个数的位置归零
				flagAfterMerge = 0;	//队列中下一个数的位置归零
				memset(container, 0, sizeof(container));	//清空队列数组
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//清空队列数组
				for(i = 0; i < 4; i++)	//从上到下
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//开始合并操作
				for(i = 0; i < flag; i++)
				{
					if(i + 1 < flag && container[i] == container[i + 1] && container[i] != 0)	//发现相同的数字
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[i] * 2;	//将合并后的数字加入到 合并后数字的队列数组 中
						if(containerAfterMerge[flagAfterMerge] == 2048)	//出现2048即代表游戏胜利
							isWin = true;
						delta += container[i] * 2;	//加分大小
						i++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[i];	//不满足合并条件，则将原数原样加入到 合并后数字的队列数组 中
					}
					flagAfterMerge++;
				}

				//重新生成该列
				for(i = 0; i < flagAfterMerge; i++)
				{
					matrix[i][j] = containerAfterMerge[i];
				}
				for(i = flagAfterMerge; i < 4; i++)
				{
					matrix[i][j] = 0;
				}

				//记录状态
				if(isFail)
				{
					if(status & (1 << 3))
						status -= (1 << 3);
				}
				else
					status |= (1 << 3);
			}
			break;

		case down:	//键盘按 下方向键
			for(j = 0; j < 4; j++)	//从左到右遍历每一列
			{
				flag = 0;	//队列中下一个数的位置归零
				flagAfterMerge = 0;	//队列中下一个数的位置归零
				memset(container, 0, sizeof(container));	//清空队列数组
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//清空队列数组
				for(i = 3; i >= 0; i--)	//从下到上
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//开始合并操作
				for(i = 0; i < flag; i++)
				{
					if(i + 1 < flag && container[i] == container[i + 1] && container[i] != 0)	//发现相同的数字
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[i] * 2;	//将合并后的数字加入到 合并后数字的队列数组 中
						if(containerAfterMerge[flagAfterMerge] == 2048)	//出现2048即代表游戏胜利
							isWin = true;
						delta += container[i] * 2;	//加分大小
						i++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[i];	//不满足合并条件，则将原数原样加入到 合并后数字的队列数组 中
					}
					flagAfterMerge++;
				}

				//重新生成该列
				for(i = 0; i < 4 - flagAfterMerge; i++)
				{
					matrix[i][j] = 0;
				}
				for(i = 4 - flagAfterMerge; i < 4; i++)
				{
					matrix[i][j] = containerAfterMerge[3 - i];
				}

				//记录状态
				if(isFail)
				{
					if(status & (1 << 2))
						status -= (1 << 2);
				}
				else
					status |= (1 << 2);
			}
			break;

			case left:	//键盘按 左方向键
			for(i = 0; i < 4; i++)	//从上到下遍历每一行
			{
				flag = 0;	//队列中下一个数的位置归零
				flagAfterMerge = 0;	//队列中下一个数的位置归零
				memset(container, 0, sizeof(container));	//清空队列数组
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//清空队列数组
				for(j = 0; j < 4; j++)	//从左到右
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//开始合并操作
				for(j = 0; j < flag; j++)
				{
					if(j + 1 < flag && container[j] == container[j + 1] && container[j] != 0)	//发现相同的数字
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[j] * 2;	//将合并后的数字加入到 合并后数字的队列数组 中
						if(containerAfterMerge[flagAfterMerge] == 2048)	//出现2048即代表游戏胜利
							isWin = true;
						delta += container[j] * 2;	//加分大小
						j++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[j];	//不满足合并条件，则将原数原样加入到 合并后数字的队列数组 中
					}
					flagAfterMerge++;
				}

				//重新生成该行
				for(j = 0; j < flagAfterMerge; j++)
				{
					matrix[i][j] = containerAfterMerge[j];
				}
				for(j = flagAfterMerge; j < 4; j++)
				{
					matrix[i][j] = 0;
				}

				//记录状态
				if(isFail)
				{
					if(status & (1 << 1))
						status -= (1 << 1);
				}
				else
					status |= (1 << 1);
			}
			break;

			case right:	//键盘按 右方向键
			for(i = 0; i < 4; i++)	//从上到下遍历每一行
			{
				flag = 0;	//队列中下一个数的位置归零
				flagAfterMerge = 0;	//队列中下一个数的位置归零
				memset(container, 0, sizeof(container));	//清空队列数组
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//清空队列数组
				for(j = 3; j >= 0; j--)	//从右到左
				{
					if(matrix[i][j] > 0)	//如果存在数字（即非零）就把该数放入队列数组中
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//开始合并操作
				for(j = 0; j < flag; j++)
				{
					if(j + 1 < flag && container[j] == container[j + 1] && container[j] != 0)	//发现相同的数字
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[j] * 2;	//将合并后的数字加入到 合并后数字的队列数组 中
						if(containerAfterMerge[flagAfterMerge] == 2048)	//出现2048即代表游戏胜利
							isWin = true;
						delta += container[j] * 2;	//加分大小
						j++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[j];	//不满足合并条件，则将原数原样加入到 合并后数字的队列数组 中
					}
					flagAfterMerge++;
				}

				//重新生成该行
				for(j = 0; j < 4 - flagAfterMerge; j++)
				{
					matrix[i][j] = 0;
				}
				for(j = 4 - flagAfterMerge; j < 4; j++)
				{
					matrix[i][j] = containerAfterMerge[3 - j];
				}

				//记录状态
				if(isFail)
				{
					if(status & 1)
						status -= 1;
				}
				else
					status |= 1;
			}
			break;
	}

	score += delta;	//根据新合成出的方块的值进行加分

}

bool isFull()
{
	int i, j;
	bool isDone = false;	//标记是否不为空
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(matrix[i][j] == 0)	//发现空的格
			{
				isDone = true;
				break;
			}
		}
		if(isDone)
			break;
	}
	if(!isDone)
		return true;
	else
		return false;
}
