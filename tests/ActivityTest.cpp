//
// Created by gabry on 9/24/24.
//

#ifndef  ACTIVITYTEST_H
#define ACTIVITYTEST_H
#include <gtest/gtest.h>

#include "../Activity.h"

TEST(ActivityTest, testConstructor) {
    auto now = std::chrono::system_clock::now();
    const std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
    const Activity activity("Test", time);
    ASSERT_EQ(activity.getNameActivity(), "Test");
    ASSERT_FALSE(activity.isDone());
}


#endif//ACTIVITYTEST_H
