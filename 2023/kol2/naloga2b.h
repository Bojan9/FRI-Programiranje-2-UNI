
#ifndef _NALOGA2B_H
#define _NALOGA2B_H

typedef struct _Vozlisce Vozlisce;
struct _Vozlisce {
    int* p;
    Vozlisce* naslednje;
};

void izlociDuplikate(Vozlisce* zacetek);

#endif
