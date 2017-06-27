/**
 * Words library
 * 
 * @author Pierre HUBERT
 */

/**
 * Count the number of words in the library
 * 
 * @return int The number of words available
 */
int countWordsNumbers(FILE *fileCursor){
	
	int numberOfEntries = 0;
	char readChar;
	
	//Place the cursor at the begining of the file
	rewind(fileCursor);
	
	//Read all the file
	while(readChar != EOF){
		
		//Read a new char
		readChar = fgetc(fileCursor);
		
		//We determine if the char is a line breaker or not
		if(readChar == '\n')
			numberOfEntries++;
		
	}
	
	return numberOfEntries;
}

/**
 * Get a word specified by its number
 * 
 * @param int wordNumber The number of the word to get
 * @param char word The returned word
 * @param FILE fileCursor Pointer on words database
 * @return void
 */
void getWord(int wordNumber, char *word, FILE *fileCursor){
	
	//First, reset the position of the cursor
	rewind(fileCursor);
	
	//Go through the file straight to the right word
	while(wordNumber > 0){
		
		//Make the cursor go to the next line
		while(fgetc(fileCursor) != '\n');
		
		//Decrease wordNumber
		wordNumber --;
	}
	
	//Now the cursor is at the right position, we can get the word
	char newCharacter;
	int i = 0;
	while(1){
		//Read a line
		newCharacter = fgetc(fileCursor);
		
		//Check it is not EOF or breakline
		if(newCharacter == '\n' || newCharacter == EOF)
			break;
		
		//Add the character to the word
		word[i] = newCharacter;
		i++;
	}
	
	//Add the end of string character
	word[i] = '\0';
}

/**
 * Returns a random word
 * 
 * @param char The char to populate
 * @return void
 */
void getRandomWord(char *wordReturn){
	
	//Open file
	FILE* definitionsFile = NULL;
	definitionsFile = fopen("words.txt", "r");
	
	//Count the number of available words in the library
	int numberOfWords = countWordsNumbers(definitionsFile);
	printf("\nThere are %d words in the database.\n", numberOfWords);
	
	//Choose a random word
	srand(time(NULL));
	int randomWord = rand() % numberOfWords;
	printf("%d %d\n", randomWord, rand());

	//Get the right word
	getWord(randomWord, wordReturn, definitionsFile);
	
	//Close file
	fclose(definitionsFile);
}
