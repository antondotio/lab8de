//hydro.cpp
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include "hydro.h"
#define FILENAME "flow.txt"

int main(){
    FlowList list;
    int numrecords;
    displayHeader();
    numrecords = readData(list);
    cout<< numrecords <<endl;
    int quit = 0;

    while(1){
        switch(menu()){
            case 1:
                //display list, average, median
                display(list, numrecords);
                pressEnter();
                break;
                
            case 2:
                //add data
                cout<< "2>>";
                addData();
                pressEnter();
                break;
                
            case 3:
                //save data into file
                cout<< "3>>";
                saveData();
                pressEnter();
                break;
                
            case 4:
                //remove data
                cout<< "4>>";
                removeData();
                pressEnter();
                break;
                
            case 5:
                cout << "\nProgram Terminated.\n";
                quit = 1;
                break;
            default:
                cout << "\nInvalid input.\n";
                pressEnter();
                break;
                
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

int readData(FlowList &list){ 
    int year;
    int numrecords = 0;
    double flow;
    ifstream in_stream;
    in_stream.open(FILENAME);
    if(in_stream.fail()){
        cerr << "\nError opening file." << endl;
        exit(1);
    }
    while(!in_stream.eof()){
        in_stream >> year;
        in_stream >> flow;
        numrecords++;
        ListItem *data =  new ListItem {year, flow};
        list.insert(*data);
    }

    in_stream.close();

    return numrecords;
    
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

void display(FlowList &list, int numrecords){
    list.print();
    double avg = average(list);
    cout << "The annual average of the flow is: " << avg << " billions cubic meter" << endl;
    double med = median(list, numrecords);
    cout << "The median flow is: " << med << " billions cubic meter" << endl;
}

void addData(){

}

void removeData(){

}

double average(FlowList &list){


}

double median(FlowList &list, int numrecords){

}

void saveData(){

}

void pressEnter(){
    cout<<"\n<<<Press Enter to Continue>>>\n";
    cin.clear();
    if(cin.get() != '\n'){
        cout << "\nProgram Terminated.\n";
        exit(1);
    }else{
        return;
    }
}