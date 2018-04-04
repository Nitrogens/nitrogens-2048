#include "headers/io.h"
#include "headers/game.h"

unsigned int matrix[4][4];
unsigned int score, totalScore;

int main(void)
{
	initializeGame();
	
	printUI();
	
	Sleep(1000);
	
	moveNumber(right);
	
	printUI();
	
	return 0;
}

