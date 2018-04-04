#include "headers/game.h"

extern unsigned int matrix[4][4];

void initializeGame()
{
	memset(matrix, 0, sizeof(matrix));	//��վ������鲢��ÿ��Ԫ�س�ʼ��Ϊ0 
	generateNumber(2);	//�����λ�������������� 
}

void generateNumber(int frequency)
{
	int i;
	unsigned int x, y, number;
	
	srand(time(NULL));	//�������������
	
	for(i=0; i<frequency; i++)
	{
		x = rand() % 3;	//����0~3������� 
		y = rand() % 3;
		number = (rand() % 10 <= 7)?2:4;	//�������2��4���趨����2�ĸ���Ϊ0.7 
		
		if(matrix[x][y] != 0)
		{
			i--;	//ʵ�����ǵ����˺�����i++���㣬Ҳ����˵�ٴο�ʼ���غ�ѭ�� 
			continue;
		} 
		
		matrix[x][y] = number; 
	}
}
