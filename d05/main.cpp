#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int first(const std::vector<std::string>& input);
int second(const std::vector<std::string>& input);

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

struct Crates
{
    int stack_count;
    std::vector<std::vector<char>> stacks;
    
    Crates(int count)
    {
        stack_count = count;
        stacks.resize(stack_count);
    }

    void Populate(std::vector<std::string>& crates)
    {
        for (std::vector<std::string>::reverse_iterator it = crates.rbegin(); it != crates.rend(); it++)
        {
            for (int j = 0, i = 1; i < (*it).length(); j++, i = i + 4)
            {
                if ((*it)[i] != ' ') stacks[j].push_back((*it)[i]);
            }
        }
    }

    void Display()
    {
        for (int i = 0; i < stack_count; i++)
        {
            for (char c : stacks[i])
            {
                std::cout << "[" << c << "] ";
            }
            std::cout << std::endl;
        }
    }
};

int first(const std::vector<std::string>& input)
{
    int stack_coord = 0;
    while (input[stack_coord][1] != '1')
    {
        stack_coord++;
    }
    int stack_count = input[stack_coord].length() / 4 + 1; // works for numbers up to 9 :D
    //std::cout << stack_count << std::endl;
    Crates crates(stack_count);

    std::vector<std::string> crates_init_pos;
    for (int i = 0; i < stack_coord; i++)
    {
        crates_init_pos.push_back(input[i]);
    }
    crates.Populate(crates_init_pos);
    crates.Display();

    return 0;
}

int second(const std::vector<std::string>& input)
{
    return 0;
}
