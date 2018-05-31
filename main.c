#include "headers/io.h"
#include "headers/game.h"
#include "headers/file.h"

//���ڴ洢�����ֵ 
unsigned int matrix[4][4];
/*
	status��ÿһλ�ֱ����ڴ洢ĳһ�����Ƿ��ܹ��ϳɣ�1��ʾ���ԣ�״̬ѹ���� 
	score���ڴ洢��ǰ�ֵķ���
	maxScore���ڴ洢��߷���
	dalta�洢���غϵĵ÷� 
*/
unsigned int score, maxScore, delta, status;
//����Ƿ�ʤ�� 
bool isWin = false; 

int main(void)
{
	//�洢����ļ��̰������������Ҫ���μ�⣬��ĸ����Ҫһ�μ�� 
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
				case 224:	//�������Ҫ���μ�� 
					ch2 = getch();
					switch(ch2)
					{
						case 72:	//�Ϸ����
							moveAndMergeNumber(up);
						break;
						case 80:	//�·���� 
							moveAndMergeNumber(down);
						break; 
						case 75:	//�����
							moveAndMergeNumber(left);
						break;
						case 77:	//�ҷ���� 
							moveAndMergeNumber(right);
						break; 
					}
				break;
				case 115:	//����"S"�� 
					saveGame();	//�浵 
					continue;
				break;
				case 114:	//����"R"�� 
					readGame();	//����
					continue;
				break; 
			}
			
			if(!isFull())
				generateNumber(1);	//�����λ��������������
			else
				if(status == 0)
					break; 
		}
	}
	
	if(!isWin)
		printf("��Ϸʧ�ܣ�");
	else
		printf("��Ӯ�ˣ�");
	
	return 0;
}

