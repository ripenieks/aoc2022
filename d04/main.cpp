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

bool check_full_overlap(const std::string& pair)
{
    int low_a = 0;
    int high_a = 0;
    int low_b = 0;
    int high_b = 0;
    // parsing    
    int it = 0;
    while (pair[it] != '-')
    {
        low_a = low_a * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (pair[it] != ',')
    {
        high_a = high_a * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (pair[it] != '-')
    {
        low_b = low_b * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (it < pair.length())
    {
        high_b = high_b * 10 + (pair[it] - '0');
        it++;
    }

    if      (low_a <= low_b && high_a >= high_b) return true;
    else if (low_b <= low_a && high_b >= high_a) return true;
    else                                         return false;
}

int first(const std::vector<std::string>& input)
{
    int res = 0;
    for (int i = 0; i < input.size(); i++)
    {
        res += check_full_overlap(input[i]);
    }
    return res;
}

bool check_overlap(const std::string& pair)
{
    int low_a = 0;
    int high_a = 0;
    int low_b = 0;
    int high_b = 0;
    // parsing    
    int it = 0;
    while (pair[it] != '-')
    {
        low_a = low_a * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (pair[it] != ',')
    {
        high_a = high_a * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (pair[it] != '-')
    {
        low_b = low_b * 10 + (pair[it] - '0');
        it++;
    }
    it++;
    while (it < pair.length())
    {
        high_b = high_b * 10 + (pair[it] - '0');
        it++;
    }
    if      (high_a >= low_b && high_a <= high_b) return true;
    else if (high_b >= low_a && high_b <= high_a) return true;
    else return false;
}

int second(const std::vector<std::string>& input)
{
    int res = 0;
    for (int i = 0; i < input.size(); i++)
    {
        res += check_overlap(input[i]);
    }
    return res;
}
