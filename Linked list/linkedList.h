// Implementação da classe de uma lista singularmente ligada

#ifndef INT_LINKED_LIST // Fiz uma alteração para aceitar o ifndef, pode ocasionar erro
#define INT_LINKED_LIST


class intLinkedListNode{
    public: 
        intLinkedListNode(){
            proximo = 0;
        }

        intLinkedListNode(int element, intLinkedListNode *pointer = 0){
            info = element;
            proximo = pointer;
        }

        int info;
        intLinkedListNode *proximo;
};

class linkedList{
    public:
        linkedList(){
            topo = resto = 0;
        }
        ~linkedList();
        int isEmpty(){
            return topo == 0;
        }

        void addToTopo(int);
        void addToResto(int);
        int deleteFromTopo();
        int deleteFromResto();
        void deleteNode(int);
        bool isInList(int) const;
        void printList();
    
    private:
        intLinkedListNode *topo, *resto;
};

#endif