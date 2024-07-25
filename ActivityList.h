//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <list>
#include <iostream>
#include <fstream>
#include "Activity.h"

class ActivityList {
public:
    int getList();

    int saveList();

private:
    std::list<Activity> ActList;
};


#endif //TODOLIST_ACTIVITYLIST_H
