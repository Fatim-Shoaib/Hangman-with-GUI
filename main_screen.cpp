// INCLUDE
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <cctype>
#include <SFML/Audio.hpp>

using namespace std;

// RANDOM WORD 1

string read_random_word(string difficulty)
{
    // Variables
    string current_line = "";
    int current_line_number = 1;

    // Choosing random number
    srand(time(0));
    int rand_int = 0;

    // Setting number range of lines for random line number

    if (difficulty == "easy")
    {
        for (int i = 0; i < 5; i++)
        {
            rand_int = rand() % 1556 + 1;
        }
    }

    else if (difficulty == "medium")
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

string random_word(string difficulty)
{
    // Variables
    int choice_int = 0;
    string random_word = "";

    // Difficulties
    // cout << "\nChoose a difficulty:" << endl;
    // cout << "Easy: 1" << endl;
    // cout << "Medium: 2" << endl;
    // cout << "Hard: 3" << endl
    //      << endl;
    // cin >> choice_int;

    // Input
    while (true)
    {

        // if (choice_int <= 3 || choice_int >= 1)
        // {
        system("CLS");
        // cout << "Loading..." << endl;
        //  EASY
        if (difficulty == "easy")
        {
            random_word = read_random_word(difficulty);
            while (true)
            {
                if (random_word.length() != 5)
                {
                    random_word = read_random_word(difficulty);
                }
                else
                {
                    break;
                }
            }
        }

        // MEDIUM
        else if (difficulty == "medium")
        {
            random_word = read_random_word(difficulty);
            while (true)
            {
                if (random_word.length() > 11 || random_word.length() < 6)
                {
                    random_word = read_random_word(difficulty);
                }
                else
                {
                    break;
                }
            }
        }

        // HARD
        else if (difficulty == "hard")
        {
            random_word = read_random_word(difficulty);
            while (true)
            {
                if (random_word.length() < 12)
                {
                    random_word = read_random_word(difficulty);
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
        // }
    }
    return random_word;
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
            new_random_word += "__ ";
        }
    }
    return new_random_word;
}

// REPLACE LETTER
void replace_letter(int index, string &word, char letter)
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
            temp_string += word[i];
        }
    }
    word = temp_string;
}

// LETTER CORRECT 1

bool in_letter_pool(string letter_pool, char guess_letter)
{
    bool flag3 = false;
    for (int i = 0; i < letter_pool.length(); i++)
    {
        if (guess_letter == letter_pool[i])
        {
            flag3 = true;
            // cout << "a" << endl;
        }
    }
    return flag3;
}

bool letter_correct(int &tries_left, string random_word, char guess_letter, string &current_word, string &letter_pool)
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

        if (guess_letter == random_word[i])
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

