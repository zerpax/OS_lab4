int Prime(int num){
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0) {
			return 0;		
		}
	}
	return 1;
}


int Primes(int A, int B){
	int count = 0;	
	for(int i = A; i <= B; i++){
		if(Prime(i)){
			count++;
		}
	}
	return count;
}

void Sort(int* array, int size){
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-1; j++){
			if(array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}	
		}
	}
}


