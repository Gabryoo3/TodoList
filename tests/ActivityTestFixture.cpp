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
        auto time = std::chrono::system_clock::now();
        activity = new Activity("Test", time);
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

//endtime < startime, gestire eccezioni
TEST_F(ActivityTestFixture, endTimeMinor)
{
    std::tm tm = {};
    std::istringstream ss("2023-12-11 12:12:12"); // Before start time
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string");
    }
    auto invalidEndTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    EXPECT_THROW(activity->setEndTime(invalidEndTime), std::invalid_argument);
}


//time impossibile, gestire eccezioni
TEST_F(ActivityTestFixture, impossibleTime)
{
    std::tm tm = {};
    std::istringstream ss("14-23-2025 12:12:12"); // Before start time
    ss >> std::get_time(&tm, "%d-%m-%y %H:%M:%S");
    EXPECT_TRUE(ss.fail());
    if (ss.fail()) {
        EXPECT_THROW(throw std::runtime_error("Failed to parse time string"), std::runtime_error);
    }
} //it can be valid also for a bad time formatting

TEST_F(ActivityTestFixture, testGetEndTimeEpoch) {
    auto endTime = activity->getEndTime();
    EXPECT_EQ(endTime, std::chrono::system_clock::time_point());
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
    std::tm tm = {};
    std::istringstream ss("2025-12-12 12:12:12");
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string");
    }
    auto time = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    activity->setEndTime(time);
    EXPECT_EQ(activity->getEndTime(), time);
}

TEST_F(ActivityTestFixture, emptyActivityName) {
    EXPECT_THROW(Activity a("", std::chrono::system_clock::now()), std::invalid_argument);
}

TEST_F(ActivityTestFixture, testSetEndTimeToSameAsStartTime) {
    auto startTime = activity->getStartTime();
    EXPECT_NO_THROW(activity->setEndTime(startTime));
    EXPECT_EQ(activity->getEndTime(), startTime);
}

#endif //ACTIVITYTEST_H
