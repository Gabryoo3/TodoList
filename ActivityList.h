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
#include <ctime>
#include "Activity.h"
#include "Observer.h"


class ActivityList {
public:
    ActivityList() = default;
    int getListFromFile();

    int saveList() const ;

    bool addActivity(const std::string& activityName, const std::chrono::system_clock::time_point& time);

    bool completeActivity(int complete, const std::chrono::system_clock::time_point& time);

    void removeActivity(int remove);

    void printActivities() const;

    int remainingActivities() const;

    int getSize() const {
        return actList.size();
    }

    Activity& getActivity(int index) {
        if (index < 0 || index >= actList.size()) {
            throw std::out_of_range("Activity index out of range");
        }
        return actList.at(index);
    }

    void attach(Observer* obs) {
        observers.push_back(obs);
    }

    void detach(Observer* obs) {
        std::erase(observers, obs);
        //delete for observer value
    }

    void notifyAdd(const Activity& act) {
        for(Observer* obs : observers) {
            obs->updateAdd(act);
        }
    }

    void notifyComplete(const Activity& act) {
        for(Observer* obs : observers) {
            obs->updateComplete(act);
        }
    }

    void notifyRemove(const Activity& act) {
        for(Observer* obs : observers) {
            obs->updateRemove(act);
        }
    }


private:
    std::vector<Activity> actList;
    std::vector<Observer*> observers;
};


#endif //TODOLIST_ACTIVITYLIST_H
