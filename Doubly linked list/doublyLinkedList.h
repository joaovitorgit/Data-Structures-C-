#ifndef DOUBLY_LINKED_LIST  
#define DOUBLY_LINKED_LIST 

template<class T>

class doublyLinkedListNode{
    public:
        doublyLinkedListNode(){
            proximo = prev = 0;
        }
        doublyLinkedListNode(const T& element, doublyLinkedListNode *n = 0, doublyLinkedListNode *p = 0){
            info = element; proximo = n; prev = p;
        }
        T info;
        doublyLinkedListNode *proximo, *prev;

};

template<class T>
class doublyLinkedList{
    public:
        doublyLinkedList(){
            topo = resto = 0;
        }
        void addToTopo(const T&);
        void addToResto(const T&);
        T deleteFromTopo();
        T deleteFromResto();
        void deleteNode(const T&);
        bool isInList(const T&) const;
        void printList();

    protected:
        doublyLinkedListNode<T> *topo, *resto;
};

#endif