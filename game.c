#include "headers/game.h"

extern unsigned int matrix[4][4];
extern unsigned int score, delta, status;
extern bool isWin;

void initializeGame()
{
	memset(matrix, 0, sizeof(matrix));	//��վ������鲢��ÿ��Ԫ�س�ʼ��Ϊ0
	generateNumber(2);	//�����λ��������������
	status = 0;
	score = 0;
	delta = 0;
}

void generateNumber(int frequency)
{
	int i;
	unsigned int x, y, number;

	srand(time(NULL));	//�������������

	for(i = 0; i < frequency; i++)
	{
		x = rand() % 4;	//����0~3�������
		y = rand() % 4;
		number = (rand() % 10 <= 6)?2:4;	//�������2��4���趨����2�ĸ���Ϊ0.7

		if(matrix[x][y] != 0)
		{
			i--;	//ʵ�����ǵ����˺�����i++���㣬Ҳ����˵�ٴο�ʼ���غ�ѭ��
			continue;
		}

		matrix[x][y] = number;
	}
}

void moveAndMergeNumber(enum directions direction)
{
	int container[4];	//����ƶ������ֵĶ�������
	int containerAfterMerge[4];	//��źϲ������ֵĶ�������
	int i, j, flag, flagAfterMerge;	//flag��flagAfterMerge�ֱ��ʾ �ƶ������ֵĶ��� �� �ϲ������ֵĶ��� ����һ������λ��
	bool isFail = true;	//����Ƿ��κη��鶼δ�ϳ�

	delta = 0;

	switch(direction)
	{
		case up:	//���̰� �Ϸ����
			for(j = 0; j < 4; j++)	//�����ұ���ÿһ��
			{
				flag = 0;	//��������һ������λ�ù���
				flagAfterMerge = 0;	//��������һ������λ�ù���
				memset(container, 0, sizeof(container));	//��ն�������
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//��ն�������
				for(i = 0; i < 4; i++)	//���ϵ���
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ����������������
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//��ʼ�ϲ�����
				for(i = 0; i < flag; i++)
				{
					if(i + 1 < flag && container[i] == container[i + 1] && container[i] != 0)	//������ͬ������
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[i] * 2;	//���ϲ�������ּ��뵽 �ϲ������ֵĶ������� ��
						if(containerAfterMerge[flagAfterMerge] == 2048)	//����2048��������Ϸʤ��
							isWin = true;
						delta += container[i] * 2;	//�ӷִ�С
						i++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[i];	//������ϲ���������ԭ��ԭ�����뵽 �ϲ������ֵĶ������� ��
					}
					flagAfterMerge++;
				}

				//�������ɸ���
				for(i = 0; i < flagAfterMerge; i++)
				{
					matrix[i][j] = containerAfterMerge[i];
				}
				for(i = flagAfterMerge; i < 4; i++)
				{
					matrix[i][j] = 0;
				}

				//��¼״̬
				if(isFail)
				{
					if(status & (1 << 3))
						status -= (1 << 3);
				}
				else
					status |= (1 << 3);
			}
			break;

		case down:	//���̰� �·����
			for(j = 0; j < 4; j++)	//�����ұ���ÿһ��
			{
				flag = 0;	//��������һ������λ�ù���
				flagAfterMerge = 0;	//��������һ������λ�ù���
				memset(container, 0, sizeof(container));	//��ն�������
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//��ն�������
				for(i = 3; i >= 0; i--)	//���µ���
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ����������������
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//��ʼ�ϲ�����
				for(i = 0; i < flag; i++)
				{
					if(i + 1 < flag && container[i] == container[i + 1] && container[i] != 0)	//������ͬ������
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[i] * 2;	//���ϲ�������ּ��뵽 �ϲ������ֵĶ������� ��
						if(containerAfterMerge[flagAfterMerge] == 2048)	//����2048��������Ϸʤ��
							isWin = true;
						delta += container[i] * 2;	//�ӷִ�С
						i++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[i];	//������ϲ���������ԭ��ԭ�����뵽 �ϲ������ֵĶ������� ��
					}
					flagAfterMerge++;
				}

				//�������ɸ���
				for(i = 0; i < 4 - flagAfterMerge; i++)
				{
					matrix[i][j] = 0;
				}
				for(i = 4 - flagAfterMerge; i < 4; i++)
				{
					matrix[i][j] = containerAfterMerge[3 - i];
				}

				//��¼״̬
				if(isFail)
				{
					if(status & (1 << 2))
						status -= (1 << 2);
				}
				else
					status |= (1 << 2);
			}
			break;

			case left:	//���̰� �����
			for(i = 0; i < 4; i++)	//���ϵ��±���ÿһ��
			{
				flag = 0;	//��������һ������λ�ù���
				flagAfterMerge = 0;	//��������һ������λ�ù���
				memset(container, 0, sizeof(container));	//��ն�������
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//��ն�������
				for(j = 0; j < 4; j++)	//������
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ����������������
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//��ʼ�ϲ�����
				for(j = 0; j < flag; j++)
				{
					if(j + 1 < flag && container[j] == container[j + 1] && container[j] != 0)	//������ͬ������
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[j] * 2;	//���ϲ�������ּ��뵽 �ϲ������ֵĶ������� ��
						if(containerAfterMerge[flagAfterMerge] == 2048)	//����2048��������Ϸʤ��
							isWin = true;
						delta += container[j] * 2;	//�ӷִ�С
						j++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[j];	//������ϲ���������ԭ��ԭ�����뵽 �ϲ������ֵĶ������� ��
					}
					flagAfterMerge++;
				}

				//�������ɸ���
				for(j = 0; j < flagAfterMerge; j++)
				{
					matrix[i][j] = containerAfterMerge[j];
				}
				for(j = flagAfterMerge; j < 4; j++)
				{
					matrix[i][j] = 0;
				}

				//��¼״̬
				if(isFail)
				{
					if(status & (1 << 1))
						status -= (1 << 1);
				}
				else
					status |= (1 << 1);
			}
			break;

			case right:	//���̰� �ҷ����
			for(i = 0; i < 4; i++)	//���ϵ��±���ÿһ��
			{
				flag = 0;	//��������һ������λ�ù���
				flagAfterMerge = 0;	//��������һ������λ�ù���
				memset(container, 0, sizeof(container));	//��ն�������
				memset(containerAfterMerge, 0, sizeof(containerAfterMerge));	//��ն�������
				for(j = 3; j >= 0; j--)	//���ҵ���
				{
					if(matrix[i][j] > 0)	//����������֣������㣩�ͰѸ����������������
					{
						container[flag] = matrix[i][j];
						flag++;
					}
				}

				//��ʼ�ϲ�����
				for(j = 0; j < flag; j++)
				{
					if(j + 1 < flag && container[j] == container[j + 1] && container[j] != 0)	//������ͬ������
					{
						isFail = false;
						containerAfterMerge[flagAfterMerge] = container[j] * 2;	//���ϲ�������ּ��뵽 �ϲ������ֵĶ������� ��
						if(containerAfterMerge[flagAfterMerge] == 2048)	//����2048��������Ϸʤ��
							isWin = true;
						delta += container[j] * 2;	//�ӷִ�С
						j++;
					}
					else
					{
						containerAfterMerge[flagAfterMerge] = container[j];	//������ϲ���������ԭ��ԭ�����뵽 �ϲ������ֵĶ������� ��
					}
					flagAfterMerge++;
				}

				//�������ɸ���
				for(j = 0; j < 4 - flagAfterMerge; j++)
				{
					matrix[i][j] = 0;
				}
				for(j = 4 - flagAfterMerge; j < 4; j++)
				{
					matrix[i][j] = containerAfterMerge[3 - j];
				}

				//��¼״̬
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

	score += delta;	//�����ºϳɳ��ķ����ֵ���мӷ�

}

bool isFull()
{
	int i, j;
	bool isDone = false;	//����Ƿ�Ϊ��
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(matrix[i][j] == 0)	//���ֿյĸ�
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
