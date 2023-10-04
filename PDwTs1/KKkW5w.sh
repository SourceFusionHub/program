#!/bin/bash

# Simulate quantum particles
particle1_spin=$((RANDOM % 2))
particle2_spin=$((RANDOM % 2))

echo "Particle 1 Spin: $particle1_spin"
echo "Particle 2 Spin: $particle2_spin"

# Calculate quantum entanglement
if [ $particle1_spin -eq $particle2_spin ]; then
    entanglement="High"
else
    entanglement="Low"
fi

echo "Quantum Entanglement: $entanglement"
