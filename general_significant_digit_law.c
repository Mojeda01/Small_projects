// This C Script shows the mathematical foundation for a general significant
// digit law, which is derived from Benford's Law. Benford's Law predicts the
// frequency distribution of the first digits in a set of natural numerical data.
// The law states that in many naturally occurring collections of numbers, the
// leading significant digit is likely to be small. For example, the number 1
// appears as the leading significant digit about 30% of the time, while 9
// appears as the leading significant digit less thanm 5% of the time.
//
// The Specific formula provided is a generalization that allows the calculation
// of the probability not just for the first digit, but for the sequence of the first
// k digits in decimal represents.
//
// Date: 08.11.2023

#include <stdio.h>
#include <math.h>

double benford_probability(int digits[], int k){
	double denominator = 0;
	for(int i=0; i<k; i++){
		denominator += digits[i] * pow(10, k - i - 1);
	}

	return log10(1 + (1/denominator));
}

int main(){
		int k = 6;	//	The number of digits we are considering.
		// The specific digits for which we're calculating the probability.
		int digits[] = {9, 9, 9, 9, 9, 9};

		double probability = benford_probability(digits, k);
		printf("The Probability is: %lf \n", probability);

		return 0;
}
