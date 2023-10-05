class HashTable {
    constructor(size = 100) {
      this.size = size;
      this.table = new Array(size);
    }
  
    // Hash function to convert a key into an index
    hash(key) {
      let hash = 0;
      for (let i = 0; i < key.length; i++) {
        hash += key.charCodeAt(i);
      }
      return hash % this.size;
    }
  
    // Insert a key-value pair into the hash table
    insert(key, value) {
      const index = this.hash(key);
      if (!this.table[index]) {
        this.table[index] = [];
      }
      this.table[index].push({ key, value });
    }
  
    // Retrieve the value associated with a key from the hash table
    get(key) {
      const index = this.hash(key);
      if (this.table[index]) {
        for (const pair of this.table[index]) {
          if (pair.key === key) {
            return pair.value;
          }
        }
      }
      return undefined;
    }
  
    // Remove a key-value pair from the hash table
    remove(key) {
      const index = this.hash(key);
      if (this.table[index]) {
        for (let i = 0; i < this.table[index].length; i++) {
          if (this.table[index][i].key === key) {
            this.table[index].splice(i, 1);
            return true; // Key found and removed
          }
        }
      }
      return false; // Key not found
    }
  }
  
  // Example usage:
  const myHashTable = new HashTable();
  
  myHashTable.insert("name", "John");
  myHashTable.insert("age", 30);
  myHashTable.insert("city", "New York");
  
  console.log(myHashTable.get("name")); // Output: John
  console.log(myHashTable.get("age"));  // Output: 30
  console.log(myHashTable.get("city")); // Output: New York
  
  myHashTable.remove("age");
  console.log(myHashTable.get("age"));  // Output: undefined  