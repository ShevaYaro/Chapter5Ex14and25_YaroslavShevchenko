/*

Tite Chapter 5 Exercise 11 - Population
File name:Chapter5Ex11_YaroslavShevchenko.cpp
Programmer: Yaroslav Shevchenko
Date: 10/22/2024
Requirements:

A teacher has asked all her students to line up according to their first name.

For example, in one class Amy will be at the front of the line, and Yolanda will be at the end.

Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.

Once all the names have been read, it reports which student would be at the front of the line and

which one would be at the end of the line. You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.


Using Files—Student Line Up -Create a second branch for this project and modify your program to do the following:
Create a new branch in your Exercise 14 project that modifies the Student Line Up program described in Programming Challenge 14 
so it reads the student names from the file LineUp.txt. 
The program should read names from the file until there is no more data to read.

*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string findFirst(string names[], int numQ);
string findEnd(string names[], int numQ);


int main()
{
    string names[25];
    int numQ = 0;/*
    while (numQ < 1 || numQ > 25) {
        cout << "enter the number of names (1 - 25): ";
    }*/

    ifstream file("LineUp.txt");

    if (file.is_open()) {
        string firstName;
        while (getline(file, firstName) && numQ < 25) {
            cout << firstName << endl;
            names[numQ] = firstName;
            numQ++;
        }
        file.close();
    }
    else {
        cout << "Failed to open the file." << endl;
    }
    
    cout << findFirst(names, numQ) << " will be at the front of the line" << endl;
    cout << findEnd(names, numQ) << " will be at the end of the line" << endl;
}


string findFirst(string names[], int numQ) {
    string firstN = names[0];
    for (int i = 1; i < numQ; i++) {
        int result = names[i].compare(firstN);
        if (result < 0) {
            firstN = names[i];
        }
    }
    return firstN;
}

string findEnd(string names[], int numQ) {
    string endN = names[0];
    for (int i = 1; i < numQ; i++) {
        int result = names[i].compare(endN);
        if (result > 0) {
            endN = names[i];
        }
    }
    return endN;
}