#include"agen.h"
#include"agen_E-S.h"
#include<iostream>
using namespace std;


template<typename T>
size_t gemelos(const Agen<T>&A);


template<typename T>
size_t gemelos_Rec(const Agen<T>&A, typename Agen<T>::nodo n, size_t contador);


template<typename T>
bool procesarSubArboles(const Agen<T>&A,  typename Agen<T>::nodo raiz1,  typename Agen<T>::nodo raiz2);








template<typename T>
size_t gemelos(const Agen<T>&A)
{
    return gemelos_Rec(A,A.raiz(),0);
}



template<typename T>

size_t gemelos_Rec(const Agen<T>&A, typename Agen<T>::nodo n, size_t contador)
{

    if(A.hijoIzqdo(n)!=Agen<T>::NODO_NULO)
    {
        typename Agen<T>::nodo hizq=A.hijoIzqdo(n);
        typename Agen<T>::nodo herm=A.hermDrcho(n);

        while(A.hermDrcho(hizq)!=Agen<T>::NODO_NULO)
        {
            while(herm!=Agen<T>::NODO_NULO)
            {
                if(hizq->elto==herm->elto)
                    contador+=procesarSubArboles(A,hizq,hder);

                else
                    herm=A.hermDrcho(herm);

            }

            hizq=A.hermDrcho(hizq);
            herm=A.hermDrcho(hizq);
        }

        hizq=A.hijoIzqdo(n);

        while(hizq!=Agen<T>::NODO_NULO)
        {
            return gemelos_Rec(A,hizq,contador);
            hizq=A.hermDrcho(hizq);
        }
    }

    else
        return contador;
}


template<typename T>
bool procesarSubArboles(const Agen<T>&A,  typename Agen<T>::nodo raiz1,  typename Agen<T>::nodo raiz2)
{
    if(raiz1!=Agen<T>::NODO_NULO && raiz2==Agen<T>::NODO_NULO)
        return false;
    
    if(raiz1==Agen<T>::NODO_NULO)
        return false;
    
    else
    {
        if(raiz1->elto==raiz2->elto)
        {   
            typename Agen<T>::nodo hijo1=A.hijoIzqdo(raiz1);
            typename Agen<T>::nodo hijo2=A.hijoIzqdo(raiz2);

            while(hijo1!=Agen<T>::NODO_NULO  || hijo2!=Agen<T>::NODO_NULO)
            {
                procesarSubArboles(A,hijo1,hijo2);
            }
        }

        else 
            return false;
        
    }

}













