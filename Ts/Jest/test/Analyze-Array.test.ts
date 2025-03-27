import { AnalyzeArray } from "../src/Analyze-Array";

describe("AnalyzeArray", () => {
  test("returns correct analysis for a valid array", () => {
    expect(AnalyzeArray.analyze([2, 3, 1, 4])).toEqual({
      average: 2.5,
      min: 1,
      max: 4,
      length: 4,
    });
  });

  test("returns correct analysis for a single-element array", () => {
    expect(AnalyzeArray.analyze([5])).toEqual({
      average: 5,
      min: 5,
      max: 5,
      length: 1,
    });
  });

  test("handles an array with negative numbers", () => {
    expect(AnalyzeArray.analyze([-2, -1, -3, 4])).toEqual({
      average: -0.5,
      min: -3,
      max: 4,
      length: 4,
    });
  });

  test("handles an empty array by throwing an error", () => {
    expect(() => AnalyzeArray.analyze([])).toThrow("Array cannot be empty");
  });
});
