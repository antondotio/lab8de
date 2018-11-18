//hydro.cpp
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "hydro.h"

void main(){
    Flowlist list;
    int numRecords;
    displayHeader();
    numRecords = readData(list);
    int quit = 0;

}

void displayHeader(){
    cout<<" \nProgram: Flow Studies - Fall 2018
            \nVersion: 1.0
            \nLab Section: B01
            \nProduced by: Antonio Santos
            \n";

    pressEnter();
}

int readData(Flowlist list){ 

}

int menu(){

}

void display(){

}

void addData(){

}

void removeData(){

}

double average(){

}

double median(){

}

void saveData(){

}

void pressEnter(){
    cout<<"\n<<<Press Enter to Continue>>>\n";

    
}