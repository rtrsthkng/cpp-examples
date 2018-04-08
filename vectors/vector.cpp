#include <iostream>
#include <string>
#include <vector>

#define INIT_N_ELEM 5
#define INIT_VAL -1

using namespace std;

void print_elements(const std::vector<int>& numbers);
void print_elements(const std::vector<int>& numbers) {
    int j = 0;
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << j << ": " << *it << std::endl;
        j++;
    }
}

int main() {
    int j = 0;
    // Construct vector of type int with INIT_N_ELEM elements of value INIT_VAL
    std::cout << "Initialize vector" << std::endl;
    std::vector<int> numbers(INIT_N_ELEM, INIT_VAL);

    std::cout << "Populate vector by appeding numbers to it" << std::endl;
    for (int x = 0; x != INIT_N_ELEM; x++) {
        //Add elements at the end of the vector
        std::cout << "Add number: " << (x*2 +1) << std::endl;
        numbers.push_back(x*2 + 1);
    }

    std::cout <<
        "We print the initial " << INIT_N_ELEM << " elements. "
        "As it can be seen, they are initialized to " << INIT_VAL
    << std::endl;
    for (int x = 0; x != INIT_N_ELEM; x++) {
        //std::cout << x <<": " << numbers[x] << std::endl; WARNING
        //std::cout << x <<": " << numbers[(size_t) x] << std::endl; WARNING
        //http://www.cplusplus.com/reference/vector/vector/operator[]
        //I should have used size_t for the type of 'x', instead of 'int'.
        //In that manner, it wouldn't be necessary to cast
        std::cout << x <<": " << numbers[static_cast<size_t>(x)] << std::endl;
    }

    std::cout << "We print all elements using iterators" << std::endl;
    //numbers.erase(0); //This does not work because the erase method takes
    //an iterator for an argument
    numbers.erase(numbers.begin() + 0); //Erase first element
    std::cout << "We have removed the first element" << std::endl;
    print_elements(numbers);

    numbers.erase(numbers.begin() + 0); //Erase first element
    std::cout << "We have removed the first element again" << std::endl;
    print_elements(numbers);
}
