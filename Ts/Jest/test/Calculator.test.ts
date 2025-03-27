import { Calculator } from "../src/Calculator";

test("Add 2 numbers", () => {
  expect(Calculator.add(2, 3)).toBe(5);
  expect(Calculator.add(20, 3)).toBe(23);
});

test("subtract 2 numbers", () => {
  expect(Calculator.subtract(2, 3)).toBe(-1);
  expect(Calculator.subtract(2, 0)).toBe(2);
});

test("divide 2 numbers", () => {
  expect(Calculator.divide(15, 3)).toBe(5);
  expect(() => Calculator.divide(2, 0)).toThrow("Denominator cannot be 0");
});

test("multiply 2 numbers", () => {
  expect(Calculator.multiply(2, 3)).toBe(6);
  expect(Calculator.multiply(8, 3)).toBe(24);
  expect(Calculator.multiply(2, 3)).toBe(6);
});
