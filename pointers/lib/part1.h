#ifndef PART_1_H
#define PART_1_H

typedef struct linked_list
{
  int num;
  struct linked_list* left;
  struct linked_list* right;
} linked_list;

linked_list* init_list(int num);

void add_item(linked_list* head, int num);

void print_list(linked_list* head);

void clean_list(linked_list* head);

int randint(unsigned int min, unsigned int max);

void part1();

void part2();

void part3();

void part4();

void part5();

void part6();

void part7();

void part8();

void part9();

#endif