// GAME OVER 1
string no_dashes(string current_word)
{
    string current_word_without_dashes = "";

    for (int i = 0; i < current_word.length(); i++)
    {
        if (current_word[i] != '_' && current_word[i] != ' ')
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

// MENU
void menu(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 86 && x_pos > 15 && y_pos < 51 && y_pos > 15)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

// QUIT
void quit(bool &x, bool &y, bool &z, int x_pos, int y_pos)
{
    if (x_pos < 1014 && x_pos > 956 && y_pos < 51 && y_pos > 21)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

// EASY
void easy(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 212 && x_pos > 137 && y_pos < 395 && y_pos > 364)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

// MEDIUM
void medium(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 268 && x_pos > 137 && y_pos < 448 && y_pos > 417)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

// HARD
void hard(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 223 && x_pos > 138 && y_pos < 505 && y_pos > 470)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

#pragma region
// a
void aa(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 98 && x_pos > 49 && y_pos < 548 && y_pos > 491)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void bb(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 156 && x_pos > 107 && y_pos < 546 && y_pos > 492)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void cc(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 213 && x_pos > 166 && y_pos < 546 && y_pos > 492)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void dd(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 271 && x_pos > 225 && y_pos < 546 && y_pos > 492)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ee(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 329 && x_pos > 281 && y_pos < 546 && y_pos > 492)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ff(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 387 && x_pos > 340 && y_pos < 546 && y_pos > 492)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void gg(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 64 && x_pos > 15 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void hh(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 120 && x_pos > 74 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ii(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 178 && x_pos > 131 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void jj(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 238 && x_pos > 190 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void kk(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 294 && x_pos > 247 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ll(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 353 && x_pos > 306 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void mm(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 410 && x_pos > 363 && y_pos < 617 && y_pos > 560)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void nn(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 98 && x_pos > 49 && y_pos < 684 && y_pos > 628)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void oo(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 156 && x_pos > 108 && y_pos < 684 && y_pos > 629)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void pp(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 214 && x_pos > 166 && y_pos < 684 && y_pos > 628)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void qq(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 271 && x_pos > 223 && y_pos < 684 && y_pos > 628)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void rr(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 328 && x_pos > 281 && y_pos < 684 && y_pos > 628)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ss(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 387 && x_pos > 340 && y_pos < 684 && y_pos > 628)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void tt(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 63 && x_pos > 15 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void uu(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 121 && x_pos > 73 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void vv(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 181 && x_pos > 131 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void ww(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 238 && x_pos > 189 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void xx(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 296 && x_pos > 247 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void yy(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 353 && x_pos > 305 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void zz(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 410 && x_pos > 363 && y_pos < 752 && y_pos > 695)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}
#pragma endregion

// endgame sprites

void quit_1(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 742 && x_pos > 660 && y_pos < 503 && y_pos > 446)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void play_again(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 421 && x_pos > 233 && y_pos < 487 && y_pos > 452)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void exit(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 200 && x_pos > 108 && y_pos < 380 && y_pos > 334)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void restart(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 265 && x_pos > 103 && y_pos < 509 && y_pos > 460)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

void back(bool &x, bool &y, int x_pos, int y_pos)
{
    if (x_pos < 229 && x_pos > 102 && y_pos < 636 && y_pos > 583)
    {
        x = true;
        y = false;
    }
    else
    {
        x = false;
        y = true;
    }
}

int main()
{
// VARIABLES
#pragma region
    int text_x_pos = 0;
    int text_y_pos = 0;
    int intro_text_size = 35;
    int intro_text_x_pos = 380;
    bool bool_text_size_change = false;
    int word_x_pos = 67;
    int word_y_pos = 105;

    int dash_x_pos = 60;
    int dash_y_pos = 170;
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;
    int counter_4 = 0;
    int counter_5 = 0;
    int counter_6 = 0;
    char new_letter;
    string current_word = "";
    // string current_word_no_dashes = "";
    string string_dashes = "";
    int size_random_word = 0;
    string guessed_letters = "";
    int tries_left = 7;
    string guessed_letters_2 = "";
    string guessed_letters_3 = "";
    string guessed_letters_4 = "";
    string string_random_word = "";
    string string_random_word_1 = "";
    string difficulty = "";
    string keyboard_input = "";
    int keyboard_input_ascii = 0;
    bool new_input = false;
    int mouse_x_pos = 9999;
    int mouse_y_pos = 9999;
    bool bool_mouse_pressed = false;
    string string_display_final_word = "";
    int old_mouse_x_pos = 9999;
    int pointer_1_pos_1 = 523;
    int pointer_1_pos_2 = 9999;
    int pointer_2_pos_1 = 603;
    // bool bool_mouse_pressed = false;
    bool bool_mouse_released = false;
    int effects_volume = 50;
    int music_volume = 25;

#pragma endregion

// BOOL FLAGS
#pragma region
    bool bool_new_letter = false;
    bool bool_game_end = false;
    bool bool_flag_1 = false;
    bool bool_win = false;
    bool bool_lose = false;
    bool bool_new_letter_2 = false;
    bool bool_new_letter_3 = false;
    bool bool_rope = false;
    bool bool_face = false;
    bool bool_correct_letter = false;
    bool bool_wrong_letter = false;
    bool bool_right_arm = false;
    bool bool_left_arm = false;
    bool bool_right_leg = false;
    bool bool_left_leg = false;
    bool bool_body = false;
    bool bool_intro_img = true;
    bool bool_press_enter_to_continue = true;
    bool bool_main_game = false;
    bool bool_difficulty = false;
    bool bool_quit_small = false;
    bool bool_quit_large = false;
    bool bool_menu_small = false;
    bool bool_menu_large = false;
    bool bool_easy_small = false;
    bool bool_easy_large = false;
    bool bool_medium_small = false;
    bool bool_medium_large = false;
    bool bool_hard_small = false;
    bool bool_hard_large = false;
    bool in_letter_pool_1 = false;
    bool letter_correct_1 = false;
    bool bool_menu_screen = false;
    bool bool_back_difficulty = false;
    bool bool_back_main_game = false;
    bool bool_back_game_over = false;
    // bool bool_mouse_released = false;
    // menu
    bool bool_exit_small = false;
    bool bool_exit_large = false;
    bool bool_restart_small = false;
    bool bool_restart_large = false;
    bool bool_back_small = false;
    bool bool_back_large = false;
    // gameend
    bool bool_win_image = false;
    bool bool_loose_image = false;
    bool bool_quit_small_1 = false;
    bool bool_quit_large_1 = false;
    bool bool_play_again_small = false;
    bool bool_play_again_large = false;
    // letters
    bool bool_a_small = true;
    bool bool_b_small = true;
    bool bool_c_small = false;
    bool bool_d_small = false;
    bool bool_e_small = false;
    bool bool_f_small = false;
    bool bool_g_small = false;
    bool bool_h_small = false;
    bool bool_i_small = false;
    bool bool_j_small = false;
    bool bool_k_small = false;
    bool bool_l_small = false;
    bool bool_m_small = false;
    bool bool_n_small = false;
    bool bool_o_small = false;
    bool bool_p_small = false;
    bool bool_q_small = false;
    bool bool_r_small = false;
    bool bool_s_small = false;
    bool bool_t_small = false;
    bool bool_u_small = false;
    bool bool_v_small = false;
    bool bool_w_small = false;
    bool bool_x_small = false;
    bool bool_y_small = false;
    bool bool_z_small = false;

    bool bool_a_large = false;
    bool bool_b_large = false;
    bool bool_c_large = false;
    bool bool_d_large = false;
    bool bool_e_large = false;
    bool bool_f_large = false;
    bool bool_g_large = false;
    bool bool_h_large = false;
    bool bool_i_large = false;
    bool bool_j_large = false;
    bool bool_k_large = false;
    bool bool_l_large = false;
    bool bool_m_large = false;
    bool bool_n_large = false;
    bool bool_o_large = false;
    bool bool_p_large = false;
    bool bool_q_large = false;
    bool bool_r_large = false;
    bool bool_s_large = false;
    bool bool_t_large = false;
    bool bool_u_large = false;
    bool bool_v_large = false;
    bool bool_w_large = false;
    bool bool_x_large = false;
    bool bool_y_large = false;
    bool bool_z_large = false;

    bool bool_a_done = false;
    bool bool_b_done = false;
    bool bool_c_done = false;
    bool bool_d_done = false;
    bool bool_e_done = false;
    bool bool_f_done = false;
    bool bool_g_done = false;
    bool bool_h_done = false;
    bool bool_i_done = false;
    bool bool_j_done = false;
    bool bool_k_done = false;
    bool bool_l_done = false;
    bool bool_m_done = false;
    bool bool_n_done = false;
    bool bool_o_done = false;
    bool bool_p_done = false;
    bool bool_q_done = false;
    bool bool_r_done = false;
    bool bool_s_done = false;
    bool bool_t_done = false;
    bool bool_u_done = false;
    bool bool_v_done = false;
    bool bool_w_done = false;
    bool bool_x_done = false;
    bool bool_y_done = false;
    bool bool_z_done = false;
#pragma endregion

    system("CLS");

    sf::RenderWindow window(sf::VideoMode(1024, 786), "Hang Man");

    window.setFramerateLimit(60);

// INITIALZING SPRITES
#pragma region
    // music
    sf::Music music;
    // MENU
    sf::Sprite menu_screen_sprite;
    sf::Texture menu_screen_texture;
    sf::Sprite exit_small_sprite;
    sf::Texture exit_small_texture;
    sf::Sprite exit_large_sprite;
    sf::Texture exit_large_texture;
    sf::Sprite restart_small_sprite;
    sf::Texture restart_small_texture;
    sf::Sprite restart_large_sprite;
    sf::Texture restart_large_texture;
    sf::Sprite back_small_sprite;
    sf::Texture back_small_texture;
    sf::Sprite back_large_sprite;
    sf::Texture back_large_texture;
    // endgame
    sf::Texture win_texture;
    sf::Sprite win_sprite;
    sf::Texture loose_texture;
    sf::Sprite loose_sprite;
    sf::Texture quit_small_1_texture;
    sf::Sprite quit_small_1_sprite;
    sf::Texture quit_large_1_texture;
    sf::Sprite quit_large_1_sprite;
    sf::Texture play_again_small_texture;
    sf::Sprite play_again_small_sprite;
    sf::Texture play_again_large_texture;
    sf::Sprite play_again_large_sprite;
    // hangman
    sf::Texture seven_tries_left_texture;
    sf::Sprite seven_tries_left_sprite;
    sf::Texture six_tries_left_texture;
    sf::Sprite six_tries_left_sprite;
    sf::Texture five_tries_left_texture;
    sf::Sprite five_tries_left_sprite;
    sf::Texture four_tries_left_texture;
    sf::Sprite four_tries_left_sprite;
    sf::Texture three_tries_left_texture;
    sf::Sprite three_tries_left_sprite;
    sf::Texture two_tries_left_texture;
    sf::Sprite two_tries_left_sprite;
    sf::Texture one_tries_left_texture;
    sf::Sprite one_tries_left_sprite;
    sf::Texture zero_tries_left_texture;
    sf::Sprite zero_tries_left_sprite;
    // LETTERS
    sf::Texture a_small_texture;
    sf::Sprite a_small_Sprite;
    sf::Texture b_small_texture;
    sf::Sprite b_small_Sprite;
    sf::Texture c_small_texture;
    sf::Sprite c_small_Sprite;
    sf::Texture d_small_texture;
    sf::Sprite d_small_Sprite;
    sf::Texture e_small_texture;
    sf::Sprite e_small_Sprite;
    sf::Texture f_small_texture;
    sf::Sprite f_small_Sprite;
    sf::Texture g_small_texture;
    sf::Sprite g_small_Sprite;
    sf::Texture h_small_texture;
    sf::Sprite h_small_Sprite;
    sf::Texture i_small_texture;
    sf::Sprite i_small_Sprite;
    sf::Texture j_small_texture;
    sf::Sprite j_small_Sprite;
    sf::Texture k_small_texture;
    sf::Sprite k_small_Sprite;
    sf::Texture l_small_texture;
    sf::Sprite l_small_Sprite;
    sf::Texture m_small_texture;
    sf::Sprite m_small_Sprite;
    sf::Texture n_small_texture;
    sf::Sprite n_small_Sprite;
    sf::Texture o_small_texture;
    sf::Sprite o_small_Sprite;
    sf::Texture p_small_texture;
    sf::Sprite p_small_Sprite;
    sf::Texture q_small_texture;
    sf::Sprite q_small_Sprite;
    sf::Texture r_small_texture;
    sf::Sprite r_small_Sprite;
    sf::Texture s_small_texture;
    sf::Sprite s_small_Sprite;
    sf::Texture t_small_texture;
    sf::Sprite t_small_Sprite;
    sf::Texture u_small_texture;
    sf::Sprite u_small_Sprite;
    sf::Texture v_small_texture;
    sf::Sprite v_small_Sprite;
    sf::Texture w_small_texture;
    sf::Sprite w_small_Sprite;
    sf::Texture x_small_texture;
    sf::Sprite x_small_Sprite;
    sf::Texture y_small_texture;
    sf::Sprite y_small_Sprite;
    sf::Texture z_small_texture;
    sf::Sprite z_small_Sprite;

    sf::Texture a_large_texture;
    sf::Sprite a_large_Sprite;
    sf::Texture b_large_texture;
    sf::Sprite b_large_Sprite;
    sf::Texture c_large_texture;
    sf::Sprite c_large_Sprite;
    sf::Texture d_large_texture;
    sf::Sprite d_large_Sprite;
    sf::Texture e_large_texture;
    sf::Sprite e_large_Sprite;
    sf::Texture f_large_texture;
    sf::Sprite f_large_Sprite;
    sf::Texture g_large_texture;
    sf::Sprite g_large_Sprite;
    sf::Texture h_large_texture;
    sf::Sprite h_large_Sprite;
    sf::Texture i_large_texture;
    sf::Sprite i_large_Sprite;
    sf::Texture j_large_texture;
    sf::Sprite j_large_Sprite;
    sf::Texture k_large_texture;
    sf::Sprite k_large_Sprite;
    sf::Texture l_large_texture;
    sf::Sprite l_large_Sprite;
    sf::Texture m_large_texture;
    sf::Sprite m_large_Sprite;
    sf::Texture n_large_texture;
    sf::Sprite n_large_Sprite;
    sf::Texture o_large_texture;
    sf::Sprite o_large_Sprite;
    sf::Texture p_large_texture;
    sf::Sprite p_large_Sprite;
    sf::Texture q_large_texture;
    sf::Sprite q_large_Sprite;
    sf::Texture r_large_texture;
    sf::Sprite r_large_Sprite;
    sf::Texture s_large_texture;
    sf::Sprite s_large_Sprite;
    sf::Texture t_large_texture;
    sf::Sprite t_large_Sprite;
    sf::Texture u_large_texture;
    sf::Sprite u_large_Sprite;
    sf::Texture v_large_texture;
    sf::Sprite v_large_Sprite;
    sf::Texture w_large_texture;
    sf::Sprite w_large_Sprite;
    sf::Texture x_large_texture;
    sf::Sprite x_large_Sprite;
    sf::Texture y_large_texture;
    sf::Sprite y_large_Sprite;
    sf::Texture z_large_texture;
    sf::Sprite z_large_Sprite;

    sf::Texture a_done_texture;
    sf::Sprite a_done_Sprite;
    sf::Texture b_done_texture;
    sf::Sprite b_done_Sprite;
    sf::Texture c_done_texture;
    sf::Sprite c_done_Sprite;
    sf::Texture d_done_texture;
    sf::Sprite d_done_Sprite;
    sf::Texture e_done_texture;
    sf::Sprite e_done_Sprite;
    sf::Texture f_done_texture;
    sf::Sprite f_done_Sprite;
    sf::Texture g_done_texture;
    sf::Sprite g_done_Sprite;
    sf::Texture h_done_texture;
    sf::Sprite h_done_Sprite;
    sf::Texture i_done_texture;
    sf::Sprite i_done_Sprite;
    sf::Texture j_done_texture;
    sf::Sprite j_done_Sprite;
    sf::Texture k_done_texture;
    sf::Sprite k_done_Sprite;
    sf::Texture l_done_texture;
    sf::Sprite l_done_Sprite;
    sf::Texture m_done_texture;
    sf::Sprite m_done_Sprite;
    sf::Texture n_done_texture;
    sf::Sprite n_done_Sprite;
    sf::Texture o_done_texture;
    sf::Sprite o_done_Sprite;
    sf::Texture p_done_texture;
    sf::Sprite p_done_Sprite;
    sf::Texture q_done_texture;
    sf::Sprite q_done_Sprite;
    sf::Texture r_done_texture;
    sf::Sprite r_done_Sprite;
    sf::Texture s_done_texture;
    sf::Sprite s_done_Sprite;
    sf::Texture t_done_texture;
    sf::Sprite t_done_Sprite;
    sf::Texture u_done_texture;
    sf::Sprite u_done_Sprite;
    sf::Texture v_done_texture;
    sf::Sprite v_done_Sprite;
    sf::Texture w_done_texture;
    sf::Sprite w_done_Sprite;
    sf::Texture x_done_texture;
    sf::Sprite x_done_Sprite;
    sf::Texture y_done_texture;
    sf::Sprite y_done_Sprite;
    sf::Texture z_done_texture;
    sf::Sprite z_done_Sprite;
    // main game test
    sf::Texture main_game_test_texture;
    sf::Sprite main_game_test_sprite;

    // quit
    sf::Texture quit_small_texture;
    sf::Sprite quit_small_sprite;
    sf::Texture quit_large_texture;
    sf::Sprite quit_large_sprite;

    // menu
    sf::Texture menu_small_texture;
    sf::Sprite menu_small_sprite;
    sf::Texture menu_large_texture;
    sf::Sprite menu_large_sprite;

    // easy
    sf::Texture easy_small_texture;
    sf::Sprite easy_small_sprite;
    sf::Texture easy_large_texture;
    sf::Sprite easy_large_sprite;

    // medium
    sf::Texture medium_small_texture;
    sf::Sprite medium_small_sprite;
    sf::Texture medium_large_texture;
    sf::Sprite medium_large_sprite;

    // hard
    sf::Texture hard_small_texture;
    sf::Sprite hard_small_sprite;
    sf::Texture hard_large_texture;
    sf::Sprite hard_large_sprite;

    // Press enter to continue
    sf::Texture press_enter_to_continue_texture;
    sf::Sprite press_enter_to_continue_sprite;

    // intro image
    sf::Texture intro_image_texture;
    sf::Sprite intro_image_sprite;

    // difficulty
    sf::Texture difficulty_texture;
    sf::Sprite difficulty_sprite;
#pragma endregion

// LOADING IMAGES
#pragma region
    // music
    if (!music.openFromFile("audios/audio_3.wav"))
        cout << "Error could not load file";
    // MENU
    if (!menu_screen_texture.loadFromFile("images/menu_screen.jpg"))
        cout << "Error could not load file";
    if (!exit_small_texture.loadFromFile("images/exit_small.png"))
        cout << "Error could not load file";
    if (!exit_large_texture.loadFromFile("images/exit_large.png"))
        cout << "Error could not load file";
    if (!restart_small_texture.loadFromFile("images/restart_small.png"))
        cout << "Error could not load file";
    if (!restart_large_texture.loadFromFile("images/restart_large.png"))
        cout << "Error could not load file";
    if (!back_small_texture.loadFromFile("images/back_small.png"))
        cout << "Error could not load file";
    if (!back_large_texture.loadFromFile("images/back_large.png"))
        cout << "Error could not load file";

    // gameend
    if (!win_texture.loadFromFile("images/win.png"))
        cout << "Error could not load image";
    if (!loose_texture.loadFromFile("images/loose.png"))
        cout << "Error could not load image";
    if (!quit_small_1_texture.loadFromFile("images/quit_small_1.png"))
        cout << "Error could not load image";
    if (!quit_large_1_texture.loadFromFile("images/quit_large_1.png"))
        cout << "Error could not load image";
    if (!play_again_small_texture.loadFromFile("images/play_again_small.png"))
        cout << "Error could not load image";
    if (!play_again_large_texture.loadFromFile("images/play_again_large.png"))
        cout << "Error could not load image";
    // hangman
    if (!seven_tries_left_texture.loadFromFile("images/7_tries.jpg"))
        cout << "Error could not load image";
    if (!six_tries_left_texture.loadFromFile("images/6_tries.jpg"))
        cout << "Error could not load image";
    if (!five_tries_left_texture.loadFromFile("images/5_tries.jpg"))
        cout << "Error could not load image";
    if (!four_tries_left_texture.loadFromFile("images/4_tries.jpg"))
        cout << "Error could not load image";
    if (!three_tries_left_texture.loadFromFile("images/3_tries.jpg"))
        cout << "Error could not load image";
    if (!two_tries_left_texture.loadFromFile("images/2_tries.jpg"))
        cout << "Error could not load image";
    if (!one_tries_left_texture.loadFromFile("images/1_tries.jpg"))
        cout << "Error could not load image";
    if (!zero_tries_left_texture.loadFromFile("images/0_tries.jpg"))
        cout << "Error could not load image";
    // letters
    if (!a_small_texture.loadFromFile("images/a_small.png"))
        cout << "Error could not load image";
    if (!b_small_texture.loadFromFile("images/b_small.png"))
        cout << "Error could not load image";
    if (!c_small_texture.loadFromFile("images/c_small.png"))
        cout << "Error could not load image";
    if (!d_small_texture.loadFromFile("images/d_small.png"))
        cout << "Error could not load image";
    if (!e_small_texture.loadFromFile("images/e_small.png"))
        cout << "Error could not load image";
    if (!f_small_texture.loadFromFile("images/f_small.png"))
        cout << "Error could not load image";
    if (!g_small_texture.loadFromFile("images/g_small.png"))
        cout << "Error could not load image";
    if (!h_small_texture.loadFromFile("images/h_small.png"))
        cout << "Error could not load image";
    if (!i_small_texture.loadFromFile("images/i_small.png"))
        cout << "Error could not load image";
    if (!j_small_texture.loadFromFile("images/j_small.png"))
        cout << "Error could not load image";
    if (!k_small_texture.loadFromFile("images/k_small.png"))
        cout << "Error could not load image";
    if (!l_small_texture.loadFromFile("images/l_small.png"))
        cout << "Error could not load image";
    if (!m_small_texture.loadFromFile("images/m_small.png"))
        cout << "Error could not load image";
    if (!n_small_texture.loadFromFile("images/n_small.png"))
        cout << "Error could not load image";
    if (!o_small_texture.loadFromFile("images/o_small.png"))
        cout << "Error could not load image";
    if (!p_small_texture.loadFromFile("images/p_small.png"))
        cout << "Error could not load image";
    if (!q_small_texture.loadFromFile("images/q_small.png"))
        cout << "Error could not load image";
    if (!r_small_texture.loadFromFile("images/r_small.png"))
        cout << "Error could not load image";
    if (!s_small_texture.loadFromFile("images/s_small.png"))
        cout << "Error could not load image";
    if (!t_small_texture.loadFromFile("images/t_small.png"))
        cout << "Error could not load image";
    if (!u_small_texture.loadFromFile("images/u_small.png"))
        cout << "Error could not load image";
    if (!v_small_texture.loadFromFile("images/v_small.png"))
        cout << "Error could not load image";
    if (!w_small_texture.loadFromFile("images/w_small.png"))
        cout << "Error could not load image";
    if (!x_small_texture.loadFromFile("images/x_small.png"))
        cout << "Error could not load image";
    if (!y_small_texture.loadFromFile("images/y_small.png"))
        cout << "Error could not load image";
    if (!z_small_texture.loadFromFile("images/z_small.png"))
        cout << "Error could not load image";

    if (!a_large_texture.loadFromFile("images/a_large.png"))
        cout << "Error could not load image";
    if (!b_large_texture.loadFromFile("images/b_large.png"))
        cout << "Error could not load image";
    if (!c_large_texture.loadFromFile("images/c_large.png"))
        cout << "Error could not load image";
    if (!d_large_texture.loadFromFile("images/d_large.png"))
        cout << "Error could not load image";
    if (!e_large_texture.loadFromFile("images/e_large.png"))
        cout << "Error could not load image";
    if (!f_large_texture.loadFromFile("images/f_large.png"))
        cout << "Error could not load image";
    if (!g_large_texture.loadFromFile("images/g_large.png"))
        cout << "Error could not load image";
    if (!h_large_texture.loadFromFile("images/h_large.png"))
        cout << "Error could not load image";
    if (!i_large_texture.loadFromFile("images/i_large.png"))
        cout << "Error could not load image";
    if (!j_large_texture.loadFromFile("images/j_large.png"))
        cout << "Error could not load image";
    if (!k_large_texture.loadFromFile("images/k_large.png"))
        cout << "Error could not load image";
    if (!l_large_texture.loadFromFile("images/l_large.png"))
        cout << "Error could not load image";
    if (!m_large_texture.loadFromFile("images/m_large.png"))
        cout << "Error could not load image";
    if (!n_large_texture.loadFromFile("images/n_large.png"))
        cout << "Error could not load image";
    if (!o_large_texture.loadFromFile("images/o_large.png"))
        cout << "Error could not load image";
    if (!p_large_texture.loadFromFile("images/p_large.png"))
        cout << "Error could not load image";
    if (!q_large_texture.loadFromFile("images/q_large.png"))
        cout << "Error could not load image";
    if (!r_large_texture.loadFromFile("images/r_large.png"))
        cout << "Error could not load image";
    if (!s_large_texture.loadFromFile("images/s_large.png"))
        cout << "Error could not load image";
    if (!t_large_texture.loadFromFile("images/t_large.png"))
        cout << "Error could not load image";
    if (!u_large_texture.loadFromFile("images/u_large.png"))
        cout << "Error could not load image";
    if (!v_large_texture.loadFromFile("images/v_large.png"))
        cout << "Error could not load image";
    if (!w_large_texture.loadFromFile("images/w_large.png"))
        cout << "Error could not load image";
    if (!x_large_texture.loadFromFile("images/x_large.png"))
        cout << "Error could not load image";
    if (!y_large_texture.loadFromFile("images/y_large.png"))
        cout << "Error could not load image";
    if (!z_large_texture.loadFromFile("images/z_large.png"))
        cout << "Error could not load image";

    if (!a_done_texture.loadFromFile("images/a_done.png"))
        cout << "Error could not load image";
    if (!b_done_texture.loadFromFile("images/b_done.png"))
        cout << "Error could not load image";
    if (!c_done_texture.loadFromFile("images/c_done.png"))
        cout << "Error could not load image";
    if (!d_done_texture.loadFromFile("images/d_done.png"))
        cout << "Error could not load image";
    if (!e_done_texture.loadFromFile("images/e_done.png"))
        cout << "Error could not load image";
    if (!f_done_texture.loadFromFile("images/f_done.png"))
        cout << "Error could not load image";
    if (!g_done_texture.loadFromFile("images/g_done.png"))
        cout << "Error could not load image";
    if (!h_done_texture.loadFromFile("images/h_done.png"))
        cout << "Error could not load image";
    if (!i_done_texture.loadFromFile("images/i_done.png"))
        cout << "Error could not load image";
    if (!j_done_texture.loadFromFile("images/j_done.png"))
        cout << "Error could not load image";
    if (!k_done_texture.loadFromFile("images/k_done.png"))
        cout << "Error could not load image";
    if (!l_done_texture.loadFromFile("images/l_done.png"))
        cout << "Error could not load image";
    if (!m_done_texture.loadFromFile("images/m_done.png"))
        cout << "Error could not load image";
    if (!n_done_texture.loadFromFile("images/n_done.png"))
        cout << "Error could not load image";
    if (!o_done_texture.loadFromFile("images/o_done.png"))
        cout << "Error could not load image";
    if (!p_done_texture.loadFromFile("images/p_done.png"))
        cout << "Error could not load image";
    if (!q_done_texture.loadFromFile("images/q_done.png"))
        cout << "Error could not load image";
    if (!r_done_texture.loadFromFile("images/r_done.png"))
        cout << "Error could not load image";
    if (!s_done_texture.loadFromFile("images/s_done.png"))
        cout << "Error could not load image";
    if (!t_done_texture.loadFromFile("images/t_done.png"))
        cout << "Error could not load image";
    if (!u_done_texture.loadFromFile("images/u_done.png"))
        cout << "Error could not load image";
    if (!v_done_texture.loadFromFile("images/v_done.png"))
        cout << "Error could not load image";
    if (!w_done_texture.loadFromFile("images/w_done.png"))
        cout << "Error could not load image";
    if (!x_done_texture.loadFromFile("images/x_done.png"))
        cout << "Error could not load image";
    if (!y_done_texture.loadFromFile("images/y_done.png"))
        cout << "Error could not load image";
    if (!z_done_texture.loadFromFile("images/z_done.png"))
        cout << "Error could not load image";

    if (!main_game_test_texture.loadFromFile("main_game_test.jpg"))
        cout << "Error could not load image";
    if (!quit_small_texture.loadFromFile("quit_small.png"))
        cout << "Error could not load image";
    if (!quit_large_texture.loadFromFile("quit_large.png"))
        cout << "Error could not load image";
    if (!easy_small_texture.loadFromFile("easy_small.png"))
        cout << "Error could not load image";
    if (!easy_large_texture.loadFromFile("easy_large.png"))
        cout << "Error could not load image";
    if (!medium_small_texture.loadFromFile("medium_small.png"))
        cout << "Error could not load image";
    if (!medium_large_texture.loadFromFile("medium_large.png"))
        cout << "Error could not load image";
    if (!hard_small_texture.loadFromFile("hard_small.png"))
        cout << "Error could not load image";
    if (!hard_large_texture.loadFromFile("hard_large.png"))
        cout << "Error could not load image";
    if (!difficulty_texture.loadFromFile("difficulty.jpg"))
        cout << "Error could not load image";
    if (!menu_small_texture.loadFromFile("menu_small.png"))
        cout << "Error could not load image" << endl;
    if (!menu_large_texture.loadFromFile("menu_large.png"))
        cout << "Error could not load image" << endl;
    if (!intro_image_texture.loadFromFile("images/intro_pic.jpg"))
        cout << "Error could not load image" << endl;
    if (!press_enter_to_continue_texture.loadFromFile("press_enter_to_continue.jpg"))
        cout << "Error could not load image" << endl;
#pragma endregion

// TEXTURES TO IMAGES
#pragma region
    // MENU
    menu_screen_sprite.setTexture(menu_screen_texture);
    exit_small_sprite.setTexture(exit_small_texture);
    exit_large_sprite.setTexture(exit_large_texture);
    restart_small_sprite.setTexture(restart_small_texture);
    restart_large_sprite.setTexture(restart_large_texture);
    back_small_sprite.setTexture(back_small_texture);
    back_large_sprite.setTexture(back_large_texture);
    // gameend
    win_sprite.setTexture(win_texture);
    loose_sprite.setTexture(loose_texture);
    quit_small_1_sprite.setTexture(quit_small_1_texture);
    quit_large_1_sprite.setTexture(quit_large_1_texture);
    play_again_small_sprite.setTexture(play_again_small_texture);
    play_again_large_sprite.setTexture(play_again_large_texture);
    // hangman
    seven_tries_left_sprite.setTexture(seven_tries_left_texture);
    six_tries_left_sprite.setTexture(six_tries_left_texture);
    five_tries_left_sprite.setTexture(five_tries_left_texture);
    four_tries_left_sprite.setTexture(four_tries_left_texture);
    three_tries_left_sprite.setTexture(three_tries_left_texture);
    two_tries_left_sprite.setTexture(two_tries_left_texture);
    one_tries_left_sprite.setTexture(one_tries_left_texture);
    zero_tries_left_sprite.setTexture(zero_tries_left_texture);

    // letters
    a_small_Sprite.setTexture(a_small_texture);
    b_small_Sprite.setTexture(b_small_texture);
    c_small_Sprite.setTexture(c_small_texture);
    d_small_Sprite.setTexture(d_small_texture);
    e_small_Sprite.setTexture(e_small_texture);
    f_small_Sprite.setTexture(f_small_texture);
    g_small_Sprite.setTexture(g_small_texture);
    h_small_Sprite.setTexture(h_small_texture);
    i_small_Sprite.setTexture(i_small_texture);
    j_small_Sprite.setTexture(j_small_texture);
    k_small_Sprite.setTexture(k_small_texture);
    l_small_Sprite.setTexture(l_small_texture);
    m_small_Sprite.setTexture(m_small_texture);
    n_small_Sprite.setTexture(n_small_texture);
    o_small_Sprite.setTexture(o_small_texture);
    p_small_Sprite.setTexture(p_small_texture);
    q_small_Sprite.setTexture(q_small_texture);
    r_small_Sprite.setTexture(r_small_texture);
    s_small_Sprite.setTexture(s_small_texture);
    t_small_Sprite.setTexture(t_small_texture);
    u_small_Sprite.setTexture(u_small_texture);
    v_small_Sprite.setTexture(v_small_texture);
    w_small_Sprite.setTexture(w_small_texture);
    x_small_Sprite.setTexture(x_small_texture);
    y_small_Sprite.setTexture(y_small_texture);
    z_small_Sprite.setTexture(z_small_texture);

    a_large_Sprite.setTexture(a_large_texture);
    b_large_Sprite.setTexture(b_large_texture);
    c_large_Sprite.setTexture(c_large_texture);
    d_large_Sprite.setTexture(d_large_texture);
    e_large_Sprite.setTexture(e_large_texture);
    f_large_Sprite.setTexture(f_large_texture);
    g_large_Sprite.setTexture(g_large_texture);
    h_large_Sprite.setTexture(h_large_texture);
    i_large_Sprite.setTexture(i_large_texture);
    j_large_Sprite.setTexture(j_large_texture);
    k_large_Sprite.setTexture(k_large_texture);
    l_large_Sprite.setTexture(l_large_texture);
    m_large_Sprite.setTexture(m_large_texture);
    n_large_Sprite.setTexture(n_large_texture);
    o_large_Sprite.setTexture(o_large_texture);
    p_large_Sprite.setTexture(p_large_texture);
    q_large_Sprite.setTexture(q_large_texture);
    r_large_Sprite.setTexture(r_large_texture);
    s_large_Sprite.setTexture(s_large_texture);
    t_large_Sprite.setTexture(t_large_texture);
    u_large_Sprite.setTexture(u_large_texture);
    v_large_Sprite.setTexture(v_large_texture);
    w_large_Sprite.setTexture(w_large_texture);
    x_large_Sprite.setTexture(x_large_texture);
    y_large_Sprite.setTexture(y_large_texture);
    z_large_Sprite.setTexture(z_large_texture);

    a_done_Sprite.setTexture(a_done_texture);
    b_done_Sprite.setTexture(b_done_texture);
    c_done_Sprite.setTexture(c_done_texture);
    d_done_Sprite.setTexture(d_done_texture);
    e_done_Sprite.setTexture(e_done_texture);
    f_done_Sprite.setTexture(f_done_texture);
    g_done_Sprite.setTexture(g_done_texture);
    h_done_Sprite.setTexture(h_done_texture);
    i_done_Sprite.setTexture(i_done_texture);
    j_done_Sprite.setTexture(j_done_texture);
    k_done_Sprite.setTexture(k_done_texture);
    l_done_Sprite.setTexture(l_done_texture);
    m_done_Sprite.setTexture(m_done_texture);
    n_done_Sprite.setTexture(n_done_texture);
    o_done_Sprite.setTexture(o_done_texture);
    p_done_Sprite.setTexture(p_done_texture);
    q_done_Sprite.setTexture(q_done_texture);
    r_done_Sprite.setTexture(r_done_texture);
    s_done_Sprite.setTexture(s_done_texture);
    t_done_Sprite.setTexture(t_done_texture);
    u_done_Sprite.setTexture(u_done_texture);
    v_done_Sprite.setTexture(v_done_texture);
    w_done_Sprite.setTexture(w_done_texture);
    x_done_Sprite.setTexture(x_done_texture);
    y_done_Sprite.setTexture(y_done_texture);
    z_done_Sprite.setTexture(z_done_texture);

    main_game_test_sprite.setTexture(main_game_test_texture);
    intro_image_sprite.setTexture(intro_image_texture);
    menu_small_sprite.setTexture(menu_small_texture);
    press_enter_to_continue_sprite.setTexture(press_enter_to_continue_texture);
    difficulty_sprite.setTexture(difficulty_texture);
    easy_small_sprite.setTexture(easy_small_texture);
    easy_large_sprite.setTexture(easy_large_texture);
    medium_small_sprite.setTexture(medium_small_texture);
    medium_large_sprite.setTexture(medium_large_texture);
    hard_small_sprite.setTexture(hard_small_texture);
    hard_large_sprite.setTexture(hard_large_texture);
    menu_small_sprite.setTexture(menu_small_texture);
    menu_large_sprite.setTexture(menu_large_texture);
    quit_small_sprite.setTexture(quit_small_texture);
    quit_large_sprite.setTexture(quit_large_texture);
#pragma endregion

// BLANK SPACES
#pragma region
// sf::RectangleShape blank_1;
// sf::Vector2f blank_1_position(135, 315);
// blank_1.setPosition(blank_1_position);
// blank_1.setFillColor(sf::Color(85, 3, 3));
// blank_1.setSize(sf::Vector2f(4, 40));
// blank_1.rotate(90);

// sf::RectangleShape blank_2;
// sf::Vector2f blank_2_position(190, 315);
// blank_2.setPosition(blank_2_position);
// blank_2.setFillColor(sf::Color(85, 3, 3));
// blank_2.setSize(sf::Vector2f(4, 40));
// blank_2.rotate(90);

// sf::RectangleShape blank_3;
// sf::Vector2f blank_3_position(195, 315);
// blank_3.setPosition(blank_3_position);
// blank_3.setFillColor(sf::Color(85, 3, 3));
// blank_3.setSize(sf::Vector2f(4, 40));
// blank_3.rotate(90);

// sf::RectangleShape blank_4;
// sf::Vector2f blank_4_position(225, 315);
// blank_4.setPosition(blank_4_position);
// blank_4.setFillColor(sf::Color(85, 3, 3));
// blank_4.setSize(sf::Vector2f(4, 40));
// blank_4.rotate(90);

// sf::RectangleShape blank_5;
// sf::Vector2f blank_5_position(255, 315);
// blank_5.setPosition(blank_5_position);
// blank_5.setFillColor(sf::Color(85, 3, 3));
// blank_5.setSize(sf::Vector2f(4, 40));
// blank_5.rotate(90);
#pragma endregion

// FONT
#pragma region
    sf::Font font;
    if (!font.loadFromFile("BerlinSansFBRegular.ttf"))
        throw("COULD NOT LOAD FONT!");
#pragma endregion

// TEXT
#pragma region
    sf::Text word;
    word.setFont(font);
    word.setCharacterSize(58);
    word.setFillColor(sf::Color(85, 3, 3));
    // text.setColor(Color(68, 3, 3));
    word.setPosition(90, 290);
    word.setString(current_word);

    sf::Text dashes;
    dashes.setFont(font);
    dashes.setCharacterSize(60);
    dashes.setFillColor(sf::Color(85, 3, 3));
    dashes.setPosition(110, 290);
    // string a = "__ __ __";
    dashes.setString(string_dashes);

    sf::Text display_final_word;
    display_final_word.setFont(font);
    display_final_word.setCharacterSize(35);
    display_final_word.setFillColor(sf::Color(85, 3, 3));
    display_final_word.setPosition(200, 575);

    sf::Text intro_text;
    intro_text.setFont(font);
    intro_text.setCharacterSize(35);
    intro_text.setFillColor(sf::Color(85, 3, 3));
    intro_text.setPosition(380, 465);
    intro_text.setString("Press enter to continue");
#pragma endregion

    // DASHES TEST
    sf::RectangleShape dash_1;
    sf::Vector2f dash_1_position(110, 290);
    dash_1.setPosition(dash_1_position);
    dash_1.setFillColor(sf::Color(85, 3, 3));
    dash_1.setSize(sf::Vector2f(50, 5));

    sf::Music sound_effect;
    if (!sound_effect.openFromFile("audios/audio_4.wav"))
        cout << "Error could not load from file";

    music.play();
    music.setVolume(5);
    sound_effect.setVolume(50);

    // MENU
    sf::CircleShape pointer_1;
    pointer_1.setRadius(13);
    pointer_1.setPointCount(3);
    pointer_1.setFillColor(sf::Color(92, 64, 51));
    pointer_1.setPosition(sf::Vector2f(523, 413));

    sf::CircleShape pointer_2;
    pointer_2.setRadius(13);
    pointer_2.setPointCount(3);
    pointer_2.setFillColor(sf::Color(92, 64, 51));
    pointer_2.setPosition(sf::Vector2f(603, 553));

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
                    keyboard_input_ascii = event.text.unicode;
                    keyboard_input = static_cast<char>(event.text.unicode);
                    new_input = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                bool_mouse_released = true;
                bool_mouse_pressed = false;
            }
            if (bool_mouse_pressed == false)
            {
                if (event.type == sf::Event::MouseMoved)
                {
                    mouse_x_pos = sf::Mouse::getPosition(window).x;
                    mouse_y_pos = sf::Mouse::getPosition(window).y;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mouse_x_pos = sf::Mouse::getPosition(window).x;
                mouse_y_pos = sf::Mouse::getPosition(window).y;
                cout << "Mouse coordinates: x: " << mouse_x_pos << ", y: " << mouse_y_pos << endl;
                bool_mouse_pressed = true;
                bool_mouse_released = false;
                break;
            }
            // if (event.type == sf::Event::MouseButtonPressed)
            // {
            //     mouse_x_pos = sf::Mouse::getPosition(window).x;
            //     mouse_y_pos = sf::Mouse::getPosition(window).y;
            //     bool_mouse_pressed = true;
            // }
        }

        if (new_input == true)
        {
            if (keyboard_input_ascii == 13)
            {
                bool_press_enter_to_continue = false;
                bool_difficulty = true;
                bool_quit_small = true;
                bool_menu_small = true;
                bool_easy_small = true;
                bool_medium_small = true;
                bool_hard_small = true;
            }
            new_input = false;
        }

        // menu(bool_menu_large, bool_menu_small, mouse_x_pos, mouse_y_pos);
        // quit(bool_quit_large, bool_quit_small, bool_mouse_pressed, mouse_x_pos, mouse_y_pos);
        // easy(bool_easy_large, bool_easy_small, mouse_x_pos, mouse_y_pos);
        // medium(bool_medium_large, bool_medium_small, mouse_x_pos, mouse_y_pos);
        // hard(bool_hard_large, bool_hard_small, mouse_x_pos, mouse_y_pos);

        window.clear();
        // // Intro image
        // if (bool_intro_img == true)
        // {
        //     window.draw(intro_image_sprite);
        //     bool_intro_img = false;
        //     bool_press_enter_to_continue = true;
        //     window.display();
        //     Sleep(1000);
        // }
        // Press enter to continue
        if (bool_press_enter_to_continue == true)
        {
            window.draw(intro_image_sprite);
            window.draw(intro_text);
            if (bool_text_size_change == false)
            {
                if (counter_3 % 2 == 0)
                {
                    intro_text_size -= 1;
                    intro_text_x_pos += 5;
                    // intro_text_x_pos++;
                }
                if (intro_text_size <= 30)
                {
                    bool_text_size_change = true;
                }
                counter_3++;
            }
            else
            {
                if (counter_3 % 2 == 0)
                {
                    intro_text_size += 1;
                    intro_text_x_pos -= 5;
                    // intro_text_x_pos--;
                }
                if (intro_text_size >= 35.0)
                {
                    bool_text_size_change = false;
                }
                counter_3++;
            }
            intro_text.setPosition(sf::Vector2f(intro_text_x_pos, 465));
            intro_text.setCharacterSize(intro_text_size);
        }
        // Difficulty
        else if (bool_difficulty == true)
        {
            if (bool_mouse_pressed == true)
            {
                // quit
                if (mouse_x_pos < 1014 && mouse_x_pos > 956 && mouse_y_pos < 51 && mouse_y_pos > 21)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    window.close();
                }
                // menu
                else if (mouse_x_pos < 86 && mouse_x_pos > 15 && mouse_y_pos < 51 && mouse_y_pos > 15)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    bool_difficulty = false;
                    bool_back_difficulty = true;
                    bool_menu_screen = true;
                }
                // easy
                else if (mouse_x_pos < 212 && mouse_x_pos > 137 && mouse_y_pos < 395 && mouse_y_pos > 364)
                {
                    // music.setVolume(5);
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    difficulty = "easy";
                    bool_difficulty = false;
                    bool_main_game = true;
                    string_random_word_1 = random_word(difficulty);
                    // cout << string_random_word_1 << endl;
                    for (int i = 0; i < string_random_word_1.length(); i++)
                    {
                        string_random_word += toupper(string_random_word_1[i]);
                    }
                    cout << "Random word: " << string_random_word;
                    string_dashes = current_word2(string_random_word);
                    size_random_word = string_random_word.length();
                }
                // medium
                else if (mouse_x_pos < 268 && mouse_x_pos > 137 && mouse_y_pos < 448 && mouse_y_pos > 417)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    difficulty = "medium";
                    bool_difficulty = false;
                    bool_main_game = true;
                    string_random_word_1 = random_word(difficulty);
                    for (int i = 0; i < string_random_word_1.length(); i++)
                    {
                        string_random_word += toupper(string_random_word_1[i]);
                    }
                    cout << "Random word: " << string_random_word;
                    string_dashes = current_word2(string_random_word);
                    size_random_word = string_random_word.length();
                }
                // hard
                else if (mouse_x_pos < 223 && mouse_x_pos > 138 && mouse_y_pos < 505 && mouse_y_pos > 470)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    difficulty = "hard";
                    bool_difficulty = false;
                    bool_main_game = true;
                    string_random_word_1 = random_word(difficulty);
                    for (int i = 0; i < string_random_word_1.length(); i++)
                    {
                        string_random_word += toupper(string_random_word_1[i]);
                    }

                    cout << "Random word: " << string_random_word;
                    string_dashes = current_word2(string_random_word);
                    size_random_word = string_random_word.length();
                }
                bool_mouse_pressed = false;
            }

            window.draw(difficulty_sprite);
            menu(bool_menu_large, bool_menu_small, mouse_x_pos, mouse_y_pos);
            quit(bool_quit_large, bool_quit_small, bool_mouse_pressed, mouse_x_pos, mouse_y_pos);
            easy(bool_easy_large, bool_easy_small, mouse_x_pos, mouse_y_pos);
            medium(bool_medium_large, bool_medium_small, mouse_x_pos, mouse_y_pos);
            hard(bool_hard_large, bool_hard_small, mouse_x_pos, mouse_y_pos);

            // EASY
            if (bool_easy_small == true)
            {
                window.draw(easy_small_sprite);
            }
            if (bool_easy_large == true)
            {
                window.draw(easy_large_sprite);
            }
            // MEDIUM
            if (bool_medium_small == true)
            {
                window.draw(medium_small_sprite);
            }
            if (bool_medium_large == true)
            {
                window.draw(medium_large_sprite);
            }
            // HARD
            if (bool_hard_small == true)
            {
                window.draw(hard_small_sprite);
            }
            if (bool_hard_large == true)
            {
                window.draw(hard_large_sprite);
            }
            // QUIT
            if (bool_quit_small == true)
            {
                window.draw(quit_small_sprite);
            }
            if (bool_quit_large == true)
            {
                window.draw(quit_large_sprite);
            }
            // MENU
            if (bool_menu_small == true)
            {
                window.draw(menu_small_sprite);
            }
            if (bool_menu_large == true)
            {
                window.draw(menu_large_sprite);
            }
        }

        // Main game
        else if (bool_main_game == true)
        {
            // PRINTING DASHES

            // dashes.setString(string_dashes);
            // menu
            if (mouse_x_pos < 86 && mouse_x_pos > 15 && mouse_y_pos < 51 && mouse_y_pos > 15 && bool_mouse_pressed == true)
            {
                sound_effect.setPlayingOffset(sf::seconds(0.2));
                sound_effect.play();
                bool_back_main_game = true;
                bool_mouse_pressed = false;
                bool_difficulty = false;
                bool_menu_screen = true;
                bool_main_game = false;
                // break;
            }

            if (tries_left == 7)
            {
                window.draw(seven_tries_left_sprite);
            }
            else if (tries_left == 6)
            {
                window.draw(six_tries_left_sprite);
            }
            else if (tries_left == 5)
            {
                window.draw(five_tries_left_sprite);
            }
            else if (tries_left == 4)
            {
                window.draw(four_tries_left_sprite);
            }
            else if (tries_left == 3)
            {
                window.draw(three_tries_left_sprite);
            }
            else if (tries_left == 2)
            {
                window.draw(two_tries_left_sprite);
            }
            else if (tries_left == 1)
            {
                window.draw(one_tries_left_sprite);
            }
            else if (tries_left == 0)
            {
                window.draw(zero_tries_left_sprite);
            }
            // window.draw(main_game_test_sprite);
            // window.draw(dashes);
            // dash_1.setPosition(sf::Vector2f(110, 290));
            // window.draw(dash_1);
            // dash_1_position(110, 320);
            // dash_1.setPosition(sf::Vector2f(195, 290));
            // window.draw(dash_1);

            counter_1 = 0;
            dash_x_pos = 60;
            dash_y_pos = 170;
            for (int i = 0; i < size_random_word; i++)
            {
                if (counter_1 == 5)
                {
                    counter_1 = 0;
                    dash_x_pos -= 5;
                    dash_y_pos -= 15;
                    dash_1.setPosition(sf::Vector2f(dash_x_pos, dash_y_pos));
                    dash_1.setSize(sf::Vector2f(20, 3));
                    window.draw(dash_1);
                    dash_x_pos -= 345;
                    dash_y_pos += 75;
                    dash_1.setSize(sf::Vector2f(50, 5));
                }
                dash_1.setPosition(sf::Vector2f(dash_x_pos, dash_y_pos));
                window.draw(dash_1);
                dash_x_pos += 70;
                counter_1++;
            }

            // quit
            if (mouse_x_pos < 1014 && mouse_x_pos > 956 && mouse_y_pos < 51 && mouse_y_pos > 21 && bool_mouse_pressed == true)
            {
                sound_effect.setPlayingOffset(sf::seconds(0.2));
                sound_effect.play();
                window.close();
            }

            // window.draw(main_game_test_sprite);
            // window.draw(a_small_Sprite);
            // cout << "Random word: " << string_random_word;
            menu(bool_menu_large, bool_menu_small, mouse_x_pos, mouse_y_pos);
            quit(bool_quit_large, bool_quit_small, bool_mouse_pressed, mouse_x_pos, mouse_y_pos);

            // QUIT
            if (bool_quit_small == true)
            {
                window.draw(quit_small_sprite);
            }
            if (bool_quit_large == true)
            {
                window.draw(quit_large_sprite);
            }
            // MENU
            if (bool_menu_small == true)
            {
                window.draw(menu_small_sprite);
            }
            if (bool_menu_large == true)
            {
                window.draw(menu_large_sprite);
            }

            // // hangman
            // if (bool_rope == true)
            // {
            //     window.draw(six_tries_left_sprite);
            // }
            // if (bool_face == true)
            // {
            //     window.draw(five_tries_left_sprite);
            // }
            // if (bool_body == true)
            // {
            //     window.draw(four_tries_left_sprite);
            // }
            // if (bool_right_arm == true)
            // {
            //     window.draw(three_tries_left_sprite);
            // }
            // if (bool_left_arm == true)
            // {
            //     window.draw(two_tries_left_sprite);
            // }
            // if (bool_right_leg == true)
            // {
            //     window.draw(one_tries_left_sprite);
            // }
            // if (bool_left_leg == true)
            // {
            //     window.draw(zero_tries_left_sprite);
            // }

            // letters

            if (bool_mouse_pressed == true)
            {
                bool_mouse_pressed = false;
                if (mouse_x_pos < 98 && mouse_x_pos > 49 && mouse_y_pos < 548 && mouse_y_pos > 491)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_a_done = true;
                    // cout << "You pressed A" << endl;
                    guessed_letters += "A";
                    bool_new_letter = true;
                    // word_x_pos += 19;
                }
                if (mouse_x_pos < 156 && mouse_x_pos > 107 && mouse_y_pos < 546 && mouse_y_pos > 492)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_b_done = true;
                    // cout << "You pressed B" << endl;
                    guessed_letters += "B";
                    bool_new_letter = true;
                    // word_x_pos += 15;
                }
                if (mouse_x_pos < 213 && mouse_x_pos > 166 && mouse_y_pos < 546 && mouse_y_pos > 492)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_c_done = true;
                    // cout << "You pressed C" << endl;
                    guessed_letters += "C";
                    bool_new_letter = true;
                    // word_x_pos += 16;
                }
                if (mouse_x_pos < 271 && mouse_x_pos > 225 && mouse_y_pos < 546 && mouse_y_pos > 492)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_d_done = true;
                    // cout << "You pressed D" << endl;
                    guessed_letters += "D";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 329 && mouse_x_pos > 281 && mouse_y_pos < 546 && mouse_y_pos > 492)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_e_done = true;
                    // cout << "You pressed E" << endl;
                    guessed_letters += "E";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 387 && mouse_x_pos > 340 && mouse_y_pos < 546 && mouse_y_pos > 492)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_f_done = true;
                    // cout << "You pressed F" << endl;
                    guessed_letters += "F";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 64 && mouse_x_pos > 15 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_g_done = true;
                    // cout << "You pressed G" << endl;
                    guessed_letters += "G";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 120 && mouse_x_pos > 74 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_h_done = true;
                    // cout << "You pressed H" << endl;
                    guessed_letters += "H";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 178 && mouse_x_pos > 131 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_i_done = true;
                    // cout << "You pressed I" << endl;
                    guessed_letters += "I";
                    bool_new_letter = true;
                    // current_word += " ";
                }
                if (mouse_x_pos < 238 && mouse_x_pos > 190 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_j_done = true;
                    // cout << "You pressed J" << endl;
                    guessed_letters += "J";
                    bool_new_letter = true;
                    // current_word += " ";
                }
                if (mouse_x_pos < 294 && mouse_x_pos > 247 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_k_done = true;
                    // cout << "You pressed K" << endl;
                    guessed_letters += "K";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 353 && mouse_x_pos > 306 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_l_done = true;
                    // cout << "You pressed L" << endl;
                    guessed_letters += "L";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 410 && mouse_x_pos > 363 && mouse_y_pos < 617 && mouse_y_pos > 560)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_m_done = true;
                    // cout << "You pressed M" << endl;
                    guessed_letters += "M";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 98 && mouse_x_pos > 49 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_n_done = true;
                    // cout << "You pressed N" << endl;
                    guessed_letters += "N";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 156 && mouse_x_pos > 108 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_o_done = true;
                    // cout << "You pressed O" << endl;
                    guessed_letters += "O";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 214 && mouse_x_pos > 166 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_p_done = true;
                    // cout << "You pressed P" << endl;
                    guessed_letters += "P";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 271 && mouse_x_pos > 223 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_q_done = true;
                    // cout << "You pressed Q" << endl;
                    guessed_letters += "Q";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 328 && mouse_x_pos > 281 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_r_done = true;
                    // cout << "You pressed R" << endl;
                    guessed_letters += "R";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 387 && mouse_x_pos > 340 && mouse_y_pos < 684 && mouse_y_pos > 628)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_s_done = true;
                    // cout << "You pressed S" << endl;
                    guessed_letters += "S";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 63 && mouse_x_pos > 15 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_t_done = true;
                    // cout << "You pressed T" << endl;
                    guessed_letters += "T";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 121 && mouse_x_pos > 73 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_u_done = true;
                    // cout << "You pressed U" << endl;
                    guessed_letters += "U";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 181 && mouse_x_pos > 131 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_v_done = true;
                    // cout << "You pressed V" << endl;
                    guessed_letters += "V";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 238 && mouse_x_pos > 189 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_w_done = true;
                    // cout << "You pressed W" << endl;
                    guessed_letters += "W";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 296 && mouse_x_pos > 247 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_x_done = true;
                    // cout << "You pressed X" << endl;
                    guessed_letters += "X";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 353 && mouse_x_pos > 305 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_y_done = true;
                    // cout << "You pressed Y" << endl;
                    guessed_letters += "Y";
                    bool_new_letter = true;
                }
                if (mouse_x_pos < 410 && mouse_x_pos > 363 && mouse_y_pos < 752 && mouse_y_pos > 695)
                {
                    music.pause();
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    music.play();
                    bool_z_done = true;
                    // cout << "You pressed Z" << endl;
                    guessed_letters += "Z";
                    bool_new_letter = true;
                }
                // #pragma endregion
            }

// udfs
#pragma region

            if (bool_new_letter == true)
            {
                guessed_letters_3 = "";
                cout << "guessed_letters_4: " << guessed_letters_4 << endl;
                new_letter = guessed_letters[guessed_letters.length() - 1];

                if (tries_left > 0)
                {
                    // cout << "Check 1" << endl;
                    // cout << guessed_letters_4.length();
                    for (int i = 0; i < guessed_letters_4.length(); i++)
                    {
                        // cout << new_letter << " and " << guessed_letters_3[i] << endl;
                        if (new_letter == guessed_letters_4[i])
                        {
                            // cout << "You already guesed this letter" << endl;
                            bool_flag_1 = true;
                        }
                    }
                    if (bool_flag_1 == false)
                    {
                        guessed_letters_4 += new_letter;

                        for (int i = 0; i < string_random_word.length(); i++)
                        {
                            if (new_letter == string_random_word[i])
                            {
                                bool_correct_letter = true;
                            }
                        }

                        if (bool_correct_letter == true)
                        {
                            counter_6 = 0;

                            for (int i = 0; i < guessed_letters_4.length(); i++)
                            {
                                for (int j = 0; j < string_random_word.length(); j++)
                                {
                                    if (guessed_letters_4[i] == string_random_word[j])
                                    {
                                        counter_6++;
                                    }
                                }
                            }
                        }
                        if (counter_6 == string_random_word.length())
                        {
                            cout << "You win!" << endl;
                            bool_main_game = false;
                            bool_win_image = true;
                            bool_game_end = true;
                        }
                        else if (bool_correct_letter == false)
                        {
                            tries_left--;
                        }

                        if (tries_left == 0)
                        {
                            cout << "You Loose" << endl;
                            bool_main_game = false;
                            bool_loose_image = true;
                            bool_game_end = true;
                        }
                    }
                    bool_correct_letter = false;

                    if (bool_flag_1 == true)
                    {
                        bool_flag_1 = false;
                    }
                }
                cout << "Tries left: " << tries_left << endl;

                for (int i = 0; i < guessed_letters.length(); i++)
                {
                    for (int j = 0; j < guessed_letters_3.length(); j++)
                    {
                        if (guessed_letters[i] == guessed_letters_3[j])
                        {
                            counter_5++;
                        }
                    }
                    if (counter_5 == 0)
                    {
                        guessed_letters_3 += guessed_letters[i];
                    }
                    counter_5 = 0;
                }
                // cout << "new letter: " << new_letter << endl;
                // cout << "guessed letters: " << guessed_letters << endl;
                // for (int i = 0; i < guessed_letters.length(); i++)
                // {
                //     if (new_letter == guessed_letters[i])
                //     {
                //         bool_new_letter_3 = true;
                //         cout << "hi" << endl;
                //         cout << new_letter << " = " << guessed_letters[i] << endl;
                //     }
                // }
                // if (bool_new_letter_3 == false)
                // {
                //     guessed_letters_3 += new_letter;
                // }
                // else
                // {
                //     bool_new_letter_3 = false;
                // }
                cout << "guessed_letters_3 : " << guessed_letters_3 << endl;
                guessed_letters_2 = "";
                for (int i = 0; i < string_random_word.length(); i++)
                {
                    // cout << "True" << endl;
                    for (int j = 0; j < guessed_letters_3.length(); j++)
                    {
                        // cout << "True" << endl;
                        // cout << guessed_letters[j] << " and " << string_random_word[i] << endl;
                        if (guessed_letters_3[j] == string_random_word[i])
                        {
                            guessed_letters_2 += string_random_word[i];
                            bool_new_letter_2 = true;
                            // cout << "True" << endl;
                        }
                    }
                    // cout << "true" << endl;
                    if (bool_new_letter_2 == false && i != string_random_word.length() - 1)
                    {
                        guessed_letters_2 += " ";
                    }
                    bool_new_letter_2 = false;
                }
                // cout << guessed_letters << endl;
                // cout << guessed_letters_3 << endl;
                // cout << guessed_letters_2 << endl;
                bool_new_letter = false;
            }

            for (int i = 0; i < guessed_letters_2.length(); i++)
            {
                if (counter_4 == 5)
                {
                    word_y_pos += 61;
                    counter_4 = 0;
                    word_x_pos = 67;
                }
                counter_4++;
                word.setString(guessed_letters_2[i]);
                word.setPosition(sf::Vector2f(word_x_pos, word_y_pos));
                window.draw(word);
#pragma region
                if (guessed_letters_2[i] == 'A')
                {
                    word_x_pos += 70;
                }
                else if (guessed_letters_2[i] == 'B')
                {
                    word_x_pos += 71;
                }
                else if (guessed_letters_2[i] == 'C')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'D')
                {
                    word_x_pos += 70;
                }
                else if (guessed_letters_2[i] == 'E')
                {
                    word_x_pos += 70;
                }
                else if (guessed_letters_2[i] == 'F')
                {
                    word_x_pos += 70;
                }
                else if (guessed_letters_2[i] == 'G')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'H')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'I')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'J')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'K')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'L')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'M')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'N')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'O')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'P')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'Q')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'R')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'S')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'T')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'U')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'V')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'W')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'X')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'Y')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == 'Z')
                {
                    word_x_pos += 69;
                }
                else if (guessed_letters_2[i] == ' ')
                {
                    word_x_pos += 69;
                }

