class Node {
    constructor(value, level) {
      this.value = value;
      this.forward = new Array(level + 1);
    }
  }
  
  class SkipList {
    constructor(maxLevel) {
      this.head = new Node(-1, maxLevel);
      this.maxLevel = maxLevel;
      this.level = 0;
    }
  
    randomLevel() {
      let level = 0;
      while (Math.random() < 0.5 && level < this.maxLevel) {
        level++;
      }
      return level;
    }
  
    insert(value) {
      const update = new Array(this.maxLevel + 1);
      let current = this.head;
  
      for (let i = this.level; i >= 0; i--) {
        while (
          current.forward[i] !== undefined &&
          current.forward[i].value < value
        ) {
          current = current.forward[i];
        }
        update[i] = current;
      }
  
      current = current.forward[0];
  
      if (current === undefined || current.value !== value) {
        const newNodeLevel = this.randomLevel();
        if (newNodeLevel > this.level) {
          for (let i = this.level + 1; i <= newNodeLevel; i++) {
            update[i] = this.head;
          }
          this.level = newNodeLevel;
        }
  
        const newNode = new Node(value, newNodeLevel);
  
        for (let i = 0; i <= newNodeLevel; i++) {
          newNode.forward[i] = update[i].forward[i];
          update[i].forward[i] = newNode;
        }
      }
    }
  
    search(target) {
      let current = this.head;
      for (let i = this.level; i >= 0; i--) {
        while (
          current.forward[i] !== undefined &&
          current.forward[i].value < target
        ) {
          current = current.forward[i];
        }
      }
  
      current = current.forward[0];
      if (current !== undefined && current.value === target) {
        return true;
      }
      return false;
    }
  }
  
  // Example usage:
  const skipList = new SkipList(4); // Max level is 4 for this example
  
  skipList.insert(10);
  skipList.insert(25);
  skipList.insert(5);
  skipList.insert(30);
  
  console.log(skipList.search(5)); // Output: true
  console.log(skipList.search(15)); // Output: false
  