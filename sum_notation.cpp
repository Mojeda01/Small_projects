#include <iostream>

void for_function(){

    int start = 1;      // Starting index of the sum
    int end = 5;        // Ending index of the sum
    int sum = 0;        // Variable to store the sum

    for (int i = start; i <= end; ++i) {
    // Replace this expression with the one you want to sum
    sum += i * i ;  
    }

    std::cout << "[+] Sum_notation: " << sum << std::endl;
}

void linearFunction(double x){
    // Define the parameters of the linear function
    double a = 2.0; //  Slope
    double b = 3.0; //  Y-interecept

    // Calculate the value of the linear function for the given x
    double result = a * x + b;

    //  Print the result
    std::cout << "[:)]=> linear f(" << x << ") = " << result << std::endl;
}

void polyQuadraticFunction(double x1, double x2){
    // Define the coefficients of the quadratic function
    double a = 2.0;
    double b = -3.0;
    double c = 1.0;

    //  Calculate the value of the quadratic function for the given x1 and x2
    double result = a * x1 + b * x2 + c;

    // Print the result
    std::cout << "[+] Polynomial Quadratic f(" << x1 << "," << x2 << ") = " << result << std::endl;

}

int main(){
    // Variable for linearFunction
    double lin_x = 5.0;
    // Variable for polyQuadraticFunction
    double pol_x1 = 3.0;
    double pol_x2 = 4.5;

    for_function();
    linearFunction(lin_x);
    polyQuadraticFunction(pol_x1, pol_x2);

    return 0;
}
