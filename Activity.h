//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <iostream>
#include <chrono>

class Activity {
public:
    Activity(const std::string& name, const std::chrono::system_clock::time_point& currTime): nameActivity(name), startTime(currTime) {
    }

    std::string getNameActivity() const{
        return nameActivity; //FIXME
    }

    bool isDone() const {
        return done;
    }

    std::chrono::system_clock::time_point getStartTime() const{ //aggiungere controllo
        return startTime;
    }

    std::chrono::system_clock::time_point getEndTime() const{
        return endTime;
    }

    void setNameActivity(const std::string &nameActivity){
        Activity::nameActivity = nameActivity;
    }

    void setDone(const bool done) {
        Activity::done = done;
    }

    void setEndTime(const std::chrono::system_clock::time_point &endTime){
        if (endTime < startTime && endTime != std::chrono::system_clock::time_point()) {
            throw std::invalid_argument("End time cannot be before start time");
        }
        Activity::endTime = endTime;
    }


private:
    std::string nameActivity;
    bool done = false;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
};


#endif //TODOLIST_ACTIVITY_H
