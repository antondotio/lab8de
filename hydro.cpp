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
    int quit = 0;

    while(1){
        switch(menu()){
            case 1:
                display(list, numrecords);
                pressEnter();
                break;
                
            case 2:
                addData(list, &numrecords);
                pressEnter();
                break;
                
            case 3:
                saveData(list);
                pressEnter();
                break;
                
            case 4:
                removeData(list, &numrecords);
                pressEnter();
                break;
                
            case 5:
                cout << "\nProgram Terminated." << endl;
                quit = 1;
                break;
            default:
                cout << "\nInvalid input." << endl;
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
    cout << "\nPlease select on the following operations:" << endl;
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
    double avg = average(list, numrecords);
    cout << "The annual average of the flow is: " << avg << " billions cubic meter" << endl;
    double med = median(list, numrecords);
    cout << "The median flow is: " << med << " billions cubic meter" << endl;
}

void addData(FlowList &list, int *numrecords){
    int newyear;
    double newflow;
    Node *check = list.get_headM();
    cout << "Please enter a new year: ";
    cin >> newyear;
    cout << "Please enter the flow: ";
    cin >> newflow;
    while(check != nullptr){
        if(check->item.year == newyear){
            cout << "\nInvalid input. Duplicate data." << endl;
            return;
        }
        check = check->next;
    }
    (*numrecords)++;
    ListItem *newdata = new ListItem {newyear, newflow};
    list.insert(*newdata);
    cout << "\nNew value inserted successfully." << endl;
}

void removeData(FlowList &list, int *numrecords){
    int removeyear;
    Node *check = list.get_headM();
    cout << "Please enter the year you want to remove: ";
    cin >> removeyear;
    while(check != nullptr){
        if(check->item.year == removeyear){
            list.remove(removeyear);
            (*numrecords)--;
            cout << "\nRecord was removed successfully." << endl;
            return;
        }
        check = check->next;
    }
    cout << "\nInvalid input. Data does not exist." << endl;

}

double average(FlowList &list, int numrecords){
    double sum = 0;
    Node *sumptr = list.get_headM();
    while(sumptr != nullptr){
        sum += sumptr->item.flow;
        sumptr = sumptr->next;
    }
    return sum/numrecords;
}

double median(FlowList &list, int numrecords){
    int middle;
    Node * medptr = list.get_headM();
    int i = 0;
    if(numrecords % 2 == 0){
        middle = numrecords / 2;
    }else{
        middle = (numrecords - 1) / 2;
    }
    while(i < middle){
        medptr = medptr->next;
        i++;
    }
    return medptr->item.flow;
}

void saveData(FlowList &list){
    ofstream out_stream;
    Node * read = list.get_headM();
    out_stream.open(FILENAME);
    if(out_stream.fail()){
        cerr << "\nError opening file." << endl;
        exit(1);
    }
    while(read != nullptr){
        out_stream << read->item.year << "\t" << read->item.flow << endl;
        read = read->next;
    }
    cout << "\nData saved into file successfully." << endl;
    out_stream.close();
}

void pressEnter(){
    cout << "\n<<<Press Enter to Continue>>>\n";
    cin.clear();
    
    if(cin.get() != '\n'){
        cout << "\nProgram Terminated.\n";
        exit(1);
    }else{
        return;
    }
}