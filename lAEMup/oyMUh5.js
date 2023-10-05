// Define a node class
class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

// Define a linked list class
class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  // Insert a node at the end of the list
  insertLast(data) {
    let node = new Node(data);
    let current;

    // If the list is empty, make the node the head
    if (!this.head) {
      this.head = node;
    } else {
      current = this.head;

      // Traverse the list until the last node
      while (current.next) {
        current = current.next;
      }

      // Append the node to the last node
      current.next = node;
    }

    this.size++;
  }

  // Print the data of each node in the list
  printListData() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }

  // Reverse the list
  reverseList() {
    let prev = null;
    let current = this.head;
    let next = null;
    while (current) {
      next = current.next; // save the next node
      current.next = prev; // point the current node to the previous node
      prev = current; // update the previous node
      current = next; // update the current node
    }
    this.head = prev; // update the head of the list
  }
}

// Create a linked list and insert some nodes from user input
let list = new LinkedList();
let n = prompt("How many elements do you want to insert in the linked list?"); // get the number of elements from user input
for (let i = 0; i < n; i++) {
  let data = prompt("Enter element " + (i + 1)); // get each element from user input
  list.insertLast(data); // insert the element at the end of the list
}

// Print the original list
console.log("Original list:");
list.printListData();

// Reverse the list
list.reverseList();

// Print the reversed list
console.log("Reversed list:");
list.printListData();
