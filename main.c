#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

void main(){
  srand(time(NULL));
  addSong("artist","song1");
  addSong("artist","song2");
  addSong("artist2","song3");
  addSong("singer","lalala");
  addSong("singer","hahaha");
  addSong("group","hello");
  addSong("group","hi");
  printf("\nTesting printLib:\n");
  printLib();
  printf("\nTesting printLetter:\nprinting a\n");
  printLetter('a');
  printf("\nTesting printArtist:\nprinting singer\n");
  printArtist("singer");
  printf("\nTesting searchName:\nsearching for song1\n");
  printNode(searchSong("song1"));
  printf("searching for song4\n");
  printNode(searchSong("song4"));
  printf("\nTesting searchArtist:\nsearching for artist2\n");
  printNode(searchArtist("artist2"));
  printf("searching for band\n");
  printNode(searchArtist("band"));  
  printf("\nTesting deleteSong:\nremoving artist - song2\n");
  deleteSong("artist","song2");
  printLib();
  printf("\nTesting shuffle:\n");
  shuffle();
  printf("\nTesting deleteAll:\n");
  deleteAll();
  printLib();
}
