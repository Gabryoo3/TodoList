//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"

std::chrono::system_clock::time_point parseTimePoint(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%d-%m-%Y %H:%M:%S");
    /*if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string");
    }*/
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int ActivityList::getListFromFile() {
    actList.clear();
    std::ifstream txtlist("todolist.txt");
    if(!txtlist.is_open()){
        return -1;
    }

    std::string line;
    while(std::getline(txtlist >> std::ws, line)){
        std::istringstream iss(line); //separe values
        std::string item, name;
        std::chrono::system_clock::time_point startTime, endTime;
        bool done = false;
        int column = 0;
        while(std::getline(iss, item, ',')) {
            switch(column){
                case 0:
                    name = item;
                break;
                case 1:
                    startTime = parseTimePoint(item);
                break;
                case 2:
                    endTime = parseTimePoint(item);
                break;
                /*case 3:
                    done = std::stoi(item);
                break;*/ //since the presence of the endtime is enough to check if the activity is done
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
        txtlist << a.getNameActivity()<<",";
        auto startTime = std::chrono::system_clock::to_time_t(a.getStartTime());
        txtlist <<std::put_time(std::localtime(&startTime), "%d-%m-%Y %H:%M:%S")<<",";
        auto endTime = std::chrono::system_clock::to_time_t(a.getEndTime());
        txtlist <<std::put_time(std::localtime(&endTime), "%d-%m-%Y %H:%M:%S")<</*",";
        txtlist <<std::to_string(a.isDone())<<*/std::endl;

    }
    txtlist.close();
    return 0;
}

bool ActivityList::addActivity(const std::string& name, const std::chrono::system_clock::time_point& time){
    Activity actv(name, time);
    if(actv.getNameActivity()==name) {
        actList.push_back(actv);
        notifyAdd(actv);
        return true; //modifica a boolean:fatto
    }
    return false;
}

bool ActivityList::completeActivity(const int complete, const std::chrono::system_clock::time_point& time){
    if (complete < 0 || complete >= actList.size()) {
        throw std::out_of_range("Activity index out of range");
    }
    bool isCompleted = false;
    if(!actList[complete].isDone()) {
        actList[complete].setDone(true);
        actList[complete].setEndTime(time);
        notifyComplete(actList[complete]);
    }
    else
        isCompleted = true;
    return isCompleted;

}


void ActivityList::removeActivity(const int remove){
    actList.erase(actList.begin()+remove);
    notifyRemove(actList[remove]);
     //settare a void:fatto
}


void ActivityList::printActivities() const{
    int i = 0;
    std::cout<<"Index Name          StartTime       EndTime"<<std::endl;
    for (auto const &a : actList){
        std::cout<<i<<" | "<<a.getNameActivity()<<" | ";
        auto startTime = std::chrono::system_clock::to_time_t(a.getStartTime());
        std::cout<<std::put_time(std::localtime(&startTime), "%d-%m-%Y %H:%M:%S")<<" | ";
        auto endTimePoint = a.getEndTime(); //for the comparison, I need the time_point, not the time_t
        if (endTimePoint == std::chrono::system_clock::time_point())
            std::cout<<"Activity not finished yet"<<std::endl;
        else {
            auto endTime = std::chrono::system_clock::to_time_t(endTimePoint);
            std::cout<<std::put_time(std::localtime(&endTime), "%d-%m-%Y %H:%M:%S")<<std::endl;
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





