#include "../include/BMH.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> BMH::Pref(const std::string &strBusca)
{
    int tamPadrao = strBusca.size();
    std::vector<int> tabela(256);

    for (int i = 0; i < 256; i++)
        tabela[i] = tamPadrao - 1;
    

    for (int i = 0; i < tamPadrao - 1; i++)
        tabela[static_cast<unsigned char>(strBusca[i])] = tamPadrao - 1 - i; // Correção importante

    return tabela;
}

void BMH::Busca(const std::string &strArq, const std::string &strBusca, bool imp)
{
    int len = strBusca.length(), tamanhoInd = len - 1, pos{0}, i{};
    size_t lenCSV{strArq.length()};
    std::string jaTem{};
    std::vector<int> cPos = Pref(strBusca);
    std::cout << "Tabela: ";

    std::cout << jaTem<<"\n";

    for(int i : cPos)
        std::cout<< i << " ";

    bool t{false};

    /*for (i = pos + tamanhoInd; i >= pos && i < lenCSV; i--)
    {
        t = false;

        if (strArq[i] != strBusca[i - pos])
        {
            for (int j{0}; j < jaTem.length(); j++)
            {
                if (strArq[i] == jaTem[j])
                {
                    pos += cPos[j];
                    t = true;
                    break;
                }
            }

            if (!t)
                pos += strBusca.length();

            i = pos + tamanhoInd + 1;
        }
    }*/
    for (i = pos + tamanhoInd; i >= pos && i < lenCSV; i--)
    {
        t = false;

        if (strArq[i] != strBusca[i - pos])
        {
            for (int j{0}; j < cPos.size(); j++)
            {
                if (strArq[i] == cPos[j])
                {
                    pos += cPos[j];
                    t = true;
                    break;
                }
            }

            if (!t)
                pos += strBusca.length();

            i = pos + tamanhoInd + 1;
        }
    }

    if(imp) //se necessário pode-se remover a impressão para benchmarks
        if (i <= pos) // não teve diferença
        {
            std::cout << "O prefixo foi encontrado entre as posições [" << pos << " , " << pos + tamanhoInd << "]\n";
            return;
        }
        else
        {
            std::cout << "O prefixo não foi encontrado no documento\n";
            return;
        }
}
