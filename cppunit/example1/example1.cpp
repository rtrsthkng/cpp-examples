#include "example1.h"

// For a list of existing assertion types, check: http://cppunit.sourceforge.net/doc/cvs/group___assertions.html
class exampleTests{
    public:
        static bool test() {
            testAssert();
            testAssertNegated();
            return true;
        }
    private:
        static bool testAssert() {
            // Assertions that a condition is true
            CPPUNIT_ASSERT(1 == 1);
            return true;
        }
        static bool testAssertNegated() {
            // Check that 2 is NOT smaller than 1
            CPPUNIT_ASSERT(! 2 < 1);
            return true;
        }
};

class moreExampleTests{
    public:
        static bool test() {
            testAssertEqual();
            testAssertAssertionFail();
            return true;
        }
    private:
        static bool testAssertEqual() {
            // Asser that two numbers are equal
            CPPUNIT_ASSERT_EQUAL(5,5);
            return true;
        }
        static bool testAssertAssertionFail() {
            // Assert that saying "5 is bigger than 8" is a false
            CPPUNIT_ASSERT_ASSERTION_FAIL(5 > 8);
            return true;
        }
};

void MyExampleModuleTests::exampleTests(void) {
    exampleTests::test();
}
void MyExampleModuleTests::moreExampleTests(void) {
    moreExampleTests::test();
}
