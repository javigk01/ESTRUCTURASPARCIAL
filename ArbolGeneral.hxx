#include "ArbolGeneral.h"

template<class T>
ArbolGeneral<T>::ArbolGeneral(){
    this->raiz = NULL;
}

template<class T>
ArbolGeneral<T>::ArbolGeneral(T val){
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}

template<class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz = NULL;
}

template<class T>
bool ArbolGeneral<T>::esVacio(){
    return this->raiz == NULL;
}

template<class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template<class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz){
    this->raiz = nraiz;
}

template<class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    // Si el arbol es vacio:
    // Crear nuevo nodo, asignar dato, poner ese nodo como raiz

    //si hay al menos un nodo en el arbol:
    // - revisar el nodo donde estoy para ver si coincide con padre
    // - si es padre, insertar ahi el nuevo hijo
    // - si no es padre, revisar cada nodo hijo y llamar a insertar alli

    if (this->esVacio()) {
        this->raiz = new NodoGeneral<T>();
        this->raiz->fijarDato(padre);
    }

    std::queue<NodoGeneral<T>*> cola;
    cola.push(this->raiz);

    while (!cola.empty()) {
        NodoGeneral<T>* actual = cola.front();
        cola.pop();

        if (actual->obtenerDato() == padre) {
            actual->adicionarDesc(n);
            return true;
        }

        for (auto hijo : actual->desc) {
            cola.push(hijo);
        }
    }
    return false;
    
}

template<class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
    // Si el arbol es vacio:
    // retornar

   //si es la raiz la que quiero eliminar:
   //- hacer delete a raiz
   //- poner raiz en nulo

    //si hay al menos un nodo en el arbol:
    // - si alguno de los hijos es el que quiero eliminar
    // - si ninguno de los hijos es el que quiero eliminar
    // - revisa cada nodo hijo y llama a eliminar alli

    if (this->esVacio()) return false;

    if (this->raiz->obtenerDato() == n) {
        delete this->raiz;
        this->raiz = nullptr;
        return true;
    }

    std::queue<NodoGeneral<T>*> cola;
    cola.push(this->raiz);

    while (!cola.empty()) {
        NodoGeneral<T>* actual = cola.front();
        cola.pop();

        for (auto it = actual->desc.begin(); it != actual->desc.end(); ++it) {
            if ((*it)->obtenerDato() == n) {
                delete *it;
                actual->desc.erase(it);
                return true;
            }
            cola.push(*it);
        }
    }
    return false;
}

template<class T>
bool ArbolGeneral<T>::buscar(T n){
    // Si el arbol es vacio:
    // comparo dato en el nodo actual con dato parametro
    //si es este, retorno que lo encontre
    //si no, para cada nodo hijo hacer llamado a buscar

    if (this->esVacio()) return false;

    std::queue<NodoGeneral<T>*> cola;
    cola.push(this->raiz);

    while (!cola.empty()) {
        NodoGeneral<T>* actual = cola.front();
        cola.pop();

        if (actual->obtenerDato() == n) return true;

        for (auto hijo : actual->desc) {
            cola.push(hijo);
        }
    }
    return false;
    
}

template<class T>
int ArbolGeneral<T>::altura(){
    if(this->esVacio()){
        return -1;
    } else {
        return this->altura(this->raiz);
    }
}

template<class T>
int ArbolGeneral<T>::altura(NodoGeneral<T>* nodo){
    int alt = -1;

    if(nodo->esHoja()){
        alt = 0;
    } else {
        int alth;
        typename std::list<NodoGeneral<T>*>::iterator it;
        for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
            alth = this->altura(*it);
            if(alt < alth+1)
                alt = alth+1;
        }
    }
    
    return alt;
}

    
template<class T>
int ArbolGeneral<T>::tamano(){}

template<class T>
void ArbolGeneral<T>::preOrden(){
    if(!this->esVacio()){
        this->preOrden(this->raiz);
    }
}

template<class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
    std::cout << nodo->obtenerDato() << " ";

    typename std::list<NodoGeneral<T>*>::iterator it;
    for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
        this->preOrden(*it);
    }
}

//caso 2 si queremos que el preorden lo calcule el nodo (NO USAR)
/*
template<class T>
void ArbolGeneral<T>::preOrden(){
    if(!this->esVacio()){
        (this->raiz)->preOrden();
    }
}
*/

template<class T>
void ArbolGeneral<T>::posOrden(){
  //llama a posOrden sobre cada hijo
  //imprimo en pantalla el dato del nodo actual
    if (!this->esVacio()) {
        this->posOrden(this->raiz);
    }
}

template<class T>
void ArbolGeneral<T>::posOrden(NodoGeneral<T>* nodo) {
    for (auto hijo : nodo->desc) {
        this->posOrden(hijo);
    }
    std::cout << nodo->obtenerDato() << " ";
}

template<class T>
void ArbolGeneral<T>::nivelOrden(){
  //NO ES RECURRENTE (O RECURSIVO)
  //ubicarme en la raiz
  //poner la raiz en una cola
  //hacer un ciclo mientras haya algo en la cola
  // - saco el primero disponible en la cola
  // - imprimo su dato
  // - inserto en la cola todos sus hijos

    if (this->esVacio()) return;

    std::queue<NodoGeneral<T>*> cola;
    cola.push(this->raiz);

    while (!cola.empty()) {
        NodoGeneral<T>* actual = cola.front();
        cola.pop();

        std::cout << actual->obtenerDato() << " ";

        for (auto hijo : actual->desc) {
            cola.push(hijo);
        }
    }
    
}
