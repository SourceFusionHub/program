#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

// Define a structure to represent a particle in the N-Body simulation
struct Particle {
    double x, y, z;  // Position
    double mass;     // Mass

    Particle(double x, double y, double z, double mass)
        : x(x), y(y), z(z), mass(mass) {}
};

// Function to compute the force between two particles
void computeForce(const Particle& p1, const Particle& p2, double& fx, double& fy, double& fz) {
    const double G = 6.67430e-11;  // Gravitational constant

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = std::sqrt(dx * dx + dy * dy + dz * dz);
    
    double f = (G * p1.mass * p2.mass) / (r * r * r);

    fx = f * dx;
    fy = f * dy;
    fz = f * dz;
}

// Function to compute the total force acting on a particle from all other particles
void computeTotalForce(const Particle& particle, const std::vector<Particle>& particles, 
                       double& fx, double& fy, double& fz) {
    fx = fy = fz = 0.0;

    #pragma omp parallel for reduction(+:fx,fy,fz)
    for (int i = 0; i < particles.size(); ++i) {
        if (&particle != &particles[i]) {  // Skip self-interaction
            double local_fx, local_fy, local_fz;
            computeForce(particle, particles[i], local_fx, local_fy, local_fz);
            fx += local_fx;
            fy += local_fy;
            fz += local_fz;
        }
    }
}

int main() {
    const int numParticles = 1000;
    const int numSteps = 1000;
    const double timeStep = 0.1;

    // Initialize particles
    std::vector<Particle> particles;
    for (int i = 0; i < numParticles; ++i) {
        particles.emplace_back(1.0 * i, 1.0 * i, 1.0 * i, 1.0);
    }

    // Simulate N-Body system
    for (int step = 0; step < numSteps; ++step) {
        // Compute forces in parallel for all particles
        #pragma omp parallel for
        for (int i = 0; i < numParticles; ++i) {
            double fx, fy, fz;
            computeTotalForce(particles[i], particles, fx, fy, fz);

            // Update particle position (simple Euler integration)
            particles[i].x += fx * timeStep / particles[i].mass;
            particles[i].y += fy * timeStep / particles[i].mass;
            particles[i].z += fz * timeStep / particles[i].mass;
        }

        // Optionally, you can add code to save or visualize the particle positions here
    }

    std::cout << "Simulation completed." << std::endl;
    return 0;
}
