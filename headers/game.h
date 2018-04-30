#include "standard.h"

/*
	* 
	* Function initializeGame
	* 用于初始化游戏 
	
	* @return void
	
*/
void initializeGame();

/*
	* 
	* Function generateNumber
	* 用于在随机位置生成数字（2或4） 
	
	* @param int frequency 生成数字的个数 
	
	* @return void
	
*/
void generateNumber(int frequency);

/*
	* 
	* Function moveAndMergeNumber
	* 用于在按下键盘之后，按照游戏规则移动及合并数字
	
	* @param enum directions direction 方向
	
	* @return void
	
*/
void moveAndMergeNumber(enum directions direction);

/*
	* 
	* Function isFull
	* 用于判断矩阵是否已满 
	
	* @return bool
	* true表示已满 
	
*/
bool isFull();

/*
	* 
	* Function isFail 
	* 用于判断游戏是否失败 
	
	* @return bool
	* true表示失败 
	
*/
bool isFail();
