// StructLista.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>

typedef struct node{
	int number;
	struct node *next;
}
node;

using namespace std;

void add_number(node** numbers);
void add_to_list(int number, node** numbers, node* n);
void print_list(node* numbers);
void free_memory(node *numbers);

int main(){
	// Memory for numbers
	node *numbers = NULL;

	add_number(&numbers);
	add_number(&numbers);
	add_number(&numbers);

	// Print numbers
	print_list(numbers);

	// Free memory
	free_memory(numbers);

	return 0;
}

void add_number(node** numbers) {
	// Prompt for number
	int number;
	cout << "number: " << endl;
	cin >> number;

	// Allocate space for number
	node* n = (node*)malloc(sizeof(node));
	if (!n) {
		return;
	}
	add_to_list(number, numbers, n);
}

void add_to_list(int number, node** numbers, node* n) {
	n->number = number;
	n->next = NULL;
	if (*numbers) {
		for (node *ptr = *numbers; ptr != NULL; ptr = ptr->next) {
			if (!ptr->next) {
				ptr->next = n;
				break;
			}
		}
	}
	else {
		*numbers = n;
	}
}

void print_list(node* numbers) {
	cout << endl;
	for (node *ptr = numbers; ptr != NULL; ptr = ptr->next){
		cout << ptr->number;
	}
}

void free_memory(node *numbers) {
	node *ptr = numbers;
	while (ptr != NULL) {
		node *next = ptr->next;
		free(ptr);
		ptr = next;
	}
}
