//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"
int ActivityList::getList() {
    ActList.clear();
    std::ifstream txtlist("todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
        return -1;
    }
    std::string name;
    bool done;
    while(std::getline(txtlist >> std::ws, name, ',') >> done){
        //ws skips whitespaces, so I can place whatever name I want, then I can continue with the next values
        Activity a(name);
        a.setDone(done);
        ActList.push_back(a);
    }
    std::cout<<"All activities were successfully copied"<<std::endl;
    return 0;
}

void ActivityList::saveList() const {
    std::ofstream txtlist;
    txtlist.open("todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
        return;
    }
    for(const Activity& a : ActList){
        txtlist << a.getNameActivity()<<",";
        txtlist << std::to_string(a.isDone())<<std::endl;
    }
    txtlist.close();
}

void ActivityList::addActivity() {
    std::string name;
    std::cout<<"Insert the name of the activity: ";
    std::cin>>name;
    std::cout<<std::endl;
    const Activity a(name);
    ActList.push_back(a);
    std::cout<<"Activity "<<a.getNameActivity()<<" added"<<std::endl;
}

void ActivityList::completeActivity() {
    int complete;
    if(ActList.empty()){
        std::cerr<<"List is empty"<<std::endl;
        return;
    }
    printActivities();
    std::cout<<"Insert the index of activity you want to complete: ";
    std::cin>>complete;
    std::cout<<std::endl;
    if(complete > ActList.size() || complete < 0){
        std::cerr<<"Complete value wrong"<<std::endl;
        return;
    }
    if(ActList[complete].isDone()){
        std::cerr<<"Activity already completed"<<std::endl;
        return;
    }
    ActList[complete].setDone(true);
    std::cout<<"Activity "<<ActList[complete].getNameActivity()<<" completed"<<std::endl;
}


void ActivityList::removeActivity() {
    int remove;
    bool confirm = false;
    if(ActList.empty()){
        std::cerr<<"List is empty"<<std::endl;
        return;
    }
    printActivities();
    std::cout<<"Insert the index of activity you want to remove: ";
    std::cin>>remove;
    std::cout<<std::endl;
    if(remove > ActList.size() || remove < 0){
        std::cerr<<"Remove value wrong"<<std::endl;
        return;
    }
    const Activity a = ActList[remove];
    if(!ActList[remove].isDone()) {
        std::cout<<"Attention: the activity is not completed. Do you want to continue? Type 1 if you want, 0 otherwise"<<std::endl;
        std::cin>>confirm;
        if(!confirm) {
            return;
        }
    }
    ActList.erase(ActList.begin()+remove);
    std::cout<<"Activity "<<a.getNameActivity()<<" removed"<<std::endl;
}


void ActivityList::printActivities() const{
    int i = 0;
    std::cout<<"List of all activities: "<<std::endl;
    std::cout<<"Index Name Done"<<std::endl;
    for (auto const &a : ActList){
        std::cout<<i<<" | "<<a.getNameActivity()<<" | ";
        std::cout<<( a.isDone() ? "true" : "false" )<<std::endl;
        i++;
    }
}



