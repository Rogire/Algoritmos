#ifndef ORDEMALF_H
#define ORDEMALF_H
#include "letra.h"

class ordemAlf
{
    public:
        ordemAlf();
        ~ordemAlf();
        void imprime();
        void ordena(string plvs[], int ind);
        void ordenar(string plvs[], int t);
        void troca(string *c1, string *c2);
        void auxOrd(string plvs[], int t, int trocas);

    private:
    letra* Alf[26];
    int numRep(string *plvs,int i);
    string minu[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    string maiu[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
};

#endif // ORDEMALF_H
