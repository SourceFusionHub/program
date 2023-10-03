#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SIGNALS 4
#define NUM_GENERATIONS 1000
#define POPULATION_SIZE 100
#define MUTATION_RATE 0.1


typedef struct {
    int timings[NUM_SIGNALS];
    float fitness;
} TrafficPlan;


void generate_random_plan(TrafficPlan* plan) {
    for (int i = 0; i < NUM_SIGNALS; i++) {
        plan->timings[i] = rand() % 61; // Random signal timings between 0 and 60 seconds
    }
}


float evaluate_fitness(const TrafficPlan* plan) {
  
    return (float)(rand() % 1000) / 1000.0; // Placeholder fitness score
}


void crossover(const TrafficPlan* parent1, const TrafficPlan* parent2, TrafficPlan* child) {
    int crossover_point = rand() % NUM_SIGNALS;
    for (int i = 0; i < NUM_SIGNALS; i++) {
        child->timings[i] = (i < crossover_point) ? parent1->timings[i] : parent2->timings[i];
    }
}


void mutate(TrafficPlan* plan) {
    for (int i = 0; i < NUM_SIGNALS; i++) {
        if ((float)rand() / RAND_MAX < MUTATION_RATE) {
            plan->timings[i] = rand() % 61; // Randomly change the timing
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    TrafficPlan population[POPULATION_SIZE];
    TrafficPlan new_population[POPULATION_SIZE];

   
    for (int i = 0; i < POPULATION_SIZE; i++) {
        generate_random_plan(&population[i]);
    }

   
    for (int generation = 0; generation < NUM_GENERATIONS; generation++) {
       
        for (int i = 0; i < POPULATION_SIZE; i++) {
            population[i].fitness = evaluate_fitness(&population[i]);
        }

        
        qsort(population, POPULATION_SIZE, sizeof(TrafficPlan), 
              (int (*)(const void *, const void *))cmp_fitness_descending);

      
        for (int i = 0; i < POPULATION_SIZE / 10; i++) {
            new_population[i] = population[i];
        }

       
        for (int i = POPULATION_SIZE / 10; i < POPULATION_SIZE; i++) {
            TrafficPlan parent1 = population[rand() % POPULATION_SIZE];
            TrafficPlan parent2 = population[rand() % POPULATION_SIZE];
            crossover(&parent1, &parent2, &new_population[i]);
            mutate(&new_population[i]);
        }

        
        for (int i = 0; i < POPULATION_SIZE; i++) {
            population[i] = new_population[i];
        }
    }

   
    TrafficPlan best_solution = population[0];
    printf("Best solution: [");
    for (int i = 0; i < NUM_SIGNALS; i++) {
        printf("%d%s", best_solution.timings[i], (i < NUM_SIGNALS - 1) ? ", " : "]\n");
    }

    return 0;
}
