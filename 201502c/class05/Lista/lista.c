#include <string.h>
#include <stdlib.h>

#include "lista.h"

void lista_init(Node* this) {
  memset(this, 0, sizeof(Node));
}

const Node* lista_push(Node* this, const void* data, unsigned size) {
  void* newData = malloc(size);
  Node* nodeToBeUpdated = this;

  // Busco el proximo node vacio
  while ( nodeToBeUpdated->next ) {
    nodeToBeUpdated = nodeToBeUpdated->next;
  };

  nodeToBeUpdated->data = newData;
  nodeToBeUpdated->size = size;
  memcpy(nodeToBeUpdated->data, data, size);

  nodeToBeUpdated->next = malloc(sizeof(Node));
  memset(nodeToBeUpdated->next, 0, sizeof(Node));

  return nodeToBeUpdated;
}

const Node* lista_at(Node* this, unsigned pos) {
  Node* node = this;
  pos += 1;
  while( --pos && node ) {
     node = node->next;
  };

  return node;


}
