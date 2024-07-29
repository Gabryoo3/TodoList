//
// Created by gabry on 7/25/24.
//

#include "ActivityList.h"

/*int ActivityList::getList() {
    std::ifstream txtlist("Todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
    }
    txtlist.read((char*)&a, sizeof(a));
    while(!txtlist.eof()){

    }

}*/

int ActivityList::saveList() {
    std::ofstream txtlist("Todolist.txt");
    if(!txtlist.is_open()){
        std::cerr<<"File didn't open"<<std::endl;
        return -1;
    }
    for(const Activity& a : ActList){
        txtlist << a.getNameActivity() << std::to_string(a.getInsertTime());
        if(a.isDone())
            txtlist << std::to_string(a.getFinishedTime());
        txtlist << std::to_string(a.isDone()); //FIXME conversione a tostring e non funzia
    }
    txtlist.close();
    return 0;
}
