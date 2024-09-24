//
// Created by gabry on 23/09/24.
//



#ifndef ACTIVITYTEST_H
#define ACTIVITYTEST_H

#include <gtest/gtest.h>

#include "../Activity.h"

class ActivityTest : public ::testing::Test {

protected:
    Activity* activity;
    virtual void SetUp() {
        activity = new Activity("Test");
    }
    virtual void TearDown()  {
        delete activity;
    }
};

TEST_F(ActivityTest, testGetNameActivity) {
    ASSERT_EQ(activity->getNameActivity(), "Test");
    ASSERT_FALSE(activity->isDone());
}

TEST_F(ActivityTest, testSetNameActivity) {
    activity->setNameActivity("Test2");
    ASSERT_EQ(activity->getNameActivity(), "Test2");
}

TEST_F(ActivityTest, testSetDone) {
    activity->setDone(true);
    ASSERT_TRUE(activity->isDone());
}


#endif //ACTIVITYTEST_H
