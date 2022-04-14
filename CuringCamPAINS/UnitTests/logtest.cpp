#include "logtest.h"

LogTest::LogTest() {
}

TEST(Log, UnimplementedTest) {
    ASSERT_TRUE(false) << "This test was not implemented. Failing...";
}
