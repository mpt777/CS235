//
// Created by mptay on 9/7/2020.
//

#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
    vector <string> tasks;
    TodoList() {
      /*cout << "In Constructor" << endl;*/
      ifstream infile ("TODOList.txt");
      string line;
      if (infile.is_open()) {
        while (getline(infile,line)){
          /*cout << line << '\n'; */
          tasks.push_back(line);
        }
        infile.close();
      }
    }
    virtual ~TodoList() {
      /*cout << "In Destructor" << endl;*/
      ofstream outfile;
      outfile.open("TODOList.txt", ofstream::out | ofstream:: trunc);
      for(int i = 0; i < tasks.size(); i++) {
        outfile << tasks[i] << endl;
      }
      outfile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
      /*cout << "In Add" << endl;*/
      tasks.push_back(_duedate + " " + _task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
      /*cout << "In Remove" << endl;*/
      int OG_LIST_SIZE = tasks.size(); 
      for(int i=0; i < tasks.size(); i++) {
        if(tasks[i].find(_task) != std::string::npos) {
          /*cout << tasks[i] << endl;*/
          tasks.erase(tasks.begin()+i);
        }
      }
      /*
      vector<string>::iterator result = find(tasks.begin(), tasks.end(), _task);
      tasks.erase(result);
*/

      if (OG_LIST_SIZE != tasks.size()) {
        cout << "Item successfully removed" << endl;
        return 1;
      } else {
        cout << "Item not removed, please try again" << endl;
        return 0;
      }
    }
    

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
      /*cout << "In Print Todo" << endl;*/
      for(int i=0; i < tasks.size(); i++){
        cout << tasks[i] << endl;
      }
    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
      /*cout << "In Print Days Task" << endl;*/
      for(int i=0; i < tasks.size(); i++){
        if(tasks[i].find(_date) != std::string::npos) {
        cout << tasks[i] << endl;
        }
      }
    }
};

#endif