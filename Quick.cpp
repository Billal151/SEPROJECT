#include "head.h"
#include <string>
#include <vector>
#include <gdbm.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void quickSort(int vec[], int n, string k){
	if ((k.compare("DESC")) && (k.compare("desc"))  ){
		qsort(vec,n, sizeof(int), compare2);
	} else {
		qsort(vec,n, sizeof(int), compare1);
	}
}

int compare1(const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}

int compare2(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}
