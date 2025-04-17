#include "agen.h"
#include "agen_E-S.h"

using namespace std;

typedef int tElto;
const tElto fin = -1; // Fin de lectura.

void podaAgen(Agen<int> &, int);
void busqueda_Rec(Agen<int> &, int, typename Agen<int>::nodo); // esta funcion buscará el nodo a podar y llamará a la funcion correspondiente para que pode el subárbol
void podaAgen_Rec(Agen<int> &, typename Agen<int>::nodo);      // función encargada de la poda

int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);

    int x = 0;
    cout << "Introduce un valor para podar en el árbol" << endl;
    cin >> x;

    cout << "Arbol antes de la poda: " << endl;
    // Arbol antes de la poda:
    imprimirAgen(A);

    // procedemos a podar
    podaAgen(A, x);

    cout << "Arbol después de la poda: " << endl;
    // verificamos que se ha llevado a cabo la poda
    imprimirAgen(A);

    return 0;
}

void podaAgen(Agen<int> &A, int x)
{
    busqueda_Rec(A, x, A.raiz());
}

void busqueda_Rec(Agen<int> &A, int x, typename Agen<int>::nodo n)
{
    if (n != Agen<int>::NODO_NULO)
    {
        if (n->elto == x) // hemos encontrado al elemento, podamos a partir de aquí
        {
            podaAgen_Rec(A, n);
        }
        else // debemos seguir buscando
        {
            Agen<int>::nodo hijos = A.hijoIzqdo(n);

            while (hijos != Agen<int>::NODO_NULO)
            {
                busqueda_Rec(A, x, hijos);
                hijos = A.hermDrcho(hijos);
            }
        }
    }
}

// debemos eliminar primero los nodos hoja, ya que así es como funciona el Agen en nuestro TAD. Comenzaremos eliminando por los hijos izquierdo

void podaAgen_Rec(Agen<int> &A, typename Agen<int>::nodo n)
{

    if (n != Agen<int>::NODO_NULO)
    {
        if (A.hijoIzqdo(n) != Agen<int>::NODO_NULO && A.hijoIzqdo(A.hijoIzqdo(n)) == Agen<int>::NODO_NULO) // el hijo izquierdo de n es una hoja
        {
            cout<<"Se va a eliminar el nodo:" <<A.hijoIzqdo(n)->elto<<endl;
            A.eliminarHijoIzqdo(n);
            podaAgen_Rec(A, n); // puede tener más hijos
        }

        else
        {
            if (A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
            {
                Agen<int>::nodo hijos = A.hijoIzqdo(n);
                Agen<int>::nodo nod=hijos;
                while (hijos != Agen<int>::NODO_NULO)
                {
                    podaAgen_Rec(A, hijos);
                    hijos = A.hermDrcho(hijos);
                }
                podaAgen_Rec(A, A.padre(nod));
            }
        }
    }
}

// void podaAgen_Rec(Agen<int> &A, typename Agen<int>::nodo n,typename Agen<int>::nodo raiz)
