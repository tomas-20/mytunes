#include <stdio.h>
#include "library.h"

int main() {
  struct song_list *library[27];
  fill_library(library);
  add_to_library(library, "ymca", "village people");
  add_to_library(library, "los dinosaurios", "charly garcia");
  add_to_library(library, "i'm a princess", "bill wurtz");
  add_to_library(library, "go west", "village people");
  add_to_library(library, "la de da", "bill wurtz");
  add_to_library(library, "just did a bad thing", "bill wurtz");
  remove_from_library(library, "nothing", "nobody");
  remove_from_library(library, "go west", "village people");
  print_library(library);
  clear_library(library);
  return 0;
}
