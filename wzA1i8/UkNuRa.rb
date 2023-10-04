# Define the genetic algorithm parameters
population_size = 50
mutation_rate = 0.01
generations = 100

# Define the range for possible solutions
min_value = -10
max_value = 10

# Define the fitness function to be optimized (minimized)
def fitness_function(x)
  # Example function: f(x) = x^2 - 4x + 4
  return x**2 - 4*x + 4
end

# Generate an initial population of random solutions
def generate_population(size, min_value, max_value)
  return Array.new(size) { rand(min_value..max_value) }
end

# Select parents for reproduction using tournament selection
def select_parents(population, fitness_function)
  tournament_size = 3
  selected_parents = []

  population.size.times do
    tournament = population.sample(tournament_size)
    selected_parent = tournament.min_by { |x| fitness_function.call(x) }
    selected_parents << selected_parent
  end

  return selected_parents
end

# Crossover function (blend two parents to create a child)
def crossover(parent1, parent2)
  alpha = rand(0.1..0.9)
  child = alpha * parent1 + (1 - alpha) * parent2
  return child
end

# Mutation function (add small random noise to a solution)
def mutate(solution, mutation_rate, min_value, max_value)
  if rand < mutation_rate
    solution += rand(-1.0..1.0)
    solution = [solution, max_value].min
    solution = [solution, min_value].max
  end
  return solution
end

# Main genetic algorithm loop
population = generate_population(population_size, min_value, max_value)

generations.times do |generation|
  # Evaluate fitness of the current population
  fitness_scores = population.map { |x| fitness_function.call(x) }

  # Find the best solution in the current population
  best_solution = population[fitness_scores.index(fitness_scores.min)]

  puts "Generation #{generation}: Best Solution = #{best_solution}, Fitness = #{fitness_function.call(best_solution)}"

  # Select parents for reproduction
  parents = select_parents(population, fitness_function)

  # Create a new population through crossover and mutation
  new_population = []

  while new_population.length < population_size
    parent1, parent2 = parents.sample(2)
    child = crossover(parent1, parent2)
    child = mutate(child, mutation_rate, min_value, max_value)
    new_population << child
  end

  population = new_population
end

# Final result
best_solution = population.min_by { |x| fitness_function.call(x) }
puts "Optimal Solution: x = #{best_solution}, Fitness = #{fitness_function.call(best_solution)}"
