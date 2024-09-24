//
// Created by gabry on 9/24/24.
//

#ifndef  ACTIVITYTEST_H
#define ACTIVITYTEST_H
#include <gtest/gtest.h>

#include "../Activity.h"

TEST(ActivityTest, testConstructor) {
    Activity activity("Test");
    ASSERT_EQ(activity.getNameActivity(), "Test");
    ASSERT_FALSE(activity.isDone());
}


#endif//ACTIVITYTEST_H
