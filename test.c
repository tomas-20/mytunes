#include <stdio.h>
#include "song.h"

void compare_songs(struct song *a, struct song *b) {
  print_song(a);
  printf(" ");
  print_song(b);
  printf(" ");
  printf("%d\n", songcmp(a, b));
}

int main() {
  struct song *dinosaurios = get_song("los dinosaurios", "charly garcia");
  struct song *west = get_song("go west", "village people");
  compare_songs(dinosaurios, west);
  compare_songs(west, dinosaurios);
  free_song(dinosaurios);
  free_song(west);
  return 0;
}
