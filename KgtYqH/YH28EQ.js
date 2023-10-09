// Node class
class Node {
  constructor(order) {
    this.order = order;
    this.values = [];
    this.keys = [];
    this.nextKey = null;
    this.parent = null;
    this.checkLeaf = false;
  }

  // Insert at the leaf
  insertAtLeaf(leaf, value, key) {
    if (this.values) {
      const temp1 = this.values;
      for (let i = 0; i < temp1.length; i++) {
        if (value === temp1[i]) {
          this.keys[i].push(key);
          break;
        } else if (value < temp1[i]) {
          this.values = this.values.slice(0, i).concat([value]).concat(this.values.slice(i));
          this.keys = this.keys.slice(0, i).concat([[key]]).concat(this.keys.slice(i));
          break;
        } else if (i + 1 === temp1.length) {
          this.values.push(value);
          this.keys.push([key]);
          break;
        }
      }
    } else {
      this.values = [value];
      this.keys = [[key]];
    }
  }
}

// B+ tree class
class BplusTree {
  constructor(order) {
    this.root = new Node(order);
    this.root.checkLeaf = true;
  }

  // Insert operation
  insert(value, key) {
    value = String(value);
    const oldNode = this.search(value);
    oldNode.insertAtLeaf(oldNode, value, key);

    // Check if the node is full
    if (oldNode.values.length > oldNode.order * 2 / 3) {
      this.splitNode(oldNode);
    }
  }

  // Split node operation
  splitNode(node) {
    const middleIndex = Math.floor(node.values.length / 2);
    const middleValue = node.values[middleIndex];
    const middleKey = node.keys[middleIndex];

    // Create a new node
    const newNode = new Node(node.order);

    // Copy the values and keys to the new node
    newNode.values = node.values.slice(middleIndex + 1);
    newNode.keys = node.keys.slice(middleIndex + 1);

    // Update the parent node
    if (node.parent) {
      node.parent.insertAtLeaf(node.parent, middleValue, middleKey);
    } else {
      // Create a new root node
      const newRoot = new Node(node.order);
      newRoot.insertAtLeaf(newRoot, middleValue, middleKey);
      newRoot.left = node;
      newRoot.right = newNode;

      this.root = newRoot;
    }

    // Update the child nodes
    node.right = newNode;
    newNode.parent = node.parent;
  }

  // Search operation
  search(value) {
    value = String(value);
    let currentNode = this.root;

    while (!currentNode.checkLeaf) {
      let i = 0;
      while (i < currentNode.values.length && value > currentNode.values[i]) {
        i++;
      }

      currentNode = currentNode.keys[i];
    }

    // Search the leaf node for the value
    for (let i = 0; i < currentNode.values.length; i++) {
      if (currentNode.values[i] === value) {
        return currentNode;
      }
    }

    // Value not found
    return null;
  }
}
