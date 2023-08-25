Name: Maryam Ayub
Student ID: 26100257

Name: Mohammad Fatim Shoaib
Student ID: 26100004

Project: Hangman
- We created the famous game called hangman. In our game, the program randomly chooses a word
  based on the difficulty from a text file containing over 10K words. Next, the program displays 
  underscores instead of letters and prompts the user to guess a letter. If the letter is in
  the word, the letter is replaced with the under score/s. If the guessed letter is not in the word,
  the number of tries decreases by one and another part of the hangman diagram is drawn.
- We used the sfml library for graphics. We learnt about it using the following YouTube video:
  https://www.youtube.com/watch?v=rZE700aaT5I&t=447s
- We also used file handling (for reading the file with words). We learnt this from the following website:
  https://www.w3schools.com/cpp/cpp_files.asp
- For sorting the file according to size of words, we used a Python script. The Python file is in this
  folder and is named sorting_words

Functions:
- We created a total of 11 functions. 
1) intro(): This is the intro message displayed at the start of the game
2) display_current_hangman(): This outputs the current word, guessed letters, tries left, and appropriate
  comments according to the tries left. It is named the way it is because initially we were using
  ascii art to display the hangman, and this function did that too. Now, this function changes the 
  value of boolean variables so that new parts of the hangman can be displayed
3-4) read_random_word() and random_word(): These work together to choose a random word from the text 
  file based on the difficulty chosen by the user
5-6) no_dashes() and game_over(): These work together to check after every guess whether the user has 
  lost or not. The no_dashes() function converts the current word (with dashes) into a string without
  dashes so that it can be compared in the game_over() function. game_over() returns a boolean value
  depending on if the user has lost or not
7) win(): This is similar to game_over(). It uses the no_dashes() function to check if the user has won
  or not. It also returns a boolean value depending on whether the user has won or not
8, 9, 10) in_letter_pool(): This checks whether or not the user entered a letter they already guessed.
  It returns a boolean value. 
  replace_letter(): This simply replaces a letter at a given index and 
  returns the new word. 
  letter_correct(): This replaces the guessed letter (if correct) with the underscores and returns a boolean
  value depending on if the guessed letter is correct.
11) current_word_2(): This finds the inital current word so that it can be displayed.
- The main function combines all these functions, along with the code for displaying the graphics.
- The letters that the user enters are entered into the graphics window because it is more user friendly
  since the user does not have to press enter after typing every letter.

NOTE:
- To run the code, run the main.exe file in the same folder (since the folder contains the necessary 
  libraries and the text file with words needed for it to run.
- Originally, we were going to use ascii art. The code we wrote for that is in the Hang_Man_V3.cpp
  file in the display_current_hangman() function.





