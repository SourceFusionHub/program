class TreeNode {
    var value: Int
    var left: TreeNode?
    var right: TreeNode?
    
    init(_ value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

// Function to find the kth smallest element in a BST
func kthSmallest(root: TreeNode?, k: Int) -> Int? {
    // Initialize an array to store the in-order traversal elements
    var inorderElements = [Int]()
    
    // Helper function to perform in-order traversal
    func inorderTraversal(node: TreeNode?) {
        guard let node = node else { return }
        
        // Recursively traverse the left subtree
        inorderTraversal(node: node.left)
        
        // Append the current node's value to the array
        inorderElements.append(node.value)
        
        // Recursively traverse the right subtree
        inorderTraversal(node: node.right)
    }
    
    // Perform in-order traversal to populate the array
    inorderTraversal(node: root)
    
    // Check if k is within the valid range
    if k > 0 && k <= inorderElements.count {
        // The kth smallest element is at index k-1 in the sorted array
        return inorderElements[k - 1]
    } else {
        // k is out of range
        return nil
    }
}

// Example usage:
// Create a sample BST:
//      3
//     / \
//    1   4
//     \
//      2
let root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left?.right = TreeNode(2)

let k = 2 // Find the 2nd smallest element
if let result = kthSmallest(root: root, k: k) {
    print("The \(k)th smallest element is: \(result)")
} else {
    print("Invalid value of k")
}
