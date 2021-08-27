#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void get_name(char* buf, size_t n){

  size_t sz;
  sz = fread(buf, 1, n, stdin);
  if (sz != n) {
    fprintf(stderr, "Error reading from stdin\n");
    exit(-1);
  }
  return;

}

void say_hi(char* name){
  printf("Hi %s!\n", name);
  return;
}

int main(){

  uint32_t n;
  size_t sz;
  char buf[128] = { 0 };

  sz = fread(&n, 1, sizeof(uint32_t), stdin);
  printf("Reading %d bytes.\n", n);
  if (sz != sizeof(uint32_t)) {
    fprintf(stderr, "Error reading from stdin\n");
    return -1;
  }
  get_name(buf, n);
  say_hi(buf);
  return 0;
}
