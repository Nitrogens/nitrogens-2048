#include "headers/io.h"
#include "headers/file.h"

extern unsigned int matrix[4][4];
extern unsigned int score, maxScore, delta;
extern struct Node *head, *last;

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
	printf("��S���浵��R������\n");
	printf("��P���浵���˳�����L��ֱ���˳�\n");
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
    printf("|   A   |        ��ʼ��Ϸ       |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   B   |         ���а�        |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   C   |        ��Ϸ˵��       |\n");
    printf("|       |                       |\n");
    printf("+-------+-------+-------+-------+\n");
    printf("|       |                       |\n");
    printf("|   D   |        �˳���Ϸ       |\n");
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
    printf("|               ���а�              |\n");
    printf("|                                   |\n");
    printf("+--------+---------------+----------+\n");
    printf("|  ����  |      ����     |   �÷�   |\n");

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
    printf("|              ��Ϸ˵��             |\n");
    printf("|                                   |\n");
    printf("+-----------------------------------+\n");
    printf("|1. ������������ƶ���              |\n");
    printf("+-----------------------------------+\n");
    printf("|2. ��S��������Ϸ����R����ȡ��Ϸ��  |\n");
    printf("+-----------------------------------+\n");
    printf("|3. ��P���浵���˳�����L��ֱ���˳���|\n");
    printf("+-----------------------------------+\n");
    printf("|4. ÿ�ɹ��ϲ�һ�����֣��ּܷ����µ�|\n");
    printf("|   ���ֵ�ֵ��                      |\n");
    printf("+-----------------------------------+\n");
    printf("|5. �ϲ���2048����Ϸʤ����          |\n");
    printf("+-----------------------------------+\n");
    printf("|6. ÿ�������޷��ƶ�ʱ����Ϸʧ�ܣ�|\n");
    printf("+-----------------------------------+\n");
    printf("|7. ף����Ϸ��죡                  |\n");
    printf("+-----------------------------------+\n");
}
