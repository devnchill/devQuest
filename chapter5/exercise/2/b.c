#include <stdio.h>
int main(void) {
  int i = 2, j = 1;
  printf("%d", !!i + !j);
  return 0;
}
/**********************************************
 * !x retuns false prehaps 0 if no is non zero , !!x means !(flase) => true
 * therefore 1 , so in above code , !!i will mean true => 1
 * so 1 + !j => 1+ flase => 1 + 0 = 1
 * ********************************************/
