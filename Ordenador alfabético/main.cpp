#include <iostream>
#include <string>
#include "letra.h"
#include "ordemAlf.h"
using namespace std;

int main()
{
    ordemAlf teste;
    string ex[] = {"bruno","aurelio","lucas","joel","igor","carlos","belle","fer","tulio","loq","bullets"};

    teste.ordenar(ex,11);

    for(int i=0; i<11; i++)
        cout<<ex[i]<<" ";
    return 0;
}
