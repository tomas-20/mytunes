#include <stdio.h>
#include "song_list.h"
#include "rando.h"

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

void print_oeuvre(struct song_list *library[27], char *artist) {
  printf("songs by %s: ", artist);
  print_songs_by_artist(library[char_to_index(artist[0])], artist);
  printf("\n");
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

int get_library_length(struct song_list *library[27]) {
  int length = 0;
  for (int i = 0; i < 27; i ++) {
    length += get_song_list_length(library[i]);
  }
  return length;
}

void print_library_song_at(struct song_list *library[27], int n) {
  for (int i = 0; i < 27; i ++) {
    int list_length = get_song_list_length(library[i]);
    if (n < list_length) {
      print_song_at(library[i], n);
      i = 27;
    }
    else {
      n -= list_length;
    }
  }
}

void print_random_library_song(struct song_list *library[27]) {
  print_library_song_at(library, rando(get_library_length(library)));
}

void shuffle(struct song_list *library[27], int n) {
  printf("some random songs for you: ");
  printf("{");
  for (int i = 0; i < n; i ++) {
    print_random_library_song(library);
    if (i + 1 < n) {
      printf(", ");
    }
  }
  printf("}\n");
}
