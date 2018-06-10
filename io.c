#include "headers/io.h"
#include "headers/file.h"

extern unsigned int matrix[4][4];
extern unsigned int score, maxScore, delta;
extern struct Node *head, *last;

void printNumber(int number)
{
	int temp = number;	//临时存放需要计算位数的数字
	int numberOfDigits = 0;	//数字位数

	//计算数字位数
	while(temp)
	{
		numberOfDigits++;
		temp /= 10;
	}

	switch(numberOfDigits)
	{
		case 0:
			printf("       ");	//输出7个空格
			break;
		case 1:
			printf("   %d   ", number);
			break;
		case 2:
			printf("  %d %d  ", number/10, number%10);	//取数字的各个位数
			break;
		case 3:
			printf("  %d  ", number);
			break;
		case 4:
			printf("%d %d %d %d", number/1000, number/100%10, number/10%10, number%10);	//取数字的各个位数
			break;
	}
}

void printUI(void)
{
	unsigned int i, j;
	system("cls");
	printf("+-------+-------+-------+-------+\n");
	for(i = 0; i < 4; i++)
	{
		printf("|       |       |       |       |\n");
		printf("|");
		for(j = 0; j < 4; j++)
		{
			printNumber(matrix[i][j]);	//将矩阵的各行各列输出
			printf("|");
		}
		printf("\n");
		printf("|       |       |       |       |\n");
		if(i < 3)
			printf("+-------+-------+-------+-------+\n");
	}
	printf("+-------+-------+-------+-------+\n");
	printf("得分：%u(+%u)\n", score, delta);
	printf("按S键存档，R键读档\n");
	printf("按P键存档并退出，按L键直接退出\n");
}

void printGuidance()
{
    system("cls");
    printf("+-------+-------+-------+-------+\n");
    printf("|                               |\n");
    printf("|   2       0       4       8   |\n");
    printf("|                               |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   A   |        开始游戏       |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   B   |         排行榜        |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   C   |        游戏说明       |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   D   |        退出游戏       |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("Copyright 2018 Nitrogens(Mingjie XU).\n");
    printf("Licensed under the MIT License.\n");
}

void printRankList()
{
    Node * iterator;

    system("cls");
    printf("+--------+----------------+---------+\n");
    printf("|                                   |\n");
    printf("|               排行榜              |\n");
    printf("|                                   |\n");
    printf("+--------+---------------+----------+\n");
    printf("|  排名  |      姓名     |   得分   |\n");

    getRankList();

    iterator = head->next;

    while(iterator != head)
    {
        printf("+--------+---------------+----------+\n");
        printf("|%8d|%15s|%10d|\n", iterator->value.rank, iterator->value.name, iterator->value.score);
        iterator = iterator->next;
    }

    printf("+--------+---------------+----------+\n");
}

void printInstruction()
{
    system("cls");
    printf("+-----------------------------------+\n");
    printf("|                                   |\n");
    printf("|              游戏说明             |\n");
    printf("|                                   |\n");
    printf("+-----------------------------------+\n");
    printf("|1. 按方向键控制移动；              |\n");
    printf("+-----------------------------------+\n");
    printf("|2. 按S来保存游戏，按R来读取游戏；  |\n");
    printf("+-----------------------------------+\n");
    printf("|3. 按P键存档并退出，按L键直接退出；|\n");
    printf("+-----------------------------------+\n");
    printf("|4. 每成功合并一组数字，总分加上新的|\n");
    printf("|   数字的值；                      |\n");
    printf("+-----------------------------------+\n");
    printf("|5. 合并出2048，游戏胜利；          |\n");
    printf("+-----------------------------------+\n");
    printf("|6. 每个方向都无法移动时，游戏失败；|\n");
    printf("+-----------------------------------+\n");
    printf("|7. 祝您游戏愉快！                  |\n");
    printf("+-----------------------------------+\n");
}
