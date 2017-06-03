#include <sum.h>

#include <ctest.h>

CTEST(check_suite,check_knowingly_true)
{
const int expected = 1;
const int result = isnumbercorrect(1234);
ASSERT_EQUAL(expected, result);
}