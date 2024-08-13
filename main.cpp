#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
int main() {

    ActivityList al;
    Activity a1 ("test");
    al.addActivity(a1);
    al.printActivities();
    al.saveList();
    Activity a2 ("test2");
    al.addActivity(a2);
    al.printActivities();
    std::cout<<"two activities"<<std::endl;
    al.getList();
    al.printActivities();

}
