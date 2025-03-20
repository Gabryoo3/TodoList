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
        /*std::tm tm = {};
        std::istringstream ss("12-12-2023 12:12:12");
        ss >> std::get_time(&tm, "%d-%m-%Y %H:%M:%S");
        /*if (ss.fail()) {
            throw std::runtime_error("Failed to parse time string");
        }*/
        //const auto time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        /*std::tm tm = {};
        tm.tm_year = 2023 - 1900; // Year since 1900
        tm.tm_mon = 9 - 1;        // Month (0-11)
        tm.tm_mday = 15;          // Day of the month (1-31)
        tm.tm_hour = 14;          // Hour (0-23)
        tm.tm_min = 30;           // Minute (0-59)
        tm.tm_sec = 0;            // Second (0-59)
        auto time = std::chrono::system_clock::from_time_t(std::mktime(&tm));*/
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
//endtime impossibile e starttime impossibile, gestire eccezioni
//endtime < startime, gestire eccezioni

TEST_F(ActivityTestFixture, testSetDone) {
    EXPECT_FALSE(activity->isDone());
    activity->setDone(true);
    EXPECT_TRUE(activity->isDone());
}

/*TEST_F(ActivityTestFixture, testSetEndTime) {
    EXPECT_NO_THROW({
            activity->getEndTime();
    });
    std::tm tm = {};
    std::istringstream ss("2023-12-12 12:12:12");
    ss >> std::get_time(&tm, "%d-%m-%Y %H:%M:%S");
    /*if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string");
    }
    auto time = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    activity->setEndTime(time);
    EXPECT_EQ(activity->getEndTime(), time);
}*/







#endif //ACTIVITYTEST_H
