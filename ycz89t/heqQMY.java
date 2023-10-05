package ycz89t;

import java.util.ArrayList;  // Import the ArrayList class from the java.util package

import java.util.ArrayList;  // Import the ArrayList class from the java.util package

public class heqQMY {  // Define a class named ToDoList
    private ArrayList<String> tasks;  // Declare a private ArrayList to store tasks

    public heqQMY() {  // Constructor for initializing the ToDoList object
        tasks = new ArrayList<>();  // Initialize the tasks ArrayList
    }

    // Add a task to the to-do list
    public void addTask(String task) {  // Define a method for adding a task
        tasks.add(task);  // Add the specified task to the tasks ArrayList
    }

    // Mark a task as completed
    public void completeTask(int index) {  // Define a method for marking a task as completed
        if (index >= 0 && index < tasks.size()) {  // Check if the index is valid
            String task = tasks.get(index);  // Get the task at the specified index
            tasks.set(index, "[DONE] " + task);  // Update the task to mark it as completed
        } else {
            System.out.println("Invalid task index.");  // Display an error message for an invalid index
        }
    }

    // List all tasks in the to-do list
    public void listTasks() {  // Define a method for listing all tasks
        System.out.println("To-Do List:");  // Print a heading for the to-do list
        for (int i = 0; i < tasks.size(); i++) {  // Iterate through the tasks ArrayList
            System.out.println((i + 1) + ". " + tasks.get(i));  // Display each task with its index
        }
    }

    public static void main(String[] args) {  // The main method to run the program
        heqQMY toDoList = new heqQMY();  // Create an instance of the ToDoList class

        // Adding tasks
        toDoList.addTask("Buy groceries");  // Add a task to the to-do list
        toDoList.addTask("Finish homework");  // Add another task to the to-do list
        toDoList.addTask("Go to the gym");  // Add one more task to the to-do list

        // Listing tasks
        toDoList.listTasks();  // List all tasks in the to-do list

        // Completing a task
        toDoList.completeTask(0);  // Mark the first task as completed

        // Listing tasks after completing one
        toDoList.listTasks();  // List all tasks in the to-do list again
    }
}
