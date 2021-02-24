#include <stdio.h>
#include <stdlib.h>


int dim =0;
int n = 2;
struct node{
  /* malloc size of dimension */

	int v;
	float weight;
	struct node*next;
};
;
struct node* createNode(int, float);
struct edge{
  int row;
  int col;
  int weight;
  struct edge*next;
};
struct edge* createEdge(int,int, int);
struct edge* createEdge(int r, int c, int w){
  struct edge* newEdge = malloc(sizeof(struct edge));
  newEdge->row = r;
  newEdge->col = c;
  newEdge->weight = w;
  newEdge->next = NULL;
  return newEdge;
}
struct node* createNode(int a,  float w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->v= a;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}
void printNode(struct node* n){
  printf("%s", "(");
  printf("%d",n->v);
  printf("%s", ",");
  printf("%f",n->weight);
  printf("%s", ")");
}

/*****************
    UNION FIND
******************/

struct Set {
  int key;
  int rank;
  struct Set* parent;
};

struct Set* makeSet(int x) {
  struct Set* newSet = malloc(sizeof(struct Set));
  newSet->rank = 0;
  newSet->parent = newSet;
  return newSet;
};

struct Set* findSet(struct Set* set) {
  if (set != set->parent){
    set->parent = findSet(set->parent);
  }
  return set->parent;
}

struct Set* linkSet(struct Set* x, struct Set* y){
  if (x->rank > y->rank){
    y->parent = x;
    return x;
  }
  if (x->rank == y->rank){
    y->rank = y->rank + 1;
    x->parent = y;
  }
  else{
    x->parent = y;
  }
  return y;
}

struct Set* unionSet(struct Set* x, struct Set* y){
  return linkSet(findSet(x), findSet(y));
}

/*****************
    Kruskals
******************/
int kruskals(int V, struct edge* E){
  int mstWeight = 0;
  struct Set* setArray[V];
  /* SORT E BY WEIGHT */
  for (int i = 0; i < V; i++){
    setArray[i] = makeSet(i);
  }
  for (int e = 0; e < sizeof(E); e++){
    int u = E[e].row;
    int v = E[e].col;
    if (findSet(setArray[u]) != findSet(setArray[v])){
      mstWeight = mstWeight + E[e].weight;
      unionSet(setArray[u], setArray[v]);
    }
  }
  return mstWeight;
}

int main() {
 struct edge edges [n*n]; /* this should be n choose 2, but for now it is n^2 */
 struct node adj [n][n];
 int count = 0;
 for(int i = 0; i< n; i ++){
  for (int j = 0; j<n; j ++){
    if (i == j){
    adj[i][j].v = i; /* there are no self loops */
    adj[i][j].weight = 0.0;

  }
  else if (i< j){
    float w1 = (rand() % 100)/ 100.0f;
    adj[i][j].v=j;
    adj[i][j].weight = w1;
    edges[count].col = i;
    edges[count].row =j;
    edges[count].weight =w1;
    count++;


   /* will be to tell which edge is with  what, since i corresponds to the in vertex and j is the out vertex */

  }
  else{
    adj[i][j].v = j;
    adj[i][j].weight = 0.0;

  }
  }}
  for (int i = 0; i< n; i++){
    printf("%s\n", " ");
    for(int j =0 ; j<n; j ++){
      printNode(&adj[i][j]);
    }
  }
 }




