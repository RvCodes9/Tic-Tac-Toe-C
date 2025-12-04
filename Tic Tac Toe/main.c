// C standart librarys
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


// Terminal Colors / Windows 10 
#define YELLOW "\x1b[33m"
#define GREEN  "\x1b[32m"
#define RED    "\x1b[31m"
#define BLUE   "\x1b[34m"
#define RESET  "\x1b[0m"


// Global variables
static char list[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
static char queue = 'X';
static int8_t input;
static bool winner_control = false;


// Win Control Function
bool win_control(){
		
	if (list[0] == queue && list[1] == queue && list[2] == queue)  return true;
	else if (list[3] == queue && list[4] == queue && list[5] == queue) return true;
	else if (list[6] == queue && list[7] == queue && list[8] == queue) return true;
	
	else if (list[0] == queue && list[3] == queue && list[6] == queue) return true;
	else if (list[1] == queue && list[4] == queue && list[7] == queue) return true;
	else if (list[2] == queue && list[5] == queue && list[8] == queue) return true;
	
	else if (list[0] == queue && list[4] == queue && list[8] == queue) return true;
	else if (list[2] == queue && list[4] == queue && list[6] == queue) return true;
	
	else return false;
}


// Input Control Function
bool input_control(){
	if (input >= 1 && input <= 9 && list[input-1] == ' ') return true;
	else return false;
}


// Interface Function
void interface(){
	
	printf("\n\t%s+---+---+---+%s\n", YELLOW, RESET);
	
	printf("\t%s|%s %s%c%s %s|%s %s%c%s %s|%s %s%c%s %s|%s\n", 
            YELLOW, RESET,
            (list[0] == 'X') ? (RED) : (BLUE), list[0], RESET,
            YELLOW, RESET,
            (list[1] == 'X') ? (RED) : (BLUE), list[1], RESET,
            YELLOW, RESET,
		    (list[2] == 'X') ? (RED) : (BLUE), list[2], RESET,
		    YELLOW, RESET);
											   
	printf("\t%s+---+---+---+%s\n", YELLOW, RESET);
	
	printf("\t%s|%s %s%c%s %s|%s %s%c%s %s|%s %s%c%s %s|%s\n",
			YELLOW, RESET,
			(list[3] == 'X') ? (RED) : (BLUE), list[3], RESET,
			YELLOW, RESET,
	        (list[4] == 'X') ? (RED) : (BLUE), list[4], RESET,
	        YELLOW, RESET,
			(list[5] == 'X') ? (RED) : (BLUE), list[5], RESET,
			YELLOW, RESET);
	
	printf("\t%s+---+---+---+%s\n", YELLOW, RESET);
	
	printf("\t%s|%s %s%c%s %s|%s %s%c%s %s|%s %s%c%s %s|%s\n",
			YELLOW, RESET,
			(list[6] == 'X') ? (RED) : (BLUE), list[6], RESET,
			YELLOW, RESET,
	        (list[7] == 'X') ? (RED) : (BLUE), list[7], RESET,
	        YELLOW, RESET,
			(list[8] == 'X') ? (RED) : (BLUE), list[8], RESET,
			YELLOW, RESET);
	
	printf("\t%s+---+---+---+%s\n\n", YELLOW, RESET);
	
}

// Main Function
int main(void){
	
	while (true){
		
		// Game Loop
		for (int8_t i = 0; i < 9; i++){
			
			system("cls");
			printf("\n%sClassic Tic Tac Toe Console Game.%s\n\n", GREEN, RESET);
			interface();
			printf("%s%c --> %s", (queue == 'X') ? (RED) : (BLUE), queue, RESET);
			scanf("%d", &input);
			
			if (queue == 'X'){
				
				if (input_control() == true){
					
					list[input - 1] = 'X';
				
					if (win_control() == true){
						winner_control = true;
						system("cls");
						printf("\n%sClassic Tic Tac Toe Console Game.%s\n\n", GREEN, RESET);
						interface();
						printf("\n\t%sWin %sX%s player!!!%s\n", GREEN, RED, GREEN, RESET);
						break;
					}
				}
				
				else {
					
					while(input_control() != true){
						printf("%s:: %c --> %s", RED, queue, RESET);
						scanf("%d", &input);
					}
					
					list[input - 1] = 'X';
				}
				
				queue = 'O';
			}
			
			else if (queue == 'O'){
				
				if (input_control() == true){
					
					list[input - 1] = 'O';
				
					if (win_control() == true){
						winner_control = true;
						system("cls");
						printf("\n%sClassic Tic Tac Toe Console Game.%s\n\n", GREEN, RESET);
						interface();
						printf("\n\t%sWin %sO%s player!!!%s\n", GREEN, BLUE, GREEN, RESET);
						break;
					}
				}
				
				else {
					
					while(input_control() != true){
						printf("%s:: %c --> %s", BLUE, queue, RESET);
						scanf("%d", &input);
					}
					
					list[input - 1] = 'O';
				}
				
				queue = 'X';
			}
			
		}
		
		// No winner
		if (winner_control == false){
			system("cls");
			printf("\nClassic Tic Tac Toe Console Game.\n\n");
			interface();
			printf("\n\tNo winner!!!\n");
		}
		
		// Terminal display pause
		putchar('\n');
		system("pause");
		
		// Clear Memory
		for (int8_t i = 0; i < 9; i++){
			list[i] = ' ';
		}
		
	}
	
	return 0;
}
