
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

void izdelaj(char** nizi, int indeks, const char* niz) {
    nizi[indeks] = malloc((strlen(niz) + 1) * sizeof(char));
    strcpy(nizi[indeks], niz);
}

int main() {
    int n = 357;
    char** nizi = calloc(n + 1, sizeof(char*));

    izdelaj(nizi, 0, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 1, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 2, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 3, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 4, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 5, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 6, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 7, "mUP32hL_yNKvUjunny5");
    izdelaj(nizi, 8, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 9, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 10, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 11, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 12, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 13, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 14, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 15, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 16, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 17, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 18, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 19, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 20, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 21, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 22, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 23, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 24, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 25, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 26, "XGhrVQ4zQam");
    izdelaj(nizi, 27, "hCtNb5VNwoCeBCsNNZRNcf6uSuZeHRJ30Cf1RQCcKssfVES");
    izdelaj(nizi, 28, "_6_dGVH_kxH8Vrj3g2_6wdhr1LRr765Ku5tQsbanbAQU4noNVfnC7dyhQ1gVcyb5Q5WVrv4ZtlW3pBcc1AWRkqYW");
    izdelaj(nizi, 29, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 30, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 31, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 32, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 33, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 34, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 35, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 36, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 37, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 38, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 39, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 40, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 41, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 42, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 43, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 44, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 45, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 46, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 47, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 48, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 49, "K2au_4HpqN4Y");
    izdelaj(nizi, 50, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 51, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 52, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 53, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 54, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 55, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 56, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 57, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 58, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 59, "QTKF8GZSj0UTxPamWC7qyKLUHPxiNL4weDI2QjjlC");
    izdelaj(nizi, 60, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 61, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 62, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 63, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 64, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 65, "aAOWH1dJQ65JlUef8");
    izdelaj(nizi, 66, "bJp_T_KazYKMGQfaLZpD39xoHjONqdMJKj1M");
    izdelaj(nizi, 67, "SIrz1MdS_KdXvuWFc6Z44y");
    izdelaj(nizi, 68, "_6_dGVH_kxH8Vrj3g2_6wdhr1LRr765Ku5tQsbanbAQU4noNVfnC7dyhQ1gVcyb5Q5WVrv4ZtlW3pBcc1AWRkqYW");
    izdelaj(nizi, 69, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 70, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 71, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 72, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 73, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 74, "44XkJDUzljzjDiwrQ_JLI0BDwjZfVxbQ9gP0isQd9KFbtLFQlUkN53HzdWXayF9CB3L6kO2");
    izdelaj(nizi, 75, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 76, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 77, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 78, "0Mm7Wop7Rev3k7EgyI0Fd8_ychVXJIRnZU7rXMCwc");
    izdelaj(nizi, 79, "QTKF8GZSj0UTxPamWC7qyKLUHPxiNL4weDI2QjjlC");
    izdelaj(nizi, 80, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 81, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 82, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 83, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 84, "EmhGuaKzikpnT0Ruxtm4PFu8pWi2bte3kOVUhO7_hoeX8uBxj1Ua7pG6S3B2TEu8zcJG8RTh6lLDpIHaWynjUja2thNutA");
    izdelaj(nizi, 85, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 86, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 87, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 88, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 89, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 90, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 91, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 92, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 93, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 94, "yVtOARlXDGCZCGrPFYlay5Ftxvo36RDQ01zXGXpBVmPdepp7gD1DO4RZRPLRQ8Re5ftGn8fI9hz9JsHEB");
    izdelaj(nizi, 95, "Wzr9SXuyQe2Bc1stB0s4g2AIvu_FD8nsTXlw8AwaGiObcGQxNq2oJFzS4");
    izdelaj(nizi, 96, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 97, "tHutpGvzEyoeTzecXUWcVKIQSIhlYvEkeg9U21cDZ7TFvYswfhCHUjhStri3PZL8IkSHg7mv1Y67PC");
    izdelaj(nizi, 98, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 99, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 100, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 101, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 102, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 103, "0Mm7Wop7Rev3k7EgyI0Fd8_ychVXJIRnZU7rXMCwc");
    izdelaj(nizi, 104, "rApIScb1pdjBqa0ZzqZQ8gZOU7plHkSleeLEwfITvEX5ITKXYRizsj_1jKL3pbWF3NGp7MxAtE_Fvwft26");
    izdelaj(nizi, 105, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 106, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 107, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 108, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 109, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 110, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 111, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 112, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 113, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 114, "aAOWH1dJQ65JlUef8");
    izdelaj(nizi, 115, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 116, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 117, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 118, "MA_4lHuPwXWvfO2quEz0mg5vJPwv_jW");
    izdelaj(nizi, 119, "t4trqZE9VAELYdVbBJnQh6Q7D0oW8OnznBIQ9HnHPQnVmIIpJObFvK5Y3Y26_sq");
    izdelaj(nizi, 120, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 121, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 122, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 123, "BNpAR4D19tAqWwZIpxPlPEOWCvYiP2VA1lbvvkqcNRq12BVMTu2TWjr");
    izdelaj(nizi, 124, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 125, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 126, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 127, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 128, "BNpAR4D19tAqWwZIpxPlPEOWCvYiP2VA1lbvvkqcNRq12BVMTu2TWjr");
    izdelaj(nizi, 129, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 130, "50RRb0N_2YsVdpxOH5Vfgv9pNGx0rf_fK4yXwRdUJLobA");
    izdelaj(nizi, 131, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 132, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 133, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 134, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 135, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 136, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 137, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 138, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 139, "EmhGuaKzikpnT0Ruxtm4PFu8pWi2bte3kOVUhO7_hoeX8uBxj1Ua7pG6S3B2TEu8zcJG8RTh6lLDpIHaWynjUja2thNutA");
    izdelaj(nizi, 140, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 141, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 142, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 143, "dNVi60wnplpcSk7A4L6jGMQHX_KI_rxPKSToBrGR1p");
    izdelaj(nizi, 144, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 145, "6wGYXdjMHmj2_uRwyVvDKg_pWrr7Tra4qFXmnJDDx3l0FCxNYvuALFgrmNbrVaMWtmXXxrybj5bi7jtspMxBk");
    izdelaj(nizi, 146, "6Z2JEPnOu1I5WFqfA0cvvW4feghBUNgY8P5GbC667hRmb37bawjuX");
    izdelaj(nizi, 147, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 148, "mUP32hL_yNKvUjunny5");
    izdelaj(nizi, 149, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 150, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 151, "107KfUfd_WwVH_hKzeNVPM2K9l4kltxHgfRYnL5Bf1rre2txGKCt0r");
    izdelaj(nizi, 152, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 153, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 154, "s19E1qM5zSP2vzTu7Z4o9GsGsljMZx8FNtVs4vhYSj_r_swkYXiMka8lzqMfm7992CleaqvnO_6BTWNe");
    izdelaj(nizi, 155, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 156, "F_7VeOgvboYuZCcenCvaFqKMDhLDHcyxYA9jOT2fEiAdyMTW7XGzFsHNMBt0TG0q92x09S1VhdfI26B5");
    izdelaj(nizi, 157, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 158, "SrdP59JOKySw75HRJNEtFfiMFug3twkqV9p4NJ_U4Wru1jX6yASXpzyZzQecviay7xiBxjLqzzeRu3Ipomv");
    izdelaj(nizi, 159, "QTKF8GZSj0UTxPamWC7qyKLUHPxiNL4weDI2QjjlC");
    izdelaj(nizi, 160, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 161, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 162, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 163, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 164, "BNpAR4D19tAqWwZIpxPlPEOWCvYiP2VA1lbvvkqcNRq12BVMTu2TWjr");
    izdelaj(nizi, 165, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 166, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 167, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 168, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 169, "mUP32hL_yNKvUjunny5");
    izdelaj(nizi, 170, "FlXZHIIpONQA2oltge1vHgiJ60Bl3BH9DtnelpzQWVj7kY_BwSsgjJXznF4Z1g5YgdNAdDsBOwETLAbur4Jelut2BAeaf");
    izdelaj(nizi, 171, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 172, "KwtmS_b");
    izdelaj(nizi, 173, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 174, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 175, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 176, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 177, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 178, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 179, "0Mm7Wop7Rev3k7EgyI0Fd8_ychVXJIRnZU7rXMCwc");
    izdelaj(nizi, 180, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 181, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 182, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 183, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 184, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 185, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 186, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 187, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 188, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 189, "_6_dGVH_kxH8Vrj3g2_6wdhr1LRr765Ku5tQsbanbAQU4noNVfnC7dyhQ1gVcyb5Q5WVrv4ZtlW3pBcc1AWRkqYW");
    izdelaj(nizi, 190, "_6_dGVH_kxH8Vrj3g2_6wdhr1LRr765Ku5tQsbanbAQU4noNVfnC7dyhQ1gVcyb5Q5WVrv4ZtlW3pBcc1AWRkqYW");
    izdelaj(nizi, 191, "rZUKaEWHwdPltJ2ZuVxGZrFbycA8CiUKOS2ssVVeccYXnvHd68P8urlx41k0JXbBKK6pRE4aUtmdgHis7769szSlm5ctT90m");
    izdelaj(nizi, 192, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 193, "uPKP69RYLVfwzEYaz__hs_OsEsajKuzqUymwH_An5");
    izdelaj(nizi, 194, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 195, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 196, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 197, "My9WkU0oIIYqRAT5SM7TTi");
    izdelaj(nizi, 198, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 199, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 200, "R3_VM1pRZ_eCPNCBxrxjPQp_LtNoA48quKQ3IM40FNEsv0keEPU1DE4F");
    izdelaj(nizi, 201, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 202, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 203, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 204, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 205, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 206, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 207, "VwY2y7CeK3Grl_ae_sVb79zrNs2EXp3nvyQvq0vQMxAtn");
    izdelaj(nizi, 208, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 209, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 210, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 211, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 212, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 213, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 214, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 215, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 216, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 217, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 218, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 219, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 220, "MbrtyI5NuUSmLObe1FBmmhiDLcE5CJFO8Bf33Fv");
    izdelaj(nizi, 221, "hCtNb5VNwoCeBCsNNZRNcf6uSuZeHRJ30Cf1RQCcKssfVES");
    izdelaj(nizi, 222, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 223, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 224, "rPbvZd6MqFRsNXOcqs5CQBrPNLAPsPeHBBD6qX3nLbp7DxL9YIiYlX9pI786GkapeILnmRYbR0Y1MG9y");
    izdelaj(nizi, 225, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 226, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 227, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 228, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 229, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 230, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 231, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 232, "YK70FIVLiBUthBFJfHMQN9PRPIYFi8OiMmoZN");
    izdelaj(nizi, 233, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 234, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 235, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 236, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 237, "BNpAR4D19tAqWwZIpxPlPEOWCvYiP2VA1lbvvkqcNRq12BVMTu2TWjr");
    izdelaj(nizi, 238, "vmJqWBgZJxRySzGGLukbVaoRg2resG1NGqkyLff8e");
    izdelaj(nizi, 239, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 240, "j6OrLXbc6AbJC65tCTIpFlQosOS5eR6T1cNboYZg30GfAE0izTymjP4OQOONVo8EUeLvrY1IuupO1GIJ");
    izdelaj(nizi, 241, "n3I5aEKdhZt_3R1qm_TKTBgN8TsyeT4rUpaq4eXeASSY0A1qGBuwcqSFJ9RPuMr1P");
    izdelaj(nizi, 242, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 243, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 244, "tHutpGvzEyoeTzecXUWcVKIQSIhlYvEkeg9U21cDZ7TFvYswfhCHUjhStri3PZL8IkSHg7mv1Y67PC");
    izdelaj(nizi, 245, "rApIScb1pdjBqa0ZzqZQ8gZOU7plHkSleeLEwfITvEX5ITKXYRizsj_1jKL3pbWF3NGp7MxAtE_Fvwft26");
    izdelaj(nizi, 246, "mUP32hL_yNKvUjunny5");
    izdelaj(nizi, 247, "GnUbxK_ufQjPo8NsDhZTyXw2Jh7G");
    izdelaj(nizi, 248, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 249, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 250, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 251, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 252, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 253, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 254, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 255, "R921qT3NnFh0WJa4epqshobDn8VA8TOP_Aj6XKyGJQ6rWMCjoSPadQx8iCeA9lJnfc79RImNdBRMYNLBW1VV1gFHV7vT3Ul3s");
    izdelaj(nizi, 256, "q_upwAknQQTpE");
    izdelaj(nizi, 257, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 258, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 259, "rFYxuFSf0LJMt");
    izdelaj(nizi, 260, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 261, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 262, "My9WkU0oIIYqRAT5SM7TTi");
    izdelaj(nizi, 263, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 264, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 265, "SrdP59JOKySw75HRJNEtFfiMFug3twkqV9p4NJ_U4Wru1jX6yASXpzyZzQecviay7xiBxjLqzzeRu3Ipomv");
    izdelaj(nizi, 266, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 267, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 268, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 269, "XGhrVQ4zQam");
    izdelaj(nizi, 270, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 271, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 272, "tdsmeMO31jXGGCpBnqLA4WiOvIsLX9TZdcXsE8bwc0yn4f4GuSWespIl4CG9VCAAevI");
    izdelaj(nizi, 273, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 274, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 275, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 276, "AH58w1SXdd4Rhad4y5D1onfYV8jrNYcDyAXo7RnDphy20PCsNWnC6F2EZbDwV3_qBM57o1s3wDqVFCrvUtfekkC8kiyEi");
    izdelaj(nizi, 277, "hvCpSWCTVpEyvQtx0Oh9fAD6gpkkEgpGfGbiHZG1HaIoQ");
    izdelaj(nizi, 278, "50RRb0N_2YsVdpxOH5Vfgv9pNGx0rf_fK4yXwRdUJLobA");
    izdelaj(nizi, 279, "I6HHj8cCiGcW8VjErFptWpGNVP17rIDajrRUhhH7");
    izdelaj(nizi, 280, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 281, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 282, "9cZebc0e9EImK461kwndYDstaapGxzJcTrXJRX8yLp5npZYvXTkgFTyCg9");
    izdelaj(nizi, 283, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 284, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 285, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 286, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 287, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 288, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 289, "hvCpSWCTVpEyvQtx0Oh9fAD6gpkkEgpGfGbiHZG1HaIoQ");
    izdelaj(nizi, 290, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 291, "4RTjA4fnVFPaMa");
    izdelaj(nizi, 292, "6wGYXdjMHmj2_uRwyVvDKg_pWrr7Tra4qFXmnJDDx3l0FCxNYvuALFgrmNbrVaMWtmXXxrybj5bi7jtspMxBk");
    izdelaj(nizi, 293, "BN2V0c8Xpn7V2IO0d");
    izdelaj(nizi, 294, "GnUbxK_ufQjPo8NsDhZTyXw2Jh7G");
    izdelaj(nizi, 295, "ic_Vt3246FATVvsxtmggKVJWohZfs");
    izdelaj(nizi, 296, "50RRb0N_2YsVdpxOH5Vfgv9pNGx0rf_fK4yXwRdUJLobA");
    izdelaj(nizi, 297, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 298, "cSlhB9pCNiSya23HcfmHN5WZ1A");
    izdelaj(nizi, 299, "Ei1pJSy7fA2sj3rsU9lJ1srzwkz_Zsf");
    izdelaj(nizi, 300, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 301, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 302, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 303, "TMGDqSd0MkYykNv6zq2");
    izdelaj(nizi, 304, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 305, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 306, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 307, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 308, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 309, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 310, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 311, "aInysUYp8tzGwM3QK63AaVnWffB6DMhiQWgr2fsAGIJnCzJ");
    izdelaj(nizi, 312, "Zd4z7xK5bm4EpX1N_AHLUROvRQ3uC_WaclG34I05eN4B");
    izdelaj(nizi, 313, "tHutpGvzEyoeTzecXUWcVKIQSIhlYvEkeg9U21cDZ7TFvYswfhCHUjhStri3PZL8IkSHg7mv1Y67PC");
    izdelaj(nizi, 314, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 315, "SIrz1MdS_KdXvuWFc6Z44y");
    izdelaj(nizi, 316, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 317, "4RTjA4fnVFPaMa");
    izdelaj(nizi, 318, "hvCpSWCTVpEyvQtx0Oh9fAD6gpkkEgpGfGbiHZG1HaIoQ");
    izdelaj(nizi, 319, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 320, "NtuN29SnYnwikvo26HP5mdde5e1gF1PKICaYm1mLUeOQgk7dP83aAhcSkC7ruIlxRfe0QSN1nG8JRB0");
    izdelaj(nizi, 321, "XYLBDROmcPfVGLVwI9JjzAiF5eoXuH91YfUJwjqQcS_b2mITB9xdYBPq3mQtDmKO8Y9onngDqmBqc7LWuDQL5oGsOCKc7mY8M");
    izdelaj(nizi, 322, "aAOWH1dJQ65JlUef8");
    izdelaj(nizi, 323, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 324, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 325, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 326, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 327, "5bw_Nfn");
    izdelaj(nizi, 328, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 329, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 330, "ZM9VLsiPA1wj_qpwOWltpfICGJrzX1jwPN_LiOYkQsT8cydeZIka7THMo0GvyiTR5qAOPQnqP_htnMyDJBT_B");
    izdelaj(nizi, 331, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 332, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 333, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 334, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 335, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 336, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 337, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 338, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 339, "rZUKaEWHwdPltJ2ZuVxGZrFbycA8CiUKOS2ssVVeccYXnvHd68P8urlx41k0JXbBKK6pRE4aUtmdgHis7769szSlm5ctT90m");
    izdelaj(nizi, 340, "jYEJe_Xm0eZwh905EeZC9xaJcQ8jhT9N2yqNnvrGuHRtQ2oqFvm5uw44YCgOXBGgb34dJsSjKv2oqGhen0OqtI");
    izdelaj(nizi, 341, "SDPMHsc4MxemSDcz1bwm_fn82ssZzjUvAAX6Q39MgoRObPQplNZ0i1");
    izdelaj(nizi, 342, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 343, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 344, "QlGmG55pi4uyKT");
    izdelaj(nizi, 345, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 346, "0Mm7Wop7Rev3k7EgyI0Fd8_ychVXJIRnZU7rXMCwc");
    izdelaj(nizi, 347, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 348, "jJl5CAo1CCjkaoTAF4ndGxvCVCr9hWUt0JYaYZGeUia4VRhLHmDGpnZ_jecLSkh5ZOasZm");
    izdelaj(nizi, 349, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 350, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 351, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 352, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 353, "YpGQPpwSnWjpvhNCTpLwnyoqTS1cMX8rd9xi2NWY7Hkg");
    izdelaj(nizi, 354, "XtqKIYS5KLSDZv9hRITBOh5i1");
    izdelaj(nizi, 355, "GmHs4xYtCVQNKMbd8hFoxWBUNLf2RXZUbmgC2ypaQUQejyYgCAtM6c3LfqEzw4Mp56J1ygGil2EIwWzLqFB90VMqxECCGt");
    izdelaj(nizi, 356, "t3JP2yoB0_6ayn6brkPubkHotrPPUqqiHa0aD64Jc9Xx3g");

    char** niziKopija = malloc((n + 1) * sizeof(char*));
    memcpy(niziKopija, nizi, (n + 1) * sizeof(char*));

    racionaliziraj(nizi);

    for (int i = 0; i < n; i++) {
        printf("%d", nizi[i] == niziKopija[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("<%s>\n", nizi[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (nizi[i] == niziKopija[i]) {
            free(nizi[i]);
        }
    }

    free(nizi);
    free(niziKopija);

    printf("-----\n");

    return 0;
}