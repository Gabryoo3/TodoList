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

    void SetUp() override {
        al = new ActivityList();
    }
};

TEST_F(ActivityListTestsFixture, testAddActivity) {
    const std::string time = "07-08-2019 14:19:32";
    EXPECT_EQ(al->addActivity("test", time), 0);
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testCompleteActivity) {

    const std::string timeStart = "08-08-2019 14:19:32";
    const std::string timeEnd = "08-08-2019 14:19:32";
    al->addActivity("test", timeStart);
    EXPECT_EQ(al->completeActivity(0,timeEnd), 0);
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testRemoveActivity) {
    const std::string timeStart = "07-08-2019 14:19:32";
    const std::string timeEnd = "08-08-2019 14:19:32";
    al->addActivity("test", timeStart);
    al->completeActivity(0, timeEnd);
    EXPECT_EQ(al->removeActivity(0), 0);
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}





#endif //ACTIVITYLISTTESTS_H


