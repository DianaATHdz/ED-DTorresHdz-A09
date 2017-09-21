//
// Created by DianaAlessa on 21/09/2017.
//

#include "DLList.hpp"
#include "NodeDL.cpp"
using namespace std;

template <typename T> class DLList{
public:
    NodeDL<T>* first;
    NodeDL<T>* last;
    NodeDL<T>* pointer;
    int length;

    MyList(){ //Constructor por defecto
        first=NULL;
        last=NULL;
        pointer=NULL;
        length=0;
    }
    void MyList(T d){//Constructor con un primer nodo
        NodeDL<T> node = new NodeDL<T>(d);
        //Apuntamos primero y ultimo al nuevo nodo
        *first=node;
        *last=node;
        //Los apuntadores siguiente y atrás apuntan a nulo
        node.next=NULL;
        node.back=NULL;
        //Incrementamos el contador de elementos de la lista
        length++;
    }

    //Métodos
    //Está vacía?
    bool isEmpty(){
        return length==0;
    }

    //Insertar al inicio
    //Escenarios: Lista vacía, lista con elementos
    void insertFirst(T d) {
        NodeDL<T> node = new NodeDL<T>(d);
        if (isEmpty()) { //Si la lista está vacía
            *first = node;
            *last = node;
            length++;
        } else {//Si la lista ya cuenta con elementos
            //El siguiente del nuevo nodo apunta al nodo que apunta first
            node.*next = first;
            //El nodo que apunta first en su apuntador back apuntará al nuevo nodo
            first->back = node;
            //El apuntador fisrt apunta al nuevo nodo
            *first = node;
        }
        length++;
    }

    void insertLast(T d){
        //Istanciamos el nuevo nodo
        NodeDL <T> node = new NodeDL <T>(d);
        if (isEmpty()) { //Si la lista está vacía
            *first = node;
            *last = node;
        } else {

        }
    }

    void deleteFirst(){
        if(!isEmpty()){ //Si la lista no esta vacía
            if(first.next==nullptr){//Si la lista solamente tiene un elemento
                *first=NULL;
                *last=NULL;
            } else { //Si la lista tiene más de un elemento
                *first = first->next;
                first -> back;
            }
            length--;
        }
        if(isEmpty()){
            printf("The list is Empty");
        }
    }

    void deleteLast(){
        if(!isEmpty()){//Si la lista no esta vacía
            if(first==last){//Si la lista solamente tiene un elemnto
                first=last= nullptr;
            } else { //Se busca dentro del arreglo
                pointer -> first;
                while (pointer->next!=last){
                    pointer=pointer.*next;
                }
                last = pointer;
                last -> next = nullptr;
                pointer = nullptr;
                length --;
            }
            length --;
        }

    }

    void deleteNode(T n){
        pointer = first;
        while (pointer.next != nullptr){
            if(pointer.data==n){
            pointer.back.next = pointer.next;
            pointer.next.back = pointer.back;
            lenght --;
                return;
            } else pointer=pointer.next;
        }
    }

    void showList(){
        pointer=first;
        printf("first->");
        for (int i=0; i<length; i++){
            printf("["+pointer.data.toString()+"]->"); //Se pone toString para imprimir la lista de cadenas y no solo un entero (direccion de memoria)
            pointer = pointer.next;
        }
        printf("<-last");
    }
};