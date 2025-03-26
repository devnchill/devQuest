export function generateArrayWithRandomNumber(
  upperLimit: number,
  length: number,
): Array<number> {
  if (!upperLimit || upperLimit <= 0 || !length || length <= 0)
    throw new Error("Invalid range");
  let i = 0;
  let arr = [];
  while (i <= length) {
    let randomNumber = Math.random() * upperLimit;
    arr.push(randomNumber);
    i++;
  }
  return arr;
}
