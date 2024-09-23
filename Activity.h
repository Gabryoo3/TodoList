//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <iostream>



class Activity {
public:
    Activity(std::string name) : nameActivity(name){

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


private:
    std::string nameActivity;
    bool done = false;

};


#endif //TODOLIST_ACTIVITY_H
