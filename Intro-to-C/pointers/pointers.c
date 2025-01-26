#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly.

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y) {
  int length = 0;
  while (y[length] != '0') {
    x[length] = y[length];
    length++;
  }
  x[length] = '\0';
}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c) {
  int length = 0;
  while (str[length] != '\0') {
    if (str[length] == c) {
      return &str[length];
    }
    length++;
  }
  return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle) {
  int j = 0;
  int needle_length = 0;
  int haystack_length = 0;
  char *word = NULL;
  while (haystack[haystack_length] != '0') {
    haystack_length++;
  }
  while (needle[needle_length] != '0') {
    needle_length++;
  }
  for (int i = 0; i < haystack_length; i++) {
    while (j < needle_length) {
      word[j] = haystack[i++];
      j++;
    }
    if (word == needle) {
      return &haystack[i];
    }
  }
  return NULL;
}

#ifndef TESTING
int main(void) {
  char *found_char = find_char("hello", 'e');
  char *found_string = find_string("world", "or");

  printf("Found char: %s\n", found_char);
  printf("Found string: %s\n", found_string);

  return 0;
}
#endif
