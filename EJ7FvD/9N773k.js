class TreeNode {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

function isValidBST(root) {
  function isBST(node, min, max) {
    if (!node) return true;
    if (node.val <= min || node.val >= max) {
      return false;
    }
    return (
      isBST(node.left, min, node.val) &&
      isBST(node.right, node.val, max)
    );
  }

 
  return isBST(root, Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
}

const root = new TreeNode(2);
root.left = new TreeNode(1);
root.right = new TreeNode(3);

console.log(isValidBST(root)); // Output: true
