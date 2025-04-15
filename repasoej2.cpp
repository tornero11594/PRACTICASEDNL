#include "agen.h"
#include "agen_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int profundidadnodo(const Agen<char>&A, typename Agen<char>::nodo n);
int profundidadnodo_Rec(const Agen<char>&A, typename Agen<char>::nodo n, int &prof);


int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);

    typename Agen<char>::nodo n = A.hijoIzqdo(A.hermDrcho(A.hijoIzqdo(A.raiz()))); 
    int profundidad = profundidadnodo(A, n);

    cout << "La profundidad del nodo " << n->elto << " es: " << profundidad << endl;

    return 0;

}


int profundidadnodo(const Agen<char>&A, typename Agen<char>::nodo n)
{
    int prof=0;
    return profundidadnodo_Rec(A, n, prof);
}

int profundidadnodo_Rec(const Agen<char>&A, typename Agen<char>::nodo n, int &prof)
{
    if(n==A.raiz())
        return prof;

    else
    {
        prof++;
        return profundidadnodo_Rec(A,A.padre(n),prof);
    }
     
}



