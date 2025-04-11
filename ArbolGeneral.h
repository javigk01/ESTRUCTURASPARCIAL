#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"

template <class T>
class ArbolGeneral {
  protected:
    NodoGeneral<T>* raiz;

  public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
    int altura();
    int altura(NodoGeneral<T>* nodo);
    int tamano();
    void preOrden();
    void preOrden(NodoGeneral<T>* nodo);
    void posOrden();
    void posOrden(NodoGeneral<T>* nodo);
    void nivelOrden();
};
 
#include "ArbolGeneral.hxx"

#endif