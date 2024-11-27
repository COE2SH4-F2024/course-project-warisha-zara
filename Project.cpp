#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

//bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM -> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    // placed object in heap, go delete it in cleanup

    myGM = new GameMechs();
    myPlayer = new Player(myGM); // nullptr is a placeholder
    //char Gameboard[30][15];
    //exitFlag = false;
}

void GetInput(void)
{
//    char userInput = myGM-> getInput();
//    if (userInput == ' '){
//         myGM->setExitTrue();
//    }
    myGM-> collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    // if (myPlayer->getPlayerPos().pos->x == 0) {
    //     myGM->setLoseFlag();
    //     myGM->setExitTrue();
    // }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos playerPos = myPlayer -> getPlayerPos();
    //  1. clear the current screen contents
    //WILL NEED TP IMPLEMENT YOUR COPY ASSIGNMENT OPERATOR
    //TO MAKE THIS LINE WORK
    //MacUILib_clearScreen();
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i; //==y
    int j; //==x
    int k;

    for (i = 0; i < myGM -> getBoardSizeX(); i++){
        for (j = 0; j < myGM -> getBoardSizeY(); j++){
            if (i == 0 || j == 0 || i == myGM -> getBoardSizeX() -1 || j ==  myGM -> getBoardSizeY()-1){
                // Gameboard[i][j] = '#';
                // MacUILib_printf("%c", board[i][j]);
                MacUILib_printf("#"); // Border symbol
            }
            else if (i == playerPos.pos->x && j == playerPos.pos->y){
                //board[i][j]= playerPos.symbol;
                MacUILib_printf("%c", playerPos.symbol);
            }
            else {
                MacUILib_printf(" ");
            }
            // else {
            //     //empty space being printed
            //     //int isItem =0;
            //     board[i][j] = ' ';
            //     for (k=0; k < ITEM_BIN_SIZE; k++){
            //         if(i == itemBin[k].x && j == itemBin[k].y){
            //             board[i][j] = itemBin[k].symbol;
            //             //isItem =1;
            //             break;
            //         }
            //     }                
            //     MacUILib_printf("%c", board[i][j]);

            // }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\n"); //Move to next line after printed each row
    MacUILib_printf("Player [x,y,sym] = [%d,%d,%c]\n", playerPos.pos->x, playerPos.pos->y,playerPos.symbol);    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;  
    delete myGM;

    MacUILib_uninit();
}
