// 30.10.2023 - Struct Lesson
// A Struct in C is a user-defined data type that allows you to combine data items of different
// kinds. Structs are used to crate a data type that can hold a group of related data items.
// Here are 10 practical examples demonstrating the use of structs in C, along with detailed
// explanations and code comments.

#include <stdio.h>

// Example 1: Basic Struct Definition and usage
void example_1(){
	//	Define a simple struct for a point in 2D space.
	struct Point{
		int x;
		int y;
	};

	//	Create and use a Point struct
	struct Point p1 = {1, 2};
	printf("Point p1: (%d, %d) \n", p1.x, p1.y);
	//	p1 is an instance of point with x=1 and y=2
}

// Example 2: Struct with Array
void example_2(){
	//	Define a struct to hold a student's grades
	struct Grades{
		int scores[5];
		int count;
	};
	//	Create and use a Grades struct
	struct Grades student1 = {{90, 85, 92, 78, 88}, 5};
	printf("Average grade: %2.f \n", student1.scores[0] + student1.scores[1] + 
			student1.scores[2] + student1.scores[3] 
			+ student1.scores[4] / (float)student1.count);
	// Calculate the average score from the grades array
}

int main(){

	example_1();
	printf("\n");
	example_2();

	return 0;
}
