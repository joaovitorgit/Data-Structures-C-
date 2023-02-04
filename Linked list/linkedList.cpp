#include <iostream>
#include "linkedList.h"
using namespace std;

linkedList::~linkedList(){
    for(intLinkedListNode *current; !isEmpty();){
        current = topo->proximo;
        delete topo;
        topo = current;
    }
}

void linkedList::addToTopo(int element){        // O(1);
    topo = new intLinkedListNode(element, topo);
    if(resto == 0 ){
        resto = topo;
    }
}

void linkedList::addToResto(int element){   //   // O(1);
    if(resto != 0){
        resto->proximo = new intLinkedListNode(element);
        resto = resto->proximo;
    }else{
        topo = resto = new intLinkedListNode(element);
    }
}

int linkedList::deleteFromTopo(){   // O(1);
    int element = topo->info;
    intLinkedListNode *temp = topo;

    if(topo == resto){
        topo = resto = 0;
    }else{
        topo = topo->proximo;
    }
    delete temp;
    return element;
}

int linkedList::deleteFromResto(){ // O(n);
    int element = resto->info;
    if(topo == resto){
        delete topo;
        topo = resto = 0;
    }else{
        intLinkedListNode *temp;
        for(temp = topo; temp->proximo != resto; temp = temp->proximo);
        delete resto;
        resto = temp;
        resto->proximo = 0;
    }
    return element;

}
void linkedList::deleteNode(int element){// O(n);
    if(topo != 0){
        if( topo == resto && element == topo->info){
            delete topo;
            topo = resto = 0;
        }else if(element == topo->info){
            intLinkedListNode *temp = topo;
            topo = topo->proximo;
            delete temp;
        }else{
            intLinkedListNode *pred, *temp;
            for(pred = topo, temp = topo->proximo; temp != 0 && !(temp->info==element); pred = pred->proximo, temp = temp->proximo);
            if(temp != 0 ){
                pred->proximo = temp->proximo;
                if(temp == resto){
                    resto  = pred;
                }
                delete temp;
            }
        }
    }
}

bool linkedList::isInList(int element) const{ // O(n);
    intLinkedListNode *temp;
    for(temp = topo; temp !=0 &&!(temp->info == element); temp = temp->proximo);
    return temp != 0;
}

void linkedList::printList(){
    intLinkedListNode *element;
    for(element = topo; element != 0; element = element->proximo){
        std::cout<<element->info<< " ";
    }
    
}

int main()
{
    linkedList list;
    list.addToTopo(1);
    list.addToTopo(2);
    list.addToResto(3);
    list.addToResto(4);
    
    list.printList();
    std::cout<<std::endl;

    list.addToTopo(5);
    list.addToResto(6);
    list.printList();

    list.deleteFromTopo();
    list.deleteFromResto();
    
    std::cout<<std::endl;
    list.printList();
    
    return 0;
}

