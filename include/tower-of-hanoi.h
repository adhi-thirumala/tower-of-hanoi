#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

#include "stack.h"

typedef enum rod {
  A = 0,
  B = 1,
  C = 2,
} Rod;

typedef struct tower_of_hanoi {
  Stack *rods[3];
  int num_disks;
} TowerOfHanoi;

TowerOfHanoi *tower_of_hanoi_init(int num_disks);

void tower_of_hanoi_free(TowerOfHanoi *hanoi);

bool move_disk(TowerOfHanoi *hanoi, Rod from, Rod to);

void print_tower_of_hanoi(TowerOfHanoi *hanoi);

void print_rod(Stack *rod);

bool can_move_disk(TowerOfHanoi *hanoi, Rod from, Rod to);

#endif
