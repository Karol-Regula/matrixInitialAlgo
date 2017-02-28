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

  edges = new_matrix(4, 4);
  print_matrix(edges);
  ident(edges);
  print_matrix(edges);
  scalar_mult(5, edges);
  print_matrix(edges);

  edges->lastcol = 3;
  add_point(edges, 2, 3, 4);
  print_matrix(edges);

  points = new_matrix(4, 0);
  add_point(points, 2, 3, 4);
  add_point(points, 5, 6, 8);
  add_point(points, 2, 3, 4);
  add_point(points, 5, 6, 8);
  print_matrix(points);

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
