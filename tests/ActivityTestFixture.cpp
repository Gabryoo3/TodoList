//
// Created by gabry on 23/09/24.
//



#ifndef ACTIVITYTEST_H
#define ACTIVITYTEST_H

#include "gtest/gtest.h"

#include "../Activity.h"

class ActivityTestFixture : public ::testing::Test {

protected:
    Activity* activity{};
    void SetUp() override{
        activity = new Activity("Test", "07-08-2019 14:19:32");
    }
};

TEST_F(ActivityTestFixture, testSetNameActivity) {
    activity->setNameActivity("Test2");
    EXPECT_EQ(activity->getNameActivity(), "Test2");
    activity->setNameActivity("Test");
}

TEST_F(ActivityTestFixture, testGetNameAndDoneActivity) {
    EXPECT_EQ(activity->getNameActivity(), "Test");
    EXPECT_FALSE(activity->isDone());
}


TEST_F(ActivityTestFixture, testSetDone) {
    EXPECT_FALSE(activity->isDone());
    activity->setDone(true);
    EXPECT_TRUE(activity->isDone());
}

TEST_F(ActivityTestFixture, testSetEndTime) {
    EXPECT_NO_THROW({
            activity->getEndTime();
    });
    activity->setEndTime("08-08-2019 14:19:32");
    EXPECT_EQ(activity->getEndTime(), "08-08-2019 14:19:32");
}







#endif //ACTIVITYTEST_H
