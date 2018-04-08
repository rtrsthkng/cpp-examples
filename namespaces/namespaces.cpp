#include <iostream>

using namespace std;

namespace A {
    int var1 = 0;
}
namespace B {
    int var1 = 1;
}

int main() {
    using namespace A;
    cout << "var1: " << var1 << endl;
    using namespace B;
    //This would return an error "reference to var1 is ambiguous", since there
    //are now two namespaces that define the variable 'var1'
    //cout << "var1: " << var1 << endl;

    cout << "A::var1: " << A::var1 << endl;
    cout << "B::var1: " << B::var1 << endl;
}
