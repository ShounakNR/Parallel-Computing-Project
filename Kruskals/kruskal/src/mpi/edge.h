#ifndef EDGE
#define EDGE

// Edge type.
typedef struct edgeType {
    uint32_t u;
    uint32_t v;
    uint32_t weight;
} edge;

// Edge comparison.
int compareEdges(const void *a, const void *b) {
    const edge *pa = (const edge *)a;
    const edge *pb = (const edge *)b;
	if (pa->weight > pb->weight)return 1;
	else if (pa->weight < pb->weight) return -1;
	return 0;
}

#endif
