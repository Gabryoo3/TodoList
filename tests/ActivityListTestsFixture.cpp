//
// Created by gabry on 9/24/24.
//
#ifndef ACTIVITYLISTTESTS_H
#define ACTIVITYLISTTESTS_H
#include <gtest/gtest.h>
#include "../Activity.h"
#include "../ActivityList.h"
#include "../TUI.h"

class ActivityListTestsFixture : public ::testing::Test {

protected:

    ActivityList* al{};
    Observer* obs{};

    void SetUp() override {
        al = new ActivityList();
        obs = new TUI();
    }
};

TEST_F(ActivityListTestsFixture, testAddActivity) {
    auto time = std::chrono::system_clock::now();
    EXPECT_TRUE(al->addActivity("test", time));
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testCompleteActivity) {
    al->addActivity("test", std::chrono::system_clock::now());
    EXPECT_FALSE(al->completeActivity(0,std::chrono::system_clock::now())); //false because activity is not completed yet
    al->printActivities();
    EXPECT_EQ(al->saveList(), 0);
    EXPECT_EQ(al->getListFromFile(), 0);
}

TEST_F(ActivityListTestsFixture, testCompleteActivityAlreadyDone) {
    al->addActivity("test", std::chrono::system_clock::now());
    al->completeActivity(0,std::chrono::system_clock::now());
    EXPECT_TRUE(al->completeActivity(0,std::chrono::system_clock::now())); //true because activity is already completed
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

//remove and complete nonexistent activity return sigsev because the control of the index is not done by the method
//but by the caller, so it is not a test unless you check the caller

TEST_F(ActivityListTestsFixture, testGetActivityByIndex) {
    auto time = std::chrono::system_clock::now();
    al->addActivity("test", time);
    EXPECT_EQ(al->getActivity(0).getNameActivity(), "test");
    EXPECT_THROW(al->getActivity(1), std::out_of_range);
}


//test conteggio attività
TEST_F(ActivityListTestsFixture, testGetSize) {
    al->addActivity("test", std::chrono::system_clock::now());
    EXPECT_EQ(al->getSize(), 1);
    al->removeActivity(0);
    EXPECT_EQ(al->getSize(), 0);
}

TEST_F(ActivityListTestsFixture,testCountActivities) {
    al->addActivity("test", std::chrono::system_clock::now());
    al->addActivity("test2", std::chrono::system_clock::now());
    EXPECT_EQ(al->remainingActivities(), 2);
    al->removeActivity(0);
    EXPECT_EQ(al->remainingActivities(), 1);
    al->removeActivity(0);
    EXPECT_EQ(al->remainingActivities(), 0);
}

TEST_F(ActivityListTestsFixture, testAttachDetachObserver) {
    al->attach(obs);
    EXPECT_EQ(al->numObservers(), 1);
    al->detach(obs);
    EXPECT_EQ(al->numObservers(), 0);
}

#endif //ACTIVITYLISTTESTS_H


