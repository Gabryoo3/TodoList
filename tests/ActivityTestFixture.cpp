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
        auto now = std::chrono::system_clock::now();
        std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
        activity = new Activity("Test", time);
    }
};

TEST_F(ActivityTestFixture, testSetNameActivity) {
    activity->setNameActivity("Test2");
    ASSERT_EQ(activity->getNameActivity(), "Test2");
}

TEST_F(ActivityTestFixture, testSetDone) {
    activity->setDone(true);
    ASSERT_TRUE(activity->isDone());
}




#endif //ACTIVITYTEST_H
