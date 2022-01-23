struct song_list;
void fill_library(struct song_list *[27]);
void clear_library(struct song_list *[27]);
void print_by_letter(struct song_list *[27], char);
void print_library(struct song_list *[27]);
void add_to_library(struct song_list *[27], char *, char *);
void remove_from_library(struct song_list *[27], char *, char *);
void print_oeuvre(struct song_list *[27], char *);
void shuffle(struct song_list *[27], int n);
