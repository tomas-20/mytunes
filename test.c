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
  add_to_library(library, "who am I", "24601");
  add_to_library(library, "the times they are a changin", "bob dylan");
  print_library(library);
  print_oeuvre(library, "bill wurtz");
  print_oeuvre(library, "bob dylan");
  print_oeuvre(library, "village people");
  print_by_letter(library, 'b');
  shuffle(library, 3);
  find_in_library(library, "happy birthday", "somebody");
  find_in_library(library, "la de da", "bill wurtz");
  clear_library(library);
  return 0;
}
