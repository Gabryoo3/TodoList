//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <vector>
#include <iostream>
#include <fstream>
#include "Activity.h"
#include <string>

class ActivityList {
public:
    int getList();

    int saveList();

    void addActivity (Activity& a){
        ActList.push_back(a);
        std::cout<<"Activity "<<a.getNameActivity()<<" added";
    }

    void removeActivity(){
        int remove;
        std::cout<<"List of all activities: "<<std::endl;
        printActivities();
        std::cout<<"Insert what activity you want to remove"<<std::endl;
        std::cin>>remove;
        if(remove > ActList.size() || remove < 0){
            std::cerr<<"Remove value wrong"<<std::endl;
            return;
        }
        Activity a = ActList[remove];
        ActList.erase(ActList.begin()+remove);
        std::cout<<"Activity "<<a.getNameActivity()<<" removed"<<std::endl;
    }

    void printActivities(){
        int i = 0;
        for (auto const &a : ActList){
            std::cout<<i<<a.getNameActivity()<<a.getInsertTime();
            if(a.isDone())
                std::cout<<a.getFinishedTime();
            std::cout<<a.isDone();
        }
    }

private:
    std::vector<Activity> ActList;

};


#endif //TODOLIST_ACTIVITYLIST_H
