class Moves {
  private static isValid(vertex: [number, number]): boolean {
    let [x, y] = vertex;
    return x >= 0 && x < 8 && y >= 0 && y < 8;
  }
  private static findNextMoves(vertex: [number, number]): [number, number][] {
    let positions: [number, number][] = [];
    let [x, y] = vertex;
    let i: number = 0;
    const deltaCoor: [number, number][] = [
      [2, 1],
      [2, -1],
      [-2, 1],
      [-2, -1],
      [1, 2],
      [1, -2],
      [-1, 2],
      [-1, -2],
    ];

    while (i < 8) {
      const [dx, dy] = deltaCoor[i];
      const newMove: [number, number] = [x + dx, y + dy];
      if (this.isValid(newMove)) {
        positions.push(newMove);
      }
      i++;
    }
    return positions;
  }

  static getMoves(vertex: [number, number]): [number, number][] {
    return this.findNextMoves(vertex);
  }
}

export { Moves };
