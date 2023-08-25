#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// GLOBAL VARIABLES
bool try_1 = false;
bool try_2 = false;
bool try_3 = false;
bool try_4 = false;
bool try_5 = false;
bool try_6 = false;
bool try_7 = false;

// FUNCTIONS

// INTRO
void intro()

{
    system("CLS");
    cout << setw(30) << "Hey there xD" << endl;
    cout << " \n   O" << fixed << setw(45) << "This is Fatim and we're hanging him.\n";
    cout << "  /|\\" << fixed << setw(45) << "You, being an empath, want to save him.\n";
    cout << "  / \\\n";
    cout << "------------------------------------------------------------------" << endl;

    cout << "\nAll you gotta do to save him is play hangman with us ;)";
    cout << "\n\nGuess the word and save the innocent(doubt) soul." << endl;
    cout << "Good luck xD" << endl;
}

// DISPLAY CURRENT HANGMAN
void display_current_hangman(string current_word, int tries_left, bool &flag1, string letter_pool)
{
    if (tries_left == 7)
    {
        // try_1 = true;
        if (flag1 == false)
        {
            cout << "Let's begin\n"
                 << endl;
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries Left: " << tries_left;
    }

    else if (tries_left == 6)
    {
        try_1 = true;
        if (flag1 == false)
        {
            cout << "Oops, try again:/\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 5)
    {
        try_2 = true;
        if (flag1 == false)
        {
            cout << "Fatim's going to die of you continue like this.\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 4)
    {
        try_3 = true;
        if (flag1 == false)
        {
            cout << "Come on man, you gotta do better.\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 3)
    {
        try_4 = true;
        if (flag1 == false)
        {
            cout << "You wanna save him, right? Yea so try harder.\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 2)
    {
        try_5 = true;
        if (flag1 == false)
        {
            cout << "Umm...\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 1)
    {
        try_6 = true;
        if (flag1 == false)
        {
            cout << "I hope your disappointment is immeasurable and your day is ruined.\n\n";
        }

        cout << "\n\n\t  The Word:      ";
        cout << current_word << endl;

        cout << "\n\n\t  Guessed Letters:      ";
        for (int a = 0; a < letter_pool.length(); a++)
        {
            cout << letter_pool[a] << " ";
        }

        cout << "\n\nTries left: " << tries_left;
    }

    else if (tries_left == 0)
    {
        try_7 = true;
    }
    if (tries_left > 0)
    {
        cout << "\nGuess a letter ";
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
        }
    }

    else if (choice == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 11594 + 1556;
        }
    }

    else
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 2800 + 14706;
        }
    }

    // Reading the file
    ifstream file_("Words_Sorted.txt");
    if (file_.is_open())
    {
        while (getline(file_, current_line))
        {
            if (current_line_number == rand_int)
            {
                break;
            }
            current_line_number++;
        }
        file_.close();
    }
    else
    {
        cout << "File is not open";
    }
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

// LETTER CORRECT 2

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

// LETTER CORRECT 3

bool letter_correct(int &tries_left, string random_word, string guess_letter, string &current_word, string &letter_pool)
{
    bool flag1 = false;
    bool flag2 = false;

    if (in_letter_pool(letter_pool, guess_letter) == true)
    {
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

// FINDING INITIAL CURRENT WORD
string current_word2(string random_word1)
{
    string new_random_word = "";
    for (int i = 0; i < random_word1.length(); i++)
    {
        // new_random_word += random_word1.substr(i,1);
        if (i != random_word1.length())
        {
            new_random_word += "_ ";
        }
    }
    return new_random_word;
}

int main()
{
    // Variables
    bool new_input = false;
    string random_word1 = "";
    string current_word = "";
    string guess_letter = "";
    int tries_left = 7;
    bool in_letter_pool_1;
    bool letter_correct_1;
    string letter_pool = "";
    string poop;
    bool flag1 = false;
    bool play_again = true;
    int game_num_flag = 0;

    while (play_again == true)
    {
        try_1 = false;
        try_2 = false;
        try_3 = false;
        try_4 = false;
        try_5 = false;
        try_6 = false;
        try_7 = false;
        new_input = false;
        random_word1 = "";
        current_word = "";
        guess_letter = "";
        tries_left = 7;
        letter_pool = "";
        poop = "";
        flag1 = false;
        play_again = true;

        // INTRO
        system("CLS");

        if (game_num_flag > 0)
        {
            cout << "\nPress enter to continue..." << endl;
            getline(cin, poop);
            system("CLS");
        }
        intro();

        cout << "\nPress enter to continue..." << endl;
        getline(cin, poop);

        system("CLS");

        random_word1 = random_word();
        // cout << "\n(the word is: " << random_word1 << ")" << endl;

        current_word = current_word2(random_word1);

        // MAIN

        sf::RenderWindow window(sf::VideoMode(720, 720), "Hang Man");

        window.setFramerateLimit(60);

        // base1 1
        sf::RectangleShape base1;
        sf::Vector2f base1Position(470, 700);
        base1.setPosition(base1Position);
        base1.setSize(sf::Vector2f(220, 2));
        base1.setFillColor(sf::Color(255, 255, 255));

        // base 2
        sf::RectangleShape base2;
        sf::Vector2f base2Position(465, 710);
        base2.setPosition(base2Position);
        base2.setSize(sf::Vector2f(230, 2));
        base2.setFillColor(sf::Color(255, 255, 255));

        // base 3
        sf::RectangleShape base3;
        sf::Vector2f base3Position(470, 700);
        base3.setPosition(base3Position);
        base3.setSize(sf::Vector2f(3, 11));
        base3.setFillColor(sf::Color(255, 255, 255));
        base3.rotate(25);

        // base 4
        sf::RectangleShape base4;
        sf::Vector2f base4Position(687, 702);
        base4.setPosition(base4Position);
        base4.setSize(sf::Vector2f(3, 11));
        base4.setFillColor(sf::Color(255, 255, 255));
        base4.rotate(-25);

        // pole 1
        sf::RectangleShape pole1;
        sf::Vector2f pole1Position(575, 100);
        pole1.setPosition(pole1Position);
        pole1.setSize(sf::Vector2f(2, 600));
        pole1.setFillColor(sf::Color(255, 255, 255));

        // pole 2
        sf::RectangleShape pole2;
        sf::Vector2f pole2Position(585, 90);
        pole2.setPosition(pole2Position);
        pole2.setSize(sf::Vector2f(2, 610));
        pole2.setFillColor(sf::Color(255, 255, 255));

        // top bar
        sf::RectangleShape topbar1;
        sf::Vector2f topbar1Position(220, 90);
        topbar1.setPosition(topbar1Position);
        topbar1.setSize(sf::Vector2f(365, 2));
        topbar1.setFillColor(sf::Color(255, 255, 255));

        // top bar 2
        sf::RectangleShape topbar2;
        sf::Vector2f topbar2Position(220, 100);
        topbar2.setPosition(topbar2Position);
        topbar2.setSize(sf::Vector2f(355, 2));
        topbar2.setFillColor(sf::Color(255, 255, 255));

        // top bar 3
        sf::RectangleShape topbar3;
        sf::Vector2f topbar3Position(220, 90);
        topbar3.setPosition(topbar3Position);
        topbar3.setSize(sf::Vector2f(2, 10));
        topbar3.setFillColor(sf::Color(255, 255, 255));

        // rope
        sf::RectangleShape rope;
        sf::Vector2f ropePosition(240, 100);
        rope.setPosition(ropePosition);
        rope.setSize(sf::Vector2f(4, 100));
        rope.setFillColor(sf::Color(255, 255, 255));

        // head
        sf::CircleShape head;
        sf::Vector2f headPosition(207, 200);
        head.setPosition(headPosition);
        head.setRadius(35);
        head.setFillColor(sf::Color(0, 0, 0));
        head.setOutlineColor(sf::Color(255, 255, 255));
        head.setOutlineThickness(3);

        // body
        sf::RectangleShape body;
        sf::Vector2f bodyPosition(240, 270);
        body.setPosition(bodyPosition);
        body.setSize(sf::Vector2f(4, 165));
        body.setFillColor(sf::Color(255, 255, 255));

        // right arm
        sf::RectangleShape right_arm;
        sf::Vector2f right_armPosition(305, 335);
        right_arm.setPosition(right_armPosition);
        right_arm.setSize(sf::Vector2f(4, 85));
        right_arm.setFillColor(sf::Color(255, 255, 255));
        right_arm.rotate(135);

        // left arm
        sf::RectangleShape left_arm;
        sf::Vector2f left_armPosition(240, 275);
        left_arm.setPosition(left_armPosition);
        left_arm.setSize(sf::Vector2f(4, 85));
        left_arm.setFillColor(sf::Color(255, 255, 255));
        left_arm.rotate(45);

        // right leg
        sf::RectangleShape right_leg;
        sf::Vector2f right_legPosition(305, 490);
        right_leg.setPosition(right_legPosition);
        right_leg.setSize(sf::Vector2f(4, 85));
        right_leg.setFillColor(sf::Color(255, 255, 255));
        right_leg.rotate(135);

        // left leg
        sf::RectangleShape left_leg;
        sf::Vector2f left_legPosition(240, 430);
        left_leg.setPosition(left_legPosition);
        left_leg.setSize(sf::Vector2f(4, 85));
        left_leg.setFillColor(sf::Color(255, 255, 255));
        left_leg.rotate(45);

        // EXTRA SHIT
        sf::RectangleShape top_right;
        sf::Vector2f top_rightPosition(579, 162);
        top_right.setPosition(top_rightPosition);
        top_right.setSize(sf::Vector2f(6, 88));
        top_right.setFillColor(sf::Color(255, 255, 255));
        top_right.rotate(135);

        // right eye
        sf::CircleShape right_eye;
        sf::Vector2f right_eyePosition(230, 220);
        right_eye.setPosition(right_eyePosition);
        right_eye.setRadius(2);
        right_eye.setFillColor(sf::Color(0, 0, 0));
        right_eye.setOutlineColor(sf::Color(255, 255, 255));
        right_eye.setOutlineThickness(2);

        // left eye
        sf::CircleShape left_eye;
        sf::Vector2f left_eyePosition(250, 220);
        left_eye.setPosition(left_eyePosition);
        left_eye.setRadius(2);
        left_eye.setFillColor(sf::Color(0, 0, 0));
        left_eye.setOutlineColor(sf::Color(255, 255, 255));
        left_eye.setOutlineThickness(2);

        // mouth
        sf::RectangleShape mouth;
        sf::Vector2f mouthPosition(231, 247);
        mouth.setPosition(mouthPosition);
        mouth.setSize(sf::Vector2f(20, 2));
        mouth.setFillColor(sf::Color(255, 255, 255));

        // nose
        sf::RectangleShape nose;
        sf::Vector2f nosePosition(240, 230);
        nose.setPosition(nosePosition);
        nose.setSize(sf::Vector2f(2, 12));
        nose.setFillColor(sf::Color(255, 255, 255));

        window.clear(); // This is always there
        window.draw(base1);
        window.draw(base2);
        window.draw(base3);
        window.draw(base4);
        window.draw(pole1);
        window.draw(pole2);
        window.draw(topbar1);
        window.draw(topbar2);
        window.draw(topbar3);
        window.display(); // This is always there

        // DISPLAYING INITIAL HANGMAN
        display_current_hangman(current_word, tries_left, flag1, letter_pool);

        // GRAPHICS LOOP
        while (window.isOpen())
        {

            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode < 128)
                    {
                        // cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
                        guess_letter = static_cast<char>(event.text.unicode);
                        new_input = true;
                    }
                }
            }

            // GAME PROCESSING
            if (new_input == true)
            {
                if (tries_left > 0)
                {
                    system("CLS");

                    in_letter_pool_1 = in_letter_pool(letter_pool, guess_letter);
                    letter_correct_1 = letter_correct(tries_left, random_word1, guess_letter, current_word, letter_pool);

                    if (letter_correct_1 == true && in_letter_pool_1 == false)
                    {
                        if (win(tries_left, random_word1, current_word) == true)
                        {
                            // cout << "You win." << endl;
                            system("CLS");
                            // cout << "        " << current_word << endl;
                            cout << endl;
                            cout << "      \\   /  |----|  |    |" << endl;
                            cout << "       \\ /   |    |  |    |" << endl;
                            cout << "        |    |    |  |    |" << endl;
                            cout << "        |    |    |  |    |" << endl;
                            cout << "        |    |----|  |----|" << endl;
                            cout << "" << endl;
                            cout << "\\        /\\        /  ---|---  |\\    |" << endl;
                            cout << " \\      /  \\      /      |     | \\   |" << endl;
                            cout << "  \\    /    \\    /       |     |  \\  |" << endl;
                            cout << "   \\  /      \\  /        |     |   \\ |" << endl;
                            cout << "    \\/        \\/      ---|---  |    \\|" << endl;
                            cout << "\n The word was: \n "
                                 << random_word1;
                            cout << "\nWould you like to play again? Enter 'y' or 'n': ";
                            base1.setFillColor(sf::Color(0, 255, 0));
                            base2.setFillColor(sf::Color(0, 255, 0));
                            base3.setFillColor(sf::Color(0, 255, 0));
                            base4.setFillColor(sf::Color(0, 255, 0));
                            pole1.setFillColor(sf::Color(0, 255, 0));
                            pole2.setFillColor(sf::Color(0, 255, 0));
                            topbar1.setFillColor(sf::Color(0, 255, 0));
                            topbar2.setFillColor(sf::Color(0, 255, 0));
                            topbar3.setFillColor(sf::Color(0, 255, 0));
                            rope.setFillColor(sf::Color(0, 255, 0));
                            body.setFillColor(sf::Color(0, 255, 0));
                            mouth.setFillColor(sf::Color(0, 255, 0));
                            nose.setFillColor(sf::Color(0, 255, 0));
                            right_arm.setFillColor(sf::Color(0, 255, 0));
                            left_arm.setFillColor(sf::Color(0, 255, 0));
                            right_leg.setFillColor(sf::Color(0, 255, 0));
                            left_leg.setFillColor(sf::Color(0, 255, 0));
                            head.setOutlineColor(sf::Color(0, 255, 0));
                            right_eye.setOutlineColor(sf::Color(0, 255, 0));
                            left_eye.setOutlineColor(sf::Color(0, 255, 0));

                            tries_left = -1;
                            // break;
                        }
                        else
                        {
                            cout << "Correct Guess!\n"
                                 << endl;
                        }
                        flag1 = true;
                    }
                    else if (letter_correct_1 == false && in_letter_pool_1 == true)
                    {
                        cout << "You already guessed this letter.\n"
                             << endl;
                        flag1 = true;
                    }
                    else
                    {
                        if (game_over(tries_left, random_word1, current_word) == true)
                        {
                            // cout << "You loose" << endl;
                            cout << "       \\   /  |----|  |    |" << endl;
                            cout << "        \\ /   |    |  |    |" << endl;
                            cout << "         |    |    |  |    |" << endl;
                            cout << "         |    |    |  |    |" << endl;
                            cout << "         |    |----|  |----|" << endl;
                            cout << "" << endl;
                            cout << "   |      |----|  |-----  |----" << endl;
                            cout << "   |      |    |  |       |" << endl;
                            cout << "   |      |    |  |----|  |----" << endl;
                            cout << "   |      |    |       |  |" << endl;
                            cout << "   |----  |----|  -----|  |----" << endl;
                            cout << "\n The word was: \n "
                                 << random_word1;
                            cout << "\n Would you like to play again? Enter 'y' or 'n': ";
                            base1.setFillColor(sf::Color(255, 0, 0));
                            base2.setFillColor(sf::Color(255, 0, 0));
                            base3.setFillColor(sf::Color(255, 0, 0));
                            base4.setFillColor(sf::Color(255, 0, 0));
                            pole1.setFillColor(sf::Color(255, 0, 0));
                            pole2.setFillColor(sf::Color(255, 0, 0));
                            topbar1.setFillColor(sf::Color(255, 0, 0));
                            topbar2.setFillColor(sf::Color(255, 0, 0));
                            topbar3.setFillColor(sf::Color(255, 0, 0));
                            rope.setFillColor(sf::Color(255, 0, 0));
                            body.setFillColor(sf::Color(255, 0, 0));
                            mouth.setFillColor(sf::Color(255, 0, 0));
                            nose.setFillColor(sf::Color(255, 0, 0));
                            right_arm.setFillColor(sf::Color(255, 0, 0));
                            left_arm.setFillColor(sf::Color(255, 0, 0));
                            right_leg.setFillColor(sf::Color(255, 0, 0));
                            left_leg.setFillColor(sf::Color(255, 0, 0));
                            head.setOutlineColor(sf::Color(255, 0, 0));
                            right_eye.setOutlineColor(sf::Color(255, 0, 0));
                            left_eye.setOutlineColor(sf::Color(255, 0, 0));
                            // break;
                        }
                        flag1 = false;
                    }
                    new_input = false;
                    display_current_hangman(current_word, tries_left, flag1, letter_pool);
                }
                else
                {
                    // cout << "\nWould you like to play again? Enter 'y' or 'n': ";
                    if (guess_letter == "y")
                    {
                        play_again = true;
                        game_num_flag++;
                        window.close();
                    }
                    else
                    {
                        play_again = false;
                        window.close();
                    }
                }
            }

            // render
            window.clear(); // This is always there
            window.draw(base1);
            window.draw(base2);
            window.draw(base3);
            window.draw(base4);
            window.draw(pole1);
            window.draw(pole2);
            window.draw(topbar1);
            window.draw(topbar2);
            window.draw(topbar3);
            // window.draw(rope);
            if (try_1 == true)
            {
                window.draw(rope);
            }
            if (try_2 == true)
            {
                window.draw(head);
                window.draw(nose);
                window.draw(right_eye);
                window.draw(left_eye);
                window.draw(mouth);
            }
            if (try_3 == true)
            {
                window.draw(body);
            }
            if (try_4 == true)
            {
                window.draw(right_arm);
            }
            if (try_5 == true)
            {
                window.draw(left_arm);
            }
            if (try_6 == true)
            {
                window.draw(right_leg);
            }
            if (try_7 == true)
            {
                window.draw(left_leg);
            }
            window.display(); // This is always there
        }

        // cout << "\nWould you like to play again? Enter 'y' or 'n': ";
        // cin >> poop;
        // if (poop == "y")
        // {
        //     play_again = true;
        // }
        // else
        // {
        //     play_again = false;
        // }
    }

    // cout << "\nTEST" << endl;
}