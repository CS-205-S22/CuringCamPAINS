#include <iostream>
#include "gtest/gtest.h"
#include "contacttest.h"
#include "contactlisttest.h"
#include "csvtest.h"
#include "customtest.h"
#include "databasetest.h"
#include "logtest.h"
#include "logintest.h"
#include "savedmessagestest.h"

/**
 * @brief main runs the unit tests.
 *
 * @param argc default number of arguments.
 * @param argv default array of arguments.
 * @return int RUN_ALL_TESTS() output.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
