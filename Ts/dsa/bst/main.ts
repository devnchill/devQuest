import { Tree } from "./components/Tree";
import { generateArrayWithRandomNumber } from "./Util/buildArray";

const BST = new Tree(generateArrayWithRandomNumber(100, 20));
console.log(BST.isBalanced());

// Pre-order Traversal
const preOrderNodes: number[] = [];
BST.preOrder(BST.root, (node) => {
  preOrderNodes.push(node.data);
});
console.log("Pre-order:", preOrderNodes);

// In-order Traversal
const inOrderNodes: number[] = [];
BST.inOrder(BST.root, (node) => {
  inOrderNodes.push(node.data);
});
console.log("In-order:", inOrderNodes);

// Post-order Traversal
const postOrderNodes: number[] = [];
BST.postOrder(BST.root, (node) => {
  postOrderNodes.push(node.data);
});
console.log("Post-order:", postOrderNodes);

// Insert more nodes
BST.insert(119);
BST.insert(182);
BST.insert(218);
BST.insert(317);
BST.insert(328);
BST.insert(339);
BST.insert(410);
BST.insert(511);
BST.insert(312);
BST.insert(373);

console.log(BST.isBalanced());

// Rebalance the tree
BST.rebalance();
console.log(BST.isBalanced());

// ✅ Reset the traversal arrays before re-running
const preOrderNodesAfter: number[] = [];
BST.preOrder(BST.root, (node) => {
  preOrderNodesAfter.push(node.data);
});
console.log("Pre-order after rebalance:", preOrderNodesAfter);

const inOrderNodesAfter: number[] = [];
BST.inOrder(BST.root, (node) => {
  inOrderNodesAfter.push(node.data);
});
console.log("In-order after rebalance:", inOrderNodesAfter);

const postOrderNodesAfter: number[] = [];
BST.postOrder(BST.root, (node) => {
  postOrderNodesAfter.push(node.data);
});
console.log("Post-order after rebalance:", postOrderNodesAfter);
