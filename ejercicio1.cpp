
#include "agen.h"
#include "agen_E-S.h"
#include "ejercicio1.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);

    int grado = gradoAgen(A);

    cout << "El grado del árbol A es: " << grado << endl;

    return 0;
}
