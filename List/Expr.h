#pragma once
#include "st_and_queue.h"
#include "List.h"
struct variables {
	double  data;
	char *name_data;
	variables *next;
};

class expression {
	queue ExpStack;		
	variables *var;

public:

	expression();
	expression(char* input);

	void push_name_in_struct(char *name_, double data_);
	int prior_of_operator(char sign);				
	bool test_on_operator(char input); 
	bool test_on_symbol(char *input);	
	double counting();							
	double find_el_var(char * str);
	bool test_on_equal_varnames(char *str);
	bool test_on_unar_minus(char* input, int pointer, bool abs_flag);

	~expression() {
		if (var != 0) {
			while (var->next != 0) {
				variables *buf = var;
				var = var->next;
				delete[] buf->name_data;
				delete buf;
			}
			delete[] var->name_data;
			delete var;
		}
	}
};
