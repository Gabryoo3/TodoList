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
    auto time = std::chrono::system_clock::now();
    EXPECT_EQ(al->addActivity("test", time), 0);
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testCompleteActivity) {
    al->addActivity("test", std::chrono::system_clock::now());
    EXPECT_TRUE(al->completeActivity(0,std::chrono::system_clock::now()));
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testRemoveActivity) {
    al->addActivity("test", std::chrono::system_clock::now());
    al->removeActivity(0);
    EXPECT_EQ(al->getSize(), 0);
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);

}

//test conteggio attività
TEST_F(ActivityListTestsFixture, testGetSize) {
    al->addActivity("test", std::chrono::system_clock::now());
    EXPECT_EQ(al->getSize(), 1);
    al->removeActivity(0);
    EXPECT_EQ(al->getSize(), 0);
}




#endif //ACTIVITYLISTTESTS_H


