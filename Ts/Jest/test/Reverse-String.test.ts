import { reverseString } from "../src/Reverse-String";

test("reverseString for single word", () => {
  expect(reverseString("hell")).toBe("lleh");
});
test("reverseString for multiple word", () => {
  expect(reverseString("hello brother priviet")).toBe("teivirp rehtorb olleh");
});
test("reverseString for multiple word with both upper and lower case", () => {
  expect(reverseString("hEllO BrotHER TeStIng TeStIng")).toBe(
    "gnItSeT gnItSeT REHtorB OllEh",
  );
});
test("reverseString for multiple word with both upper and lower case including special characters", () => {
  expect(reverseString("hEllO BrotHER-TeStIng-TeStIng")).toBe(
    "gnItSeT-gnItSeT-REHtorB OllEh",
  );
});
