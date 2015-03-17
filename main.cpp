#include "LinkedList.h"
#include "LinkedListTests.h"
using namespace std;

void get_test_instructions(){
  cout <<"Enter one of the following to test specific data structure:\n"
    << "==>  1 to test Linked lists\n"
    << "==>  2 to test Binary Search Trees\n"
    << "==>  3 to test Queues\n"
    << "==>  4 to test Stacks\n"
    << "==>  5 to test Hash Tables\n"
    << "==>  6 to test Heaps\n"
    << "==>  7 to test Merge Sort\n"
    << "==>  8 to test Quick Sort\n"
    << "==>  -1 to exit testing\n"; 
}

void test_loop(int tests = 0){
  int choice;
  cout << "\nWelcome to our custome data structure test suite!\n";
  do {
    get_test_instructions();
    cout << "Choice : ";
    cin >> choice;
    switch(choice) {
      case 1:
        cout << "\nRunning test (1): 'Linked lists'"<<endl;
        test_linked_list();
        break;
      case 2:
        cout << "\nRunning test (2): 'Binary Search Tree'"<<endl;
        cout << "Binary Search Tree not yet implemented\n"<<endl;
        break;
      case 3:
        cout << "\nRunning test (3): 'Queue'"<<endl;
        cout << "Queue Not yet implemented\n"<<endl;
        break;
      case 4:
        cout << "\nRunning test (4): 'Stack'"<<endl;
        cout << "Stack Not yet implemented\n"<<endl;
        break;
      case 5:
        cout << "\nRunning test (5): 'Hash Table'"<<endl;
        cout << "Hash table Not yet implemented\n"<<endl;
        break;
      case 6:
        cout << "\nRunning test (6): 'Heap'"<<endl;
        cout << "Heap Not yet implemented\n"<<endl;
        break;
      case 7:
        cout << "\nRunning test (7): 'Merge Sort'"<<endl;
        cout << "\nMerge Sort not yet implemented\n"<<endl;
        break;
      case 8:
        cout << "\nRunning test (8): 'Quick Sort'"<<endl;
        cout << "Quick sort Not yet implemented\n"<<endl;
        break;

      case -1:
        cout << "\nExiting testing\n"<<endl;
        break;
      default:
        cout << "\nPlease enter valid choice.\n"<<endl;
    }
  } while (choice != -1);
}


int main(){
  test_loop();
  return 0;
}
