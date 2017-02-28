#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  print_matrix(edges);

  
  ident(edges);

  print_matrix(edges);

  scalar_mult(2, edges);
  print_matrix(edges);

  struct matrix *a;
  a = new_matrix(4, 2);
  printf("%d\n", a->lastcol);

  add_point(a, 3, 4, 5);
  add_point(a, 1, 2, 3);
  add_point(a, 37, 47, 750);
  print_matrix(a);
  add_edge(a, 34, 34, 34, 56, 56, 56);
  print_matrix(a);
  printf("%d\n", a->lastcol);
  
  /*
  struct matrix *a;
  a = new_matrix(4, 4);

  edges->m[0][0] = 1;
  edges->m[0][3] = 10;
  edges->m[1][1] = 1;
  edges->m[1][3] = 200;
  edges->m[2][2] = 1;
  edges->m[3][3] = 1;

  a->m[0][1] = -1;
  a->m[1][0] = 1;
  a->m[2][2] = 1;
  a->m[3][3] = 1;

  print_matrix(edges);
  print_matrix(a);
  
  matrix_mult(a, edges);
  print_matrix(edges);
  */
  free_matrix( edges );
} 
