#include <stdio.h>
typedef enum error {
  HTTP_BAD_REQUEST = 400,
  HTTP_UNAUTHORIZED = 401,
  HTTP_NOT_FOUND = 414,
  HTTP_TEAPOT = 418,
  HTTP_INTERNAL_SERVER_ERROR = 500,
} HttpErrorCode;
char *http_to_str(HttpErrorCode code) {
  switch (code) {
  case HTTP_BAD_REQUEST:
    return "400 Bad request";
    break;
  case HTTP_UNAUTHORIZED:
    return "401 unauthorized";
    break;
  case HTTP_NOT_FOUND:
    return "402 not found";
    break;
  case HTTP_TEAPOT:
    return "418 i am teapot";
    break;
  case HTTP_INTERNAL_SERVER_ERROR:
    return "500 internal server error";
    break;
  default:
    return "unknow HTTP status code";
    break;
  }
}
int main(void) {
  printf("%s", http_to_str(419));
  return 0;
}
