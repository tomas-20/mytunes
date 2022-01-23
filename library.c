#include <stdio.h>
#include "song_list.h"

void fill_library(struct song_list *library[27]) {
  for (int i = 0; i < 27; i ++) {
    library[i] = NULL;
  }
}

void clear_library(struct song_list *library[27]) {
  for (int i = 0; i < 27; i ++) {
    if (library[i]) {
      free_song_list(library[i]);
      library[i] = NULL;
    }
  }
}

int is_letter(char c) {
  return 'a' <= c && c <= 'z';
}

int char_to_index(char c) {
  if (is_letter(c)) {
    return c - 'a' + 1;
  }
  return 0;
}

void add_to_library(struct song_list *library[27], char *title, char *artist) {
  int index = char_to_index(artist[0]);
  library[index] = add_song(library[index], title, artist);
}

void remove_from_library(struct song_list *library[27], char *title, char *artist) {
  int index = char_to_index(artist[0]);
  library[index] = remove_song(library[index], title, artist);
}

void print_songs_by_letter(struct song_list *library[27], char c) {
  int index = char_to_index(c);
  if (library[index]) {
    if (is_letter(c)) {
      printf("%c: ", c);
    }
    else {
      printf("other: ");
    }
    print_song_list(library[index]);
    printf("\n");
  }
}

void print_library(struct song_list *library[27]) {
  for (char c = '`'; c <= 'z'; c ++) {
    print_songs_by_letter(library, c);
  }
}
