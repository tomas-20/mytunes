#include <stdlib.h>
#include <stdio.h>
#include "song.h"

struct song_list {
  struct song *cancion;
  struct song_list *next;
};

struct song_list *get_song_list(struct song *cancion, struct song_list *next) {
  struct song_list *list = malloc(sizeof (struct song_list));
  list->cancion = cancion;
  list->next = next;
  return list;
}

void free_song_list(struct song_list *list) {
  if (list) {
    free_song(list->cancion);
    free_song_list(list->next);
  }
  free(list);
}

struct song_list *add_song(struct song_list *list, struct song *cancion) {
  if (!list || songcmp(cancion, list->cancion) <= 0) {
    return get_song_list(cancion, list);
  }
  list->next = add_song(list->next, cancion);
  return list;
}

struct song_list *get_songs_by_artist(struct song_list *list, char *artist) {
  if (!(artist && list)) {
    return list;
  }
  int difference = artistcmp(artist, list->cancion);
  if (difference == 0) {
    return list;
  }
  if (difference > 0) {
    return get_songs_by_artist(list->next, artist);
  }
  return NULL;
}

void print_songs_by_artist_helper(struct song_list *list, char *artist) {
  print_song(list->cancion);
  if (list->next && !(artist && artistcmp(artist, list->next->cancion))) {
    printf(", ");
    print_songs_by_artist_helper(list->next, artist);
  }
}

void print_songs_by_artist(struct song_list *list, char *artist) {
  list = get_songs_by_artist(list, artist);
  printf("{");
  if (list) {
    print_songs_by_artist_helper(list, artist);
  }
  printf("}");
}

void print_song_list(struct song_list *list) {
  print_songs_by_artist(list, NULL);
}
