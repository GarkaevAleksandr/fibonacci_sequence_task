#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include <string>
#include <omp.h>

using namespace std;


void fib(int value, int file_count);
void recur_fib(int value, int file_count);
unsigned long int in_warp_rec_fib(unsigned long int value);


int main(void) {

	fib(50, 1);
	fib(100, 2);
	recur_fib(40, 3);

	
	cout << "Done" << endl;

	return 0;
}

void fib(int value, int file_count) {

	mpz_t fib_arr[value]; 
	double start;
	
	ofstream file(to_string(file_count) + ".txt");

	for(int i = 0; i <= value; i++) {
		
		mpz_init(fib_arr[i]);
	}

    start = omp_get_wtime();
    
    mpz_set_ui(fib_arr[0], 0);
    mpz_set_ui(fib_arr[1], 1);
    file << fib_arr[0] << " " << omp_get_wtime() - start << endl;
    file << fib_arr[1] << " " << omp_get_wtime() - start << endl;

    for(int count = 2; count <= value; count++) {

    	mpz_add(fib_arr[count], fib_arr[count - 1], fib_arr[count - 2]);
	    file << fib_arr[count] << " " << omp_get_wtime() - start << endl;
   	}
}

unsigned long int in_warp_rec_fib(unsigned long int value) {

	if (value == 0)
	{
    	return 0;
  	}
  	else if (value == 1)
  	{
    	return 1;
  	}
  	else
  	{
    	return in_warp_rec_fib(value - 1) + in_warp_rec_fib(value - 2);
  	}
}


void recur_fib(int value, int file_count) {

	double start;
	ofstream file(to_string(file_count) + ".txt");

	start = omp_get_wtime();

	for(unsigned long int count = 0; count <= value; count++) {

		file << in_warp_rec_fib(count) << " " << omp_get_wtime() - start << endl;
	}
}

