#include <stdio.h>
#include <complex.h>
#include <math.h>

// Define the quantum state as a complex number
typedef struct {
    double complex alpha; // Coefficient for |0⟩
    double complex beta;  // Coefficient for |1⟩
} Qubit;

// Function to create a quantum state |0⟩
Qubit createZeroQubit() {
    Qubit q;
    q.alpha = 1.0;
    q.beta = 0.0;
    return q;
}

// Function to create a quantum state |1⟩
Qubit createOneQubit() {
    Qubit q;
    q.alpha = 0.0;
    q.beta = 1.0;
    return q;
}

// Function to perform a quantum entanglement operation (Bell State)
void entangle(Qubit* q1, Qubit* q2) {
    // Apply a Hadamard gate to q1
    double complex new_alpha1 = (q1->alpha + q1->beta) / sqrt(2);
    double complex new_beta1 = (q1->alpha - q1->beta) / sqrt(2);

    // Swap q1 and q2
    double complex temp_alpha = q1->alpha;
    q1->alpha = q2->alpha;
    q2->alpha = temp_alpha;

    double complex temp_beta = q1->beta;
    q1->beta = q2->beta;
    q2->beta = temp_beta;

    // Apply a CNOT gate to q1 and q2
    q2->alpha = q2->alpha + q2->beta;
    q2->beta = q2->alpha - 2 * q2->beta;
    q1->beta = q1->beta + q2->alpha;
}

int main() {
    // Create two qubits
    Qubit qubit1 = createZeroQubit();
    Qubit qubit2 = createZeroQubit();

    // Entangle the two qubits
    entangle(&qubit1, &qubit2);

    // Print the final state of the qubits
    printf("Qubit 1: alpha = %f, beta = %f\n", creal(qubit1.alpha), cimag(qubit1.alpha));
    printf("Qubit 2: alpha = %f, beta = %f\n", creal(qubit2.alpha), cimag(qubit2.alpha));

    return 0;
}
