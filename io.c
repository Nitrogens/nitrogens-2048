#include "headers/io.h"

extern unsigned int matrix[4][4];
extern unsigned int score, maxScore, delta;

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
	printf("最高得分：%u\n", maxScore);
}
