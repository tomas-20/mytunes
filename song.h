struct song;
char *get_title(struct song *);
char *get_artist(struct song *);
struct song *get_song(char *, char *);
void free_song(struct song *);
void print_song(struct song *);
int songcmp(struct song *, struct song *);
int artistcmp(char *, struct song *);
