#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int first(const std::vector<std::string>& input);
int second(const std::vector<std::string>& input);

const char items[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int get_priority(const std::string& rucksack)
{
    long long hash_a = 0;
    long long hash_b = 0;
    for (int i = 0; i < sizeof(items); i++)
    {
        for(int j = 0; j < rucksack.length() / 2; j++)
        {
            if (rucksack[j] == items[sizeof(items) - i])
            {
                hash_a |= 1;
            }
            if (rucksack[j + rucksack.length() / 2] == items[sizeof(items) - i])
            {
                hash_b |= 1;
            }
        }
        hash_a = hash_a << 1;
        hash_b = hash_b << 1;
    }
    long long overlap = hash_a & hash_b;
    int priority = 0;
    for (int i = 0; i < sizeof(items); i++)
    {
        if (overlap & 1 == 1) 
        {
            priority += i + 1;
        }
        overlap = overlap >> 1;
    }
    return priority;
}

int first(const std::vector<std::string>& input)
{
    int sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        sum += get_priority(input[i]);
    }
    return sum;
}

int get_badge(const std::vector<std::string>& three_input)
{
    long long hash_a = 0;
    long long hash_b = 0;
    long long hash_c = 0;

    for (int i = 0; i < sizeof(items); i++)
    {
        for (int j = 0; j < three_input[0].length(); j++)
        {
            if (three_input[0][j] == items[sizeof(items) - i])
            {
                hash_a |= 1;
            }
        }
        for (int j = 0; j < three_input[1].length(); j++)
        {
            if (three_input[1][j] == items[sizeof(items) - i])
            {
                hash_b |= 1;
            }
        }
        for (int j = 0; j < three_input[2].length(); j++)
        {
            if (three_input[2][j] == items[sizeof(items) - i])
            {
                hash_c |= 1;
            }
        }
        hash_a = hash_a << 1;
        hash_b = hash_b << 1;
        hash_c = hash_c << 1;
    }
    long long overlap = hash_a & hash_b & hash_c;
    
    int priority = 0;
    for (int i = 0; i < sizeof(items); i++)
    {
        if (overlap & 1 == 1) 
        {
            priority += i + 1;
        }
        overlap = overlap >> 1;
    }
    return priority;
}

int second(const std::vector<std::string>& input)
{
    int sum = 0;
    for (int i = 0; i < input.size(); i = i+3)
    {
        std::vector<std::string> three_input;
        for (int j = 0; j < 3; j++)
        {
            three_input.push_back(input[i + j]);
        }
        sum += get_badge(three_input);
    }
    return sum;
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
