#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;

int main() {
    int bar_length  = 0;
    for (int x = 0; x <= 100; x++) {
        bar_length = floor(x * 20/100);
        cout << "[";
        for (int j = 0; j < bar_length; j++) {
            cout << "#";
        }
        for (int j = 0; j < (20 - bar_length); j++) {
            cout << " ";
        }
        cout << "]";
        cout << " " << x << " %" << "\r";
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cout << endl;
}
