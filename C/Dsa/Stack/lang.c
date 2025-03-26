#include "lang.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

stack_t *stack_new(size_t capacity) {
  stack_t *s = malloc(sizeof(stack_t));
  if (s == NULL)
    free(s);
  return NULL;
  s->count = 0;
  s->capacity = capacity;
  s->data = malloc(sizeof(stack_t) * capacity);
  if (s->data == NULL) {
    free(s);
    return NULL;
  }
  return s;
}

void *stack_pop(stack_t *stack) {
  if (stack->data == 0)
    return NULL;
  stack->count--;
  return stack->data[stack->count];
}

void stack_push(stack_t *stack, void *obj) {
  if (stack->capacity == stack->count) {
    stack->capacity = 2 * stack->capacity;
    stack->data = realloc(stack->data, sizeof(void *) * stack->capacity);
    if ((stack->data) == NULL) {
      stack->capacity = stack->capacity / 2;
      return;
    }
    stack->data[stack->count] = obj;
    stack->count++;
  }
}

void stack_free(stack_t *stack) {
  if (stack == NULL)
    return;
  if (stack->data != NULL)
    free(stack->data);
  free(stack);
}

void scary_double_push(stack_t *s) {
  stack_push(s, (void *)1337);
  int *new_int = malloc(sizeof(int));
  *new_int = 1024;
  stack_push(s, (void *)new_int);
}

void stack_push_multiple_types(stack_t *s) {
  float *float_pointer = malloc(sizeof(float));
  *float_pointer = 3.14;
  char *char_pointer = "this lang is blazingly slow";
  size_t len = strlen(char_pointer) + 1;
  char *string = malloc(sizeof(char) * len);
  strcpy(string, char_pointer);
  stack_push(s, (void *)float_pointer);
  stack_push(s, (void *)string);
}
