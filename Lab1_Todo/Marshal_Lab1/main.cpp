#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "TodoList.h"
#include "TodoListInterface.h"

using namespace std;

int main(int argc, char *argv[]) {
    TodoList mylist;
   /* for(int i=0; i < argc; i++) {
      cout << "argv["<<i<<"]=" << argv[i] << endl;
    } */
    string firstarg = argv[1];
    if (firstarg =="add") {
      string date = argv[2];
      string task = argv[3];
      mylist.add(date, task);
    }
    if (firstarg=="printList") {
      mylist.printTodoList();
    }
    if (firstarg=="printDay") {
      mylist.printDaysTasks(argv[2]);
    }
    if (firstarg=="remove") {
      mylist.remove(argv[2]);
    }
}
