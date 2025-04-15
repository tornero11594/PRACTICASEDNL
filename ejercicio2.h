#include"agen.h"


template<typename T>
int profundidadNodo(const Agen<T>&A, typename Agen<T>::nodo n)
{
    return profundidadNodo_Rec(A,n);
}

template<typename T>
int profundidadNodo_Rec(const Agen<T>&A, typename Agen<T>::nodo nodobuscar)
{
    int prof=0;

    while(n!=A.raiz())
    {
        prof++;
        n=A.padre(n);
    }
    return prof;
  
}
