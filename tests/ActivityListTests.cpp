//
// Created by gabry on 9/24/24.
//
#ifndef ACTIVITYLISTTESTS_H
#define ACTIVITYLISTTESTS_H
#include <gtest/gtest.h>
#include "../Activity.h"
#include "../ActivityList.h"

class ActivityListTests : public ::testing::Test {

protected:
    ActivityList* al;
    Activity* activity;
    virtual void SetUp() {
        al = new ActivityList();
        activity = new Activity("Test");
    }
};

TEST_F(ActivityListTests, testAddActivity) {
    al->addActivity();
    al->saveList();
    al->printActivities();
    ASSERT_EQ(al->getList(), 0);
}

TEST_F(ActivityListTests, testCompleteActivity) {
    al->addActivity();
    al->completeActivity();
    al->printActivities();
    al->saveList();
    ASSERT_EQ(al->getList(), 0);
}

TEST_F(ActivityListTests, testRemoveActivity) {
    al->addActivity();
    al->removeActivity();
    al->printActivities();
    al->saveList();
    ASSERT_EQ(al->getList(), 0);
}



#endif //ACTIVITYLISTTESTS_H


