//------------------------------------------------------------------------------
// file: snakemain.cpp
// by: K.Gomez
// org: COP 2001, Spring 2020
// for: polishing the snake program by using classes with member methods, along with pointers to simplify the snake main and make it shorter
//------------------------------------------------------------------------------
#include <iostream>
#include <time.h> //time
#include <stdlib.h> //srand,rand

#include "snake.h"    

using namespace std;

/*

/0<-[23,10]-><-[24,10]-><-[25,10]->/0   /0<-[25,11]->/0

       ^                     ^                  ^
       head                tail              prevTail

*/





//----------------------------------------
// function prototypes
//---------------------------------------
void render(HDC hdc, Snake snake, Block food);
void update(Snake& snake,Block& food);
Block nextFood(Snake snake);

int main() { // start program
   
    HDC drawing = initConsole(CONSOLE_WIDTH, CONSOLE_HEIGHT, DRAWING_SCALE);

    drawBorders(drawing, CONSOLE_WIDTH, CONSOLE_HEIGHT, DRAWING_SCALE,White);
    drawBorders(drawing, CONSOLE_WIDTH, CONSOLE_HEIGHT, DRAWING_SCALE, White);


    //initialize random numbers
    srand(time(NULL));

    Snake snake = Snake(STARTING_X, STARTING_Y);

    //current food location
    Block food = nextFood(snake);

    // main game loop
    do {
        //process player input
        if (snake.getNextDirection() == None)
            snake.setDirections(getGameKeys());
       
            

        //update game objects
        if (snake.getNextDirection() != Quit) {
            update(snake,food);
        }
           
        //draw the game
        render(drawing,snake,food);

        Sleep(.05 * 1000); // pause 5th of a second

    } while (snake.getNextDirection() != Quit); //end main game loop

    drawBorders(drawing, CONSOLE_WIDTH, CONSOLE_HEIGHT, DRAWING_SCALE, White);


    return 0;

} //end main


/*************************************************************************
updates objects in the game
Parameters:
   snake - (out) snake structure
   food - (out) food block
Returns:
    void
  **************************************************************************/
void update(Snake& snake , Block& food){

    if (snake.getNextDirection() != None) {
        snake.turn();
    }

    // see if snake has started moving yet
    if (snake.isMoving()) {

        snake.move();

        // see if snake ate food
        if (snake.getHead()->equals(food)) {
            //grow snake
            snake.grow();

            // get a new food block
            food = nextFood(snake);
        }
        else {
            // see if snake has any collisions
            snake.collisions();

        }

    }  // end isMoving
  
    return;
    
}

/*************************************************************************
draw game board on console window
Parameters:
    hdc - handle to windows device context for drawing
    snake - snake structure
    food - food block
Returns:
    void
**************************************************************************/
void render(HDC hdc, Snake snake, Block food) {

    // draw the food block
    draw(hdc, food.getColumn(), food.getRow(), DRAWING_SCALE, FOOD_COLOR);

    // erase previous tail of the snake
    if (!snake.getPrevTail()->isEmpty())
        draw(hdc, snake.getPrevTail()->getColumn(), snake.getPrevTail()->getRow(), DRAWING_SCALE, BACKGROUND_COLOR);

    // draw head of the snake new position
    draw(hdc, snake.getHead()->getColumn(), snake.getHead()->getRow(), DRAWING_SCALE, SNAKE_COLOR);

    return;
}

/*************************************************************************
generate random location for new food
Parameters:
    snake  - snake class object
Returns:
    Block - Location of next food
**************************************************************************/
Block nextFood(Snake snake) {
    Block food = Block();

    while (food.isEmpty()) {

        food.setColumn(rand() % CONSOLE_WIDTH); //random column
        food.setRow(rand() % CONSOLE_HEIGHT); // random row

        //check if the snake occupies this location
        if (snake.intersects(food,true)) {
            food = Block();
        }
       
    }

    return food;
}
