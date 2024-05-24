#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int k1, int k2, int s, bool* poseteni, int idx, int idxSkok) {
    static int stPoseteni = 1;
    
    if (idxSkok == s) {
        return 0;
    }

    if (idx + k1 < n && !poseteni[idx + k1]) {
        stPoseteni++;
		poseteni[idx + k1] = true;
		rek(n, k1, k2, s, poseteni, idx + k1, idxSkok + 1);
    }

    if (idx + k2 < n && !poseteni[idx + k2]) {
        stPoseteni++;
		poseteni[idx + k2] = true;
		rek(n, k1, k2, s, poseteni, idx + k2, idxSkok + 1);
    }

    if (idx - k1 >= 0 && !poseteni[idx - k1]) {
        stPoseteni++;
		poseteni[idx - k1] = true;
		rek(n, k1, k2, s, poseteni, idx - k1, idxSkok + 1);
    }

    if (idx - k2 >= 0 && !poseteni[idx - k2]) {
        stPoseteni++;
		poseteni[idx - k2] = true;
		rek(n, k1, k2, s, poseteni, idx - k2, idxSkok + 1);
    }

    return stPoseteni;
}

int main() {
    int n, k1, k2, s;

    scanf("%d %d %d %d", &n, &k1, &k2, &s);

    bool* poseteni = calloc(n, sizeof(bool));

	poseteni[0] = true;

    printf("%d", rek(n, k1, k2, s, poseteni, 0, 0));

    free(poseteni);

    return 0;
}