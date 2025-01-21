#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
#include "TUI.h"

void controlSaveList(const ActivityList& al) {

      const int control = al.saveList();
      if(control == 0)
            std::cout<<"Successfully saved list"<<std::endl;

      if(control == -1)
            std::cerr<<"Failed to save list"<<std::endl;
}

void checkToComplete(const ActivityList& al) {
      if (al.remainingActivities() == 0)
            std::cout<<"You have completed all your activities!"<<std::endl;
      std::cout<<"You have to complete "<<al.remainingActivities()<<" activities yet"<<std::endl;
}

int main() {
      /* small guide for the user */
      /* 0 means that the operation is successful */
      /* -1 means that the operation failed for external reasons */
      /* 1 means that the operation was already done before */
      ActivityList list;
      if (int check = list.getListFromFile(); check == -1) {
            std::cerr<<"File didn't open"<<std::endl;
            return -1;
      }
      std::cout<<"All activities were successfully copied"<<std::endl;
      checkToComplete(list);
      list.printActivities();
      TUI tui;
      list.attach(&tui);
      int choice = 0;
      while(choice !=6) {
            int control = 0;
            TUI::printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1: {
                        std::string name;
                        std::cout<<"Insert activity name: ";
                        std::cin>>name;
                        auto now = std::chrono::system_clock::now();
                        const std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
                        control = list.addActivity(name, time);

                        if(control == 0) {
                              std::cout<<"Successfully added activity"<<std::endl;
                        }
                        else if(control==-1) {
                              std::cerr<<"Failed to add activity"<<std::endl;
                        }
                        break;
                  }
                  case 2: {
                        int complete;
                        if(list.getSize() == 0) {
                              std::cerr<<"Empty list"<<std::endl;
                              break;
                        }
                        std::cout<<"Insert index of the activity you want to complete: ";
                        std::cin>>complete;
                        if(complete > list.getSize() || complete < 0) {
                              std::cerr<<"Invalid index"<<std::endl;
                              break;
                        }
                        //TODO controlla se attività già completata: fatto
                        auto now = std::chrono::system_clock::now();
                        const std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
                        control = list.completeActivity(complete, time);
                        if(control == 0) {
                              std::cout<<"Activity successfully completed"<<std::endl;
                        }
                        else if (control == 1)
                              std::cout<<"Activity was already completed"<<std::endl;
                        checkToComplete(list);

                        break;
                  }

                  case 3: {
                        int remove;
                        bool force = false;
                        if(list.getSize() == 0) {
                              std::cerr<<"Empty list"<<std::endl;
                              break;
                        }
                        std::cout<<"Insert index of the activity you want to remove: ";
                        std::cin>>remove;
                        if(remove > list.getSize() || remove < 0) {
                              std::cerr<<"Invalid index"<<std::endl;
                              break;
                        }
                        if (!list.getActivity(remove).isDone()) {
                              std::cout<<"Activity not completed yet, you want to procede? "
                                         "Type 1 if you want, 0 otherwise: ";
                              std::cin>>force;
                        }
                        if (force == 0) {
                              std::cout<<"Remove failed"<<std::endl;
                              break;
                        }

                        control = list.removeActivity(remove);
                        if(control == 0)
                              std::cout<<"Activity successfully removed"<<std::endl;
                        break;
                  }
                  case 4: {
                        list.printActivities();
                        break;
                  }
                  case 5: {
                        controlSaveList(list);
                        break;
                  }
                  case 6: {
                        controlSaveList(list);
                        std::cout<<"Exiting..."<<std::endl;
                        break;

                  }
                  default: {
                        std::cout<<"Wrong choice"<<std::endl;
                        break;
                  }
            }
      }
      return 0;

}


