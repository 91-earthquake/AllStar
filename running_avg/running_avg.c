#include <stdio.h>
#include <stdlib.h>

#define NUM_VALS 4



void storeValue(float *array, int *counter, int length, float value) {
	array[*counter] = value;
	(*counter)++;
	*counter = *counter % length;
}

float runningAVG(float *array, int length) {
	float t = 0;
	int i;
	for (i = 0; i < length; ++i) {
		t += array[i];
	}
	return t / (float) length;
}

int main(int argc, char** argv) {

	// Store sensor readings
	float store[NUM_VALS] = {0};
	int counter = 0;
	
	storeValue(store, &counter, NUM_VALS, 1);
	storeValue(store, &counter, NUM_VALS, 1);
	storeValue(store, &counter, NUM_VALS, 1);
	storeValue(store, &counter, NUM_VALS, 1);
	storeValue(store, &counter, NUM_VALS, 2);
	storeValue(store, &counter, NUM_VALS, 2);
	storeValue(store, &counter, NUM_VALS, 2);
	storeValue(store, &counter, NUM_VALS, 2);
	
	printf("STO: %f\n", store[0]);
	
	printf("AVG: %f\n", runningAVG(store, NUM_VALS));
	
}