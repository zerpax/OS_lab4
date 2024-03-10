int Primes(int A, int B){
	int array[1000] = {0};

	int countB = B;
	int countA = A;
	for(int i = 2; i*i <= B; i++){
		if(array[i] == 0){
			for(int j = i; j*i <= B; j++){
				
				if(array[i*j] == 0){	
					if(i*j <= A){
						countA--;
					}
					countB--;				
					array[i*j] = 1;
				}
			}
		}
	}
	

	int count = countB - countA;
	return count;
}


void Sort(int* a, int size){
	if (size < 2) {
		return;
	}
	int pivot_index = size/2;
	int pivot = a[pivot_index];
	int right_size  = 0;
	
	for (int i = 0; i < size - right_size; i++) {
		while (a[i] > pivot && i <= size - right_size - 1) {
		
			int temp = a[i];
			a[i] = a[size - right_size - 1];
			a[size - right_size - 1] = temp;
			
			if (size - right_size - 1 == pivot_index) {
				pivot_index = i;
			}

			right_size++;
		}
	}
	
	int temp = a[pivot_index];
        a[pivot_index] = a[size - right_size - 1];
	a[size - right_size - 1] = temp;

	Sort(a, size - right_size - 1);
	Sort(&a[size - right_size], right_size);
}


