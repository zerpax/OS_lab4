#include <stdio.h>
#include <dlfcn.h>

int main(){
	int (*Primes)(int , int );
	int (*Sort)(int*, int );
	int com = -1;
	int lib = 1;
	void* curlib = dlopen("./first.so", RTLD_LAZY);

	while(com != 3){


		scanf("%d", &com);
		if(com == 0){
			dlclose(curlib);
			if(lib == 1){
				lib = 2;
				dlopen("./second.so", RTLD_LAZY);
			}
			else{
				lib = 1;
				dlopen("./first.so", RTLD_LAZY);
			}
		}
		if(com == 1){
			int A, B;
			scanf("%d %d", &A, &B);
			Primes = (int (*)(int,  int))dlsym(curlib, "Primes");

			printf("%d\n", Primes(A,B));

		}
		if(com == 2){
			int size, array[1000];
			scanf("%d", &size);
			for(int i = 0; i < size; i++){
				scanf("%d", &array[i]);
			}

			Sort = (int (*)(int*,  int))dlsym(curlib, "Sort");
			Sort(array, size);
			
			for(int i = 0; i < size; i++){
				printf("%d ", array[i]);
			}
			printf("\n");
		}
	}
}
