#include "./object.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL)
    return NULL;
  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}
snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL)
    return NULL;
  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}
snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL)
    return NULL;
  int string_length = strlen(value);
  obj->data.v_string = malloc(sizeof(char) * string_length + 1);
  if (obj->data.v_string == NULL) {
    free(obj->data.v_string);
    return NULL;
  }
  strcpy(obj->data.v_string, value);
  obj->kind = STRING;
  return obj;
}
snek_object_t *new_snek_vector3(snek_object_t *x, snek_object_t *y,
                                snek_object_t *z) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL)
    return NULL;
  obj->kind = VECTOR3;
  obj->data.v_vector3.x = x;
  obj->data.v_vector3.y = y;
  obj->data.v_vector3.z = z;
  return obj;
};
snek_object_t *new_snek_array(size_t size) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL)
    return NULL;
  obj->kind = ARRAY;
  snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }
  snek_array_t array = {
      .size = size,
      .elements = elements,
  };
  obj->data.v_array = array;
  return obj;
}
bool snek_array_set(snek_object_t *snek_obj, size_t index,
                    snek_object_t *value) {
  if ((snek_obj == NULL) || value == NULL) {
    return NULL;
  }
  if (snek_obj->kind != ARRAY)
    return false;
  if (index < 0 || index >= snek_obj->data.v_array.size)
    return false;
  snek_obj->data.v_array.elements[index] = value;
  return true;
}
bool snek_array_get(snek_object_t *snek_obj, size_t index) {
  if (snek_obj == NULL || snek_obj->kind != ARRAY) {
    return NULL;
  }
  if (index < 0 || index >= snek_obj->data.v_array.size)
    return NULL;
  return snek_obj->data.v_array.elements[index];
}
int snek_length(snek_object_t *obj) {
  switch (obj->kind) {
  case (INTEGER):
    return 1;
  case (FLOAT):
    return 1;
  case (STRING):
    return strlen(obj->data.v_string);
  case (VECTOR3):
    return 3;
  case (ARRAY):
    return obj->data.v_array.size;
  default:
    return -1;
  }
}
snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
  if (a == NULL || b == NULL)
    return NULL;
  switch (a->kind) {
  case INTEGER:
    switch (b->kind) {
    case INTEGER:
      return new_snek_integer(a->data.v_int + b->data.v_int);
    case FLOAT:
      return new_snek_float(a->data.v_int + b->data.v_float);
    default:
      return NULL;
    }
  case FLOAT:
    switch (b->kind) {
    case INTEGER:
      return new_snek_integer(a->data.v_float + b->data.v_int);
    case FLOAT:
      return new_snek_float(a->data.v_float + b->data.v_float);
    default:
      return NULL;
    }
  case STRING:
    if (b->kind != STRING)
      return NULL;
    const int new_length =
        strlen(a->data.v_string) + strlen(a->data.v_string) + 1;
    char *temp_string = calloc(new_length, sizeof(char));
    strcat(temp_string, a->data.v_string);
    strcat(temp_string, b->data.v_string);
    snek_object_t *new_string = new_snek_string(temp_string);
    free(temp_string);
    return new_string;
  case VECTOR3:
    if (b->kind != VECTOR3)
      return NULL;
    return new_snek_vector3(snek_add(a->data.v_vector3.x, a->data.v_vector3.x),
                            snek_add(b->data.v_vector3.y, b->data.v_vector3.y),
                            snek_add(a->data.v_vector3.z, b->data.v_vector3.z));
  case ARRAY:
    if (b->kind != ARRAY)
      return NULL;
    size_t length = a->data.v_array.size + b->data.v_array.size;
    snek_object_t *obj = new_snek_array(length);
    for (size_t i = 0; i < a->data.v_array.size; i++) {
      snek_array_set(obj, i, snek_array_get(a, i));
    }
    for (size_t i = 0; i < b->data.v_array.size; i++) {
      snek_array_set(obj, i + a->data.v_array.size, snek_array_get(b, i));
    }
    return obj;
  default:
    return NULL;
  }
}
