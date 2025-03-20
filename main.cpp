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
      if (al.getSize() == 0)
            std::cout<<"There are no activities in the list, add one!"<<std::endl;
      else if (al.remainingActivities() == 0)
            std::cout<<"You have completed all your activities!"<<std::endl;
      else
            std::cout<<"You have to complete "<<al.remainingActivities()<<" activities yet"<<std::endl;
}

int main() {
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
            TUI::printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1: {
                        bool isAdded = false;
                        std::string name;
                        std::cout<<"Insert activity name: ";
                        std::cin>>name;
                        auto now = std::chrono::system_clock::now();
                        isAdded = list.addActivity(name, now);
                        if(isAdded == true) {
                              std::cout<<"Successfully added activity"<<std::endl;
                        }
                        else if(isAdded == false) {
                              std::cerr<<"Failed to add activity"<<std::endl;
                        }
                        break;
                  }
                  case 2: {
                        bool isCompleted = false;
                        int complete;
                        if(list.getSize() == 0) {
                              std::cerr<<"Empty list"<<std::endl;
                              break;
                        }
                        std::cout<<"Insert index of the activity you want to complete: ";
                        std::cin>>complete;
                        if(complete >= list.getSize() || complete < 0) {
                              std::cerr<<"Invalid index"<<std::endl;
                              break;
                        }
                        //TODO controlla se attività già completata: fatto
                        auto now = std::chrono::system_clock::now();
                        isCompleted = list.completeActivity(complete, now);
                        if(isCompleted == false) {
                              std::cout<<"Activity successfully completed"<<std::endl;
                        }
                        else if (isCompleted == true)
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
                        if(remove >= list.getSize() || remove < 0) {
                              std::cerr<<"Invalid index"<<std::endl;
                              break;
                        }
                        if (!list.getActivity(remove).isDone()) {
                              std::cout<<"Activity not completed yet, you want to procede? "
                                         "Type 1 if you want, 0 otherwise: ";
                              std::cin>>force;
                        }
                        if (!list.getActivity(remove).isDone() && force == 0) {
                              std::cout<<"Remove failed"<<std::endl;
                              break;
                        }
                        list.removeActivity(remove);
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


