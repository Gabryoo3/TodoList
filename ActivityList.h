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
    ActivityList(): ActList() {
    };
    int getListFromFile() const;

    int saveList() const ;

    int addActivity(const std::string& activityName) const;

    int completeActivity(int complete) const;

    int removeActivity(int remove) const;

    void printActivities() const;

    int getSize() const {
        return ActList.size();
    }

    /*Activity& getActivity(const int index) {
        return ActList[index];
    }*/



private:
    std::vector<Activity>& ActList;
};


#endif //TODOLIST_ACTIVITYLIST_H
