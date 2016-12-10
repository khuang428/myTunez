typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node * next;
} song_node;

void printAll(struct song_node *);

void printNode(struct song_node *);

song_node * insertFront(struct song_node *, char *, char *);

song_node * insertOrder(struct song_node *, char *, char *);

song_node * findSong(struct song_node *, char *);

song_node * findArtist(struct song_node *, char *);

song_node * randomSong(struct song_node *);

song_node * removeSong(struct song_node *, char *, char *);

song_node * freeList(struct song_node *);
