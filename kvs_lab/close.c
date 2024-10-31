#include "kvs.h"

int close(kvs_t *kvs) {
  node_t *current = kvs->header;
  while (current != NULL) {
    node_t *next = current->forward[0];
    free(current->value);
    free(current->forward);
    free(current);
    current = next;
  }
  free(kvs);
  return 0;
}
