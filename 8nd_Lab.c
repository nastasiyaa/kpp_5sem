#include <stdio.h>
#include <stdbool.h> 

char* inputStr(char* msg);
char make_capital_letter(char c);
int len(char* string);
void change_text(char, char);

void main() {
    char* text = inputStr("Please, input your text:");
    char* nessesary_string = inputStr("Please, input your nessesary string:");
    change_text(text, nessesary_string);
    printf("Result: %s", text);
}

void change_text(char* source_text, char* nessesary_str) {
    for (int i = 0; i < len(source_text); i++) {
        if (source_text[i] == nessesary_str[0]) {
            bool flag = true;
            for (int j = 0, i2 = i; j < len(nessesary_str); j++, i2++)
                if (source_text[i2] != nessesary_str[j]) {
                    flag = false;
                    break;
                }

            if (flag) {
                for (int j = 0, i2 = i; j < len(nessesary_str); j++, i2++)
                    source_text[i2] = make_capital_letter(nessesary_str[j]);
                i += len(nessesary_str);
            }

        }
    }
}

char* inputStr(char* msg) {
    printf("%s", msg);
    char* inputStr = (char)malloc(100);
    gets(inputStr);
    return inputStr;
}

char make_capital_letter(char c) {
    char character = c;
    if ((int)c > 96 && (int)c < 123)
        character = (char)((int)c - 32);

    return character;
}

int len(char string) {
    char* p = string;
    int counter = 0;
    while (*p) {
        counter++;
        p++;
    }
    return counter;
}
