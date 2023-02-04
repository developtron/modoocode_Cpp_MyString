#include <iostream>
#include <cstring>
#include "String_To_Value.h"

double String_To_Value(const char* str) {
	bool is_minus = false;
	int string_length = strlen(str);
	int i;
	
	if(str[0] == '-' || str[0] == '+') {
		if(str[0] == '-')
			is_minus = true;
		i = 1; // -, +가 붙으면 다음 문자부터가 숫자 
	}
	
	//부호표시 없을 경우 양수 
	else {
		is_minus = false;
		i = 0;
	}
	
	bool integer_part = true;
	double value = 0.0;
	double power_of_point1 = 1.0;
	
	for(; i < string_length; i++) {
		if(str[i] != '.' && integer_part) {
			value *= 10;
			value += (str[i] - '0');
		}
		else if(str[i] != '.' && !integer_part) {
			power_of_point1 *= 0.1;
			value += ((str[i] - '0') * power_of_point1);
		}
		else
			integer_part = false;	
	}
	
	if(is_minus == true)
		return value * (-1);
		
	return value;
	
}