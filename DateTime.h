//
// Created by gabry on 7/25/24.
//

#ifndef TODOLIST_DATETIME_H
#define TODOLIST_DATETIME_H
#include <ctime>
#include <iostream>

class DateTime {
public:
    void printTime() {
        time(&timestamp);
        std::cout<<ctime(&timestamp)<<std::endl;
    }
private:
    time_t timestamp;
};


#endif //TODOLIST_DATETIME_H
