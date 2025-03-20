//
// Created by gabry on 8/16/24.
//

#ifndef TUI_H
#define TUI_H
#include <iostream>
#include <fstream>
#include <chrono>

#include "Observer.h"


//TODO Observer che tiene traccia cambiamenti
class TUI : public Observer {
public:
    TUI(){
        logFile.open("log.txt", std::ios::app);
        if (!logFile.is_open()) {
            std::cerr<<"Log file didn't open"<<std::endl;
        }
    }
    ~TUI() override{
        if (logFile.is_open())
            logFile.close();
    }

    void updateAdd(const Activity& act) override{
        auto now = std::chrono::system_clock::now();
        auto addTime = std::chrono::system_clock::to_time_t(now);
        auto time = std::put_time(std::localtime(&addTime), "%d-%m-%Y %H:%M:%S");
        logFile<<"["<<time<<"]"<<"Activity "<<act.getNameActivity()<<" added"<<std::endl;
    }

    void updateComplete(const Activity& act) override{
        auto now = std::chrono::system_clock::now();
        auto addTime = std::chrono::system_clock::to_time_t(now);
        auto time = std::put_time(std::localtime(&addTime), "%d-%m-%Y %H:%M:%S");
        logFile<<"["<<time<<"]"<<"Activity "<<act.getNameActivity()<<" completed"<<std::endl;
    }

    void updateRemove(const Activity& act) override{
        auto now = std::chrono::system_clock::now();
        auto addTime = std::chrono::system_clock::to_time_t(now);
        auto time = std::put_time(std::localtime(&addTime), "%d-%m-%Y %H:%M:%S");
        logFile<<"["<<time<<"]"<<"Activity "<<act.getNameActivity()<<" removed"<<std::endl;
    }
    static void printMenu();

private:
    std::ofstream logFile;
};



#endif //TUI_H
