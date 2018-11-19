//hydro.cpp
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include "hydro.h"

int main(){
    FlowList list;
    int numRecords;
    displayHeader();
    numRecords = readData(list);
    int quit = 0;

    while(1){
        switch(menu()){
            case 1:
                //display list, average, median
                display();
                pressEnter();
                menu();
                
            case 2:
                //add data
                addData();
                pressEnter();
                menu();
                
            case 3:
                //save data into file
                saveData();
                pressEnter();
                menu();
                
            case 4:
                //remove data
                removeData();
                pressEnter();
                menu();
                
            case 5:
                cout << "\nProgram Terminated.\n";
                quit = 1;
                break;
            default:
                cout << "\nInvalid input.\n";
                pressEnter();
                menu();
                
        }
        if(quit == 1)            
            break;
    }
    return 0;
}

void displayHeader(){
    cout << "Program: Flow Studies - Fall 2018" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: B01" << endl;
    cout << "Produced by: Antonio Santos" << endl;

    pressEnter();
}

int readData(FlowList list){ 
    
}

int menu(){
    cout << "Please select on the following operations:" << endl;
    cout << "   1.  Display flow list, average and median." << endl;
    cout << "   2.  Add data." << endl;
    cout << "   3.  Save data into the file." << endl;
    cout << "   4.  Remove data." << endl;
    cout << "   5.  Quit" << endl;
    cout << "   Enter your choice (1, 2, 3 ,4 or 5)." << endl;
    int choice;
    cin >> choice;
    return choice;
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
   
    if(cin.get() == '\n'){
        return;
    }else{
        cout << "\nProgram Terminated.\n";
        exit(1);
    }    
}