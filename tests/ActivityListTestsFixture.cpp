//
// Created by gabry on 9/24/24.
//
#ifndef ACTIVITYLISTTESTS_H
#define ACTIVITYLISTTESTS_H
#include <gtest/gtest.h>
#include "../Activity.h"
#include "../ActivityList.h"

class ActivityListTestsFixture : public ::testing::Test {

protected:

    ActivityList* al{};
    std::string time;

    void SetUp() override {
        al = new ActivityList();
    }
};

TEST_F(ActivityListTestsFixture, testAddActivity) {
    auto now = std::chrono::system_clock::now();
    time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
    ASSERT_EQ(al->addActivity("test", time), 0);
    al->printActivities();
    ASSERT_EQ(al->saveList(), 0);
    ASSERT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testCompleteActivity) {
    auto now = std::chrono::system_clock::now();
    const std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
    ASSERT_EQ(al->completeActivity(0,time), 0);
    al->printActivities();
    ASSERT_EQ(al->saveList(), 0);
    ASSERT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testRemoveActivity) {
    ASSERT_EQ(al->removeActivity(0), 0);
    al->printActivities();
    ASSERT_EQ(al->saveList(), 0);
    ASSERT_EQ(al->getListFromFile(), 0);
}





#endif //ACTIVITYLISTTESTS_H


