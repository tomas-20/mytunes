#include <fcntl.h>
#include <unistd.h>

int rando(int range) {
  unsigned long long rand;
  int file = open("/dev/random", O_RDONLY);
  read(file, &rand, sizeof rand);
  close(file);
  return rand % range;
}
