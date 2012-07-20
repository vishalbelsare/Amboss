/*
 * EntityTest.cpp
 *
 *  Created on: 19.06.2012
 *      Author: karsten
 */

#include <sstream>
#include <iostream>

#include <cppunit/config/SourcePrefix.h>
#include <cppunit/extensions/HelperMacros.h>

#include <Amboss/KML/Entity.h>
#include <Amboss/KML/WriterHelper.h>

#define TEST_NAME KMLEntityTest

using namespace Amboss::KML;

struct TestingPoint
{
    TestingPoint( void ) : x( 0.0 ) , y( 0.0 ) { }
    TestingPoint( double _x , double _y ) : x( _x ) , y( _y ) { }
    double x;
    double y;
};


namespace Amboss {
namespace KML {

template<>
struct WriteObject< TestingPoint >
{
    static inline void write( std::ostream &out , const TestingPoint &p , size_t indent , const std::string &name )
    {
	writePoint( out , p.x , p.y , indent , name );
    }
};

} // namespace KML
} // namespace Amboss 

using namespace std;

class TEST_NAME : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( TEST_NAME );
    CPPUNIT_TEST( testDefaultConstruction );
    CPPUNIT_TEST( testValueConstruction );
    CPPUNIT_TEST( testCopyConstruction );
    CPPUNIT_TEST( testCopying );
    CPPUNIT_TEST( testOneTestingPoint );
    CPPUNIT_TEST( testTwoTestingPoint );
    CPPUNIT_TEST_SUITE_END();

public:

    void setUp()
    {
    }

    void tearDown()
    {
    }

protected:

    void testDefaultConstruction( void )
    {
        Entity e;
    }

    void testValueConstruction( void )
    {
        TestingPoint p;
        Entity e( p );
    }

    void testCopyConstruction( void )
    {
        Entity e1;
        Entity e2( e1 );

        TestingPoint p;
        Entity e3( p );
        Entity e4( e3 );
    }

    void testCopying( void )
    {
        Entity e1;
        Entity e2;
        e2 = e1;

        TestingPoint p1 , p2;
        Entity e3( p1 );
        Entity e4( p2 );
        e3 = e4;
    }

    void testOneTestingPoint( void )
    {
        Entity e( TestingPoint( 10.0 , 10.0 ) );
        ostringstream str;
        e.write( str , 0 );
	
        string cmp = 
            "<Placemark>\n"
            "  <Point>\n"
	    "    <coordinates>\n"
	    "      10,10,0 \n"
	    "    </coordinates>\n"
	    "  </Point>\n"
	    "</Placemark>\n";

	CPPUNIT_ASSERT( cmp == str.str() );
    }

    void testTwoTestingPoint( void )
    {
        Entity e1( TestingPoint( 10.0 , 10.0 ) );
        Entity e2( TestingPoint( 5.0 , 5.0 ) );
        e2 = e1;
        ostringstream str;
        e2.write( str , 0 );
	
        string cmp = 
            "<Placemark>\n"
            "  <Point>\n"
	    "    <coordinates>\n"
	    "      10,10,0 \n"
	    "    </coordinates>\n"
	    "  </Point>\n"
	    "</Placemark>\n";

	CPPUNIT_ASSERT( cmp == str.str() );

    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_NAME );