#include <stdio.h> 

int main(int argc, char**argv ) { 
  int i = 512; 
	float f = 1.6; 
	int* pi = &i; 
	float* pf = &f; 
	printf("Int value: %d, %d, 0x%x\n", i, *pi, pi); 
	printf("Float value: %f, %f, 0x%x\n", f, *pf, pf); 
	return 0; 
} 
