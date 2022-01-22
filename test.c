#include <stdio.h>
#include "song_list.h"

int main() {
  struct song_list *list = NULL;
  list = add_song(list, "ymca", "village people");
  list = add_song(list, "los dinosaurios", "charly garcia");
  list = add_song(list, "go west", "village people");
  print_song_list(list);
  printf("\n");
  print_songs_by_artist(list, "village people");
  printf("\n");
  free_song_list(list);
  return 0;
}
