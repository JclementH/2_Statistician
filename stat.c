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
					displayData(head);
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
	nodePtr tem = s, prn;
	if(tem != NULL && tem->item == x) {
		s = tem->next;
		free(tem);
		return;
	}
	
	while(tem != NULL && tem->item != x) {
		prn = tem;
		tem = tem->next;
	}
	if(tem == NULL) {
		return;
	}
	
	prn->next = tem->next;
	free(tem);
}

void displayData(Statistician s) {
	int min, max, len;
	nodePtr ptr = s;
	//
	if(s->next == NULL) {
		printf("STATISTICIAN DATA : NO DATA!\n");
		return;
	}
	//Otherwise
	ptr = ptr->next;
	printf("STATISTICIAN DATA : ");
	while(ptr != NULL) {
		printf("%i ", ptr->item);
		ptr = ptr->next;
	}
	//
	sort(s);
	min = minimum(s);
	max = maximum(s);
	range(s, min, max);
	len = mean(s);
	median(s, len);
	mode(s, len);
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
	printf("\nMinimum\t\t  : %i", min);
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
	printf("\nMaximum\t\t  : %i", max);
	//
	return max;
}

int range(Statistician s, int min, int max) {
	int ran = 0;
	ran = max - min;
	
	printf("\nRange\t\t  : %i", ran);
}

float mean(Statistician s) {
	float sum = 0, n = 0;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	while(ptr != NULL) {
		sum = sum + ptr->item;
		ptr = ptr->next;
		n++;
	}
	mea = sum / n;
	printf("\nMean\t\t  : %f", mea);
	//
	return n;
}

float median(Statistician s, int len) {
	nodePtr fptr = (nodePtr)malloc(sizeof(struct node));
	nodePtr sptr = (nodePtr)malloc(sizeof(struct node));
	
	fptr = s->next;
	sptr = s->next;
	
	float med, hmd;
	
	if(len % 2 == 0) {
		while(fptr != NULL && fptr->next != NULL) {
			fptr = fptr->next->next;
			hmd = sptr->item;
			sptr = sptr->next;
		}
		med = (sptr->item + hmd) / 2;
	} else {
		while(fptr != NULL && fptr->next != NULL) {
			fptr = fptr->next->next;
			sptr = sptr->next;
		}
		med = sptr->item;
	}
	
	printf("\nMedian\t\t  : %f", med);
}

DataStore mode(Statistician s, int len) {
	nodePtr fPtr = (nodePtr)malloc(sizeof(struct node));
	nodePtr sPtr = (nodePtr)malloc(sizeof(struct node));
	
	sPtr = s->next;
	
	int i, j, k=0, c=1, b[20];
	float mod, max=0;
	
	for (fPtr = s->next; fPtr->next != NULL; fPtr = fPtr->next)
    {
        mod = 0;
        for (sPtr = fPtr->next; sPtr != NULL; sPtr = sPtr->next)
        {
            if (fPtr->item == sPtr->item) {
                mod++;
            }
        }
        if ((mod > max) && (mod != 0)) {
        	k=0;
            max = mod;
            b[k] = fPtr->item;
            k++;
        }
        else if (mod == max) {
            b[k] = fPtr->item;
            k++;
        }
    }
    for (fPtr = s->next, i = 0; fPtr != NULL || i < len; fPtr = fPtr->next, i++)
    {
        if (fPtr->item == b[i]) 
            c++;
        }
        if (c == len)
            printf("\nMode\t\t  : There is no mode");
        else
        {
            printf("\nMode\t\t  : ");
            for (i = 0; i < k; i++)
                printf("%d ",b[i]);
        }
}

float variance(Statistician s) {
	float sum = 0, n = 0, var = 0;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	while(ptr != NULL) {
		sum = sum + pow(ptr->item - mea, 2);
		ptr = ptr->next;
		n++;
	}
	var = sum / n;
	printf("\nVariance\t  : %f", var);
}

float standardDeviation(Statistician s) {
	float sum = 0, n = 0, std = 0;
	nodePtr ptr = s;
	ptr = ptr->next;
	
	while(ptr != NULL) {
		sum = sum + pow(ptr->item - mea, 2);
		ptr = ptr->next;
		n++;
	}
	std = sqrt(sum / n);
	printf("\nStandard Deviation: %f", std);
}

void sort(Statistician s) {
    nodePtr nex = (nodePtr)malloc(sizeof(struct node));
    nodePtr current = (nodePtr)malloc(sizeof(struct node));
    int swapped, swap;

    do{
        swapped = 0;

        for (current = s->next; current->next != NULL;  current = current->next) {
       
            nex = current->next;
      
            if (current->item > nex->item) {
                swap  = nex->item;
                nex->item  = current->item;
                current->item  = swap;
                swapped = 1;
            }
        }
    }while(swapped == 1);
}
