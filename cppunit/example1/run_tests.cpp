#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "example1_simpleAssertions.h"

// For a test suite to be run when executing runner.run(), it must first be
// registered
CPPUNIT_TEST_SUITE_REGISTRATION( MyExampleModuleTests);

int main( int argc, char **argv)
{
    // Object in charge of executing the registered test suites
	CppUnit::TextUi::TestRunner runner;

	// We start by getting the test registry (TestFactoryRegistry)
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	// When we call makeTest() we create a test suite object for the test
    // that has been previously registered with _REGISTRATION
    // Then we use the result to add it to the list of tests suites to be
    // executed by runner.run()
	runner.addTest(registry.makeTest());
    bool success = runner.run("", false);

    // We can use the return value of the main function to perform further
    // actions. For example, if the unit tests are being launched in the
    // context of a continuous integration system such as Jenkins, this could
    // tell Jenkins that it should abort the build process because the unit
    // tests for one module have failed
    return success ? 0 : 1;
}
