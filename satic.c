#include <stdio.h>
#include "first.h"

int main(){
	int com = 0;
	
	while(com != 3){
		scanf("%d", &com);
		if(com == 1){
			int A, B;
			scanf("%d %d", &A, &B);
			printf("%d\n", Primes(A,B));
		}
		if(com == 2){
			int size, array[1000];
			scanf("%d", &size);
			for(int i = 0; i < size; i++){
				scanf("%d", &array[i]);
			}
			Sort(array, size);
			
			for(int i = 0; i < size; i++){
				printf("%d ", array[i]);
			}
			printf("\n");
		}
	}
}
