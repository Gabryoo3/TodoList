//
// Created by gabry on 7/25/24.
//
//TODO segnare quante attività sono state completate o non completate
//TODO conteggio attività
#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Activity.h"


class ActivityList {
public:
    ActivityList() = default;
    int getListFromFile();

    int saveList() const ;

    int addActivity(const std::string& activityName, const std::string& time);

    int completeActivity(int complete, const std::string& time);

    int removeActivity(int remove);

    void printActivities() const;

    int remainingActivities() const;

    int getSize() const {
        return ActList.size();
    }




private:
    std::vector<Activity> ActList;
};


#endif //TODOLIST_ACTIVITYLIST_H
