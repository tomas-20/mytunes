struct song;
char *get_title(struct song *);
char *get_artist(struct song *);
struct song *get_song(char *, char *);
void free_song(struct song *);
