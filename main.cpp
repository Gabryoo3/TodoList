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
      list.printActivities();
      TUI tui;
      int choice = 0;
      while(choice !=6) {
            int control = 0;
            tui.printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1:

                        std::string name;
                        std::cout<<"Insert activity name: ";
                        std::cin>>name;
                        control = list.addActivity(name);
                        //TODO metti possibilità di estrarre il valore con certo indice
                        if(control == 1) {
                              std::cout<<"Successfully added activity";
                        }
                        else if(control==-1) {
                              std::cout<<"Failed to add activity";
                        }
                  break;
                  case 2:
                        int complete;
                        if(list.getSize() == 0) {
                              std::cout<<"Empty list";
                              break;
                        }
                        std::cout<<"Insert index of the activity you want to complete: ";
                        std::cin>>complete;
                        if(complete > list.getSize() || complete < 0) {
                              std::cout<<"Invalid index";
                              break;
                        }
                        //TODO controlla se attività già completata
                        control = list.completeActivity(complete);
                        if(control == 1) {
                              std::cout<<"Activity successfully completed";
                        }
                        else if(control == -1)
                              std::cout<<"Failed to complete activity";
                  break;

                  case 3: {
                        int remove;
                        if(list.getSize() == 0) {
                              std::cout<<"Empty list";
                              break;
                        }
                        std::cout<<"Insert index of the activity you want to complete: ";
                        std::cin>>remove;
                        if(remove > list.getSize() || remove < 0) {
                              std::cout<<"Invalid index";
                              break;
                        }
                        control = list.removeActivity(remove);
                        if(control == 1)
                              std::cout<<"Activity successfully removed";

                        else if(control == -1)
                              std::cout<<"Failed to remove activity";
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
                        list.saveList();
                        break;
                  }
                  default: {
                        std::cout<<"Wrong choice"<<std::endl;
                  }
            }
      }
      return 0;


}
