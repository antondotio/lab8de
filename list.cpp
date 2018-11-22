//list.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include "hydro.h"

FlowList::FlowList(): headM(0), read(0), sum (0) { }

int FlowList::get_year() const
{
    return headM->item.year;
}

double FlowList::get_flow() const
{
    return headM->item.flow;
}

void FlowList::insert(const ListItem& data){
    Node *new_node = new Node;
    new_node->item.year = data.year;
    new_node->item.flow = data.flow;

    if(headM == 0 || data.flow <= headM->item.flow){
        new_node->next = headM;
        headM = new_node;
    }else{
        Node* before = headM;
        Node* after = headM->next;
        while(after != 0 && data.flow > after->item.flow){
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::print() const
{
    cout << "Year\tFlow (in billions of  cubic meters)" << endl;
    if(headM != 0){
        cout << headM->item.year << "\t" << headM->item.flow << endl;
        for(const Node *p = headM->next; p != 0; p = p->next){
            cout << p->item.year << "\t" << p->item.flow << endl;
        }
    }
}