#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] = {
    "             +         +----     +----     +----     +----     +----     "
    "+----     +----  ",
    "             |         |         |   O     |   O     |   O     |   O     "
    "|   O     |   O  ",
    "             |         |         |         |   +     | --+     | --+--   "
    "| --+--   | --+--",
    "             |         |         |         |   |     |   |     |   |     "
    "|   |     |   |  ",
    "             |         |         |         |         |         |         "
    "|  /      |  / \\ ",
    "             |         |         |         |         |         |         "
    "|         |      ",
    "/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
    "/*****\\   /*****\\   /*****\\   "};

int main(int argc, char *argv[]) {
  /* Your code here */
  printf("hello world");
  return 0;
}
