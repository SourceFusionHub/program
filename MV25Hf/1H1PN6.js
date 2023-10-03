class SuffixTreeNode {
    constructor() {
        this.children = {};
        this.isEnd = false;
    }
}

class SuffixTree {
    constructor() {
        this.root = new SuffixTreeNode();
    }

    insert(text) {
        for (let i = 0; i < text.length; i++) {
            let currentNode = this.root;
            for (let j = i; j < text.length; j++) {
                const char = text[j];
                if (!currentNode.children[char]) {
                    currentNode.children[char] = new SuffixTreeNode();
                }
                currentNode = currentNode.children[char];
            }
            currentNode.isEnd = true;
        }
    }

    search(query) {
        let currentNode = this.root;
        for (let i = 0; i < query.length; i++) {
            const char = query[i];
            if (!currentNode.children[char]) {
                return false;
            }
            currentNode = currentNode.children[char];
        }
        return currentNode.isEnd;
    }
}

// Example usage:
const suffixTree = new SuffixTree();
suffixTree.insert("banana");
suffixTree.insert("apple");
suffixTree.insert("cherry");

console.log(suffixTree.search("apple"));  // true
console.log(suffixTree.search("orange")); // false
