export class CaesarCipher {
  private static lowercase: string[] = "abcdefghijklmnopqrstuvwxyz".split("");
  private static uppercase: string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".split("");

  static encrypt(msg: string, shiftFactor: number): string {
    if (Number.isNaN(shiftFactor)) {
      throw new Error("TypeError: Shift Factor must be a number");
    }

    let encryptedMsg = "";
    for (const char of msg) {
      if (/[a-z]/.test(char)) {
        // Handle lowercase
        const index = CaesarCipher.lowercase.indexOf(char);
        const newIndex = (index + shiftFactor) % CaesarCipher.lowercase.length;
        encryptedMsg += CaesarCipher.lowercase[newIndex];
      } else if (/[A-Z]/.test(char)) {
        // Handle uppercase
        const index = CaesarCipher.uppercase.indexOf(char);
        const newIndex = (index + shiftFactor) % CaesarCipher.uppercase.length;
        encryptedMsg += CaesarCipher.uppercase[newIndex];
      } else {
        encryptedMsg += char;
      }
    }
    return encryptedMsg;
  }
}
