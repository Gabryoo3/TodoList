//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <vector>
#include <iostream>
#include <fstream>
#include "Activity.h"
#include <string>

class ActivityList {
public:
    int getList();

    void saveList() const ;

    void addActivity ();

    void completeActivity();

    void removeActivity();

    void printActivities() const;



private:
    std::vector<Activity> ActList;

};


#endif //TODOLIST_ACTIVITYLIST_H
