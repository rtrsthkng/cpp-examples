#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define THRESHOLD 5

bool compare_with_threshold(int number);
bool some_element_is_below_threshold(std::vector<int> my_vector);

bool compare_with_threshold(int number)
{
    return number < THRESHOLD;
}

bool some_element_is_below_threshold(std::vector<int> my_vector)
{
    std::vector<int>::const_iterator it = find_if(my_vector.begin(), my_vector.end(), compare_with_threshold);
    if (it != my_vector.end())
        return true;
    else
        return false;
}

int main()
{
    std::vector<int> my_vector = {8, 7, 8, 2, 5, 6, 3};
    std::vector<int> my_vector2 = {8, 7, 8, 6, 5, 6, 8};

    std::cout << "Failed: " << some_element_is_below_threshold(my_vector) << std::endl;
    std::cout << "Failed: " << some_element_is_below_threshold(my_vector2) << std::endl;
}
