#ifndef LETRA_H
#define LETRA_H
#include <string>
using namespace std;

class letra
{
    public:
    letra(){};
    ~letra(){};

    letra(int p, char m, char M)
    {
        setPos(p);
        setVal(m);
        setVAL(M);
    }
    void setPos(int p){ pos = p;}
    int getPos(){return pos;}
    void setVal(char v){val=v;}
    char getVal(){return val;}
    void setVAL(char V){VAL=V;}
    char getVAL(){return VAL;}

    private:
    char val;
    char VAL;
    int pos;


};

#endif // LETRA_H
