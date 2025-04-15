#include "agen.h"
#include "agen_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int gradoAgen(const Agen<char> &);
int gradoAgen_Rec(const Agen<char> &, typename Agen<char>::nodo n, int &numhijos);

int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);

    int grado = gradoAgen(A);

    cout << "El grado del árbol A es: " << grado << endl;

    return 0;
}

int gradoAgen(const Agen<char> &A)
{
    int numhijos=0;
    return gradoAgen_Rec(A, A.raiz(), numhijos);
}

int gradoAgen_Rec(const Agen<char> &A, typename Agen<char>::nodo n, int& numhijos)
{

    if (n != Agen<char>::NODO_NULO)
    {

        typename Agen<char>::nodo hijos = A.hijoIzqdo(n);
        int cont = 0;
        while (hijos != Agen<char>::NODO_NULO)
        {
            cont++;
            hijos = A.hermDrcho(hijos);
        }

        if (cont > numhijos)
            numhijos = cont;

        n = A.hijoIzqdo(n);
        while (n != Agen<char>::NODO_NULO)
        {
            cout << "Estamos en el nodo:" << n->elto << endl;
            gradoAgen_Rec(A, n, numhijos);
            n = A.hermDrcho(n);
        }
    }

    return numhijos;
}
