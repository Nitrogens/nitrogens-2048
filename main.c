#include "headers/io.h"
#include "headers/game.h"
#include "headers/file.h"

//用于存储方块的值 
unsigned int matrix[4][4];
/*
	status的每一位分别用于存储某一方向是否能够合成，1表示可以（状态压缩） 
	score用于存储当前局的分数
	maxScore用于存储最高分数
	dalta存储本回合的得分 
*/
unsigned int score, maxScore, delta, status;
//标记是否胜利 
bool isWin = false; 

int main(void)
{
	//存储读入的键盘按键，方向键需要二次检测，字母仅需要一次检测 
	int ch1, ch2;
	
	initializeGame();
	
	while(true)
	{
		printUI();
		
		if(isWin)
			break;
		
		if(ch1 = getch())
		{
			switch(ch1)
			{
				case 224:	//方向键需要二次检测 
					ch2 = getch();
					switch(ch2)
					{
						case 72:	//上方向键
							moveAndMergeNumber(up);
						break;
						case 80:	//下方向键 
							moveAndMergeNumber(down);
						break; 
						case 75:	//左方向键
							moveAndMergeNumber(left);
						break;
						case 77:	//右方向键 
							moveAndMergeNumber(right);
						break; 
					}
				break;
				case 115:	//按下"S"键 
					saveGame();	//存档 
					continue;
				break;
				case 114:	//按下"R"键 
					readGame();	//读档
					continue;
				break; 
			}
			
			if(!isFull())
				generateNumber(1);	//在随机位置生成两次数字
			else
				if(status == 0)
					break; 
		}
	}
	
	if(!isWin)
		printf("游戏失败！");
	else
		printf("你赢了！");
	
	return 0;
}

