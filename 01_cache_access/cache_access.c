#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000  /* 配列のサイズ（1000万要素、約40MB） */
#define STRIDE 64      /* ストライド（飛び飛びにアクセスする間隔） */

int main(void) {
    int *array = malloc(sizeof(int) * SIZE);
    if (array == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    long long sum = 0;
    clock_t start, end;

    /* ① 順番にアクセス（ストライド1） */
    start = clock();
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }
    end = clock();
    double sequential_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("順次アクセス      : sum = %lld, 実行時間 = %f 秒\n", sum, sequential_time);

    /* ② 飛び飛びにアクセス（ストライドSTRIDE、アクセス総数は①と同じ） */
    sum = 0;
    start = clock();
    for (int offset = 0; offset < STRIDE; offset++) {
        for (int i = offset; i < SIZE; i += STRIDE) {
            sum += array[i];
        }
    }
    end = clock();
    double strided_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("ストライドアクセス: sum = %lld, 実行時間 = %f 秒\n", sum, strided_time);

    printf("倍率：ストライドアクセスは順次アクセスの約 %.2f 倍\n", strided_time / sequential_time);

    free(array);
    return 0;
}