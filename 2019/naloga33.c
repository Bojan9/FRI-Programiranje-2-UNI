#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int k1, int k2, int s, bool* obiskani, int idx, int idxSkoka) {
	static int stObiskanih = 1;

	if (idxSkoka == s) return 0;

	if (idx + k1 < n && !obiskani[idx + k1]) {
		stObiskanih++;
		obiskani[idx + k1] = true;
		rek(n, k1, k2, s, obiskani, idx + k1, idxSkoka + 1);
	}
	if (idx + k2 < n && !obiskani[idx + k2]) {
		stObiskanih++;
		obiskani[idx + k2] = true;
		rek(n, k1, k2, s, obiskani, idx + k2, idxSkoka + 1);
	}
	if (idx - k1 >= 0 && !obiskani[idx - k1]) {
		stObiskanih++;
		obiskani[idx - k1] = true;
		rek(n, k1, k2, s, obiskani, idx - k1, idxSkoka + 1);
	}
	if (idx - k2 >= 0 && !obiskani[idx - k2]) {
		stObiskanih++;
		obiskani[idx - k2] = true;
		rek(n, k1, k2, s, obiskani, idx - k2, idxSkoka + 1);
	}
    
	return stObiskanih;
}

int main() {
	int n, k1, k2, s;

	scanf("%d %d %d %d", &n, &k1, &k2, &s);

	bool* obiskani = (bool*)calloc(n, sizeof(bool));

	obiskani[0] = true;

	printf("%d\n", rek(n, k1, k2, s, obiskani, 0, 0));

	free(obiskani);

	return 0;
}