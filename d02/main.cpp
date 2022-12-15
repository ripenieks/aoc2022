#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int first(const std::vector<std::string>& input);
int second(const std::vector<std::string>& input);

// kinda useless
enum Move
{
    Rock,
    Paper,
    Scissors,
    Null = -1,
};

Move parse_move(char move)
{
    switch (move)
    {
        case 'A':
        case 'X':
            return Rock;
        case 'B':
        case 'Y':
            return Paper;
        case 'C':
        case 'Z':
            return Scissors;
        default:
            return Null;
    }
}

int evaluate_hand_first(const std::string& hand)
{
    Move game[2] = { parse_move(hand[0]), parse_move(hand[2]) };
    int outcome;
    if (game[1] == (game[0] + 1) % 3)
    {
        outcome = 6;
    }
    else if (game[1] == game[0])
    {
        outcome = 3;
    }
    else
    {
        outcome = 0;
    }
    return game[1] + 1 + outcome;
}


int first(const std::vector<std::string>& input)
{
    int score = 0;
    for (int i = 0; i < input.size(); i++)
    {
        score += evaluate_hand_first(input[i]);
    }
    return score;
}

int parse_strategy(char move)
{
    switch (move)
    {
        case 'X':
            return 2; // lose
        case 'Y':
            return 0; // tie
        case 'Z':
            return 1; // win
        default:
            return -1; // ???
    }
}

int evaluate_hand_second(const std::string& hand)
{
    int game[2] = { parse_move(hand[0]), (parse_move(hand[0]) + parse_strategy(hand[2])) % 3 };
    int outcome;
    if (game[1] == (game[0] + 1) % 3)
    {
        outcome = 6;
    }
    else if (game[1] == game[0])
    {
        outcome = 3;
    }
    else
    {
        outcome = 0;
    }
    return game[1] + 1 + outcome;
}

int second(const std::vector<std::string>& input)
{
    int score = 0;
    for (int i = 0; i < input.size(); i++)
    {
        score += evaluate_hand_second(input[i]);
    }
    return score;
}

int main()
{
    std::vector<std::string> input;
    std::string tmp = "";
    std::cin.tie(0);
    while(std::getline(std::cin, tmp))
    {
        input.push_back(tmp);
    }
    std::cout << first(input) << std::endl;
    std::cout << second(input) << std::endl;
}
