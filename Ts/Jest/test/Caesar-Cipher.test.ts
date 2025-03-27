import { CaesarCipher } from "../src/Caesar-Cipher";

describe("CaesarCipher.encrypt", () => {
  test("encrypts lowercase letters with a positive shift", () => {
    expect(CaesarCipher.encrypt("hello", 3)).toBe("khoor");
    expect(CaesarCipher.encrypt("abc", 2)).toBe("cde");
  });

  test("encrypts with wraparound behavior", () => {
    expect(CaesarCipher.encrypt("xyz", 3)).toBe("abc");
    expect(CaesarCipher.encrypt("z", 1)).toBe("a");
  });

  test("handles non-alphabetic characters", () => {
    expect(CaesarCipher.encrypt("abc!", 2)).toBe("cde!");
    expect(CaesarCipher.encrypt("a b c", 1)).toBe("b c d");
  });

  test("handles uppercase characters separately", () => {
    expect(CaesarCipher.encrypt("Hello", 3)).toBe("Khoor");
  });

  test("throws error for invalid shift factor", () => {
    expect(() => CaesarCipher.encrypt("abc", NaN)).toThrow(
      "TypeError: Shift Factor must be a number",
    );
    expect(() => CaesarCipher.encrypt("abc", Number("xyz"))).toThrow(
      "TypeError: Shift Factor must be a number",
    );
  });

  test("handles edge cases", () => {
    expect(CaesarCipher.encrypt("", 3)).toBe("");
    expect(CaesarCipher.encrypt("aaa", 0)).toBe("aaa");
    expect(CaesarCipher.encrypt("a", 26)).toBe("a");
  });
});
