//
// Created by DianaAlessa on 21/09/2017.
//

#include "NodeDL.hpp"
#include <string>
//Nodo para lista Doblemente enlazada.
template <typename T> class NodeDL {
public:
    T data; //Dato
    NodeDL *next; //Apuntador a siguiente
    NodeDL *back; //Apuntador a anterior

    NodeDL(T d) { //Constructor
        data = d;
        next = nullptr;
        back = nullptr;
    }
};
/*std::string toString(){
	return data;
}*/