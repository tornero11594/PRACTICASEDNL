#include"agen.h"


template<typename T>
int gradoAgen(const Agen<T>&A)
{
    return gradoAgen_Rec(A,A.raiz(),0);
}


template<typename T>
int gradoAgen_Rec(const Agen<T>&A, typename Agen<T>::nodo n, int contador)
{
    if(n!=Agen<T>::NODO_NULO)
    {
        typename Agen<T>::nodo hijo=A.hijoIzqdo(n);
        int contadoractual=0;
        while(hijo!=Agen<T>::NODO_NULO)
        {   
            contadoractual++;
            hijo=A.hermDrcho(hijo);
        }

        if(contadoractual > contador)
            contador=contadoractual;

        hijo=A.hijoIzqdo(n);

        while(hijo!=Agen<T>::NODO_NULO)
        {
            gradoAgen_Rec(A,hijo,0);
            hijo=A.hermDrcho(hijo);
        }
    }


    return contador;

}


