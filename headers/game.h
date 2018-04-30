#include "standard.h"

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

/*
	* 
	* Function isFail 
	* �����ж���Ϸ�Ƿ�ʧ�� 
	
	* @return bool
	* true��ʾʧ�� 
	
*/
bool isFail();
