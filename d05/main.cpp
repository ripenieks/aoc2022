#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

std::string first(const std::vector<std::string>& input);
std::string second(const std::vector<std::string>& input);

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

    void MoveByOne(const std::string& move_info)
    {
        int it = 5; // skip the word move
        int crate_count = 0;
        int stack_from = 0;
        int stack_to = 0;
        while (move_info[it] != ' ')
        {
            crate_count = crate_count * 10 + (move_info[it] - '0');
            it++;
        }
        it += 6; // skip the word from
        while (move_info[it] != ' ')
        {
            stack_from = stack_from * 10 + (move_info[it] - '0');
            it++;
        }
        it += 4; // skip the word to
        while (it < move_info.length())
        {
            stack_to = stack_to * 10 + (move_info[it] - '0');
            it++;
        }

        for (int i = 0; i < crate_count; i++)
        {
            char c = stacks[stack_from - 1].back();
            stacks[stack_from - 1].pop_back();
            stacks[stack_to - 1].push_back(c);
        }
    }

    void MoveMultiple(const std::string& move_info)
    {
        int it = 5; // skip the word move
        int crate_count = 0;
        int stack_from = 0;
        int stack_to = 0;
        while (move_info[it] != ' ')
        {
            crate_count = crate_count * 10 + (move_info[it] - '0');
            it++;
        }
        it += 6; // skip the word from
        while (move_info[it] != ' ')
        {
            stack_from = stack_from * 10 + (move_info[it] - '0');
            it++;
        }
        it += 4; // skip the word to
        while (it < move_info.length())
        {
            stack_to = stack_to * 10 + (move_info[it] - '0');
            it++;
        }
        std::vector<char> move_stack;
        for (int i = crate_count - 1; i >= 0; i--)
        {
            move_stack.push_back(stacks[stack_from - 1].at(stacks[stack_from - 1].size() - 1 - i));
        }
        stacks[stack_from - 1].erase(stacks[stack_from - 1].end() - crate_count, stacks[stack_from - 1].end());
        stacks[stack_to - 1].insert(stacks[stack_to - 1].end(), move_stack.begin(), move_stack.end());
    }

    void DisplayFull()
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
    
    std::string GetTopCrates()
    {
        std::string tops = "";
        for (std::vector<char> stack : stacks)
        {
            tops.push_back(stack.back());
        }
        return tops;
    }
};

std::string first(const std::vector<std::string>& input)
{
    int stack_coord = 0;
    while (input[stack_coord][1] != '1')
    {
        stack_coord++;
    }
    int stack_count = input[stack_coord].length() / 4 + 1; // works for numbers up to 9 :D
    Crates crates(stack_count);

    std::vector<std::string> crates_init_pos;
    for (int i = 0; i < stack_coord; i++)
    {
        crates_init_pos.push_back(input[i]);
    }
    crates.Populate(crates_init_pos);
    //crates.DisplayFull();
    for (int i = stack_coord + 2; i < input.size(); i++)
    {
        crates.MoveByOne(input[i]);
    }
    //std::cout << "======================" << std::endl;
    //crates.DisplayFull();
    return crates.GetTopCrates();
}

std::string second(const std::vector<std::string>& input)
{
    int stack_coord = 0;
    while (input[stack_coord][1] != '1')
    {
        stack_coord++;
    }
    int stack_count = input[stack_coord].length() / 4 + 1; // works for numbers up to 9 :D
    Crates crates(stack_count);

    std::vector<std::string> crates_init_pos;
    for (int i = 0; i < stack_coord; i++)
    {
        crates_init_pos.push_back(input[i]);
    }
    crates.Populate(crates_init_pos);
    //crates.DisplayFull();
    for (int i = stack_coord + 2; i < input.size(); i++)
    {
        crates.MoveMultiple(input[i]);
    }
    //std::cout << "======================" << std::endl;
    //crates.DisplayFull();
    return crates.GetTopCrates();
}
