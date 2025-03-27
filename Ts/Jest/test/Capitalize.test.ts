import { Capitalize } from "../src/Capitalize";

test("Capitalize first letter of a valid string", () => {
  expect(Capitalize("  hell")).toBe("Hell");
  expect(Capitalize("hell")).toBe("Hell");
});

test("Throw error for invalid input", () => {
  expect(() => Capitalize("1hell")).toThrow(
    "Input must start with an alphabetic character.",
  );
  expect(() => Capitalize("-hell")).toThrow(
    "Input must start with an alphabetic character.",
  );
  expect(() => Capitalize(" 123")).toThrow(
    "Input must start with an alphabetic character.",
  );
});
