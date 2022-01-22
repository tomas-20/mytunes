#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct song {
  char *title;
  char *artist;
};

char *get_title(struct song *cancion) {
  return cancion->title;
}

char *get_artist(struct song *cancion) {
  return cancion->artist;
}

char *get_string_copy(char *string) {
  char *copy = malloc(sizeof (char[strlen(string) + 1]));
  strcpy(copy, string);
  return copy;
}

struct song *get_song(char *title, char *artist) {
  struct song *cancion = malloc(sizeof (struct song));
  cancion->title = get_string_copy(title);
  cancion->artist = get_string_copy(artist);
  return cancion;
}

void free_song(struct song *cancion) {
  free(cancion->title);
  free(cancion->artist);
  free(cancion);
}

void print_song(struct song *cancion) {
  printf("(\"%s\" by %s)", cancion->title, cancion->artist);
}

int songcmp(struct song *a, struct song *b) {
  int difference = strcmp(a->artist, b->artist);
  if (difference) {
    return difference;
  }
  return strcmp(a->title, b->title);
}
