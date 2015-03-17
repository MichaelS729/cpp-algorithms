#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

void print_error_message(int testNumber, string answer, string result){
  cout << "****** FAIL ******\n"
       << "Test " << testNumber <<" failed\n"
       << "Expected Answer : " << answer << "\n"
       << "Found Answer    : " << result << "\n"
       << "******************\n";
}

void print_pass_message(int testNumber, string answer, string result){
  cout << "****** PASS ******\n"
       << "Test " << testNumber <<" passed\n"
       << "Expected Answer : " << answer << "\n"
       << "Found Answer    : " << result << "\n"
       << "******************\n";
}

#endif
