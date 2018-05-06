#include "headers/io.h"

extern unsigned int matrix[4][4];
extern unsigned int score, maxScore, delta;

void printNumber(int number)
{
	int temp = number;	//��ʱ�����Ҫ����λ�������� 
	int numberOfDigits = 0;	//����λ�� 
	
	//��������λ�� 
	while(temp)
	{
		numberOfDigits++;
		temp /= 10;	
	}
	
	switch(numberOfDigits)
	{
		case 0:
			printf("       ");	//���7���ո�
			break;
		case 1:
			printf("   %d   ", number);
			break;
		case 2:
			printf("  %d %d  ", number/10, number%10);	//ȡ���ֵĸ���λ�� 
			break;
		case 3:
			printf("  %d  ", number);
			break;
		case 4:
			printf("%d %d %d %d", number/1000, number/100%10, number/10%10, number%10);	//ȡ���ֵĸ���λ�� 
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
			printNumber(matrix[i][j]);	//������ĸ��и������ 
			printf("|");
		}
		printf("\n");
		printf("|       |       |       |       |\n");
		if(i < 3)
			printf("+-------+-------+-------+-------+\n");
	}
	printf("+-------+-------+-------+-------+\n");
	printf("�÷֣�%u(+%u)\n", score, delta);
	printf("��ߵ÷֣�%u\n", maxScore);
}
