#define BOOST_TEST_MAIN
#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( bad ) {
    BOOST_CHECK_EQUAL( 0, 0 );
}
