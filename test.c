#include <stdio.h>
#include "song.h"

int main() {
  struct song *dinosaurios = get_song("los dinosaurios", "charly garcia");
  printf("here we have the song %s by %s\n", get_title(dinosaurios), get_artist(dinosaurios));
  free_song(dinosaurios);
  return 0;
}
