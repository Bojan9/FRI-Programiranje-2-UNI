
#ifndef _NALOGA2A_H
#define _NALOGA2A_H

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB);

#endif
