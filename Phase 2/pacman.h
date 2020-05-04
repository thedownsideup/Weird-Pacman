#include <windows.h>
#include <conio.h>


#define PACMAN_RADIUS 4
#define ROWS_PER_TABLE 5
#define COLUMN_PER_TABLE 6
#define CELL_WIDTH 20
#define TIME 100

//Sets console screen to full screen
//Use this function at the beginning of your program in main()
void initScreen();
//The following function manipulates cursor position
void gotoxy(int x, int y);
//This function will wait for "waitTime" milliseconds and get the new direction from the keybord
//100<waitTime<250 
//Use this function between printing the pacman shapes in a single cell
//If the direction is changed the return value is 1 else the return value is 0
int waitAndGetDirection(int waitTime, int *direction);

void drawPacman(int dx, int dy, int mouthDegree, char direction);
void clearCell(int x, int y);
void drawOpeningMouthPacman(int x, int y, char *direction);
void setNextLocation(int *x, int *y, char direction, int table[][COLUMN_PER_TABLE + 1][2]);
void printMovingPacman(int table[][COLUMN_PER_TABLE + 1][2]);
void cookie();