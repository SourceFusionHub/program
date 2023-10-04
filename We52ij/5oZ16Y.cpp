#include <iostream>
#include <cmath>
#include <memory>

// Function to calculate the volume of a dodecahedron
double calculateDodecahedronVolume(double edgeLength) {
    // Formula to calculate the volume of a dodecahedron:
    // V = ((15 + 7 * sqrt(5)) / 4) * edgeLength * edgeLength * edgeLength
    double volume = (((15) + (7) * sqrt(5)) / 4) * pow(edgeLength, 3);
    return volume;
}

int main() {
    double edgeLength;
    std::cout << "Enter the edge length of the dodecahedron: ";
    std::cin >> edgeLength;

    // Allocate  memory for the edge length
    std::unique_ptr<double> edgeLengthPtr(new double(edgeLength));

    // Calculate the volume of the dodecahedron 
    double volume = calculateDodecahedronVolume(*edgeLengthPtr);
    std::cout << "The volume of the dodecahedron is: " << volume << std::endl;

    return 0;
}
