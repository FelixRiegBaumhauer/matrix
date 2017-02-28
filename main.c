#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  clear_screen(s); 
  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;
  
  struct matrix *edges;

  edges = new_matrix(4, 4);

  printf("This is the identity matrix \n");  
  ident(edges);
  print_matrix(edges);

  printf("Here we see some scalar multiplication, by 2\n");
  scalar_mult(2, edges);  
  print_matrix(edges);
    
  struct matrix *a;
  a = new_matrix(4, 4);
  add_point(a, 0, 0, 0);
  add_point(a, 100, 200, 300);
  add_edge(a, 34, 34, 34, 56, 56, 56);
  printf("this is matrix a: \n");
  print_matrix(a);

  struct matrix *b;
  b = new_matrix(4, 4);
  add_point(b, 10, 10, 10);
  add_point(b, 30, 20, 30);
  add_edge(b, 14, 67, 67, 46, 46, 46);
  printf("this is matrix b: \n");
  print_matrix(b);

  printf("Now lets multiply a x b\n");
  printf("Resulting matrix in b is: \n");

  matrix_mult(a, b);
  print_matrix(b);


  add_point(edges, 125, 25, 0);
  add_point(edges, 125, 225, 0);
  add_edge(edges, 125, 125, 0, 165, 190, 0);
  add_edge(edges, 125, 125, 0, 85, 190, 0);
  add_edge(edges, 125, 175, 0, 143, 210, 0);
  add_edge(edges, 125, 175, 0, 107, 210, 0);
  scalar_mult(2, edges);  
  
  draw_lines(edges, s, c);
  
  display(s);
  save_ppm(s, "matrix.ppm");
  save_extension(s, "matrix.png");

  free_matrix( edges );
} 
