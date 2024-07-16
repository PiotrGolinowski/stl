#include <forward_list>
#include <iostream>
#include <string>
#include <algorithm>
#include "sort.hpp"

bool compare_char(unsigned char x, unsigned char y)
{
    return tolower(x) < tolower(y);
}


bool compare_string(std::string input1, std:: string input2)
{
    if (input1.size() == input2.size())
        return std::lexicographical_compare(input1.begin(),input1.end(),input2.begin(),input2.end(), compare_char);

    return input1.size() < input2.size();
}


std::deque<std::string> lengthSort(std::forward_list<std::string> input)
{
    std::deque<std::string> output {};
    input.sort(compare_string);

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        output.push_back(*it);

    }
    return output;
}


template <typename Container>
void printCollection(const Container& collection) {
    for (const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::forward_list<std::string> words = {
        "Somebody", "once", "told", "me", "the", "world", "is", "gonna", "roll", "me"};
    printCollection(words);
    auto sorted = lengthSort(words);
    printCollection(sorted);

    return 0;
}
