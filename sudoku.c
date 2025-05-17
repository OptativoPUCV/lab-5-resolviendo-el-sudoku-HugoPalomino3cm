#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int i, j;

    for(i = 0; i < 9; i++){
        int seen[10] = {0};
        for(j = 0; j < 9; j++){
            int num = n->sudo[i][j];
            if(num == 0) continue;
            if(seen[num]) return 0; 
            seen[num] = 1;
        }
    }

    for(j = 0; j < 9; j++){
        int seen[10] = {0};
        for(i = 0; i < 9; i++){
            int num = n->sudo[i][j];
            if(num == 0) continue;
            if(seen[num]) return 0;
            seen[num] = 1;
        }
    }

    for(int k = 0; k < 9; k++){
        int seen[10] = {0};
        for(int p = 0; p < 9; p++){
            int i = 3 * (k / 3) + (p / 3);
            int j = 3 * (k % 3) + (p % 3);
            int num = n->sudo[i][j];
            if(num == 0) continue;
            if(seen[num]) return 0;
            seen[num] = 1;
        }
    }

    return 1; 
}

List* get_adj_nodes(Node* n){
    List* list = createList();
    int empty_i = -1, empty_j = -1;

    for(int i = 0; i < 9 && empty_i == -1; i++){
        for(int j = 0; j < 9; j++){
            if(n->sudo[i][j] == 0){
                empty_i = i;
                empty_j = j;
                break;
            }
        }
    }

    if(empty_i == -1) return list; 

    for(int k = 1; k <= 9; k++){
        Node* adj = copy(n);
        adj->sudo[empty_i][empty_j] = k;

        if(is_valid(adj)){
            pushBack(list, adj); 
        } else {
            free(adj); 
        }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}




Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/