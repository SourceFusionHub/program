import random


num_particles = 30
num_dimensions = 2
max_iterations = 100
c1 = 2.0  # Cognitive parameter
c2 = 2.0  # Social parameter
w = 0.9   # Inertia weight

lower_bound = -5.0
upper_bound = 5.0


def fitness_function(position):
    
    return sum([x**2 for x in position])


particles = []
for _ in range(num_particles):
    position = [random.uniform(lower_bound, upper_bound) for _ in range(num_dimensions)]
    velocity = [random.uniform(-1, 1) for _ in range(num_dimensions)]
    particles.append({'position': position, 'velocity': velocity, 'best_position': position})


global_best_position = particles[0]['position']
global_best_value = fitness_function(global_best_position)


for iteration in range(max_iterations):
    for particle in particles:
        
        current_fitness = fitness_function(particle['position'])

        
        if current_fitness < fitness_function(particle['best_position']):
            particle['best_position'] = particle['position']

        
        if current_fitness < global_best_value:
            global_best_value = current_fitness
            global_best_position = particle['position']

        
        for i in range(num_dimensions):
            r1, r2 = random.random(), random.random()
            cognitive_component = c1 * r1 * (particle['best_position'][i] - particle['position'][i])
            social_component = c2 * r2 * (global_best_position[i] - particle['position'][i])
            particle['velocity'][i] = w * particle['velocity'][i] + cognitive_component + social_component
            particle['position'][i] += particle['velocity'][i]

    print(f"Iteration {iteration}: Best Value = {global_best_value}, Best Position = {global_best_position}")

print("Optimization finished.")
print(f"Global Best Value = {global_best_value}")
print(f"Global Best Position = {global_best_position}")
