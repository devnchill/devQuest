/**
 * A type representing a value that can either be of type `T` or `null`.
 */
export type MaybeNull<T> = T | null;

/**
 * Represents a node in the Binary Search Tree (BST).
 */
export class Node {
  /** The value of the node. */
  public data: number;

  /** The left child node or `null` if none exists. */
  public left: MaybeNull<Node>;

  /** The right child node or `null` if none exists. */
  public right: MaybeNull<Node>;

  /**
   * Creates a new node with the given value.
   * @param data - The value to store in the node.
   */
  constructor(data: number) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}
