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
  struct matrix *points;
  struct matrix *a;
  struct matrix *b;

  color c;
  c.red = 0;
  c.green = 0;
  c.blue = 255;

  edges = new_matrix(4, 4);
  print_matrix(edges);
  printf("\n");
  ident(edges);
  print_matrix(edges);
  printf("\n");
  scalar_mult(5, edges);
  print_matrix(edges);

  edges->lastcol = 3;

  points = new_matrix(4, 0);
  add_point(points, 2, 3, 4);
  add_point(points, 5, 6, 8);
  add_point(points, 2, 3, 4);
  add_point(points, 5, 6, 8);
  add_edge(points, 100, 100, 1, 200, 200, 2);
  add_edge(points, 400, 100, 1, 400, 200, 2);
  //printf("\n");
  //print_matrix(points);
  printf("\n");

  printf("Matrix multiplication 1:\n");
  printf("Matrix a:\n");
  print_matrix(edges);
  printf("Matrix b:\n");
  print_matrix(points);
  printf("\n");
  matrix_mult(edges, points);
  printf("Matrix a after multiplying:\n");
  print_matrix(edges);
  printf("Matrix b after multiplying:\n");
  print_matrix(points);

  printf("\n");

  printf("Matrix multiplication 2:\n");
  a = new_matrix(4, 0);
  b = new_matrix(4, 0);
  add_edge(a, 2, 3, 1, 2, 3, 1);
  add_edge(a, 3, 4, 1, 3, 4, 1);
  add_edge(b, 17, 5, 1, 1, 0, 0);
  add_edge(b, 9, 8, 1, 1, 1, 3);

  printf("Matrix a:\n");
  print_matrix(a);
  printf("Matrix b:\n");
  print_matrix(b);
  matrix_mult(a, b);
  printf("\n");
  //printf("Multiplying...\n");
  printf("Matrix b after multiplying:\n");
  print_matrix(b);


  draw_lines(points, s, c);
  display(s);

  free_matrix(edges);
  free_matrix(points);
}
/*
ident
scalar
add edge
mult
mult
test headings, tell what i multiplied by what
*/
