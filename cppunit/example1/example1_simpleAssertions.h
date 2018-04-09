#ifndef MY_EXAMPLE_MODULE_TESTS
#define MY_EXAMPLE_MODULE_TESTS

#include <string>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

// This class will contain the declaration of the unit tests. It inherits from
// the CppUnit:TestFixture class. "TestFixture" is being used instead of the
// simpler "TestCase" because "TextFixture" allows the user to define a set
// of objects that will be used throughout the test suite, so that they do not
// have to be declared on every time. The definition of the objects takes place
// in the setUp() method, and they are destroyed in the tearDown() method. Such
// methods are not present in the "TestUnit" class
class MyExampleModuleTests : public CppUnit::TestFixture
{
    // Start the declaration of a new test suite
	CPPUNIT_TEST_SUITE(MyExampleModuleTests);

    // Groups of tests to be run. We use the term 'group' because although
    // each CPPUNIT_TEST declares a single CppUnit test, each of them will
    // be divided into smaller tests (implemented as independent methods),
    // which will be run one after the other
	CPPUNIT_TEST(exampleTests);
	CPPUNIT_TEST(moreExampleTests);

    // End the declaration of the test suite
	CPPUNIT_TEST_SUITE_END();

	public:

    // The setUp process if for initializing fixtures and preparing everything
    // that we need before test execution
	void setUp()
	{
		std::cout << "Setting up" << std::endl;
        number1 = 1;
	}

    // The teardown process is for performing clean-up after the test. If we
    // had allocated memory during setUp, this would be the place for freeing
    // it
	void tearDown()
	{
		std::cout << "Finished" << std::endl;
	}

    // These methods will be used to call the test() method of each individual
    // test group
	void exampleTests();
	void moreExampleTests();

    protected:
        int number1;
        int number2;
};

#endif /* MY_EXAMPLE_MODULE_TESTS */
