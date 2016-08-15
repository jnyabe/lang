#ifndef CPPUNIT_XMLTESTRESULTOUTPUTTER_H
#define CPPUNIT_XMLTESTRESULTOUTPUTTER_H

#include <cppunit/Portability.h>

#include <cppunit/Outputter.h>
#include <cppunit/portability/CppUnitDeque.h>
#include <cppunit/portability/CppUnitMap.h>
#include <cppunit/portability/Stream.h>

class TestLinkOutputter : public Outputter
{
public:
	TestLinkOutputter( TestResultCollector *result,
					   OStream &stream,
					   std::string encoding = std::string("UTF-8") );
	virtual ~TestLinkOutputter();
	
	 virtual void write();


};

