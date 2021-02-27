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
	
	if(ptr->next == NULL) {
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
	minimum(s);
	maximum(s);
	range(s);
	mean(s);
	median(s);
	mode(s);
	variance(s);
	standardDeviation(s);
	//
	printf("\n");
	return;
}

int minimum(Statistician s) {
	int min = INT_MIN;
	nodePtr ptr = s;
	
	ptr = ptr->next;
	while(ptr) {
		if(ptr->item < min) {
			min = ptr->item;
		}
		ptr = ptr->next;
	}
	printf("Minimum\t: %i\n", min);
}

int maximum(Statistician s) {
	
}

int range(Statistician s) {
	
}

float mean(Statistician s) {
	
}

float median(Statistician s) {
	
}

DataStore mode(Statistician s) {
	
}

float variance(Statistician s) {
	
}

float standardDeviation(Statistician s) {
	
}
