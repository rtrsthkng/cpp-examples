#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void print_elements(const std::vector<int>& numbers);
std::string concatenate_strings(const std::string& str1, std::string& str2);

void print_elements(const std::vector<int>& numbers)
{
    int j = 0;
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << j << ": " << *it << std::endl;
        j++;
    }
}

std::string concatenate_strings(const std::string& str1, std::string& str2)
{
    std::string result;

    //copy(begin, end, out);
    /*
    back_inserter() is a iterator adaptor, which are functions that yield
    iterators with properties that are related to their arguments in useful ways.
    The iterator adaptors are defined in <iterator> . The most common iterator 
    adaptor is back_inserter , which takes a container as its argument and 
    yields an iterator that, when used as a destination, appends values to the 
    container
    */
    copy(str1.begin(), str1.end(), back_inserter(result));
    copy(str2.begin(), str2.end(), back_inserter(result));

    return result;
}

int main()
{
    std::string name = "Arturo";
    std::string surname = "Medina";
    std::string full_name = concatenate_strings(name, surname);
    std::cout << full_name << std::endl;
}
