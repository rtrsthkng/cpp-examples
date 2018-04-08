#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "example1.h"

CPPUNIT_TEST_SUITE_REGISTRATION( MyExampleModuleTests);

int main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	// First, we retreive the instance of the TestFactoryRegistry:

	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	// Then, we obtain and add a new TestSuite created by the TestFactoryRegistry that contains all the test suite registered using CPPUNIT_TEST_SUITE_REGISTRATION().

	runner.addTest(registry.makeTest());
    bool success = runner.run("", false);
    return success ? 0 : 1;
}
