#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// INTRO

void intro()

{
    system("CLS");
    cout << setw(30) << "Hey there xD" << endl;
    cout << " \n O" << fixed << setw(45) << "This is Fatim and we're hanging him.\n";
    cout << "/|\\" << fixed << setw(45) << "You, being an empath, want to save him.\n";
    cout << "/ \\\n";
    cout << "------------------------------------------------------------------" << endl;

    cout << "\nAll you gotta do to save him is play hangman with us ;)";
    cout << "\n\nGuess the word and save the innocent(doubt) soul." << endl;
    cout << "Good luck xD" << endl;
}

// DISPLAY CURRENT HANGMAN
void display_current_hangman(string current_word, int tries_left, bool& flag1)
{
    // int tries_left = 4;
    // string random_word = "Maryam";

    if (tries_left == 7)
    {
        if (flag1 == false)
        {
            cout << "Let's begin\n" << endl;
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t          |\n";
        cout << "\t          |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t          |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left. ";
    }

    else if (tries_left == 6)
    {
        if (flag1 == false)
        {
            cout << "Oops, try again:/\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t          |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t          |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left.";
    }

    else if (tries_left == 5)
    {
        if (flag1 == false)
        {
            cout << "Fatim's going to die of you continue like this.\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t |        |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t          |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left.";
    }

    else if (tries_left == 4)
    {
        if (flag1 == false)
        {
            cout << "Come on man, you gotta do better.\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t/|        |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t          |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left.";
    }

    else if (tries_left == 3)
    {
        if (flag1 == false)
        {
            cout << "You wanna save him, right? Yea so try harder.\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t/|\\       |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t          |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left.";
    }

    else if (tries_left == 2)
    {
        if (flag1 == false)
        {
            cout << "Umm...\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t/|\\       |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t/         |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " tries left.";
    }

    else if (tries_left == 1)
    {
        if (flag1 == false)
        {  
            cout << "I hope your disappointment is immeasurable and your day is ruined.\n\n";
        }
        
        cout << "\n\n\t +--------+            ";
        cout << current_word;
        cout << "\n\t |        |\n";
        cout << "\t O        |\n";
        cout << "\t/|\\       |";

        // for (int i = 0; i < random_word.length(); i++)
        // {
        //     cout << "_ ";
        // }
        

        cout << "\n\t/ \\       |\n";
        cout << "\t _________|\n";
        cout << "\t/_________\\\n\n";

        
        cout << "You have " << tries_left << " last try left.";
    }
}

// RANDOM WORD 1

string read_random_word(int choice)
{
    // Variables
    string current_line = "";
    int current_line_number = 1;

    // Choosing random number
    srand(time(0));
    int rand_int = 0;

    // Setting number range of lines for random line number

    if (choice == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 1556 + 1;
            // cout << rand_int << endl;
        }
    }

    else if (choice == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 11594 + 1556;
            // cout << rand_int << endl;
        }
    }

    else
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 2800 + 14706;
            // cout << rand_int << endl;
        }
    }

    // cout << rand_int << endl;

    // Reading the file
    ifstream file_("Words_Sorted.txt");
    if (file_.is_open())
    {
        while (getline(file_, current_line))
        {
            if (current_line_number == rand_int)
            {
                // cout << current_line << endl;
                break;
            }
            current_line_number++;
            // cout << current_line << endl;
        }
        file_.close();
    }
    else
    {
        cout << "File is not open";
    }
    // cout << current_line << endl;
    return current_line;
}

// RANDOM WORD 2

string random_word()
{
    // Variables
    int choice_int = 0;
    string random_word = "";

    // Difficulties
    cout << "\nChoose a difficulty:" << endl;
    cout << "Easy: 1" << endl;
    cout << "Medium: 2" << endl;
    cout << "Hard: 3" << endl
         << endl;
    cin >> choice_int;

    // Input
    while (true)
    {

        if (choice_int <= 3 || choice_int >= 1)
        {
            system("CLS");
            // cout << "Loading..." << endl;
            //  EASY
            if (choice_int == 1)
            {
                random_word = read_random_word(choice_int);
                while (true)
                {
                    if (random_word.length() != 5)
                    {
                        random_word = read_random_word(choice_int);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            // MEDIUM
            else if (choice_int == 2)
            {
                random_word = read_random_word(choice_int);
                while (true)
                {
                    if (random_word.length() > 11 || random_word.length() < 6)
                    {
                        random_word = read_random_word(choice_int);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            // HARD
            else if (choice_int == 3)
            {
                random_word = read_random_word(choice_int);
                while (true)
                {
                    if (random_word.length() < 12)
                    {
                        random_word = read_random_word(choice_int);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Wrong number. Choose again" << endl;
            }
            break;
        }
    }
    // cout << random_word.length();
    return random_word;
}

// GAME OVER 1
string no_dashes(string current_word)
{
    string current_word_without_dashes = "";

    for (int i = 0; i < current_word.length(); i++)
    {
        if (current_word.substr(i, 1) != "_" && current_word.substr(i, 1) != " ")
        {
            current_word_without_dashes += current_word.substr(i, 1);
        }
    }
    return current_word_without_dashes;
}

// GAME OVER 2

bool game_over(int tries_left, string random_word, string current_word)
{
    string current_word_without_dashes = no_dashes(current_word);

    if (tries_left == 0 && random_word != current_word_without_dashes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// WIN
bool win(int tries_left, string random_word, string current_word)
{
    string current_word_without_dashes = no_dashes(current_word);

    if (tries_left >= 0 && random_word == current_word_without_dashes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// LETTER CORRECT 1

bool in_letter_pool(string letter_pool, string guess_letter)
{
    bool flag3 = false;
    for (int i = 0; i < letter_pool.length(); i++)
    {
        if (guess_letter == letter_pool.substr(i, 1))
        {
            flag3 = true;
            // cout << "a" << endl;
        }
    }
    return flag3;
}

//LETTER CORRECT 2

void replace_letter(int index, string &word, string letter)
{
    string temp_string = "";
    for (int i = 0; i < word.length(); i++)
    {
        if (i == index)
        {
            temp_string += letter;
        }
        else
        {
            temp_string += word.substr(i, 1);
        }
    }
    word = temp_string;
}

//LETTER CORRECT 3

bool letter_correct(int &tries_left, string random_word, string guess_letter, string &current_word, string &letter_pool)
{
    bool flag1 = false;
    bool flag2 = false;

    if (in_letter_pool(letter_pool, guess_letter) == true)
    {
        // cout << "You already guessed this letter." << endl;
        return flag1;
        // break;
    }
    else
    {
        letter_pool += guess_letter;
    }

    for (int i = 0; i < random_word.length(); i++)
    {

        if (guess_letter == random_word.substr(i, 1))
        {
            replace_letter(2 * i, current_word, guess_letter);
            flag1 = true;
            flag2 = true;
        }
    }
    if (flag2 == false)
    {
        tries_left--;
    }

    return flag1;
}

//FINDING INITIAL CURRENT WORD

string current_word2(string random_word1)
{
    string new_random_word = "";
    for (int i = 0; i < random_word1.length(); i++)
    {
        //new_random_word += random_word1.substr(i,1);
        if (i != random_word1.length())
        {
            new_random_word += "_ ";
        }
    }
    return new_random_word;
}

//DISPLAYING WORD POOL

void display_word_pool(string word_pool)
{
    for (int i = 0; i < word_pool.length(); i++)
    {

    }
}

int main()
{
    system("CLS");

    // Variables
    string random_word1 = "";
    string current_word = "";
    string guess_letter = "";
    int tries_left = 7;
    bool in_letter_pool_1;
    bool letter_correct_1;
    string letter_pool = "";
    string poop;
    bool flag1 = false;
    int num_wrong_guesses = 0;
    //int prev_tries_left = 8;

    intro();

    cout << "\nPress enter to continue..." << endl;
    getline(cin,poop);

    system("CLS");

    random_word1 = random_word();

    current_word = current_word2(random_word1);

    //cout << "psst the word is: " << random_word1 << endl;

    while (true)
    {
        display_current_hangman(current_word, tries_left, flag1);

        

        cout << "\nGuess a letter: ";
        cin >> guess_letter;

        system("CLS");

        in_letter_pool_1 = in_letter_pool(letter_pool, guess_letter);
        letter_correct_1 = letter_correct(tries_left, random_word1, guess_letter, current_word, letter_pool);

        if (letter_correct_1 == true && in_letter_pool_1 == false)
        {
            if (win(tries_left, random_word1, current_word) == true)
            {
                cout << "You win." << endl;
                break;
            }
            else
            {
                cout << "Correct Guess!\n" << endl;
            }
            flag1 = true;
        }
        else if (letter_correct_1 == false && in_letter_pool_1 == true)
        {
            cout << "You already guessed this letter.\n" << endl;
            flag1 = true;
        }
        else
        {
            if (game_over(tries_left, random_word1, current_word) == true)
            {
                cout << "You lose" << endl;
                cout << "The word was: " << random_word1;
                break;
            }
            else
            {
                num_wrong_guesses++;
                //cout << "Wrong Guess" << endl;
            }
            flag1 = false;
        }
    }
}