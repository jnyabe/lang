#ifndef _SAMPLE_TEST_H_
#define _SAMPLE_TEST_H_

#include <cppunit/extensions/HelperMacros.h> 


class SampleTest : public CPPUNIT_NS::TestFixture { 
  CPPUNIT_TEST_SUITE( SampleTest ); 
  CPPUNIT_TEST( test_init );         
  CPPUNIT_TEST( test_incr );         
  CPPUNIT_TEST( test_clear );        
  CPPUNIT_TEST_SUITE_END();          

public:
	SampleTest() {}
	virtual ~SampleTest() {}
	void setUp() {}
	void tearDown() {}

	void test_init();  
	void test_incr();  
	void test_clear(); 
};

#endif /* _SAMPLE_TEST_H_ */
