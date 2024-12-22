#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
#include "TUI.h"
int main() {
      ActivityList list;
      int check = list.getListFromFile();
      if (check == -1) {
            std::cerr<<"File didn't open"<<std::endl;
            return -1;
      }
      std::cout<<"All activities were successfully copied"<<std::endl;
      std::cout<<"You have to complete "<<list.remainingActivities()<<" activities yet"<<std::endl;
      list.printActivities();
      TUI tui;
      int choice = 0;
      while(choice !=6) {
            int control = 0;
            tui.printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1: {
                        std::string name;
                        std::cout<<"Insert activity name: ";
                        std::cin>>name;
                        auto now = std::chrono::system_clock::now();
                        std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
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
                        //TODO controlla se attività già completata
                        auto now = std::chrono::system_clock::now();
                        const std::string time = std::format("{:%d-%m-%Y %H:%M:%OS}", now);
                        control = list.completeActivity(complete, time);
                        if(control == 0) {
                              std::cout<<"Activity successfully completed"<<std::endl;
                        }
                        else if (control == 1)
                              std::cout<<"Activity was already completed"<<std::endl;
                        break;
                  }

                  case 3: {
                        int remove;
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
                        control = list.removeActivity(remove);
                        if(control == 0)
                              std::cout<<"Activity successfully removed"<<std::endl;

                        else if(control == -1)
                              std::cerr<<"Failed to remove activity"<<std::endl;
                        break;
                  }
                  case 4: {
                        list.printActivities();
                        break;
                  }
                  case 5: {

                        control = list.saveList();
                        if(control == -1)
                              std::cerr<<"Failed to save list"<<std::endl;

                        else if(control == 0)
                              std::cout<<"Successfully saved list"<<std::endl;

                        break;
                  }
                  case 6: {
                        control = list.saveList();
                        if(control == -1)
                              std::cerr<<"Failed to save list"<<std::endl;

                        else if(control == 0)
                              std::cout<<"Successfully saved list"<<std::endl;
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
