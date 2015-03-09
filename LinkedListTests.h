#ifndef LINKEDLISTTESTS_H_
#define LINKEDLISTTESTS_H_

#include <iostream>
#include <string>
#include "ErrorFunctions.h"

using namespace std;

void linked_list_test_instructions(){
  cout << "Enter one of the following to test:\n"
    << "==>  1 to insert numbers 1-9 into list\n"
    << "==>  -1 to exit Linked List testing\n"; 
}

string linked_list_test_1(){
  LinkedList myLinkedList;
  Node * currentNode = myLinkedList.head;
  currentNode->value() = 1;
  currentNode->set_next() = new Node();
  currentNode->next()->set_value() = 2;
  int counter = 3;
  currentNode = currentNode->next();
  while (counter < 10){
    currentNode->set_next() = new Node(counter);
    currentNode = currentNode->next();
    counter++;
  }
  string answer = myLinkedList.string_representation();
  return answer;
  //myLinkedList.print_contense();
}

void test_linked_list(int tests = 0){
  int choice;
  string result, answer;
  do {
    linked_list_test_instructions();
    cout << "Choice : ";
    cin >> choice;
    switch(choice){
			case 1:
				cout << "\nRunning test (1): 'insert numbers 1-9 into list'"<<endl;
				
				//string answer = "";
				result = linked_list_test_1();
				answer = "[1,2,3,4,5,6,7,8,9]";
				if (result.compare(answer) != 0 ){
					print_error_message(choice, answer, result);
				}
				else{
					print_pass_message(choice, answer, result);
				}
				cout<<"\n";
				break;
			case -1:
				cout << "\nExiting testing\n"<<endl;
				break;
			default:
				cout << "\nPlease enter valid choice.\n"<<endl;
		}
	}while (choice != -1);
}

#endif
