#include<stdio.h>
//const helps in storing values that are not intended to be modified. It will be unchangable and readonly. 
int main() {
	const int x = 123;
	printf("%d", x);
	//x = 234;//Compile error if we try to change the const. 
	printf("%d", x);
	return 0;
}
//consts are set at compile time, so when we refer them in the code, the value wil be a literal and there will be no need to evaluate the value again by the runtime, thus making it more optimized compared to normal variables which are extracted everytime U refer them in the code. 
//It is recommended to name a const with UPPERCASE. 
