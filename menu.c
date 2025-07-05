#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include "menu.h"

/* Constants definitions */
#define COLUMNS 5
#define PAUSE getch();
#define CLS (_WIN32 ? system("cls") : system("clear"));
#define SPAUSE                                \
    printf("Press any key to continue. . ."); \
    PAUSE
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define BLACK "\033[0m"
#define GRAY "\033[38;5;250m"
#define ORANGE "\033[38;5;202m"
#define NOCURSOR printf("\e[?25l"); // Hide text cursor
#define CURSOR printf("\e[?25h");   // Show text cursor
#define UP 72                       // Key "up" value
#define DOWN 80                     // Key "down" value
#define LEFT 75                    // Key "left" value
#define RIGHT 77                   // Key "right" value
#define ENTER 13                    // Key "Enter" value
#define ESC 27                      // Key "Esc" value

int menu(char **options, int size){
    int pos = 0;
    int key;

    NOCURSOR // Hide cursor
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            // gotoxy(0, 2 + i); // Go to println position X, Y

            if (i == pos)
            {
                printf(">> %s <<", options[i]); // Selected option
            }
            else
            {
                printf("   %s   ", options[i]);
            }
        }
        key = getch();

        // Increases or decreases the position according to the selected key
        if (key == UP)
        {
            if (pos <= 0)
            {
                pos = size - 1;
            }
            else
            {
                pos--;
            }
        }
        if(key == DOWN){
            if(pos >= size - 1){
                pos = 0;
            }
            else
            {
                pos++;
            }
        }

        if (key == ENTER)
        { // Select option
            return pos;
        }
        else if (key == 'g' || key == ESC)
        { // Selected developer mode (dont ask questions)
            return (int)key;
        }
    }
}

int horizontalMenu(char *options){
    int pos = 0;
    int size = strlen(options);
    int key;

    NOCURSOR // Hide cursor
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            char *color;
            if(i == 0){
                color = GREEN;
            } else if(i == 1){
                color = RED;
            } else if(i == 2){
                color = YELLOW;
            } else if(i == 3){
                color = BLUE;
            } else if(i == 4){
                color = ORANGE;
            }
            // gotoxy(0 + i * 4, 0); // Go to println position X, Y
            
            if (i == pos)
            {
                printf("👇"); // Gay selection indicator
                // gotoxy(0 + i * 4, 1); // Go to println position X, Y
                printf(" %s%c%s   \n\n", color, options[i], RESET); // Selected key
            }
            else
            {
                printf(" "); // Erase gay selection indicator
                // gotoxy(0 + i * 4, 1); // Go to println position X, Y
                printf(" %s%c%s  \n\n", color, options[i], RESET);
            }
        }
        printf("Press enter to select the key\n");
        key = getch();
        
        // Increases or decreases the position according to the selected key
        if (key == LEFT)
        {
            if (pos <= 0)
            {
                pos = size - 1;
            }
            else
            {
                pos--;
            }
        }
        if(key == RIGHT){
            if(pos >= size - 1){
                pos = 0;
            }
            else
            {
                pos++;
            }
        }
        
        if (key == ENTER)
        { // Select option
            // gotoxy(1 + pos * 4, 1); // Go to println position X, Y
            printf("%s%c%s", GRAY, options[pos], RESET);
            return pos;
        }
        else if (key == ESC)
        { // Selected developer mode (dont ask questions)
            return key;
        }
    }
}

int println(char *text, ...){
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    printf("\n");
    va_end(args);
    return 0;
}