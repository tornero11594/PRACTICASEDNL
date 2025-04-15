#include "agen.h"
#include "agen_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.


int desequilibrioAgen(const Agen<char>&);
int desequilibrioAgen_Rec(const Agen<char>&,typename Agen<char>::nodo n);
int alturaAgen(const Agen<char>&,typename Agen<char>::nodo);
void alturaAgen_Rec(const Agen<char>&,typename Agen<char>::nodo n, int&);

int main()
{
    Agen<tElto> A;
    cout << "*** Lectura del árbol general A ***\n";
    rellenarAgen(A, fin);

    int desequilibrio = desequilibrioAgen(A);
    cout << "El desequilibrio del árbol A es: " << desequilibrio << endl;
    return 0;
}



int desequilibrioAgen(const Agen<char>&A)
{
    return desequilibrioAgen_Rec(A,A.raiz());
}


int desequilibrioAgen_Rec(const Agen<char>&A,typename Agen<char>::nodo n)
{
     //procedo a calcular las alturas de los subárboles del nodo raíz y restar la más grande con la más pequeña
     if(A.hijoIzqdo(n)!=Agen<char>::NODO_NULO)
     {
        int alturamax=0,alturamin=__INT32_MAX__;  

        typename Agen<char>::nodo hijo=A.hijoIzqdo(n);

        int alturaaux=0;
        while(hijo!=Agen<char>::NODO_NULO)
        {
            alturaaux=alturaAgen(A,hijo);

            if(alturaaux>alturamax)
                alturamax=alturaaux;

            else
            {
                if(alturaaux<alturamin)
                    alturamin=alturaaux;
            }

            hijo=A.hermDrcho(hijo);
        }
        return alturamax-alturamin;
     }

     else //no tiene hijos, desequlibrio 0
      return 0;
}



int alturaAgen(const Agen<char>&A,typename Agen<char>::nodo n)
{
    int altura=0;
    alturaAgen_Rec(A,n,altura);
    cout<<"La altura del arbol pasado es:" <<altura<<endl;
    return altura;
}


void alturaAgen_Rec(const Agen<char>&A,typename Agen<char>::nodo n, int& alt)
{
    if(A.hijoIzqdo(n)!=Agen<char>::NODO_NULO) //tiene hijos
    {
        typename Agen<char>::nodo hijos=A.hijoIzqdo(n);
        alt++;
        while(hijos!=Agen<char>::NODO_NULO)
        {   
            alturaAgen_Rec(A,hijos,alt);
            hijos=A.hermDrcho(hijos);
        }

    }
}

