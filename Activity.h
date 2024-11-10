//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <iostream>

//TODO data e ora per segnare le attività



class Activity {
public:
    Activity(const std::string& name, const std::string& currTime): nameActivity(name), startTime(currTime) {
    }

    std::string getNameActivity() const{
        return nameActivity; //FIXME
    }

    bool isDone() const {
        return done;
    }

    std::string getStartTime() const{
        return startTime;
    }

    std::string getEndTime() const{
        if (done)
            std::cout<<"Activity not finished yet";
        return endTime;
    }

    void setNameActivity(const std::string &nameActivity){
        Activity::nameActivity = nameActivity;
    }

    void setDone(const bool done) {
        Activity::done = done;
    }

    void setEndTime(const std::string &endTime){
        Activity::endTime = endTime;
    }


private:
    std::string nameActivity;
    bool done = false;
    std::string startTime;
    std::string endTime;
};


#endif //TODOLIST_ACTIVITY_H
