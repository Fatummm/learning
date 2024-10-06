	#include <stdio.h>
	
	int main()
	{
		double res = 0.0,
			cur_number = 0.0,
			after_dot = 0.0;
		char operation = '+';
		int another_char = 0;
		char c;
		while (1) {
			c = getchar();
			switch (c) {
			case '+': case '-': {
				if (operation == '-') res -= cur_number;
				else res += cur_number;
				operation = c;
				cur_number = 0.0;
				after_dot = 0;
				break;
			}
			case '.': {
				after_dot = 0.1;
				break;
			}
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7': case '8':
			case '9': {
				if (after_dot != 0) {
					cur_number += (c - 48) * after_dot;
					after_dot *= 0.1;
				}
				else {
					if (cur_number != 0.0) cur_number *= 10;
					cur_number += (c - 48);
				}
				break;
			}
			default: {
				another_char = 1;
	
			}
			}
			if (another_char) break;
		}
		if (operation == '-') res -= cur_number;
		else res += cur_number;
	
		printf("%1f", res);
	}