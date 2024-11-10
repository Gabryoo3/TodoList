//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"
int ActivityList::getListFromFile() const {
    ActList.clear();
    std::ifstream txtlist("todolist.txt");
    if(!txtlist.is_open()){
        return -1;
    }

    std::string line;
    while(std::getline(txtlist >> std::ws, line)){
        std::istringstream iss(line); //separe values
        std::string item;
        std::string name, startTime, endTime;
        bool done = false;
        int column = 0;
        while(std::getline(iss, item, ',')) {
            switch(column){
                case 0:
                    name = item;
                break;
                case 1:
                    startTime = item;
                break;
                case 2:
                    endTime = item;
                break;
                case 3:
                    done = std::stoi(item);
                break;
                default:
                    break;
        }
            column++;
    }

        //ws skips whitespaces, so I can place whatever name I want, then I can continue with the next values
        Activity a(name, startTime);
        a.setDone(done);
        if(a.isDone()) {
            a.setEndTime(endTime);
        }
        ActList.push_back(a);
    }
    txtlist.close();
    return 0;
}

int ActivityList::saveList() const {
    std::ofstream txtlist;
    txtlist.open("todolist.txt");
    if(!txtlist.is_open()){
        return -1;
    }
    for(const Activity& a : ActList){
        txtlist << a.getNameActivity()<<","<<a.getStartTime()<<","<<a.getEndTime()<<","
        <<std::to_string(a.isDone())<<std::endl;
    }
    txtlist.close();
    return 0;
}

int ActivityList::addActivity(const std::string& name) const{
    auto now = std::chrono::system_clock::now();
    std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
    Activity actv(name, time);
    if(actv.getNameActivity()==name) {
        ActList.push_back(actv);
        return 1;
    }
    else
        return -1;


}

int ActivityList::completeActivity(const int complete) const{
    if(!ActList[complete].isDone()) {
        ActList[complete].setDone(true);
        return 1;
    }
    else
        return 0;
}


int ActivityList::removeActivity(const int remove) const{
    int forceRemove = 0;
    if(!ActList[remove].isDone()) {
        std::cout<<"Activity still not completed. You want to procede? Type 1 if you want: ";
        std::cin>>forceRemove;
    }
    if(forceRemove != 1) {
        return -1;
    }
    ActList.erase(ActList.begin()+remove);
    return 1;
}


void ActivityList::printActivities() const{
    int i = 0;
    for (auto const &a : ActList){
        std::cout<<i<<" | "<<a.getNameActivity()<<" | ";
        std::cout<<( a.isDone() ? "true" : "false" )<<std::endl;
        i++;
    }
}



