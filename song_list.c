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

void print_song_list_helper(struct song_list *list) {
  print_song(list->cancion);
  if (list->next) {
    printf(", ");
    print_song_list_helper(list->next);
  }
}

void print_song_list(struct song_list *list) {
  printf("{");
  if (list) {
    print_song_list_helper(list);
  }
  printf("}");
}
