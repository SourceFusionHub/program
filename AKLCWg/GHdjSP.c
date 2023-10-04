#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 8
#define PI 3.14159265358979323846


int oracle(int target, int guess) {
    return (target == guess) ? -1 : 1;
}


void diffusion(int* array, int n) {
    int i;
    double average = 0;
    
    for (i = 0; i < n; i++) {
        array[i] = -array[i];
        average += array[i];
    }
    
    average /= n;
    
    for (i = 0; i < n; i++) {
        array[i] = 2 * average - array[i];
    }
}


void random_phase_inversion(int* array, int n) {
    int random_index = rand() % n;
    array[random_index] = -array[random_index];
}


int grover(int* array, int n, int target) {
    int iterations = (int)(PI / 4.0 * sqrt(n));
    int guess;
    
    
    for (int i = 0; i < n; i++) {
        array[i] = 1;
    }
    
    
    for (int i = 0; i < iterations; i++) {
        
        random_phase_inversion(array, n);
        
        
        for (int j = 0; j < n; j++) {
            if (oracle(target, j) == -1) {
                array[j] = -array[j];
            }
        }
        
        
        diffusion(array, n);
    }
    
    
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] == -1) {
            result = i;
            break;
        }
    }
    
    return result;
}

int main() {
    int array[N];
    int target = 5;
    
    
    srand(time(NULL));
    
    
    int result = grover(array, N, target);
    
    printf("Target element %d found at index %d\n", target, result);
    
    return 0;

    /*Never worked on a quantum computation algorithm in C*/
    /*Hope it satisfies*/
}
