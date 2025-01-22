//
// Created by gabry on 7/25/24.
//
#include "ActivityList.h"
int ActivityList::getListFromFile() {
    actList.clear();
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
        actList.push_back(a);
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
    for(const Activity& a : actList){
        txtlist << a.getNameActivity()<<","<<a.getStartTime()<<","<<a.getEndTime()<<","
        <<std::to_string(a.isDone())<<std::endl;
    }
    txtlist.close();
    return 0;
}

int ActivityList::addActivity(const std::string& name, const std::string& time){
    Activity actv(name, time);
    if(actv.getNameActivity()==name) {
        actList.push_back(actv);
        notifyAdd(actv);
        return 0;
    }
    return -1;
}

int ActivityList::completeActivity(const int complete, const std::string& time){
    int result = 0;
    if(!actList[complete].isDone()) {
        actList[complete].setDone(true);
        actList[complete].setEndTime(time);
        notifyComplete(actList[complete]);
        result = 0;
    }
    else
        result = 1;

    return result;
}


int ActivityList::removeActivity(const int remove){
        actList.erase(actList.begin()+remove);
        notifyRemove(actList[remove]);
    return 0;
}


void ActivityList::printActivities() const{
    int i = 0;
    std::cout<<"Index Name          StartTime       EndTime"<<std::endl;
    for (auto const &a : actList){
        std::cout<<i<<" | "<<a.getNameActivity()<<" | ";
        std::cout<<a.getStartTime()<<" | ";
        if (a.getEndTime().empty())
            std::cout<<"Activity not finished yet"<<std::endl;
        else {
            std::cout<<a.getEndTime()<<std::endl;
        }/*<<" | ";
        std::cout<<( a.isDone() ? "true" : "false" )*/
        //it can be checked by the endtime if the activity is ended;
        i++;
    }
}

int ActivityList::remainingActivities() const {
    int total = 0;
    for (auto const &a : actList) {
        if(!a.isDone()) {
            total++;
        }
    }
    return total;

}



