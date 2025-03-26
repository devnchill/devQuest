import { Moves } from "./MoveGenerator";

class Graph {
  start: [number, number];
  dest: [number, number];

  constructor(start: [number, number], target: [number, number]) {
    this.start = start;
    this.dest = target;
  }

  traverse(): [number, number][] {
    console.log(`Start: ${this.start}, Target: ${this.dest}`);
    const queue: [[number, number], [number, number][]][] = [
      [this.start, [this.start]],
    ];
    const visited: Set<string> = new Set();
    visited.add(JSON.stringify(this.start));
    while (queue.length > 0) {
      const [current, path] = queue.shift()!;
      if (JSON.stringify(current) === JSON.stringify(this.dest)) {
        console.log(`You made it in ${path.length} moves! Here's your path:`);
        return path;
      }
      const validMoves = Moves.getMoves(current);
      for (const move of validMoves) {
        const moveKey = JSON.stringify(move);
        if (!visited.has(moveKey)) {
          visited.add(moveKey);
          queue.push([move, [...path, move]]);
        }
      }
    }
    console.log(" No path found.");
    return [];
  }
}

export { Graph };
