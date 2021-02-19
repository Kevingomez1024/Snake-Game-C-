/*---------------------------------------------------------
 * file: console.h
 *   by: P.Allen
 *  org: COP 2001, Spring 2020
 *  for: header file for the console library of functions
 *       for graphics, keyboard input, and timing
 *---------------------------------------------------------*/
#pragma once
#include <Windows.h>
#include <WinUser.h>

//-----------------------------------------------------------------------------
// Data definitions:
//-----------------------------------------------------------------------------
enum Color {
    Black = 0x00000000,
    White = 0x00FFFFFF,
    Red = 0x00FF0000,
    Lime = 0x0000FF00,
    Blue = 0x000000FF,
    Yellow = 0x00FFFF00,
    Cyan = 0x0000FFFF,
    Magenta = 0x00FF00FF,
    Silver = 0x00C0C0C0,
    Gray = 0x00808080,
    Maroon = 0x00800000,
    Olive = 0x00808000,
    Green = 0x00008000,
    Purple = 0x00800080,
    Teal = 0x00008080,
    Navy = 0x00000080
};

// WASD Keys
    //define key constants for WASD (hex literals)
const WORD VK_NONE = 0x00;
const WORD VK_W = 0x57;
const WORD VK_A = 0x41;
const WORD VK_S = 0x53;
const WORD VK_D = 0x44;
const WORD VK_X = 0x58;


//-----------------------------------------------------------------------------
// Function prototypes:
//-----------------------------------------------------------------------------
HDC initConsole(int width, int height, int scale);
void draw(HDC hdc, int xpos, int ypos, int scale, Color colorCode);
void draw(HDC hdc, int xpos, int ypos);
void draw(HDC hdc, int xpos, int ypos, int scale);
void draw(HDC hdc, int xpos, int ypos, Color colorCode);
int getGameKeys();
