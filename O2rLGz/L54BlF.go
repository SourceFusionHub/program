package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

// Constants for the genetic algorithm
const (
	populationSize = 100
	numGenerations = 100
	mutationRate   = 0.01
)

// Individual represents a solution in the population.
type Individual struct {
	genes      []int
	fitness    int
}

// Generate a random individual with a given gene length.
func generateIndividual(geneLength int) Individual {
	individual := Individual{}
	individual.genes = make([]int, geneLength)
	for i := range individual.genes {
		individual.genes[i] = rand.Intn(100) // Random initial genes
	}
	return individual
}

// Calculate the fitness of an individual.
func calculateFitness(individual Individual) int {
	return sum(individual.genes)
}

// Sum of all elements in a slice.
func sum(slice []int) int {
	total := 0
	for _, v := range slice {
		total += v
	}
	return total
}

// Perform crossover to create a child individual.
func crossover(parent1, parent2 Individual) Individual {
	child := Individual{}
	geneLength := len(parent1.genes)
	child.genes = make([]int, geneLength)
	crossoverPoint := rand.Intn(geneLength)
	for i := 0; i < crossoverPoint; i++ {
		child.genes[i] = parent1.genes[i]
	}
	for i := crossoverPoint; i < geneLength; i++ {
		child.genes[i] = parent2.genes[i]
	}
	return child
}

// Apply mutation to an individual.
func mutate(individual Individual) Individual {
	geneLength := len(individual.genes)
	for i := 0; i < geneLength; i++ {
		if rand.Float64() < mutationRate {
			individual.genes[i] = rand.Intn(100) // Mutate with a random gene
		}
	}
	return individual
}

func main() {
	rand.Seed(time.Now().UnixNano())

	// Initialize the population with random individuals.
	population := make([]Individual, populationSize)
	for i := range population {
		population[i] = generateIndividual(10) // 10 genes per individual
	}

	// Main loop for evolution.
	for generation := 0; generation < numGenerations; generation++ {
		// Calculate fitness for each individual.
		for i := range population {
			population[i].fitness = calculateFitness(population[i])
		}

		// Sort the population by fitness in descending order.
		sort.Slice(population, func(i, j int) bool {
			return population[i].fitness > population[j].fitness
		})

		// Display the best individual in the current generation.
		fmt.Printf("Generation %d: Best Fitness = %d\n", generation, population[0].fitness)

		// Create a new population through selection, crossover, and mutation.
		newPopulation := make([]Individual, populationSize)
		for i := 0; i < populationSize; i += 2 {
			parent1 := population[i]
			parent2 := population[i+1]
			child1 := crossover(parent1, parent2)
			child2 := crossover(parent2, parent1)
			child1 = mutate(child1)
			child2 = mutate(child2)
			newPopulation[i] = child1
			newPopulation[i+1] = child2
		}
		population = newPopulation
	}

	// Display the best solution found.
	fmt.Println("Best Solution:", population[0].genes)
	fmt.Println("Best Fitness:", population[0].fitness)
}
