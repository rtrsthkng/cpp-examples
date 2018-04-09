#include "example1.h"

// For a list of existing assertion types, check: http://cppunit.sourceforge.net/doc/cvs/group___assertions.html
//

// Our first group of tests. In this one, two types of assertions are shown,
// testAssert and testAssertNegated. As it can be seen, one after the other in
// the test() method of the class.
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

// Our second group of tests, this time with two additional types of assertions
class moreExampleTests{
    public:
        static bool test() {
            testAssertEqual();
            testAssertAssertionFail();
            return true;
        }
    private:
        static bool testAssertEqual() {
            // Assert that two numbers are equal
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
