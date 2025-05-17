#include <stdio.h>
#include <stdlib.h>

// Structure to represent a disjoint set
typedef struct {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

// Function to create a disjoint set
DisjointSet* createSet(int size) {
	int i;
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    ds->size = size;
    ds->parent = (int *)malloc(size * sizeof(int));
    ds->rank = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        ds->parent[i] = i; // Each element is its own parent
        ds->rank[i] = 0;    // Initial rank is 0
    }
    return ds;
}

// Function to find the representative of the set containing x with path compression
int findSet(DisjointSet *ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = findSet(ds, ds->parent[x]); // Path compression
    }
    return ds->parent[x];
}

// Function to unite two sets containing x and y
void unionSets(DisjointSet *ds, int x, int y) {
    int rootX = findSet(ds, x);
    int rootY = findSet(ds, y);

    if (rootX != rootY) {
        // Union by rank
        if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Function to free the disjoint set
void freeSet(DisjointSet *ds) {
    free(ds->parent);
    free(ds->rank);
    free(ds);
}

// Main function to demonstrate the disjoint set operations
int main() {
    int size = 10; // Example size
    DisjointSet *ds = createSet(size);

    // Example operations
    unionSets(ds, 1, 2);
    unionSets(ds, 2, 3);
    unionSets(ds, 4, 5);
    unionSets(ds, 5, 6);
    unionSets(ds, 1, 5);

    // Find representatives
    printf("Representative of 1: %d\n", findSet(ds, 1));
    printf("Representative of 2: %d\n", findSet(ds, 2));
    printf("Representative of 3: %d\n", findSet(ds, 3));
    printf("Representative of 4: %d\n", findSet(ds, 4));
    printf("Representative of 5: %d\n", findSet(ds, 5));
    printf("Representative of 6: %d\n", findSet(ds, 6));

    // Free the disjoint set
    freeSet(ds);
    return 0;
}

