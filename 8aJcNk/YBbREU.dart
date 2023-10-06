import 'dart:io';

// Define the Book class
class Book {
  String title;
  String author;
  int publicationYear;

  // Constructor to initialize the properties
  Book(this.title, this.author, this.publicationYear);

  // Method to print book details
  void printDetails() {
    print('Title: $title');
    print('Author: $author');
    print('Publication Year: $publicationYear');
  }
}

void main() {
  // Prompt the user for book details
  stdout.write("Enter the title of the book: ");
  String title = stdin.readLineSync() ?? '';
  
  stdout.write("Enter the author of the book: ");
  String author = stdin.readLineSync() ?? '';

  stdout.write("Enter the publication year of the book: ");
  String yearInput = stdin.readLineSync() ?? '';
  int publicationYear = int.tryParse(yearInput) ?? 0; // Use 0 if input is not a valid integer

  // Instantiate an object of the Book class with user input
  var myBook = Book(title, author, publicationYear);

  // Print the book's details
  myBook.printDetails();
}
