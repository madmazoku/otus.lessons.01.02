#define BOOST_TEST_MODULE TestMain
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_version)
{

	BOOST_CHECK(1 > 0);
}

BOOST_AUTO_TEST_SUITE_END()