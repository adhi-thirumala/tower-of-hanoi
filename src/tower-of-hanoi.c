#include "tower-of-hanoi.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

TowerOfHanoi *tower_of_hanoi_init(int num_disks) {
  TowerOfHanoi *hanoi = malloc(sizeof(TowerOfHanoi));
  hanoi->num_disks = num_disks;
  for (int i = 0; i < 3; ++i) {
    hanoi->rods[i] = create_stack(num_disks);
  }
  for (int i = num_disks; i > 0; --i) {
    push(hanoi->rods[0], i);
  }
  return hanoi;
}

void tower_of_hanoi_free(TowerOfHanoi *hanoi) {
  for (int i = 0; i < 3; ++i) {
    free_stack(hanoi->rods[i]);
  }
  free(hanoi);
}

bool move_disk(TowerOfHanoi *hanoi, Rod from, Rod to) {
  if (!can_move_disk(hanoi, from, to)) {
    return false;
  }
  push(hanoi->rods[to], pop(hanoi->rods[from]));
  return true;
}

void print_tower_of_hanoi(TowerOfHanoi *hanoi) {
  for (int i = 0; i < 3; ++i) {
    printf("Rod %c: ", i);
    print_rod(hanoi->rods[i]);
  }
}

void print_rod(Stack *rod) {
  for (int i = 0; i < size(rod); ++i) {
    printf("%d ", rod->data[i]);
  }
  printf("\n");
}

bool can_move_disk(TowerOfHanoi *hanoi, Rod from, Rod to) {
  return is_empty(hanoi->rods[from]) && !is_full(hanoi->rods[to]);
}
