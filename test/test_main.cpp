#include <gtest/gtest.h>
#include <mp/fixed_string.h>
#include <stdexcept>

#pragma GCC diagnostic ignored "-Wunused-result"

using namespace ::testing;
using namespace mp;

#ifdef gsl_lite_MAJOR
#define EXPECT_TERMINATE(x) ASSERT_DEATH(x, "terminate called without an active exception")
#else
#define EXPECT_TERMINATE(x) EXPECT_NO_THROW(x)
#endif

TEST(FixedString, AtOutOfBoundaries) {
    fixed_string<3> fs { "123" };
    EXPECT_THROW(fs.at(3), std::out_of_range); // 122 Throws: out_of_range if n >= a.size().
}

TEST(FixedString, IndexOutOfBoundaries) {
    fixed_string<3> fs { "123" };
    EXPECT_TERMINATE(fs[3]);
}

TEST(FixedString, FrontOfEmpty) {
    fixed_string<0> fs{ "" };
    EXPECT_TERMINATE(fs.front());
}

TEST(FixedString, BackOfEmpty) {
    fixed_string<0> fs{ "" };
    EXPECT_TERMINATE(fs.back());
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
