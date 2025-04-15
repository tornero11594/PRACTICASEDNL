#include "agen.h"
#include "agen_E-S.h"


using namespace std;

typedef int tElto;
const tElto fin = -1; // Fin de lectura.


void podaX(Agen<int>&,int);
void podaX_Rec(Agen<int>&,int,typename Agen<int>::nodo);
void podarArbol(Agen<int>&,typename Agen<int>::nodo);



int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);   
    
    podaX(A,15);


    imprimirAgen(A);
    
    return 0;   
}



void podaX(Agen<int>& A,int x)
{
    podaX_Rec(A,x,A.raiz());
}

void podaX_Rec(Agen<int>& A,int x,typename Agen<int>::nodo n)
{
    if(n!=Agen<int>::NODO_NULO)
    {
        if(n->elto==x)
            podarArbol(A,n); //podamos a partir del nodo encontrado

        else
        {
            n=A.hijoIzqdo(n);

            while(n!=Agen<int>::NODO_NULO)
            {
                podaX_Rec(A,x,n);
                n=A.hermDrcho(n);
            }
        }
    }
}


void podarArbol(Agen<int>& A,typename Agen<int>::nodo n)
{

    if(n!=Agen<int>::NODO_NULO)
    {
        Agen<int>::nodo hijo=A.hijoIzqdo(n);

        while(hijo!=Agen<int>::NODO_NULO)
        {
            if(A.hijoIzqdo(hijo)==Agen<int>::NODO_NULO)
            {
                A.eliminarHijoIzqdo(n);
                hijo=A.hijoIzqdo(n);
            }

            else
            {
                podarArbol(A,hijo);
                hijo=A.hijoIzqdo(n);
            }
        }
    }
}


