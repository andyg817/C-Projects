// Author: Andrew Garcia
// Email: andrewag@email.sc.edu
// Section #: 002
// Copyright 2021 Andrew Garcia
// Modified from template code @coleca24 GitHub
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::to_string;

const int COLS = 4;
const int ROWS = 5;

// TODO(commit 1): Commit #1 functions
void printUsers(const string data[ROWS][COLS]);
bool readUsers(string fh, string data[ROWS][COLS]);
char displayOptions();
bool validateOption(char option);
void executeOption(char option, string data[ROWS][COLS], string);
int searchForUser(string name, const string data[ROWS][COLS]);

// TODO(commit 2): Commit #2 functions
int findAllUsers(string title, const string data[ROWS][COLS]);
bool deleteUser(string name, string data[ROWS][COLS], string fh);
string generatePassword();
string generateEmail(string name);
int checkEmpty(const string data[ROWS][COLS]);
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh);

// definitions

void printUsers(const string data[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      std::cout << data[i][j] << "\t";
    }
    std::cout << "\n";
  }
  return;
}
bool readUsers(string fh, string data[ROWS][COLS]) {
  std::ifstream in(fh);
  if (in.is_open()) {
    string line, colname;
    int r = 0, c = 0;
    while (std::getline(in, line)) {
      c = 0;
      std::stringstream ss(line);
      while (std::getline(ss, colname, ',')) {
        data[r][c] = colname;
        c++;
       }
      r++;
    }
    return true;
  } else {
  return false;
}
}
char displayOptions() {
  std::cout << "Please choose one of the following options: \n";
  std::cout << "P(or p): Print data \n";
  std::cout << "S(or s): Search data by name \n";
  std::cout << "F(or f): Find all in data with cerain job title \n";
  std::cout << "A(or a): Add a new user \n";
  std::cout << "D(or d): Delete an existing user \n";
  std::cout << "E(or e): End session \n";
  char choice;
  std::cin >> choice;
  if (validateOption(choice) == true) {
    std::cout << choice << "\n";
  } else {
    return 'e';
  }
  return 'e';
}
bool validateOption(char option) {
  if (option == 'E' || option == 'e'|| option == 'P'|| option == 'p') {
    return true;
  } else if (option == 'S'|| option == 's'|| option == 'F' || option == 'f') {
    return true;
  } else if (option == 'A'|| option == 'a'|| option == 'D'|| option == 'd') {
    return true;
  } else {
  return false;
  }
  return true;
}
void executeOption(char option, string data[ROWS][COLS], string fn) {
  if (option == 'E' || option == 'e') {
    std::cout << "End\n";
  }
  if (option == 'P' || option == 'p') {
    printUsers(data);
  }
  if (option == 'S' || option == 's') {
    string name, name1, name2;
    std::cout << "Please enter the first name: ";
    std::cin >> name1;
    std::cout << "Please enter the last name: ";
    std::cin >> name2;
    name = name1 + " " + name2;
    searchForUser(name, data);
  }
  if (option == 'F' || option == 'f') {
    string name;
    std::cout << "Please enter a job title to search for: ";
    std::cin >> name;
    findAllUsers(name, data);
  }
  if (option == 'A' || option == 'a') {
    int found = 0;
    for (int i = 0; i < ROWS; i++) {
      if (data[i][0] == "NULL") {
        string name, name1, name2;
        std::cout << "Please enter the first name: ";
        std::cin >> name1;
        std::cout << "Please enter the last name: ";
        std::cin >> name2;
        name = name1 + " " + name2;
        string job;
        std::cout << "Please enter a job title to search for: ";
        std::cin >> job;
        addUser(i, name, job, data, fn);
      }
    }
    if (found == 0) {
      std::cout << "Database full (max 5 users) ";
    }
  }
  if (option == 'D' || option == 'd') {
    string name, name1, name2;
    std::cout << "Please enter the first name: ";
    std::cin >> name1;
    std::cout << "Please enter the last name: ";
    std::cin >> name2;
    name = name1 + " " + name2;
    deleteUser(name, data, fn);
  }
  return;
}
int searchForUser(string name, const string data[ROWS][COLS]) {
  int found = 0;
  for (int i = 0; i < ROWS; i++) {
    if (name == data[i][0]) {
      std::cout << "User was found at Index \n";
      return i;
      for (int j = 0; j < COLS; j++) {
        std::cout << data[i][j] << ", ";
        found++;
  }
  }
  }
  std::cout << "\n";
  if (found == 0) {
        std::cout << "User not found\n";
        return -1;
  }
  return 0;
}
// Commit 2

int findAllUsers(string title, const string data[ROWS][COLS]) {
  int found = 0, count = 0;
  for (int i = 0; i < ROWS; i++) {
    if (title == data[i][3]) {
      count++;
      found++;
    }
    }
  if (found == 0) {
    std::cout << "No users w/ job title: " << title << "\n";
    return 0;
  } else {
    std::cout<< "There were " << count;
    std::cout<< " users with job title " << title << "\n";
  }
  return count;
}
bool deleteUser(string name, string data[ROWS][COLS], string fh) {
  std::ofstream mf(fh);
  int found = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
       if (name == data[i][0]) {
        for (int k = 0; k < COLS; k++) {
          data[i][k].clear();
          data[i][k] = "NULL";
        }
        found++;
    }
    mf << data[i][j];
    if (j < 3) {
      mf << ",";
    }
  }
  mf << "\n";
  }
  if (found == 0) {
    std::cout << "No users were found with that name\n";
    return false;
  }
  std::cout << "\nUser was Successfully deleted\n";
  return true;
}
string generatePassword() {
  srand(time(NULL));
  int rNum = 0;
  int rUpc = 0;
  int rLoc = 0;
  rUpc = rand() % 10 + 65;
  rNum = rand() % 10;
  char charu = rUpc;
  string acharl = "";
  for (int i = 0; i < 6; i++) {
    rLoc = rand() % 10 + 97;
    char charl = rLoc;
    acharl += charl;
  }
  string pswd = "";
  pswd = acharl + to_string(rNum) + charu;
  return pswd;
}
string generateEmail(string name) {
  string str = "";
  string space = " ";
  size_t posi;
  while ((posi = name.find(space)) != std::string::npos) {
    name.replace(posi, 1, str);
  }
  string bruh = name + "@email.com";
  return bruh;
}
int checkEmpty(const string data[ROWS][COLS]) {
  int found = 0;
  for (int i = 0; i < ROWS; i++) {
    if (data[i][0] == "NULL") {
      return i;
    }
  }
  if (found == 0) {
        return -1;
  }
  return -1;
}
void addUser(int index, string name, string title,
             string data[ROWS][COLS], string fh) {
  std::ofstream mf(fh);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (data[i][0] == "NULL") {
        for (int k = 0; k < COLS; k++) {
          data[i][k].clear();
          data[i][0] = name;
          data[i][3] = title;
          data[i][1] = generateEmail(name);
          data[i][2] = generatePassword();
        }
      }
    mf << data[i][j];
    if (j < 3) {
      mf << ",";
    }
    }
  mf << "\n";
  }
  return;
}

#endif  // LOGIN_H_
