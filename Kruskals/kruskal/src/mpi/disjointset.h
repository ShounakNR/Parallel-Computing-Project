#ifndef DISJOINT
#define DISJOINT

#include <stdlib.h>

// Disjoint Set (ds) type.
typedef struct dsNodeType {
    struct dsNodeType* parent;
    uint32_t rank;
} dsNode;

// Set that contains all vertices as dsNodes.
dsNode *dsSet;

// MakeSet operation.
inline void dsMakeSet(uint32_t nVerts) {
    // Callocates (init to 0) room for all vertices.
    // parent = NULL and rank = 0.
	dsSet = calloc(nVerts, sizeof(dsNode));
}

// Find operation.
inline dsNode* dsFind(dsNode *n) {
    if (n->parent == NULL) return n;
    n->parent = dsFind(n->parent);
    return n->parent;
}

// Union operation.
// Assuming that n and m belong to different sets.
inline void dsUnion(dsNode* n, dsNode* m) {
    if (n->rank < m->rank) {
        n->parent = m;
    } else if (n->rank > m->rank) {
        m->parent = n;
    } else {
        n->parent = m;
        n->rank += 1;
    }
}

#endif
