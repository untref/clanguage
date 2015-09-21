#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct _Node Node;
typedef struct _Node {
    Node* next;
    void* data;
    unsigned size;

} Node;

void lista_init(Node* this);

const Node* lista_push(Node*this, const void* data, unsigned size);

const Node* lista_at(Node* this, unsigned pos);

#endif // LISTA_H_INCLUDED
