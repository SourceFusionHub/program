#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

typedef double complex cplx;

cplx* createSuperposition(int n) {
    cplx* superposition = (cplx*)malloc(sizeof(cplx) * n);
    double inv_sqrt_n = 1.0 / sqrt(n);
    
    for (int i = 0; i < n; i++) {
        superposition[i] = inv_sqrt_n;
    }
    
    return superposition;
}


int measureQubit(cplx* superposition, int n) {
    double rand_num = (double)rand() / RAND_MAX; // Random number between 0 and 1
    
    double cumulative_prob = 0.0;
    for (int i = 0; i < n; i++) {
        cumulative_prob += cabs(superposition[i]) * cabs(superposition[i]);
        if (rand_num <= cumulative_prob) {
            return i; 
        }
    }
    
    return n - 1; 
}

int main() {
    srand(time(NULL)); 

    int num_qubits = 2;
    int num_states = 1 << num_qubits; 
    
    cplx* superposition = createSuperposition(num_states);

    printf("Initial Superposition State:\n");
    for (int i = 0; i < num_states; i++) {
        printf("|%d>: %.3f + %.3fi\n", i, creal(superposition[i]), cimag(superposition[i]));
    }

    int measured_state = measureQubit(superposition, num_states);

    printf("\nMeasured State: |%d>\n", measured_state);

    free(superposition); 

    return 0;
}
