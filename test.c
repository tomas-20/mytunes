#include <stdio.h>
#include "song.h"
#include "song_list.h"

int main() {
  struct song *ymca = get_song("ymca", "village people");
  struct song *dinosaurios = get_song("los dinosaurios", "charly garcia");
  struct song *west = get_song("go west", "village people");
  struct song_list *list = NULL;
  list = add_song(list, ymca);
  list = add_song(list, dinosaurios);
  list = add_song(list, west);
  print_song_list(list);
  printf("\n");
  print_songs_by_artist(list, "village people");
  printf("\n");
  free_song_list(list);
  return 0;
}
