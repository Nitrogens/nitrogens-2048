#include "io.h"
extern unsigned int matrix[4][4];
extern unsigned int score, totalScore;
void printNumber(int number)
{
	int temp = number;
	int numberOfDigits = 0;
	
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
			printf("  %d %d  ", number/10, number%10);
			break;
		case 3:
			printf("  %d  ", number);
			break;
		case 4:
			printf("%d %d %d %d", number/1000, number/100%10, number/10%10, number%10);
			break;
	}
}
void printUI()
{
	unsigned int i, j;
	system("cls");
	printf("+-------+-------+-------+-------+\n");
	for(i=0; i<4; i++)
	{
		printf("|       |       |       |       |\n");
		printf("|");
		for(j=0; j<4; j++)
		{
			printNumber(matrix[i][j]);
			printf("|");
		}
		printf("\n");
		printf("|       |       |       |       |\n");
		if(i < 3)
			printf("+-------+-------+-------+-------+\n");
	}
	printf("+-------+-------+-------+-------+\n");
	printf("Score: %u\n", score);
	printf("Total Score: %u\n", totalScore);
}
