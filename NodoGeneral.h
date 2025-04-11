#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__

#include <list>

template <class T>
class NodoGeneral{
    protected:
        T dato;
        //std::list<NodoGeneral<T>*> desc;
    public:
        std::list<NodoGeneral<T>*> desc;
        NodoGeneral();
        ~NodoGeneral();
        T& obtenerDato();
        void fijarDato(T& val);
        void limpiarLista();
        void adicionarDesc(T& nval);
        bool eliminarDesc(T& val);
        bool esHoja();
        /*
        int altura(); //caso 2 si queremos  que la altura la haga el nodo
        void preOrden(); //caso 2 si queremos  que el preorden haga el nodo
        */
};

#include "NodoGeneral.hxx"

#endif