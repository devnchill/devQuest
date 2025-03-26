#include <ctype.h>
#include <stdio.h>
#define BUF_LENGHT 50
int main(void) {
  int length = 0;
  char message[BUF_LENGHT];
  char ch;
  printf("Enter message: ");
  for (int i = 0; i < BUF_LENGHT; i++) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    switch (toupper(ch)) {
    case 'A': {
      ch = '4';
      break;
    }
    case 'B': {
      ch = '8';
      break;
    }
    case 'E': {
      ch = '3';
      break;
    }
    case 'I': {
      ch = '1';
      break;
    }
    case ')': {
      ch = '0';
      break;
    }
    case 'S': {
      ch = '5';
      break;
    }
    default:
      ch = ch;
      break;
    }
    message[i] = ch;
    length += 1;
  }

  for (int i = 0; i < length; i++) {
    printf("%c", message[i]);
  }
  printf(" !!!!!!!!!!");
  return 0;
}
