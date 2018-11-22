//list.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include "hydro.h"

FlowList::FlowList(): headM(0) { }

Node* FlowList::get_headM() const
{
    return headM;
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

void FlowList::remove(const int removeyear){
    if(headM == 0) return;
    Node* doomed_node = 0;

    if(removeyear == headM->item.year){
        doomed_node = headM;
        delete doomed_node;
        headM = headM->next;
    }else{
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && maybe_doomed->item.year != removeyear){
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        doomed_node = maybe_doomed;
        before->next = maybe_doomed->next;
        delete doomed_node;
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