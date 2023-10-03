class Contact {
  String name;
  String phoneNumber;
  String email;

  Contact(this.name, this.phoneNumber, this.email);

  @override
  String toString() {
    return 'Name: $name, Phone Number: $phoneNumber, Email: $email';
  }
}

class ContactManagementSystem {
  List<Contact> contacts = [];

  void addContact(String name, String phoneNumber, String email) {
    Contact newContact = Contact(name, phoneNumber, email);
    contacts.add(newContact);
    print('Contact added successfully: ${newContact.toString()}');
  }

  void updateContact(String name, String newPhoneNumber, String newEmail) {
    for (int i = 0; i < contacts.length; i++) {
      if (contacts[i].name == name) {
        contacts[i].phoneNumber = newPhoneNumber;
        contacts[i].email = newEmail;
        print('Contact updated successfully: ${contacts[i].toString()}');
        return;
      }
    }
    print('Contact not found for updating: $name');
  }

  List<Contact> searchContacts(String query) {
    List<Contact> searchResults = [];
    for (int i = 0; i < contacts.length; i++) {
      if (contacts[i].name.contains(query) ||
          contacts[i].phoneNumber.contains(query) ||
          contacts[i].email.contains(query)) {
        searchResults.add(contacts[i]);
      }
    }
    return searchResults;
  }
}

void main() {
  ContactManagementSystem cms = ContactManagementSystem();

  cms.addContact('John Doe', '123-456-7890', 'john@example.com');
  cms.addContact('Jane Smith', '987-654-3210', 'jane@example.com');

  print('Contacts:');
  print(cms.contacts);

  cms.updateContact('John Doe', '555-555-5555', 'newemail@example.com');

  print('Updated Contacts:');
  print(cms.contacts);

  String searchQuery = 'Jane';
  List<Contact> searchResults = cms.searchContacts(searchQuery);

  print('Search Results for "$searchQuery":');
  for (var contact in searchResults) {
    print(contact);
  }
}
