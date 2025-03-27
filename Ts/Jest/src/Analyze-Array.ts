export class AnalyzeArray {
  static analyze(arr: number[]): object {
    const length = arr.length;
    if (length === 0) throw new Error("Array cannot be empty");
    const avg = arr.reduce((acc, curr) => acc + curr, 0) / length;
    const min = Math.min(...arr);
    const max = Math.max(...arr);

    return {
      average: avg,
      min: min,
      max: max,
      length: length,
    };
  }
}
