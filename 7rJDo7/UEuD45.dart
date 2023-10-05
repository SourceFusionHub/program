class Person {
  String name;
  int age;
  String city;
  Person(this.name, this.age, this.city);
}

void main() {
  // Instantiate a Person object
  var person = Person('lio chan', 24, 'Japan');

  // Print out the person's details
  print('Person\'s Name: ${person.name}');
  print('Person\'s Age: ${person.age}');
  print('Person\'s City: ${person.city}');
}
