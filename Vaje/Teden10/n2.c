#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _PO { // par predmet-ocena
    char predmet[4]; // enolična oznaka predmeta
    int ocena; // ocena pri tem predmetu
} PO;

typedef struct _Student { // podatki o študentu
    int vpisna; // vpisna številka
    PO* po; // kazalec na začetek tabele parov predmet-ocena
    int stPO; // število parov predmet-ocena
} Student;

typedef struct _VO { // par vpisna-ocena
    int vpisna; // vpisna številka
    int ocena; // ocena
} VO;

int compareVO(const void* a, const void* b) {
    const VO* vo1 = *(const VO**)a;
    const VO* vo2 = *(const VO**)b;

    // Sort by descending grades
    if (vo1->ocena != vo2->ocena)
        return vo2->ocena - vo1->ocena;
    // If grades are equal, sort by increasing enrollment numbers
    return vo1->vpisna - vo2->vpisna;
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    VO** result = malloc(stStudentov * sizeof(VO*));

    int count = 1;

    for (int i = 0; i < stStudentov; i++) {
        for (int j = 0; j < studentje[i]->stPO; j++) {
            if (strcmp(studentje[i]->po[j].predmet, predmet) == 0 && studentje[i]->po[j].ocena >= 6) {
                result[count] = malloc(sizeof(VO));
                result[count]->vpisna = studentje[i]->vpisna;
                result[count]->ocena = studentje[i]->po[j].ocena;
                count++;
                break;
            }
        }
    }

    qsort(result, count, sizeof(VO*), compareVO);

    *stVO = count;

    return result;
}

int main() {
    return 0;
}
