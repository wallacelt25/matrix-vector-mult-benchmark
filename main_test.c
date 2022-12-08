#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mylib/mylib.h"


void test_multiply_vector_matrix(int *M, int *v, int N, int *vector_expected){
    int *Mv = (int*)malloc(N * sizeof(int));

    if (Mv == NULL){
        printf("Malloc denied!\n");
        return;
    }
    
    matVecMult(M, v, Mv, N);

    int i;
    for (i = 0; i < N; i++){
        printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, Mv[i], i, vector_expected[i]);
        assert(Mv[i] == vector_expected[i]);
    }
}

int main(){
    int total_test_cases = 3;
    int N = 2;

    int matrix_input_test_case[3][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {9, 10, 11}
    };

    int vector_input_test_case[3][2] = {
        {7, 2},
        {8, 2},
        {9, 2}
    };

    int vector_expected_test_case[3][2] = {
        {20, 38},
        {52, 74},
        {101, 103}
    };

    int i;
    for (i = 0; i < total_test_cases; i++)
    {
        printf("Test #%d:\n", i + 1);

        test_multiply_vector_matrix(
        matrix_input_test_case[i],
        vector_input_test_case[i],
        N,
        vector_expected_test_case[i]
        );
         
        printf("\n");
    }

    return 0;
}