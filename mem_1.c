// DYNAMIC MEMORY ALLOCATION - The Library and Bookshelves Analogy
// ---------------------------------------------------------------
// Imagine you're at a library. This library is unique: it allows you to build
// your own bookshelves when you need them. You're given two magical tools to
// help with this:
// 		1. A "build-a-shelf" tool (think of this as 'malloc()' or 'calloc()')
// 		2. A "Dismantle Shelf" tool (this is 'free()')
// when you need a shelf, you use "Build-a-Shelf" tool. You specify how many
// slots you wants on the shelf (similar to specifying how much memory you
// need). Once built, you get a tiny magical ticket with a number on it. This
// number tells where your shelf starts (similar to the starting address of the
// memory you've allocated). This ticket is quite like a pointer in C!
//
// You can visit the shelf anytime using the ticket, place books on it, rearrange
// them, or read from them (like storing or accessing data in allocated memory).
//
// But here's the catch:
// 	*	The library has limited space. If everyone keeps building shelves without
// 		dismantling them, the library will run out of room. Similarly, if you
// 		keep allocating memory and never free it, you'll run out of memory,
// 		causing what programmers call a "memory leak".
// 	
// 	*	If you lose your ticket, you lose access to your shelf. You can't 
// 		dismantle it without the ticket. In C, if you lose your pointer
// 		(maybe you overwrite it or it goes out of scope), you can't free the
// 		memory. This also results in a memory leak.
//
// 	*	If you use the the "Dismantle Shelf" tool and later try to place a book
// 		on a previously dismantled shelf without the library's permission, the
// 		library's security will catch you! Similarly, in C, if you try to 
// 		access memory after you've freed it, you might crash your program or get
// 		unexpected behavior.
//
// 	SUMMING IT UP:
// 	--------------
// 	Dynamic Memory Allocation in C allows you to request memory when you need it
// 	and release it when you're done. It's "dynamic" because the amount and 
// 	duration aren't predetermine, you decide at runtime.
// 	
// 	1.	You use 'malloc()' or 'calloc()' to request memory, and they return a 
// 		pointer to the beginning of that memory block.
//
// 	2.	It's your responsibility to free() that memory when you're done. Otherwise
// 		, you'll have memory leaks.
//
// 	3.	Always be careful. Mismanagement can lead crashes, unexpected behaviors,
// 		or those dreaded memory leaks.
//
// 	Remember, with great power (like DMA) comes great responsibility! And just 
// 	like you'd be responsible in a magical library, you need to be responsible
// 	when managing memory in C
//--------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>	// Required for malloc() and free()

void memory_allocation_bookshelf(){
	int *bookshelf;	//	This represents our bookshelf
	int slots = 5;	//	We want a bookshelf with 5 slots
	
	// Use the "build-a-shelf" tool to create a bookshelf with 5 slots
	bookshelf = (int *)malloc(slots * sizeof(int));

	// Check if we successfully got our bookshelf
	if (bookshelf == NULL) {
		printf("[ERROR]: [Failed to build the bookshelf]!\n");
	}

	// Place books on the bookshelf.
	// For simplicity, books are represented as numbers. Let's place books numbered
	// 10 to 50.
	for (int i = 0; i < slots; i++) {
		bookshelf[i] = (i + 1) * 10; //	Places books 10, 20, 30, ... sequentially
	}

	//	Show the books on our bookshelf
	for (int i = 0; i < slots; i++) {
		printf("Book %d: %d\n", i+1, bookshelf[i]);
	}
	
	// We're done reading our books. Let's dismantle the bookshelf to free up space
	// in the library
	free(bookshelf);

	// Hand back the magical ticket so we don't accidentally try to access the 
	// dismantled bookshelf
	bookshelf = NULL;
}

int main(){

	int *arr;	// Declare a pointer to int. This will point to our array
	int length = 5;	//	We want an array of 5 integers
	
	// Request memory for 5 integers
	// sizeof(int) gives the size of an integer in bytes
	// So, length * sizeof(int) gives the total size needed for the array.
	arr = (int *)malloc(length * sizeof(int));

	// Check if memory allocation was successful.
	if (arr == NULL){
		printf("[ERROR]: [Memory Allocation failed !] \n");
		return 1; // Return with an error code.
	}
	
	// Assign values to the array
	// Let's just assign values 10, 20, 30, 40 and 50 to the array.
	for(int i = 0; i < length; i++){
		arr[i] = (i + 1) * 10; // Assigns 10, 20, 30, ... sequentially
	}

	// Print the values in the array
	for (int i = 0; i < length; i++){
		printf("%d", arr[i]);
	}

	printf("\n"); // Print a newline after the array.
	
	// It's a good practice to set the pointer to NULL after freeing.
	// This ensures that we don't accidentally use the pointer later
	arr = NULL;
	
	memory_allocation_bookshelf();

	return 0;
}
