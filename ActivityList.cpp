//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"

/*int ActivityList::getList() {
    std::ifstream txtlist("todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
    }
    txtlist.read((char*)&a, sizeof(a));
    while(!txtlist.eof()){

    }

}*/

void ActivityList::printActivities() {
    int i = 0;
    for (auto const &a : ActList){
        std::cout<<i<<" "<<a.getNameActivity()<<" "/*<<a.getInsertTime()*/;
        /*if(a.isDone())
            std::cout<<a.getFinishedTime();*/
        std::cout<<( a.isDone() ? "true" : "false" )<<std::endl;
    }
}

int ActivityList::saveList() {
    std::ofstream txtlist;
    txtlist.open("todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
        return -1;
    }
    for(const Activity& a : ActList){
        txtlist << a.getNameActivity() /*< std::to_string(a.getInsertTime())*/;
        /*if(a.isDone())
            txtlist << std::to_string(a.getFinishedTime());*/
        txtlist << std::to_string(a.isDone()); //FIXME conversione a tostring e non funzia
    }
    txtlist.close();
    return 0;
}
