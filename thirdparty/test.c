#include <stdio.h>
#include <stdlib.h>
#include "ctest.h"
#include "libgeometry/check.h"
#include <stdbool.h>

CTEST(input, word_check1)
{
    char* str = "Circle(1 2,3)";
    bool result = name_verification(str);
    ASSERT_TRUE(result);
}
CTEST(input, word_check2)
{
    char* str = "circle(1 2,3)";
    bool result = name_verification(str);
    ASSERT_FALSE(result);
}
CTEST(input, word_check3)
{
    char* str = "circle(1 2,3)";
    bool result = checking_parameters_figure(str);
    ASSERT_TRUE(result);
}
CTEST(input, word_check4)
{
    char* str = "circle(3 3 3)";
    bool result = checking_parameters_figure(str);
    ASSERT_FALSE(result);
}
CTEST(input, word_check5)
{
    char* str = "circle( 2,3";
    bool result = checking_parameters_figure(str);
    ASSERT_TRUE(result);
}
