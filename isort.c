#include <stdio.h>
#define SIZEARR 50
void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n-1; i++) {
		printf("%d,", *data);
		data++;
	}
	printf("%d", *data);
	printf("\n");
}
void shift_element(int* arr, int i) {
	int *j = arr + i;
	int iV= *(arr+i);
	for(; arr < j && *(j-1)>iV ; j--){
		*j=*(j-1);
	}
	*j = iV;
}

void insertion_sort(int* arr, int len) {
	int *i, *last = arr + len;
	int count=0;
	for(i = arr + 1; i < last; i++){
	    count++;
		if(*i < *(i-1))
			shift_element(arr,count);
	}
}

int main() {	
	int arr[SIZEARR];
	int n,i=0;
	while(scanf("%d ",&n)==1&&i<=SIZEARR-1){
		arr[i] = n;
		++i;
	}
	if(i < 50) {
		printf("less than 50 numbers");
		return 1;
	}
	//print_array(&arr[0], SIZEARR);
	insertion_sort(&arr[0], SIZEARR);
	print_array(&arr[0], SIZEARR);
	return 0;
}