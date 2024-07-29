#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
int main() {

    ActivityList al;
    Activity a1 ("test");
    al.addActivity(a1);
    al.saveList();

}
