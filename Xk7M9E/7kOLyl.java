import java.io.*;
import java.util.ArrayList;
import java.util.List;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

class Contact {
    private String name;
    private String email;

    public Contact(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}

public class AddressBook {
    private List<Contact> contacts = new ArrayList<>();

    // Add a contact to the address book
    public void addContact(String name, String email) {
        contacts.add(new Contact(name, email));
    }

    // Export contacts to a JSON file
    public void exportToFile(String filename) {
        try (Writer writer = new FileWriter(filename)) {
            Gson gson = new GsonBuilder().create();
            gson.toJson(contacts, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Import contacts from a JSON file
    public void importFromFile(String filename) {
        try (Reader reader = new FileReader(filename)) {
            Gson gson = new GsonBuilder().create();
            Contact[] importedContacts = gson.fromJson(reader, Contact[].class);
            contacts.clear();
            for (Contact contact : importedContacts) {
                contacts.add(contact);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Get all contacts
    public List<Contact> getContacts() {
        return contacts;
    }

    public static void main(String[] args) {
        AddressBook addressBook = new AddressBook();
        addressBook.addContact("John Doe", "john@example.com");
        addressBook.addContact("Jane Smith", "jane@example.com");

        // Export contacts to a file
        addressBook.exportToFile("contacts.json");

        // Clear the contacts in the address book
        addressBook = new AddressBook();

        // Import contacts from the file
        addressBook.importFromFile("contacts.json");

        // Get and display the imported contacts
        List<Contact> contacts = addressBook.getContacts();
        for (Contact contact : contacts) {
            System.out.println("Name: " + contact.getName() + ", Email: " + contact.getEmail());
        }
    }
}
