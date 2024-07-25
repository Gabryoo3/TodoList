//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <iostream>
#include "DateTime.h"

class Activity {
public:
    Activity(int num, std::string &name) : numActivity(num), nameActivity(name){

}

    int getNumActivity() const {
        return numActivity;
    }

    const std::string &getNameActivity() const {
        return nameActivity;
    }

    bool isDone() const {
        return done;
    }

    void printTime(){
        dt.printTime();
    }

private:
    int numActivity;
    std::string nameActivity;
    bool done = false;
    DateTime dt;

};


#endif //TODOLIST_ACTIVITY_H
