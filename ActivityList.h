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

    int addActivity(std::string activityName);

    int completeActivity(int complete);

    int removeActivity(int remove);

    void printActivities() const;

    int getSize() const {
        return ActList.size();
    }

    Activity& getActivity(const int index) {
        return ActList[index];
    }



private:
    std::vector<Activity> ActList;
};


#endif //TODOLIST_ACTIVITYLIST_H
