#include <stdio.h>
#include "song.h"

void compare_songs(struct song *a, struct song *b) {
  print_song(a);
  printf(" ");
  print_song(b);
  printf(" ");
  printf("%d\n", songcmp(a, b));
}

void check_artist(struct song *cancion, char *artist) {
  print_song(cancion);
  if (artist_is(cancion, artist)) {
    printf(" is by ");
  }
  else {
    printf(" is not by ");
  }
  printf("%s\n", artist);
}

int main() {
  struct song *dinosaurios = get_song("los dinosaurios", "charly garcia");
  struct song *west = get_song("go west", "village people");
  compare_songs(dinosaurios, west);
  compare_songs(west, dinosaurios);
  check_artist(dinosaurios, "bob dylan");
  check_artist(dinosaurios, "charly garcia");
  free_song(dinosaurios);
  free_song(west);
  return 0;
}
