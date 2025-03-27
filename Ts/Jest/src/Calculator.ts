export class Calculator {
  static add(n1: number, n2: number): number {
    if (Number.isNaN(n1) || Number.isNaN(n2))
      throw new Error("Invalid Input: Arguments should be numbers");
    return n1 + n2;
  }
  static subtract(n1: number, n2: number): number {
    if (Number.isNaN(n1) || Number.isNaN(n2))
      throw new Error("Invalid Input: Arguments should be numbers");
    return n1 - n2;
  }
  static multiply(n1: number, n2: number): number {
    if (Number.isNaN(n1) || Number.isNaN(n2))
      throw new Error("Invalid Input: Arguments should be numbers");
    return n1 * n2;
  }
  static divide(n1: number, n2: number): number {
    if (Number.isNaN(n1) || Number.isNaN(n2))
      throw new Error("Invalid Input: Arguments should be numbers");
    if (n2 === 0) throw new Error("Denominator cannot be 0");
    return n1 / n2;
  }
}
