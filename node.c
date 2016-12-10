#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void printAll(struct song_node *n){
  while(n){
    printf("%s - %s\n", n->artist, n->name);
    n = n->next;
  }
}
void printNode(struct song_node *n){
  if(!n){
    return;
  }
  printf("%s - %s\n", n->artist, n->name);
}

song_node * insertFront(struct song_node *n, char *a, char *s){
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  new->next = n;
  strcpy(new->artist,a);
  strcpy(new->name,s);
  return new;
}

song_node * insertOrder(struct song_node *n, char *a, char *s){
  struct song_node *node = n;
  if(!n){
    n = insertFront(n,a,s);
    return n;
  }
  if(strcmp(n->artist,a) > 0 || (!strcmp(n->artist,a) && strcmp(n->name,s) > 0)){
    n = insertFront(n,a,s);
    return n;
  }
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new->name,s);
  strcpy(new->artist,a);
  while(node->next && strcmp(n->artist,a) <0 && strcmp(node->next->artist,a) < 0){
    node = node->next;
  }
  if(strcmp(n->artist,a) <= 0){
    while(node->next && strcmp(node->name,s) < 0 && strcmp(node->next->name,s) < 0 && strcmp(node->next->artist,a) <= 0){
      node = node->next;
    }
  }
  if(node){
    new->next = node->next;
    node->next = new;
  }else{
    node->next = new;
  }
  return n;
} 

song_node * findSong(struct song_node *n, char *s){
  struct song_node *node = n;
  while(node && strcmp(node->name,s)){
    node = node->next;
  }
  if(!node){
    return NULL;
  }
  return node;
}

song_node * findArtist(struct song_node *n, char *a){
  struct song_node *node = n;
  while(node && strcmp(node->artist,a)){
    node = node->next;
  }
  if(!node){
    return NULL;
  }
  return node;
}

song_node * randomSong(struct song_node *n){
  if(!n){
    return;
  }
  int i = rand();
  struct song_node *node1 = n;
  struct song_node *node2 = n->next;
  int x = 2;
  while(node2){
    if(!(i % x)){
      node1 = node2;
    }
    node2 = node2->next;
    x++;
  }
  return node1;
}

song_node * removeSong(struct song_node *n, char *a, char *s){
  struct song_node *node = n;
  if(!strcmp(node->name,s) && !strcmp(node->artist,a)){
    struct song_node *node1 = node;
    node = node->next;
    return node1;
  }
  while(node->next && (strcmp(node->next->artist,a) || strcmp(node->next->name,s))){
    node = node->next;
  }
  struct song_node *node1 = node->next;
  if(!node->next){
    return NULL;
  }
  node->next = node->next->next;
  return node1;
}
  
song_node * freeList(struct song_node *n){
  struct song_node *node = n;
  while(node){
    n= n->next;
    printf("freeing: %s - %s\n",node->artist,node->name);
    free(node);
    node = n;
  }
  return n;
}
