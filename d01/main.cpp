#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int first();
int second();

int main()
{
    std::cout << first() << std::endl;
    std::cin.clear();
    std::cin.seekg(0, std::cin.beg);
    std::cout << second() << std::endl;
}

int first()
{
    std::vector<int> elf_calories;

    std::string input;

    std::cin.tie(0);
    std::string tmp = "";

    int i = 0;
    int sum = 0;
    while (std::getline(std::cin, tmp))
    {
        elf_calories.push_back(0);
        if (tmp != "") 
        {
            elf_calories[i] += std::stoi(tmp);
        }
        if (tmp == "") 
        {
            if (elf_calories[i] > sum) sum = elf_calories[i];
            i++;
            continue;
        }
    }
    return sum;
}

int second()
{
    std::vector<int> elf_calories;

    std::string input;

    std::cin.tie(0);
    std::string tmp = "";

    int i = 0;
    int sum;
    elf_calories.push_back(0);
    while (std::getline(std::cin, tmp))
    {
        if (tmp != "") 
        {
            elf_calories[i] += std::stoi(tmp);
        }
        if (tmp == "") 
        {
            i++;
            elf_calories.push_back(0);
            continue;
        }
    }
    std::sort(elf_calories.begin(), elf_calories.end(), std::greater<int>());
    sum = elf_calories[0] + elf_calories[1] + elf_calories[2];

    return sum;
}
