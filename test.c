#include <stdio.h>
#include "song_list.h"

int main() {
  struct song_list *list = NULL;
  list = add_song(list, "ymca", "village people");
  list = add_song(list, "los dinosaurios", "charly garcia");
  list = add_song(list, "i'm a princess", "bill wurtz");
  list = add_song(list, "go west", "village people");
  list = add_song(list, "la de da", "bill wurtz");
  list = add_song(list, "just did a bad thing", "bill wurtz");
  print_song_list(list);
  printf("\n");
  printf("songs by village people: ");
  print_songs_by_artist(list, "village people");
  printf("\n");
  printf("songs by bill wurtz: ");
  print_songs_by_artist(list, "bill wurtz");
  printf("\n");
  printf("random song: ");
  print_random_song(list);
  printf("\n");
  free_song_list(list);
  return 0;
}
