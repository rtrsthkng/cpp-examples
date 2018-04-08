#include "example1.h"


class exampleTests{
 public:
  static bool test() {
    testStringsMinLength();
    testStringsMaxLength();
    return true;
  }
 private:
  static bool testStringsMinLength() {
    // Assertions that a condition is true
    // For more assertion types, check: http://cppunit.sourceforge.net/doc/cvs/group___assertions.html
    CPPUNIT_ASSERT(! 1 == 1);
    return true;
  }
  static bool testStringsMaxLength() {
    return true;
  }
};

class moreExampleTests{
 public:
  static bool test() {
    testStringsContent1();
    testStringsContent2();
    return true;
  }
 private:
  static bool testStringsContent1() {
    return true;
  }
  static bool testStringsContent2() {
    return true;
  }
};

void MyExampleModuleTests::exampleTests(void) {
      exampleTests::test();
}
void MyExampleModuleTests::moreExampleTests(void) {
      moreExampleTests::test();
}
