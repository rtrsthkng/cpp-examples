
/*C++ input/output streams are primarily defined by iostream, a header file that is part of the
C++ standard library (the name stands for Input/Output Stream)
...
The cout object is of type ostream, which overloads the left bit-shift operator to make it
perform an operation completely unrelated to bitwise operations, and notably evaluate to the
value of the left argument, allowing multiple operations on the same ostream object, essentially
as a different syntax for method cascading, exposing a fluent interface*/
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    for (int x = 0; x < 100; x++) {
        //The '\r' returns the cursors to the beginning of the line
        cout << "Loading: " << x << " % \r";
        //The same as
        //std::cout << "Loading: " << x << " % \r";
        //if we hadn't used the namespace 'std'
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    cout << endl;
}
