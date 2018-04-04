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

void moveNumber(enum directions direction)
{
	int container[4];	//������ֵĶ������� 
	unsigned int i, j, k, flag;	//flag��ʾ��������һ������λ�� 
	
	switch(direction)
	{
		case up:	//���̰� �Ϸ���� 
			for(j=0; j<4; j++)	//�����ұ���ÿһ�� 
			{
				flag = 0;	//��������һ������λ�ù��� 
				memset(container, 0, sizeof(container));	//��ն������� 
				for(i=0; i<4; i++)	//���ϵ��� 
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ���������������� 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//�������ɸ��� 
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
			
		case down:	//���̰� �·���� 
			for(j=0; j<4; j++)	//�����ұ���ÿһ�� 
			{
				flag = 0;	//��������һ������λ�ù��� 
				memset(container, 0, sizeof(container));	//��ն������� 
				for(i=0; i<4; i++)	//���ϵ��� 
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ���������������� 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//�������ɸ��� 
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
			
			case left:	//���̰� ����� 
			for(i=0; i<4; i++)	//���ϵ��±���ÿһ�� 
			{
				flag = 0;	//��������һ������λ�ù��� 
				memset(container, 0, sizeof(container));	//��ն������� 
				for(j=0; j<4; j++)	//������ 
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ���������������� 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//�������ɸ��� 
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
			
			case right:	//���̰� �ҷ���� 
			for(i=0; i<4; i++)	//���ϵ��±���ÿһ�� 
			{
				flag = 0;	//��������һ������λ�ù��� 
				memset(container, 0, sizeof(container));	//��ն������� 
				for(j=0; j<4; j++)	//������ 
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ���������������� 
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}
				//�������ɸ��� 
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
