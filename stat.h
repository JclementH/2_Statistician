#ifndef STATISTICS_H
#define STATISTICS_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef bool Boolean;
typedef struct node *nodePtr;

struct node {
	int item;
	nodePtr next;
};
typedef nodePtr Statistician, DataStore;
Statistician head;

float mea = 0;

int selection(int sel, int stat);

Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician s, int x);
void removE(Statistician s, int x);
void displayData(Statistician s);
Boolean isEmpty(Statistician s);

int minimum(Statistician s);
int maximum(Statistician s);
int range(Statistician s, int min, int max);
float mean(Statistician s);
float median(Statistician s, int len);
DataStore mode(Statistician s, int len);
float variance(Statistician s);
float standardDeviation(Statistician s);

void sort(Statistician s);

#endif