#pragma endregion
            }
            counter_4 = 0;
            word_y_pos = 105;
            word_x_pos = 67;

#pragma region
            aa(bool_a_large, bool_a_small, mouse_x_pos, mouse_y_pos);
            if (bool_a_done == true)
            {
                window.draw(a_done_Sprite);
            }
            else if (bool_a_large == true)
            {
                window.draw(a_large_Sprite);
            }
            else
            {
                window.draw(a_small_Sprite);
            }
            bb(bool_b_large, bool_b_small, mouse_x_pos, mouse_y_pos);
            if (bool_b_done == true)
            {
                window.draw(b_done_Sprite);
            }
            else if (bool_b_large == true)
            {
                window.draw(b_large_Sprite);
            }
            else
            {
                window.draw(b_small_Sprite);
            }
            cc(bool_c_large, bool_c_small, mouse_x_pos, mouse_y_pos);
            if (bool_c_done == true)
            {
                window.draw(c_done_Sprite);
            }
            else if (bool_c_large == true)
            {
                window.draw(c_large_Sprite);
            }
            else
            {
                window.draw(c_small_Sprite);
            }
            dd(bool_d_large, bool_d_small, mouse_x_pos, mouse_y_pos);
            if (bool_d_done == true)
            {
                window.draw(d_done_Sprite);
            }
            else if (bool_d_large == true)
            {
                window.draw(d_large_Sprite);
            }
            else
            {
                window.draw(d_small_Sprite);
            }
            ee(bool_e_large, bool_e_small, mouse_x_pos, mouse_y_pos);
            if (bool_e_done == true)
            {
                window.draw(e_done_Sprite);
            }
            else if (bool_e_large == true)
            {
                window.draw(e_large_Sprite);
            }
            else
            {
                window.draw(e_small_Sprite);
            }
            ff(bool_f_large, bool_f_small, mouse_x_pos, mouse_y_pos);
            if (bool_f_done == true)
            {
                window.draw(f_done_Sprite);
            }
            else if (bool_f_large == true)
            {
                window.draw(f_large_Sprite);
            }
            else
            {
                window.draw(f_small_Sprite);
            }
            gg(bool_g_large, bool_g_small, mouse_x_pos, mouse_y_pos);
            if (bool_g_done == true)
            {
                window.draw(g_done_Sprite);
            }
            else if (bool_g_large == true)
            {
                window.draw(g_large_Sprite);
            }
            else
            {
                window.draw(g_small_Sprite);
            }
            hh(bool_h_large, bool_h_small, mouse_x_pos, mouse_y_pos);
            if (bool_h_done == true)
            {
                window.draw(h_done_Sprite);
            }
            else if (bool_h_large == true)
            {
                window.draw(h_large_Sprite);
            }
            else
            {
                window.draw(h_small_Sprite);
            }
            ii(bool_i_large, bool_i_small, mouse_x_pos, mouse_y_pos);
            if (bool_i_done == true)
            {
                window.draw(i_done_Sprite);
            }
            else if (bool_i_large == true)
            {
                window.draw(i_large_Sprite);
            }
            else
            {
                window.draw(i_small_Sprite);
            }
            jj(bool_j_large, bool_j_small, mouse_x_pos, mouse_y_pos);
            if (bool_j_done == true)
            {
                window.draw(j_done_Sprite);
            }
            else if (bool_j_large == true)
            {
                window.draw(j_large_Sprite);
            }
            else
            {
                window.draw(j_small_Sprite);
            }
            kk(bool_k_large, bool_k_small, mouse_x_pos, mouse_y_pos);
            if (bool_k_done == true)
            {
                window.draw(k_done_Sprite);
            }
            else if (bool_k_large == true)
            {
                window.draw(k_large_Sprite);
            }
            else
            {
                window.draw(k_small_Sprite);
            }
            ll(bool_l_large, bool_l_small, mouse_x_pos, mouse_y_pos);
            if (bool_l_done == true)
            {
                window.draw(l_done_Sprite);
            }
            else if (bool_l_large == true)
            {
                window.draw(l_large_Sprite);
            }
            else
            {
                window.draw(l_small_Sprite);
            }
            mm(bool_m_large, bool_m_small, mouse_x_pos, mouse_y_pos);
            if (bool_m_done == true)
            {
                window.draw(m_done_Sprite);
            }
            else if (bool_m_large == true)
            {
                window.draw(m_large_Sprite);
            }
            else
            {
                window.draw(m_small_Sprite);
            }
            nn(bool_n_large, bool_n_small, mouse_x_pos, mouse_y_pos);
            if (bool_n_done == true)
            {
                window.draw(n_done_Sprite);
            }
            else if (bool_n_large == true)
            {
                window.draw(n_large_Sprite);
            }
            else
            {
                window.draw(n_small_Sprite);
            }
            oo(bool_o_large, bool_o_small, mouse_x_pos, mouse_y_pos);
            if (bool_o_done == true)
            {
                window.draw(o_done_Sprite);
            }
            else if (bool_o_large == true)
            {
                window.draw(o_large_Sprite);
            }
            else
            {
                window.draw(o_small_Sprite);
            }
            pp(bool_p_large, bool_p_small, mouse_x_pos, mouse_y_pos);
            if (bool_p_done == true)
            {
                window.draw(p_done_Sprite);
            }
            else if (bool_p_large == true)
            {
                window.draw(p_large_Sprite);
            }
            else
            {
                window.draw(p_small_Sprite);
            }
            qq(bool_q_large, bool_q_small, mouse_x_pos, mouse_y_pos);
            if (bool_q_done == true)
            {
                window.draw(q_done_Sprite);
            }
            else if (bool_q_large == true)
            {
                window.draw(q_large_Sprite);
            }
            else
            {
                window.draw(q_small_Sprite);
            }
            rr(bool_r_large, bool_r_small, mouse_x_pos, mouse_y_pos);
            if (bool_r_done == true)
            {
                window.draw(r_done_Sprite);
            }
            else if (bool_r_large == true)
            {
                window.draw(r_large_Sprite);
            }
            else
            {
                window.draw(r_small_Sprite);
            }
            ss(bool_s_large, bool_s_small, mouse_x_pos, mouse_y_pos);
            if (bool_s_done == true)
            {
                window.draw(s_done_Sprite);
            }
            else if (bool_s_large == true)
            {
                window.draw(s_large_Sprite);
            }
            else
            {
                window.draw(s_small_Sprite);
            }
            tt(bool_t_large, bool_t_small, mouse_x_pos, mouse_y_pos);
            if (bool_t_done == true)
            {
                window.draw(t_done_Sprite);
            }
            else if (bool_t_large == true)
            {
                window.draw(t_large_Sprite);
            }
            else
            {
                window.draw(t_small_Sprite);
            }
            uu(bool_u_large, bool_u_small, mouse_x_pos, mouse_y_pos);
            if (bool_u_done == true)
            {
                window.draw(u_done_Sprite);
            }
            else if (bool_u_large == true)
            {
                window.draw(u_large_Sprite);
            }
            else
            {
                window.draw(u_small_Sprite);
            }
            vv(bool_v_large, bool_v_small, mouse_x_pos, mouse_y_pos);
            if (bool_v_done == true)
            {
                window.draw(v_done_Sprite);
            }
            else if (bool_v_large == true)
            {
                window.draw(v_large_Sprite);
            }
            else
            {
                window.draw(v_small_Sprite);
            }
            ww(bool_w_large, bool_w_small, mouse_x_pos, mouse_y_pos);
            if (bool_w_done == true)
            {
                window.draw(w_done_Sprite);
            }
            else if (bool_w_large == true)
            {
                window.draw(w_large_Sprite);
            }
            else
            {
                window.draw(w_small_Sprite);
            }
            xx(bool_x_large, bool_x_small, mouse_x_pos, mouse_y_pos);
            if (bool_x_done == true)
            {
                window.draw(x_done_Sprite);
            }
            else if (bool_x_large == true)
            {
                window.draw(x_large_Sprite);
            }
            else
            {
                window.draw(x_small_Sprite);
            }
            yy(bool_y_large, bool_y_small, mouse_x_pos, mouse_y_pos);
            if (bool_y_done == true)
            {
                window.draw(y_done_Sprite);
            }
            else if (bool_y_large == true)
            {
                window.draw(y_large_Sprite);
            }
            else
            {
                window.draw(y_small_Sprite);
            }
            zz(bool_z_large, bool_z_small, mouse_x_pos, mouse_y_pos);
            if (bool_z_done == true)
            {
                window.draw(z_done_Sprite);
            }
            else if (bool_z_large == true)
            {
                window.draw(z_large_Sprite);
            }
            else
            {
                window.draw(z_small_Sprite);
            }
