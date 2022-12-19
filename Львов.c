#include <stdio.h>
#include <string.h>

//Все возможные случаи назовём cs№ - case(Случаи)
//x = 1 + 2  	x = 1 - 2	x = 1 * 2	x = 2 / 2	x = 3 % 2  cs1 
//x + 1 = 2  	x - 1 = 2	x * 1 = 2	x / 4 = 2	           cs2  
//
//1 = 2 + x  	1 = 2 - x	4 = 2 * x	4 = 8 / x	           cs3  
//1 + 2 = x 	1 - 2 = x	1 * 2 = x	4 / 2 = x	3 % 2 = x  cs1  
//
//1 = x + 2  	1 = x - 2	4 = x * 2	4 = x / 2	           cs3
//1 + x = 2 	1 - x = 2	1 * x = 2	4 / x = 2	           cs2

int Calc(char* exp) {
    int number1, number2, cs , minus = 1;
    char sym;
    if (exp[0] == 'x') {
        number1 = (exp[2] - '0');
        number2 = (exp[4] - '0');
        if (exp[1] == '=') {
            sym = (exp[3]);
            cs = 1;
        }
        else {
            sym = (exp[1]);
            cs = 2;
        }
    }
    if (exp[4] == 'x') { 
        if (exp[3] == '-')
            minus = -1;
        number1 = (exp[0] - '0');
        number2 = (exp[2] - '0');
        if (exp[1] == '=') {
            sym = exp[3];
            cs = 3;
        }
        else {
            sym = (exp[1]);
            cs = 1;
        }
    }
    if (exp[2] == 'x') {
        if (exp[1] == '-')
            minus = -1;
        number1 = (exp[0] - '0');
        number2 = (exp[4] - '0');
        if (exp[1] == '=') {
            sym = exp[3];
            cs = 3;
        }
        else {
            sym = (exp[1]);
            cs = 2;
        }
    }
    if (cs == 1) {
        switch (sym) {
        case '+': return (number1 + number2); break;
        case '-': return (number1 - number2); break;
        case '*': return (number1 * number2); break;
        case '/': return (number1 / number2); break;
        case '%': return (number1 % number2); break;
        }
    }
    if (cs == 2) {
        switch (sym){
        case '+': return (number2 - number1); break;
        case '-': return (minus * (number2 + number1)); break;
        case '*': return (number2 / number1); break;
        }
    }
    if (cs == 3) {
        switch (sym) {
        case '+': return (number1 - number2); break;
        case '-': return (minus * (number1 + number2)); break;
        case '*': return (number1 / number2); break;
        }
    }
    if (cs == 3 && exp[4] == 'x' && sym == '/')
        return (number2 / number1);
    if (cs == 2 && exp[2] == 'x' && sym == '/')
        return (number1 / number2);
    else
        return (number1 * number2);
    return 0;
}
//проверка условия
int main() {
    char* expression[] = {"x=1+2","x=1-2","x=1*2","x=2/2","x=3%2","x+1=2","x-1=2","x*1=2","x/4=2","1=2+x","1=2-x","4=2*x","4=8/x","1+2=x","1-2=x","1*2=x","4/2=x","3%2=x","1=x+2","1=x-2","4=x*2","4=x/2","1+x=2","1-x=2","1*x=2","4/x=2"};
    
    int len = sizeof(expression) / sizeof(char*);

    for (int i = 0; i < len; i++)
        printf("%s x=%d\n", expression[i], Calc(expression[i]));
    return 0;
}