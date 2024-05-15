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


int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++) {
        if (studentje[i]->vpisna == vpisna) {
            return i;
        }
    }

    return -1;
}

int poisciPO(Student* student, char* predmet) {
    int n = student->stPO;

    for (int i = 0; i < n; i++) {
        if (strcmp(student->po[i].predmet, predmet) == 0) {
            return i;
        }
    }

    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int idx_s = poisciStudenta(studentje, stStudentov, vpisna);

    if (idx_s != -1) {
        int idx_p = poisciPO(student, predmet);

        if (idx_p != -1) {
            studentje[idx_s]->po[idx_p].ocena = ocena;
        } else {
            strcpy(studentje[idx_s]->po[studentje[idx_s]->stPO].predmet, predmet);
            studentje[idx_s]->po[studentje[idx_s]->stPO].ocena = ocena;
            studentje[idx_s]->stPO++;
        }

    } else {
        Student* novStudent = malloc(sizeof(Student));

        novStudent->vpisna = vpisna;
        novStudent->stPO = 1;
        novStudent->po = malloc(10 sizeof(PO));

        strcpy(novStudent->po[0].predmet, predmet);
        novStudent->po[0].ocena = ocena;

        studentje[stStudentov] = novStudent;
        stStudentov++;
    }

    return stStudentov;
}

int main() {
    return 0;
}