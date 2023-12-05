#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Klub {
    char ime[21];
    int st_clanov;
    char **clani;
} Klub;

Klub* izdelavaj() {
    Klub* novi_klub = malloc(sizeof(Klub));

    scanf("%s", (novi_klub->ime));
    scanf("%d", &(novi_klub->st_clanov));

    novi_klub->clani = malloc((novi_klub->st_clanov) * sizeof(char*));

    for (int i = 0; i < novi_klub->st_clanov; i++) {
        novi_klub->clani[i] = malloc(21 * sizeof(char));
        scanf("%s", novi_klub->clani[i]);
    } 

    return novi_klub;
}

int main() {
    Klub* izhod = izdelavaj();

    printf("%s ima %d clanov. Clani pa so: \n", izhod->ime, izhod->st_clanov);
    for(int i = 0; i < izhod->st_clanov; i++) {
        printf("%s\n", izhod->clani[i]);
        free(izhod->clani[i]);
    }

    free(izhod);
    free(izhod->clani);

    return 0;
}