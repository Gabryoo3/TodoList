//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"

int ActivityList::getList() {
    std::ifstream txtlist("Todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
    }
    Activity a;
    txtlist.read((char*)&a, sizeof(a));
    while(getList(txtlist, ))

}
