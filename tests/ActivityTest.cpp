//
// Created by gabry on 23/09/24.
//



#ifndef ACTIVITYTEST_H
#define ACTIVITYTEST_H
#include "lib/googletest-1.15.2/googletest/include/gtest/gtest.h"
#include "lib/googletest-1.15.2/googletest/include/gtest/gtest_pred_impl.h"
#include "../Activity.h"


class ActivityTest : public ::testing::Test {

protected:
    Activity* activity;
    virtual void SetUp() {
        activity = new Activity("Test");
        ASSERT_EQ(activity->getNameActivity(),"Test");


    }

    virtual void TearDown()  {
        delete activity;
    }
};


#endif //ACTIVITYTEST_H
