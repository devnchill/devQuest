export const reverseString = (str: string): string => {
  return str === "" ? "" : reverseString(str.substring(1)) + str.charAt(0);
};
