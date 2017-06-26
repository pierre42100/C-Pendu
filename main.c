/**
 * Main programm file
 * 
 * @author Pierre HUBERT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Include game functions
#include "game.c"


/**
 * Main function of the project
 */
int main()
{
    //Initialize variables
    char word[] = "GOOD"; //Word
    int numberOfLetters = strlen(word); //Number of letter
    char lettersFound[numberOfLetters]; //Found letters
    int lost = 0;
    int numbersTry = 10;
    char lastLetter = 0;

    //Welcome message
    printf("Welcome to my game! Have fun !\n");
    printf("Your goal : find the write word...\n");

    //Initilizate game
    //Populate letter found variable
    populateFound(lettersFound, numberOfLetters);

    //This loops runs while the game hasn't ended
    while(!is_game_finished(lettersFound) && !lost){
		
		//Print current state of the string
		printf("\n\nCurrent state of the word: %s\n", lettersFound);
		printf("Number of lives: %d\n", numbersTry);
		
        //Ask a letter to the user
        lastLetter = typeLetter();

        //Check if the letter was found in the string
        if(letterInString(word, lastLetter)){
            //Inform user
            printf("The letter was found in the string !\n");
			
			//Replace the letter in the found string
			replaceLetter(word, lettersFound, lastLetter);

        }
        else {
            //Inform user
            printf("The letter was not found in the string !\n");
            
            //Reduce number of try remaining time
            numbersTry--;
            
            //Check if gamer has lost
            if(numbersTry == 0)
				lost = 1;
        }

    }
	
	//The game ended
	printf("\n\n\nYou finished the game. The word was %s. You ", word);
	if(lost)
		printf("lost");
	else
		printf("won");
	printf(" the game ... \n");
	
	//Goodbye messages
	printf("This programm was made by Pierre HUBERT in 2017\n");
	printf("Good bye !\n");

    return 0;
}
