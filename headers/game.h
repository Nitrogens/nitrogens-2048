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
	* Function moveNumber
	* �����ڰ��¼���֮�󣬰�����Ϸ�����ƶ�����
	
	* @param enum directions direction ����
	
	* @return void
	
*/
void moveNumber(enum directions direction);

/*
	* 
	* Function mergeNumber
	* �����ڰ��¼��̼������ƶ�֮�󣬰�����Ϸ����ϲ�����
	
	* @param enum directions direction ����
	
	* @return void
	
*/
void mergeNumber(enum directions direction);

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
