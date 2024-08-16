//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <iostream>
#include <chrono>


class Activity {
public:
    Activity(std::string name) : nameActivity(name){
        //insertTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //prende il tempo attuale per inserimento
    }
    const std::string &getNameActivity() const {
        return nameActivity;
    }

    bool isDone() const {
        return done;
    }
    void setNameActivity(const std::string &nameActivity) {
        Activity::nameActivity = nameActivity;
    }

    void setDone(const bool done) {
        Activity::done = done;
    }

    /*time_t getInsertTime() const {
        return insertTime;
    }

    void setInsertTime(time_t insertTime) {
        Activity::insertTime = insertTime;
    }

    time_t getFinishedTime() const {
        return finishedTime;
    }

    void setFinishedTime(time_t finishedTime) {
        Activity::finishedTime = finishedTime;
    }*/



private:
    std::string nameActivity;
    bool done = false;
    /*std::time_t insertTime;
    std::time_t finishedTime;*/
};


#endif //TODOLIST_ACTIVITY_H
