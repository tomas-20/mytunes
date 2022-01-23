#include <stdio.h>
#include "library.h"

int main() {
  struct song_list *library[27];
  fill_library(library);
  add_song_to_library(library, "ymca", "village people");
  add_song_to_library(library, "los dinosaurios", "charly garcia");
  add_song_to_library(library, "i'm a princess", "bill wurtz");
  add_song_to_library(library, "go west", "village people");
  add_song_to_library(library, "la de da", "bill wurtz");
  add_song_to_library(library, "just did a bad thing", "bill wurtz");
  print_library(library);
  clear_library(library);
  return 0;
}
