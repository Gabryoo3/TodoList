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
    for(std::string line; getline(txtlist, line);){
        txtlist >> name >> done;
        Activity a(name);
        a.setDone(done);
        ActList.push_back(a);
    }
    std::cout<<"All activities was successfully copied"<<std::endl;
    return 0;
}

void ActivityList::printActivities() const{
    int i = 0;
    for (auto const &a : ActList){
        std::cout<<i<<" "<<a.getNameActivity()<<" "/*<<a.getInsertTime()*/;
        /*if(a.isDone())
            std::cout<<a.getFinishedTime();*/
        std::cout<<( a.isDone() ? "true" : "false" )<<std::endl;
    }
}

int ActivityList::saveList() const {
    std::ofstream txtlist;
    txtlist.open("todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
        return -1;
    }
    for(const Activity& a : ActList){
        txtlist << a.getNameActivity()<<" " /*< std::to_string(a.getInsertTime())*/;
        /*if(a.isDone())
            txtlist << std::to_string(a.getFinishedTime());*/
        txtlist << std::to_string(a.isDone());
    }
    txtlist.close();
    return 0;
}

void ActivityList::removeActivity() {
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
