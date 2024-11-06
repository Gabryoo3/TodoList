#include <iostream>
#include "Activity.h"
#include "ActivityList.h"
#include "TUI.h"
int main() {
      ActivityList list;
      list.getListFromFile();
      list.printActivities();
      TUI tui;
      int choice = 0;
      while(choice !=6) {
            tui.printMenu();
            std::cout<<"Insert your choice: ";
            std::cin >> choice;
            switch (choice) {
                  case 1:
                        std::string name;
                        std::cout<<"Insert activity name: ";
                        std::cin>>name;
                        list.addActivity(name);
                        //TODO metti possibilità di estrarre il valore con certo indice
                        for(auto i : list) {
                              if(i.getNameActivity().equals(name)) {
                                    std::cout<<"Activity"<<i.getNameActivity()<<"added";
                                    break;
                              }
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
                        list.completeActivity(complete);
                        std
                  break;



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
