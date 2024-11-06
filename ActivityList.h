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
    int getListFromFile();

    void saveList() const ;

    Activity& addActivity(std::string activityName);

    void completeActivity(int complete);

    void removeActivity(int remove);

    void printActivities() const;

    int getSize() const {
        return ActList.size();
    }



private:
    std::vector<Activity> ActList;
};


#endif //TODOLIST_ACTIVITYLIST_H
