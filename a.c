#include<stdio.h>
#include<stdint.h>
#include<ctype.h>
#include<stdlib.h>

#define LETTER_COUNT 26

int main() {
    uint32_t freq[LETTER_COUNT] = { 0 };
    char text[] = "This is China!";
    for (uint32_t i = 0; text[i] != '\0'; i++)
    {
        /* code */
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z')
        {
            /* code */
            freq[c - 'a']++;
        }
    }
    for (uint32_t i = 0; i < LETTER_COUNT; i++)
    {
        /* code */
        printf("%c : %d\n", (char)('a'+i), freq[i]);
    }
    system("cls");
    return 0;
}













