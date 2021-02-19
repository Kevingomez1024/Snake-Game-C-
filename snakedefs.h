//------------------------------------------------------------------------------
// file: snakedefs.h
// by: K.Gomez
// org: COP 2001, Spring 2020
// for: Global configuration data for the snake game
//------------------------------------------------------------------------------
#pragma once

#include "console.h"

//--------------------------------
// Global constants and Data Structures
//--------------------------------
const int CONSOLE_WIDTH = 50;
const int CONSOLE_HEIGHT = 50;
const int DRAWING_SCALE = 10;

const int STARTING_X = 21;
const int STARTING_Y = 21;

const Color BACKGROUND_COLOR = Black;
const Color SNAKE_COLOR = White;
const Color FOOD_COLOR = Purple;


enum Direction {
    None,
    Left,
    Right,
    Up,
    Down,
    Quit = -1
};
