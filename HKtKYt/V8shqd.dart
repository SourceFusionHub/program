import 'dart:math';

// Define a class for representing a resident
class Resident {
  final String name;
  final int age;

  Resident(this.name, this.age);
}

// Define a class for representing a building
class Building {
  final String name;
  final int capacity;

  Building(this.name, this.capacity);
}

// Define a class for representing a vehicle
class Vehicle {
  final String type;
  final String registrationNumber;

  Vehicle(this.type, this.registrationNumber);
}

class UrbanEnvironment {
  final List<Resident> residents;
  final List<Building> buildings;
  final List<Vehicle> vehicles;

  UrbanEnvironment({required this.residents, required this.buildings, required this.vehicles});

  UrbanEnvironment.fromList(List<Resident> residents, List<Building> buildings, List<Vehicle> vehicles) {
    this.residents = residents;
    this.buildings = buildings;
    this.vehicles = vehicles;
  }
}

// Define the main UrbanEnvironment class
class UrbanEnvironment {
  final List<Resident> residents;
  final List<Building> buildings;
  final List<Vehicle> vehicles;

  UrbanEnvironment({required this.residents, required this.buildings, required this.vehicles});

  // Simulate traffic in the urban environment
  void simulateTraffic() {
    final random = Random();

    for (final vehicle in vehicles) {
      final destination = buildings[random.nextInt(buildings.length)];
      print('${vehicle.type} ${vehicle.registrationNumber} is heading to ${destination.name}');
    }
  }

  // Print the list of residents in the urban environment
  void listResidents() {
    print('Residents in the Urban Environment:');
    for (final resident in residents) {
      print('Name: ${resident.name}, Age: ${resident.age}');
    }
  }

  // Add a new resident to the urban environment
  void addResident(String name, int age) {
    residents.add(Resident(name, age));
  }

  // Add a new building to the urban environment
  void addBuilding(String name, int capacity) {
    buildings.add(Building(name, capacity));
  }

  // Add a new vehicle to the urban environment
  void addVehicle(String type, String registrationNumber) {
    vehicles.add(Vehicle(type, registrationNumber));
  }
}

void main() {
  // Create an instance of UrbanEnvironment
  final urbanEnvironment = UrbanEnvironment(
    residents: [],
    buildings: [],
    vehicles: [],
  );

  // Add residents, buildings, and vehicles
  urbanEnvironment.addResident('Alice', 30);
  urbanEnvironment.addResident('Bob', 25);
  urbanEnvironment.addBuilding('Apartment A', 100);
  urbanEnvironment.addBuilding('Office Building X', 500);
  urbanEnvironment.addVehicle('Car', 'ABC123');
  urbanEnvironment.addVehicle('Bus', 'XYZ789');

  // List residents and simulate traffic
  urbanEnvironment.listResidents();
  urbanEnvironment.simulateTraffic();
}
final urbanEnvironment = UrbanEnvironment.fromList(
  [
    Resident('Alice', 30),
    Resident('Bob', 25),
  ],
  [
    Building('Apartment A', 100),
    Building('Office Building X', 500),
  ],
  [
    Vehicle('Car', 'ABC123'),
    Vehicle('Bus', 'XYZ789'),
  ],
);
