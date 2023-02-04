#include<iostream>
#include"doublyLinkedList.h"

using namespace std;

template<class T>
void doublyLinkedList<T>::addToResto(const T& element){
    if(resto != 0){
        resto = new doublyLinkedListNode<T>(element, 0, resto);
        resto->prev->proximo = resto;
    }
    else topo = resto = new doublyLinkedListNode<T>(element);
}

template<class T>
T doublyLinkedList<T>::deleteFromResto(){
    T element = resto->info;
    if(topo == resto){
        delete topo;
        topo = resto = 0;
    }else{
        resto = resto->prev;
        delete resto->proximo;
        resto->proximo = 0;
    }
    return element;
}

template<class T>
void doublyLinkedList<T>::addToTopo(const T& element){
    doublyLinkedListNode<T> *newNode = new doublyLinkedListNode<T>(element, topo, 0);
    if(topo != 0)topo->prev = newNode;
    if(resto == 0)resto = newNode;
    topo = newNode;
}

template<class T>
T doublyLinkedList<T>::deleteFromTopo(){
    if(topo == 0) return 0;
    T element = topo->info;
    doublyLinkedListNode<T> *temp = topo;
    topo = topo->proximo;
    if(topo != 0) topo->prev = 0;
    else resto = 0;
    delete temp;
    return element;
}

template<class T>
void doublyLinkedList<T>::deleteNode(const T& element){
    doublyLinkedListNode<T> *current = topo;
    while(current != 0 && current->info != element) current = current->proximo;
    if(current == 0) return;
    if(current == topo) topo = topo->proximo;
    else current->prev->proximo = current->proximo;
    if(current == resto) resto = current->prev;
    else current->proximo->prev = current->prev;
    delete current;
}

template<class T>
bool doublyLinkedList<T>::isInList(const T& element) const{
    doublyLinkedListNode<T> *current = topo;
    while(current != 0){
        if(current->info == element) return true;
        current = current->proximo;
    }
    return false;
}

template<class T>
void doublyLinkedList<T>::printList(){
    doublyLinkedListNode<T> *current = topo;
    while(current != 0){
        cout << current->info << " ";
        current = current->proximo;
    }
    cout << endl;
}

int main(){
    doublyLinkedList<int> list;
    list.addToTopo(1);
    list.addToTopo(2);
    list.addToTopo(3);
    list.addToResto(4);
    list.addToResto(5);
    cout << "List: ";
    list.printList();

    cout << "Deleting from top: " << list.deleteFromTopo() << endl;
    cout << "Deleting from resto: " << list.deleteFromResto() << endl;

    cout << "List after deletions: ";
    list.printList();

    cout << "Is 3 in list: " << list.isInList(3) << endl;
    cout << "Deleting node with value 3: ";
    list.deleteNode(3);
    cout << "Is 3 in list: " << list.isInList(3) << endl;

    cout << "List after deletion: ";
    list.printList();
    return 0;
}