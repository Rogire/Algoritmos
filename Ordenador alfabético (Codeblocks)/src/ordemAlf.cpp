#include "ordemAlf.h"
#include <iostream>
using namespace std;
ordemAlf::ordemAlf() // cria o vetor alfabeto
{
    for(int i=0; i<26; i++)
        Alf[i] = new letra(i+1,minu[i].at(0),maiu[i].at(0));
}

ordemAlf::~ordemAlf() //deleta o vetor alfabeto
{
    for(int i=0; i<26; i++)
        delete Alf[i];
}

void ordemAlf::imprime() //imprime os valores de alfabeto
{
    for(int i=0; i<26; i++)
    {
        cout<<"letra: "<<Alf[i]->getVal() << " "<< Alf[i]->getVAL()<<" pos:"<<Alf[i]->getPos()<<endl;
    }
}

void ordemAlf::troca(string *c1, string *c2) // troca duas strings
{
    string aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}

int ordemAlf::numRep(string plvs[],int i) // verifica o número de repetições entre 2 palavras do vetor a partir de i
{                                         // (verifica i e i+1)
    int rep=0;
    for(int j=0; j<plvs[i].length();j++)
        if(plvs[i].at(j) && plvs[i+1].at(j))
        {
            if(plvs[i].at(j) == plvs[i+1].at(j))
                rep++;
            else
                break;
        }else
            break;

    return rep;
}

void ordemAlf::auxOrd(string plvs[], int t, int trocas) //faz a troca
{
    int c1, c2, rep;
    bool ord;
    for(int i=0; i<t-1; i++)
    {
        c1=0; c2=0; rep= numRep(plvs, i);
        ord = false;

        for(int j=0; j<plvs[i].length()-rep; j++)
        {
            for(int c=0; c<26; c++)
            {
                if(plvs[i].at(j+rep) == Alf[c]->getVal() || plvs[i].at(j+rep) == Alf[c]->getVAL())
                    c1 = Alf[c]->getPos();

                if(plvs[i+1].at(j+rep) == Alf[c]->getVal() || plvs[i+1].at(j+rep) == Alf[c]->getVAL())
                    c2 = Alf[c]->getPos();

                if(c1>0 && c2>0) // verifica se c1 e c2 já foram atribuídos
                    if(c1>c2)
                    {
                        troca(&plvs[i],&plvs[i+1]);
                        trocas++;
                        ord=true;
                        break;
                    }
                    else if(c1<c2)
                    {
                        ord=true;
                        break;
                    }
                }
            if(ord) // para o laço caso a verificação tenha sido feita
                break;
        }
    }

    if(trocas>0)
        auxOrd(plvs,t,0);
}

void ordemAlf::ordenar(string plvs[], int t)
{
    auxOrd(plvs,t,0);
}





