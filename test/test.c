#include "../src/usersnumber.h"
#include <ctest.h>

CTEST(check_suite,check_knowingly_true)
{
    const int expected = 1;
    const int result = isnumbercorrect(1234);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_suite, check_correct_2000)
{
    ASSERT_EQUAL(0, isnumbercorrect(2000));
}

CTEST(check_suite, check_correct_3000)
{
    ASSERT_EQUAL(0, isnumbercorrect(3000));
}

CTEST(check_suite, check_correct_4000)
{
    ASSERT_EQUAL(0, isnumbercorrect(4000));
}

CTEST(check_suite, check_incorrect_num)
{
    ASSERT_EQUAL(0, isnumbercorrect(41232342));
}