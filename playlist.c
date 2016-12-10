#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

struct song_node *playlist[26];

int indexify(char c){
  return c - 97;
}

void addSong(char *a, char *s){  
  int i = indexify(a[0]);
  playlist[i] = insertOrder(playlist[i],a,s);
}

song_node * searchSong(char *s){
  int i = 0;
  struct song_node *node = NULL;
  while(!node && i < 26){
    node = findSong(playlist[i],s);
    i++;
  }
  if(!node){
    printf("not found\n");
  }
  return node;
}

song_node * searchArtist(char *a){
  int i = indexify(a[0]);
  struct song_node *node = NULL;
  node = findArtist(playlist[i],a);
  if(!node){
    printf("not found\n");
  }
  return node;
}

void printLetter(char c){
  printAll(playlist[indexify(c)]);
}

void printArtist(char *a){
  struct song_node *node = searchArtist(a);
  while(!strcmp(node->artist,a) && node){
    printNode(node);
    if(node->next){
      node = node->next;
    }else{
      return;
    }
  }
}

void printLib(){
  int i = 0;
  while(i < 26){
  printAll(playlist[i]);
    i++;
  }
}
void shuffle(){
  int i = 3;
  int randc;
  struct song_node * node;
  while(i){
    randc = rand() % 26;
    while(!playlist[randc]){
      randc = rand() % 26;
    }
    node = randomSong(playlist[randc]);
    printNode(node);
    i--;
  }
}

void deleteSong(char *a, char *s){
  int i = indexify(a[0]);
  removeSong(playlist[i],a,s);
}

void deleteAll(){
  int i = 0;
  while(i < 26){
    playlist[i] = freeList(playlist[i]);
    i++;
  }
}
