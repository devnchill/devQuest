export const Capitalize = (string: string): string => {
  string = string.trim();
  if (/^[a-zA-Z]/.test(string)) {
    return string.charAt(0).toUpperCase() + string.slice(1);
  }
  throw new Error("Input must start with an alphabetic character.");
};
