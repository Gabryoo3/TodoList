#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
#include "TUI.h"
int main() {
      ActivityList list;
      list.getList();
      list.printActivities();
      TUI tui;
      int choice = 0;
      while(choice !=6) {
            tui.printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1: {
                        list.addActivity();
                        break;
                  }
                  case 2: {
                        list.completeActivity();
                        break;
                  }
                  case 3: {
                        list.removeActivity();
                        break;
                  }
                  case 4: {
                        list.printActivities();
                        break;
                  }
                  case 5: {
                        list.saveList();
                        break;
                  }
                  case 6: {
                       std::cout<<"Exiting..."<<std::endl;
                        break;
                  }
                  default: {
                        std::cout<<"Wrong choice"<<std::endl;
                  }
            }
      }
      return 0;


}
