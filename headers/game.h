#include "standard.h"

#ifndef directions
enum directions
{
	up,
	right,
	down,
	left 
};
#endif

/*
	* 
	* Function initializeGame
	* ���ڳ�ʼ����Ϸ 
	
	* @return void
	
*/
void initializeGame();

/*
	* 
	* Function generateNumber
	* ���������λ���������֣�2��4�� 
	
	* @param int frequency �������ֵĸ��� 
	
	* @return void
	
*/
void generateNumber(int frequency);

/*
	* 
	* Function moveAndMergeNumber
	* �����ڰ��¼���֮�󣬰�����Ϸ�����ƶ����ϲ�����
	
	* @param enum directions direction ����
	
	* @return void
	
*/
void moveAndMergeNumber(enum directions direction);

/*
	* 
	* Function isFull
	* �����жϾ����Ƿ����� 
	
	* @return bool
	* true��ʾ���� 
	
*/
bool isFull();
