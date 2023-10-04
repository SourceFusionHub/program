class Car {
  String make;
  String model;
  int year;

  Car(this.make, this.model, this.year);

  void printDetails() {
    print('Car Details:');
    print('Make: $make');
    print('Model: $model');
    print('Year: $year');
  }
}

void main() {
  // Instantiate a Car object
  Car myCar = Car('Toyota', 'Camry', 2022);

  // Print out the car's details
  myCar.printDetails();
}
