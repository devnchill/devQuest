import { Graph } from "./components/Graph";
const graph1 = new Graph([3, 3], [3, 3]);
const graph2 = new Graph([3, 3], [4, 3]);
console.log(graph1.traverse());
console.log(graph2.traverse());
