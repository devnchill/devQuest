#include <stdio.h>
#include <string.h>

long read_size_in_bytes(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error Opening File");
    return -1;
  }
  if (fseek(file, 0, SEEK_END) != 0) {
    perror("Error seeking to end of file");
    fclose(file);
    return -1;
  }
  long len = ftell(file);
  fclose(file);
  if (len == -1) {
    perror("Error getting file size");
    return -1;
  }
  return len;
}

long count_words(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error Opening file");
    return -1;
  }
  int count = 0;
  int ch;
  while ((ch = fgetc(file)) != EOF) {
    count++;
  }
  fclose(file);
  return count;
}

int main(int argc, char *argv[]) {

  if (argc == 2 && strcmp(argv[1], "--help") == 0) {
    printf("Usage: ccwc <flag> <filename>\n\n");
    printf("Flags:\n");
    printf("  -c    Count the size of the file in bytes.\n");
    printf("  -l    Count the number of lines in the file.\n");
    printf("  -w    Count the number of words in the file.\n");
    printf("  -m    Count the number of characters in the file.\n");
    return 0;
  }

  if (argc == 2) {
    printf("Counting bytes in file: %s\n", argv[2]);
    long file_size = read_size_in_bytes(argv[2]);
    if (file_size != -1) {
      printf("File size: %ld bytes\n", file_size);
    }
    printf("Counting words in file: %s\n", argv[2]);
    int no_of_words = count_words(argv[2]);
    printf("%d words found in file %s", no_of_words, argv[2]);
  }

  if (argc < 3) {
    printf("Usage: ccwc <flag> <filename>\n");
    printf("Use ccwc --help for more info\n");
    return 1;
  }

  if (strcmp(argv[1], "-c") == 0) {
    printf("Counting bytes in file: %s\n", argv[2]);
    long file_size = read_size_in_bytes(argv[2]);
    if (file_size != -1) {
      printf("File size: %ld bytes\n", file_size);
    }
  }

  else if (strcmp(argv[1], "-w") == 0) {
    printf("Counting words in file: %s\n", argv[2]);
    int no_of_words = count_words(argv[2]);
    printf("%d words found in file %s", no_of_words, argv[2]);
  }

  else {
    printf("Invalid flag: %s\n", argv[1]);
    printf("Usage: ccwc <flag> <filename>\n");
    return 1;
  }

  return 0;
}
