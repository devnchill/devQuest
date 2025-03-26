import { MaybeNull, Node } from "./Node";

/**
 * Represents a Binary Search Tree (BST) with self-balancing capabilities.
 */
class Tree {
  root: MaybeNull<Node>;

  /**
   * Creates a BST from an array of numbers.
   * Duplicates are removed, and the array is sorted.
   * @param arr - The array of numbers to initialize the BST.
   */
  constructor(arr: Array<number>) {
    arr = [...new Set(arr)].sort((a, b) => a - b);
    this.root = this.buildTree(arr, 0, arr.length - 1);
  }

  /**
   * Recursively builds a balanced BST from a sorted array.
   * @param arr - Sorted array of numbers.
   * @param start - Start index.
   * @param end - End index.
   * @returns The root node of the BST.
   */
  private buildTree(
    arr: Array<number>,
    start: number,
    end: number,
  ): MaybeNull<Node> {
    if (start > end) return null;
    const mid = Math.floor((start + end) / 2);
    const root = new Node(arr[mid]);
    root.left = this.buildTree(arr, start, mid - 1);
    root.right = this.buildTree(arr, mid + 1, end);
    return root;
  }

  /**
   * Inserts a value into the BST.
   * Rebalances the tree if it becomes unbalanced.
   * @param value - The value to insert.
   * @param root - The current root node (used for recursion).
   * @returns The updated node after insertion.
   */
  insert(value: number, root: MaybeNull<Node> = this.root): MaybeNull<Node> {
    if (!root) return new Node(value);
    if (value < root.data) {
      root.left = this.insert(value, root.left);
    } else {
      root.right = this.insert(value, root.right);
    }
    if (!this.isBalanced()) this.rebalance();
    return root;
  }

  /**
   * Deletes a value from the BST.
   * Rebalances the tree if it becomes unbalanced.
   * @param value - The value to delete.
   * @param root - The current root node (used for recursion).
   * @returns The updated node after deletion.
   */
  delete(value: number, root: MaybeNull<Node> = this.root): MaybeNull<Node> {
    if (!root) return null;

    if (root.data === value) {
      if (!root.left && !root.right) return null; // Leaf node
      if (!root.left) return root.right; // One child
      if (!root.right) return root.left; // One child

      // Two children: Replace with the in-order successor
      let nextNode = root.right;
      while (nextNode?.left) {
        nextNode = nextNode.left;
      }
      if (nextNode) {
        root.data = nextNode.data;
        root.right = this.delete(nextNode.data, root.right);
      }
    } else if (value < root.data) {
      root.left = this.delete(value, root.left);
    } else {
      root.right = this.delete(value, root.right);
    }

    if (!this.isBalanced()) this.rebalance();
    return root;
  }

  /**
   * Finds a value in the BST.
   * @param value - The value to find.
   * @param root - The current root node (used for recursion).
   * @returns The node containing the value or `null` if not found.
   */
  find(value: number, root: MaybeNull<Node> = this.root): MaybeNull<Node> {
    if (!root) return null;
    if (root.data === value) return root;
    return value < root.data
      ? this.find(value, root.left)
      : this.find(value, root.right);
  }

  /**
   * Performs a level-order traversal (BFS) of the BST.
   * @param root - The current root node (defaults to the tree root).
   * @param callback - The function to call on each node.
   */
  levelOrder(root = this.root, callback: (node: Node) => void): void {
    if (!root) return;
    const queue: MaybeNull<Node>[] = [root];

    while (queue.length) {
      const current = queue.shift();
      if (current) {
        callback(current);
        if (current.left) queue.push(current.left);
        if (current.right) queue.push(current.right);
      }
    }
  }

  /**
   * Performs an in-order traversal of the BST.
   * @param root - The current root node (defaults to the tree root).
   * @param callback - The function to call on each node.
   */
  inOrder(root = this.root, callback: (node: Node) => void): void {
    if (!root) return;
    this.inOrder(root.left, callback);
    callback(root);
    this.inOrder(root.right, callback);
  }

  /**
   * Performs a pre-order traversal of the BST.
   * @param root - The current root node (defaults to the tree root).
   * @param callback - The function to call on each node.
   */
  preOrder(root = this.root, callback: (node: Node) => void): void {
    if (!root) return;
    callback(root);
    this.preOrder(root.left, callback);
    this.preOrder(root.right, callback);
  }

  /**
   * Performs a post-order traversal of the BST.
   * @param root - The current root node (defaults to the tree root).
   * @param callback - The function to call on each node.
   */
  postOrder(root = this.root, callback: (node: Node) => void): void {
    if (!root) return;
    this.postOrder(root.left, callback);
    this.postOrder(root.right, callback);
    callback(root);
  }

  /**
   * Calculates the height of the BST.
   * @param root - The current root node (defaults to the tree root).
   * @returns The height of the BST.
   */
  height(root = this.root): number {
    if (!root) return -1;
    return 1 + Math.max(this.height(root.left), this.height(root.right));
  }

  /**
   * Calculates the depth of a target node in the BST.
   * @param targetNode - The node whose depth is to be calculated.
   * @param root - The current root node (defaults to the tree root).
   * @param currentDepth - The current depth (used for recursion).
   * @returns The depth of the target node.
   */
  depth(targetNode: Node, root = this.root, currentDepth = 0): number {
    if (!root) return -1;
    if (root === targetNode) return currentDepth;
    return targetNode.data < root.data
      ? this.depth(targetNode, root.left, currentDepth + 1)
      : this.depth(targetNode, root.right, currentDepth + 1);
  }

  /**
   * Checks if the BST is balanced.
   * @param root - The current root node (defaults to the tree root).
   * @returns `true` if the BST is balanced, otherwise `false`.
   */
  isBalanced(root = this.root): boolean {
    if (!root) return true;
    const leftHeight = this.height(root.left);
    const rightHeight = this.height(root.right);
    return (
      Math.abs(leftHeight - rightHeight) <= 1 &&
      this.isBalanced(root.left) &&
      this.isBalanced(root.right)
    );
  }

  /**
   * Rebalances the BST by building a balanced tree from its in-order traversal.
   * @param root - The current root node (defaults to the tree root).
   */
  rebalance(root = this.root): void {
    const arr: number[] = [];
    this.inOrder(root, (node) => arr.push(node.data));
    this.root = this.buildTree(arr, 0, arr.length - 1);
  }
}
export { Tree };