#pragma endregion
        }

#pragma endregion

        // endgame
        else if (bool_game_end == true)
        {

            if (bool_mouse_pressed == true)
            {
                // menu
                if (mouse_x_pos < 86 && mouse_x_pos > 15 && mouse_y_pos < 51 && mouse_y_pos > 15)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    bool_back_game_over = true;
                    bool_difficulty = false;
                    bool_menu_screen = true;
                    bool_game_end = false;
                    bool_mouse_pressed = false;
                    // break;
                }
                bool_mouse_pressed = false;
                if (mouse_x_pos < 742 && mouse_x_pos > 660 && mouse_y_pos < 503 && mouse_y_pos > 446)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    window.close();
                }
                else if (mouse_x_pos < 421 && mouse_x_pos > 233 && mouse_y_pos < 487 && mouse_y_pos > 452)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    bool_back_difficulty = false;
                    bool_back_game_over = false;
                    bool_back_main_game = false;
                    text_x_pos = 0;
                    text_y_pos = 0;
                    intro_text_size = 35;
                    intro_text_x_pos = 380;
                    bool_text_size_change = false;
                    word_x_pos = 67;
                    word_y_pos = 105;
                    old_mouse_x_pos = 9999;
                    pointer_1_pos_1 = 523;
                    pointer_1_pos_2 = 9999;
                    pointer_2_pos_1 = 603;
                    bool_mouse_pressed = false;
                    bool_mouse_released = false;
                    // effects_volume = 50;
                    // music_volume = 5;
                    bool_exit_small = false;
                    bool_exit_large = false;
                    bool_restart_small = false;
                    bool_restart_large = false;
                    bool_back_small = false;
                    bool_back_large = false;

                    dash_x_pos = 60;
                    dash_y_pos = 170;
                    counter_1 = 0;
                    counter_2 = 0;
                    counter_3 = 0;
                    counter_4 = 0;
                    counter_5 = 0;
                    counter_6 = 0;
                    current_word = "";
                    tries_left = 7;
                    string_dashes = "";
                    size_random_word = 0;
                    guessed_letters = "";
                    guessed_letters_2 = "";
                    guessed_letters_3 = "";
                    guessed_letters_4 = "";
                    string_random_word = "";
                    string_random_word_1 = "";
                    difficulty = "";
                    keyboard_input = "";
                    keyboard_input_ascii = 0;
                    new_input = false;
                    mouse_x_pos = 9999;
                    mouse_y_pos = 9999;
                    bool_mouse_pressed = false;
                    string_display_final_word = "";

                    // flags
                    bool_new_letter = false;
                    bool_game_end = false;
                    bool_flag_1 = false;
                    bool_win = false;
                    bool_lose = false;
                    bool_new_letter_2 = false;
                    bool_new_letter_3 = false;
                    bool_rope = false;
                    bool_face = false;
                    bool_correct_letter = false;
                    bool_wrong_letter = false;
                    bool_right_arm = false;
                    bool_left_arm = false;
                    bool_right_leg = false;
                    bool_left_leg = false;
                    bool_body = false;
                    bool_intro_img = false;
                    bool_press_enter_to_continue = false;
                    bool_main_game = false;
                    bool_difficulty = true;
                    bool_quit_small = false;
                    bool_quit_large = false;
                    bool_menu_small = false;
                    bool_menu_large = false;
                    bool_easy_small = false;
                    bool_easy_large = false;
                    bool_medium_small = false;
                    bool_medium_large = false;
                    bool_hard_small = false;
                    bool_hard_large = false;
                    in_letter_pool_1 = false;
                    letter_correct_1 = false;
                    // gameend
                    bool_win_image = false;
                    bool_loose_image = false;
                    bool_quit_small_1 = false;
                    bool_quit_large_1 = false;
                    bool_play_again_small = false;
                    bool_play_again_large = false;

                    // letters
                    bool_a_small = false;
                    bool_b_small = false;
                    bool_c_small = false;
                    bool_d_small = false;
                    bool_e_small = false;
                    bool_f_small = false;
                    bool_g_small = false;
                    bool_h_small = false;
                    bool_i_small = false;
                    bool_j_small = false;
                    bool_k_small = false;
                    bool_l_small = false;
                    bool_m_small = false;
                    bool_n_small = false;
                    bool_o_small = false;
                    bool_p_small = false;
                    bool_q_small = false;
                    bool_r_small = false;
                    bool_s_small = false;
                    bool_t_small = false;
                    bool_u_small = false;
                    bool_v_small = false;
                    bool_w_small = false;
                    bool_x_small = false;
                    bool_y_small = false;
                    bool_z_small = false;

                    bool_a_large = false;
                    bool_b_large = false;
                    bool_c_large = false;
                    bool_d_large = false;
                    bool_e_large = false;
                    bool_f_large = false;
                    bool_g_large = false;
                    bool_h_large = false;
                    bool_i_large = false;
                    bool_j_large = false;
                    bool_k_large = false;
                    bool_l_large = false;
                    bool_m_large = false;
                    bool_n_large = false;
                    bool_o_large = false;
                    bool_p_large = false;
                    bool_q_large = false;
                    bool_r_large = false;
                    bool_s_large = false;
                    bool_t_large = false;
                    bool_u_large = false;
                    bool_v_large = false;
                    bool_w_large = false;
                    bool_x_large = false;
                    bool_y_large = false;
                    bool_z_large = false;

                    bool_a_done = false;
                    bool_b_done = false;
                    bool_c_done = false;
                    bool_d_done = false;
                    bool_e_done = false;
                    bool_f_done = false;
                    bool_g_done = false;
                    bool_h_done = false;
                    bool_i_done = false;
                    bool_j_done = false;
                    bool_k_done = false;
                    bool_l_done = false;
                    bool_m_done = false;
                    bool_n_done = false;
                    bool_o_done = false;
                    bool_p_done = false;
                    bool_q_done = false;
                    bool_r_done = false;
                    bool_s_done = false;
                    bool_t_done = false;
                    bool_u_done = false;
                    bool_v_done = false;
                    bool_w_done = false;
                    bool_x_done = false;
                    bool_y_done = false;
                    bool_z_done = false;
                }
            }

            quit_1(bool_quit_large_1, bool_quit_small_1, mouse_x_pos, mouse_y_pos);
            play_again(bool_play_again_large, bool_play_again_small, mouse_x_pos, mouse_y_pos);

            if (bool_win_image == true)
            {
                window.draw(win_sprite);
                string_display_final_word = "The word was: ";
                string_display_final_word += string_random_word;
                display_final_word.setString(string_display_final_word);
                window.draw(display_final_word);
            }
            else if (bool_loose_image == true)
            {
                window.draw(loose_sprite);
                string_display_final_word = "The word was: ";
                string_display_final_word += string_random_word;
                display_final_word.setString(string_display_final_word);
                window.draw(display_final_word);
            }

            if (bool_quit_small_1 == true)
            {
                window.draw(quit_small_1_sprite);
            }
            else if (bool_quit_large_1 == true)
            {
                window.draw(quit_large_1_sprite);
            }
            if (bool_play_again_small == true)
            {
                window.draw(play_again_small_sprite);
            }
            else if (bool_play_again_large == true)
            {
                window.draw(play_again_large_sprite);
            }
        }

        // MENU
        else if (bool_menu_screen == true)
        {
            exit(bool_exit_large, bool_exit_small, mouse_x_pos, mouse_y_pos);
            restart(bool_restart_large, bool_restart_small, mouse_x_pos, mouse_y_pos);
            back(bool_back_large, bool_back_small, mouse_x_pos, mouse_y_pos);

            if (bool_mouse_pressed == true)
            {
                // exit
                if (mouse_x_pos < 200 && mouse_x_pos > 108 && mouse_y_pos < 380 && mouse_y_pos > 334)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    window.close();
                }
                // restart
                if (mouse_x_pos < 265 && mouse_x_pos > 103 && mouse_y_pos < 509 && mouse_y_pos > 460)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    bool_back_difficulty = false;
                    bool_back_game_over = false;
                    bool_back_main_game = false;
                    text_x_pos = 0;
                    text_y_pos = 0;
                    intro_text_size = 35;
                    intro_text_x_pos = 380;
                    bool_text_size_change = false;
                    word_x_pos = 67;
                    word_y_pos = 105;
                    old_mouse_x_pos = 9999;
                    pointer_1_pos_1 = 523;
                    pointer_1_pos_2 = 9999;
                    pointer_2_pos_1 = 603;
                    bool_mouse_pressed = false;
                    bool_mouse_released = false;
                    // effects_volume = 50;
                    // music_volume = 5;
                    bool_exit_small = false;
                    bool_exit_large = false;
                    bool_restart_small = false;
                    bool_restart_large = false;
                    bool_back_small = false;
                    bool_back_large = false;

                    dash_x_pos = 60;
                    dash_y_pos = 170;
                    counter_1 = 0;
                    counter_2 = 0;
                    counter_3 = 0;
                    counter_4 = 0;
                    counter_5 = 0;
                    counter_6 = 0;
                    current_word = "";
                    tries_left = 7;
                    string_dashes = "";
                    size_random_word = 0;
                    guessed_letters = "";
                    guessed_letters_2 = "";
                    guessed_letters_3 = "";
                    guessed_letters_4 = "";
                    string_random_word = "";
                    string_random_word_1 = "";
                    difficulty = "";
                    keyboard_input = "";
                    keyboard_input_ascii = 0;
                    new_input = false;
                    mouse_x_pos = 9999;
                    mouse_y_pos = 9999;
                    bool_mouse_pressed = false;
                    string_display_final_word = "";

                    // flags
                    bool_new_letter = false;
                    bool_game_end = false;
                    bool_flag_1 = false;
                    bool_win = false;
                    bool_lose = false;
                    bool_new_letter_2 = false;
                    bool_new_letter_3 = false;
                    bool_rope = false;
                    bool_face = false;
                    bool_correct_letter = false;
                    bool_wrong_letter = false;
                    bool_right_arm = false;
                    bool_left_arm = false;
                    bool_right_leg = false;
                    bool_left_leg = false;
                    bool_body = false;
                    bool_intro_img = false;
                    bool_press_enter_to_continue = false;
                    bool_main_game = false;
                    bool_difficulty = true;
                    bool_quit_small = false;
                    bool_quit_large = false;
                    bool_menu_small = false;
                    bool_menu_large = false;
                    bool_easy_small = false;
                    bool_easy_large = false;
                    bool_medium_small = false;
                    bool_medium_large = false;
                    bool_hard_small = false;
                    bool_hard_large = false;
                    in_letter_pool_1 = false;
                    letter_correct_1 = false;
                    // gameend
                    bool_win_image = false;
                    bool_loose_image = false;
                    bool_quit_small_1 = false;
                    bool_quit_large_1 = false;
                    bool_play_again_small = false;
                    bool_play_again_large = false;

                    // letters
                    bool_a_small = false;
                    bool_b_small = false;
                    bool_c_small = false;
                    bool_d_small = false;
                    bool_e_small = false;
                    bool_f_small = false;
                    bool_g_small = false;
                    bool_h_small = false;
                    bool_i_small = false;
                    bool_j_small = false;
                    bool_k_small = false;
                    bool_l_small = false;
                    bool_m_small = false;
                    bool_n_small = false;
                    bool_o_small = false;
                    bool_p_small = false;
                    bool_q_small = false;
                    bool_r_small = false;
                    bool_s_small = false;
                    bool_t_small = false;
                    bool_u_small = false;
                    bool_v_small = false;
                    bool_w_small = false;
                    bool_x_small = false;
                    bool_y_small = false;
                    bool_z_small = false;

                    bool_a_large = false;
                    bool_b_large = false;
                    bool_c_large = false;
                    bool_d_large = false;
                    bool_e_large = false;
                    bool_f_large = false;
                    bool_g_large = false;
                    bool_h_large = false;
                    bool_i_large = false;
                    bool_j_large = false;
                    bool_k_large = false;
                    bool_l_large = false;
                    bool_m_large = false;
                    bool_n_large = false;
                    bool_o_large = false;
                    bool_p_large = false;
                    bool_q_large = false;
                    bool_r_large = false;
                    bool_s_large = false;
                    bool_t_large = false;
                    bool_u_large = false;
                    bool_v_large = false;
                    bool_w_large = false;
                    bool_x_large = false;
                    bool_y_large = false;
                    bool_z_large = false;

                    bool_a_done = false;
                    bool_b_done = false;
                    bool_c_done = false;
                    bool_d_done = false;
                    bool_e_done = false;
                    bool_f_done = false;
                    bool_g_done = false;
                    bool_h_done = false;
                    bool_i_done = false;
                    bool_j_done = false;
                    bool_k_done = false;
                    bool_l_done = false;
                    bool_m_done = false;
                    bool_n_done = false;
                    bool_o_done = false;
                    bool_p_done = false;
                    bool_q_done = false;
                    bool_r_done = false;
                    bool_s_done = false;
                    bool_t_done = false;
                    bool_u_done = false;
                    bool_v_done = false;
                    bool_w_done = false;
                    bool_x_done = false;
                    bool_y_done = false;
                    bool_z_done = false;
                    bool_menu_screen = false;
                }
                // back
                if (mouse_x_pos > 102 && mouse_x_pos < 229 && mouse_y_pos < 636 && mouse_y_pos > 583)
                {
                    sound_effect.setPlayingOffset(sf::seconds(0.2));
                    sound_effect.play();
                    if (bool_back_difficulty == true)
                    {
                        bool_difficulty = true;
                        bool_menu_screen = false;
                        bool_back_difficulty = false;
                    }
                    else if (bool_back_game_over == true)
                    {
                        bool_game_end = true;
                        bool_menu_screen = false;
                        bool_back_game_over = false;
                    }
                    else if (bool_back_main_game == true)
                    {
                        bool_main_game = true;
                        bool_menu_screen = false;
                        bool_back_main_game = false;
                    }
                }
            }
            // back

            if (bool_mouse_pressed == true && bool_mouse_released == false)
            {
                // MUSIC VOL
                if (mouse_x_pos > pointer_1_pos_1 && mouse_x_pos < pointer_1_pos_1 + 23 && mouse_y_pos > 411 and mouse_y_pos < 432)
                {
                    old_mouse_x_pos = mouse_x_pos;
                    mouse_x_pos = sf::Mouse::getPosition(window).x;

                    pointer_1_pos_1 += mouse_x_pos - old_mouse_x_pos;
                    if (pointer_1_pos_1 > 764)
                    {
                        pointer_1_pos_1 = 764;
                    }
                    if (pointer_1_pos_1 < 443)
                    {
                        pointer_1_pos_1 = 443;
                    }
                    pointer_1.setPosition(sf::Vector2f(pointer_1_pos_1, 413));

                    music_volume = (764.0 - pointer_1_pos_1 * 1.0) / (764.0 - 443.0) * 100.0;
                    music_volume = 100 - music_volume;
                    music.setVolume(music_volume);
                }

                // EFFECTS VOL
                if (mouse_x_pos > pointer_2_pos_1 && mouse_x_pos < pointer_2_pos_1 + 23 && mouse_y_pos > 548 and mouse_y_pos < 573)
                {
                    old_mouse_x_pos = mouse_x_pos;
                    mouse_x_pos = sf::Mouse::getPosition(window).x;
                    pointer_1.setPosition(sf::Vector2f(pointer_1_pos_1, 413));
                    pointer_2_pos_1 += mouse_x_pos - old_mouse_x_pos;

                    if (pointer_2_pos_1 > 764)
                    {
                        pointer_2_pos_1 = 764;
                    }
                    if (pointer_2_pos_1 < 443)
                    {
                        pointer_2_pos_1 = 443;
                    }

                    pointer_2.setPosition(sf::Vector2f(pointer_2_pos_1, 553));
                    effects_volume = (764.0 - pointer_2_pos_1 * 1.0) / (764.0 - 443.0) * 100.0;
                    effects_volume = 100 - effects_volume;
                    sound_effect.setVolume(effects_volume);
                }
            }

            // window.clear();
            window.draw(menu_screen_sprite);
            if (bool_restart_small == true)
            {
                window.draw(restart_small_sprite);
            }
            else
            {
                window.draw(restart_large_sprite);
            }
            if (bool_exit_small == true)
            {
                window.draw(exit_small_sprite);
            }
            else
            {
                window.draw(exit_large_sprite);
            }
            if (bool_back_small == true)
            {
                window.draw(back_small_sprite);
            }
            else
            {
                window.draw(back_large_sprite);
            }
            window.draw(pointer_1);
            window.draw(pointer_2);
            // window.display();
        }

        window.display();
    }
}
