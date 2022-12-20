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

int second(const std::vector<std::string>& input)
{
    return 0;
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
