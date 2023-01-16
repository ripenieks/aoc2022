#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int first(const std::vector<std::string>& input);
int second(const std::vector<std::string>& input);

const char items[] = "abcdefghijklmnopqrstuvwxyz";

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
bool check_dupes(int chars[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if (chars[i] == chars[j]) return true;
        }
    }
    return false;
}
int first(const std::vector<std::string>& input)
{
    int hash[4] = {0};
    char chars[4] = {0};
    long res;
    for (int i = 0; i < input[0].length(); i++)
    {
        res = i + 1;
        //chars[i % 4] = input[0][i];
        long letter_pos = input[0].c_str()[i] - 'a';
        hash[i % 4] = (1 << letter_pos);

        //std::cout << "memes: " << (hash[0] & hash[1] & hash[2] & hash[3]) << std::endl;
        if (i > 3 && !check_dupes(hash)) return res;
    }
    return res;
}
bool check_dupes_two(int chars[14])
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = i+1; j < 14; j++)
        {
            if (chars[i] == chars[j]) return true;
        }
    }
    return false;
}
int second(const std::vector<std::string>& input)
{
    int hash[14] = {0};
    char chars[14] = {0};
    long res;
    for (int i = 0; i < input[0].length(); i++)
    {
        res = i + 1;
        //chars[i % 14] = input[0][i];
        long letter_pos = input[0].c_str()[i] - 'a';
        hash[i % 14] = (1 << letter_pos);

        //std::cout << "memes: " << (hash[0] & hash[1] & hash[2] & hash[3]) << std::endl;
        if (i > 13 && !check_dupes_two(hash)) return res;
    }
    return res;
}
