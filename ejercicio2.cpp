#include "agen.h"
#include "agen_E-S.h"
#include"ejercicio2.h"


using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.



int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);
    int prof=0;

    typename Agen<tElto>::nodo n=A.raiz();
    n=A.hijoIzqdo(n);
    n=A.hijoIzqdo(n);

    

    prof=profundidadNodo(A,n);


    cout<<"La profundidad del nodo es: "<<prof<<endl;

    return 0;
}
