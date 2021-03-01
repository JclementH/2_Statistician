#include "stat.h"

int main(int stat) {
	int sel;
	//Prompt
	printf("[1] New Statistician\n");
	printf("[2] Destroy Statistician\n");
	printf("[3] Add Data\n");
	printf("[4] Delete Data\n");
	printf("[5] Display Statistics\n");
	printf("[6] QUIT\n");
	
	printf("\nSelect: ");
	if(scanf("%i", &sel) != 1) {
		printf("Inputted non-integer!");
		return 0;
	} else if(sel < 1 || sel > 6) {
		printf("Out of range. Please try again\n\n");
		sel = 0;
	}
	selection(sel, stat);
	//
	return 0;
}

int selection(int sel, int stat) {
	int x;
	switch(sel) {
		case 0	:	return main(stat);
					break;
		case 1	:	if(stat == 1) {
						head = newStatistician();
						printf("\n");
						stat++;
					} else {
						int st;
						printf("\nYou have already created a statistician!\nWould you like to delete the current statistician and start a new one instead?\n\n");
						printf("[1] Yes\n");
						printf("[2] No\n");
						//
						printf("\nSelect: ");
						if(scanf("%i", &st) != 1) {
							printf("Inputted non-integer!");
							return 0;
						} else if(st < 1 || st > 2) {
							printf("Out of range. Please try again\n\n");
							sel = 0;
						} else if(st == 1) {
							destroyStatistician(&head);
							head = newStatistician();
							printf("\n");
						}
					}
					break;
		case 2	:	if(stat == 2) {
						destroyStatistician(&head);
						printf("\n");
						stat--;
					} else {
						int st;
						printf("\nNo statistician created! Would you like to make one instead?\n\n");
						printf("[1] Yes\n");
						printf("[2] No\n");
						//
						printf("\nSelect: ");
						if(scanf("%i", &st) != 1) {
							printf("Inputted non-integer!");
							return 0;
						} else if(st < 1 || st > 2) {
							printf("Out of range. Please try again\n\n");
							sel = 0;
							return main(stat);
						} else if(st == 1) {
							head = newStatistician();
							stat++;
							printf("\n");
						}
					}
					break;
		case 3	:	if(stat == 1){
						int st;
						printf("\nNo statistician created! Would you like to make one instead?\n\n");
						printf("[1] Yes\n");
						printf("[2] No\n");
						//
						printf("\nSelect: ");
						if(scanf("%i", &st) != 1) {
							printf("Inputted non-integer!");
							return 0;
						} else if(st < 1 || st > 2) {
							printf("Out of range. Please try again\n\n");
							sel = 0;
							return main(stat);
						} else if(st == 1) {
							head = newStatistician();
							stat++;
						}
					}
					//Otherwise
					printf("\nEnter data: ");
					if(scanf("%i", &x) != 1) {
						printf("Inputted non-integer!");
						return 0;
					}
					add(head, x);
					displayData(head);
					printf("\n");
					break;
		case 4	:	if(stat == 1) {
						int st;
						printf("\nNo statistician has been created and thus cannot delete any data!\nWould you like to make one and add data instead?\n\n");
						printf("[1] Yes\n");
						printf("[2] No\n");
						//
						printf("\nSelect: ");
						if(scanf("%i", &st) != 1) {
							printf("Inputted non-integer!");
							return 0;
						} else if(st < 1 || st > 2) {
							printf("Out of range. Please try again\n\n");
							sel = 0;
							return main(stat);
						} else if(st == 1) {
							head = newStatistician();
							printf("\nEnter data: ");
							if(scanf("%i", &x) != 1) {
								printf("Inputted non-integer!");
								return 0;
							}
							add(head, x);
							stat++;
							printf("\n");
							return main(stat);
						}
					}
					//Otherwise
					printf("\nEnter data: ");
					if(scanf("%i", &x) != 1) {
						printf("Inputted non-integer!");
						return 0;
					}
					removE(head, x);
					printf("\n");
					break;
		case 5	:	if(stat == 1) {
						printf("\nNo statistician created. Nothing to be displayed\n\n");
						return main(stat);
					}
					//Otherwise
					displayData(head);
					break;
		case 6	:	return 0;
					break;
	}
	//
	return main(stat);
}

Statistician newStatistician() {
	head = malloc(sizeof(struct node));
	head->next = NULL;
	//
	printf("\nCreate new statistician done!\n");
	return head;
}

void destroyStatistician(Statistician *s) {
	printf("\nDestroy current statistician done!\n");
}

void add(Statistician s, int x) {
	nodePtr ptr, inn;
	inn = (struct node *)malloc(sizeof(struct node));
	inn->item = x;
	inn->next = NULL;
	ptr = s;
	
	if(s == NULL) {
		s = inn;
	}
	
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = inn;
}

void removE(Statistician s, int x) {
	
}

void displayData(Statistician s) {
	int min, max, len;
	nodePtr ptr = s;
	//
	if(s == NULL) {
		printf("List is empty\n");
		return;
	}
	//Otherwise
	ptr = ptr->next;
	printf("STATISTICIAN DATA: ");
	while(ptr != NULL) {
		printf("%i ", ptr->item);
		ptr = ptr->next;
	}
	//
	min = minimum(s);
	max = maximum(s);
	range(s, min, max);
	len = mean(s);
	printf("\nLengthd\t: %i", len);
	median(s, len);
	mode(s);
	variance(s);
	standardDeviation(s);
	//
	printf("\n");
	return;
}

int minimum(Statistician s) {
	int min = s->item;
	nodePtr ptr = s;
	
	while(ptr != NULL) {
		if(min > ptr->item) {
			min = ptr->item;
		}
		ptr = ptr->next;
	}
	printf("\nMinimum\t: %i", min);
	//
	return min;
}

int maximum(Statistician s) {
	int max = s->next->item;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	while(ptr != NULL) {
		if(max < ptr->item) {
			max = ptr->item;
		}
		ptr = ptr->next;
	}
	printf("\nMaximum\t: %i", max);
	//
	return max;
}

int range(Statistician s, int min, int max) {
	int ran = 0;
	ran = max - min;
	
	printf("\nRange\t: %i", ran);
}

float mean(Statistician s) {
	float sum = 0, mea = 0, n = 0;
	int N = 0;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	while(ptr != NULL) {
		sum = sum + ptr->item;
		ptr = ptr->next;
		n++;
	}
	mea = sum / n;
	printf("\nMean\t: %f", mea);
	//
	N = n;
	printf("\nLengthr\t: %i", N);
	return N;
}

float median(Statistician s, int len) {
	int hln = 0;
	float med = 0;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	printf("\nLengthm\t: %i", len);
	
	hln = len / 2;
	if((hln % 2) == 0) {
		printf("\t\t\t2\tHln: %i", hln);
		int pln = hln - 1;
		float pmd = 0;
		
		for(int i = 0; i <= hln; i++) {
			med = ptr->item;
			if(i == pln) {
				pmd = ptr->item;
			}
			ptr = ptr->next;
		}
		med = (pmd + med) / 2;
		
		printf("\nMedian2\t: %f", med);
		//
		return -1;
	}
	
	printf("\t\t\t2\tHln: %i", hln);
	for(int i = 0; i <= hln; i++) {
		med = ptr->item;
		ptr = ptr->next;
	}
	printf("\nMedian1\t: %f", med);
}

DataStore mode(Statistician s) {
	
}

float variance(Statistician s) {
	
}

float standardDeviation(Statistician s) {
	
}
