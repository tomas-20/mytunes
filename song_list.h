struct song_list;
struct song_list *get_song_list(struct song *, struct song_list *);
void free_song_list(struct song_list *);
struct song_list *add_song(struct song_list *, struct song *);
void print_songs_by_artist(struct song_list *, char *);
void print_song_list(struct song_list *);
