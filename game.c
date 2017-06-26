/**
 * Game ressources file
 * 
 * @author Pierre HUBERT
 */

/**
 * Ask the user to enter a letter
 *
 * @return {char} The typed char
 */
char typeLetter(){
    char letter = 0;
    printf("Please type a letter: ");
    letter = getchar();

    letter = toupper(letter);

    //Remove other typing
    while(getchar() != '\n') ;

    return letter;
}

/**
 * Determinate if a letter is present in a string or not
 *
 * @param {char[]} The char to inspect
 * @param {char} The letter to check
 * @return {int} True or false depending of the presence of the letter
 */
int letterInString(char *srcString, char letter){
    for(int i=0; i<strlen(srcString); i++){
        if(srcString[i] == letter){
            //The letter was found
            return 1;
        }
    }

    //No result was found
    return 0;
}

/**
 * Populate found letter variable (initializate)
 * 
 * @param {char[]} Target directory
 * @param {int} The number of carachters of the word
 */
void populateFound(char *targetString, int numberOfWords){
	int i;
	for(i=0; i<numberOfWords; i++){
		targetString[i] = '*';
	}
	targetString[i] = '\0';
}

/**
 * Replace the stars corresponding to a specific letter
 * 
 * @param char[] word The source word
 * @param char[] foundLetters The found letters
 * @param char letter The letter to replace
 * @return void
 */
void replaceLetter(char *word, char *foundLetters, char letter){
	//Process each word string
	int i;
	for(i = 0; i < strlen(word); i++){
		if(word[i] == letter){
			//Replace the word in the destination
			foundLetters[i] = letter;
		}
	}
}

/**
 * Determine if the game has ended or not
 * 
 * @param char foundLetters The found letters
 * @return 1 if the game has ended / 0 else
 */
int is_game_finished(char *foundLetters){
	
	for(int i = 0; i<strlen(foundLetters); i++){
		//Check if the letter is equals to *
		if(foundLetters[i] == '*')
			//The game has not ended yet
			return 0;
	}
	
	//The game has ended
	return 1;
}
