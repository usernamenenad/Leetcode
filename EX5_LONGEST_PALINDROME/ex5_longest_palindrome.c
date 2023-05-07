#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* longestPalindrome(char* s){
     
    if(strlen(s) == 0) {return NULL;}
    if(strlen(s) == 1) {return s;}

    char* start = s;
    char* end = s + strlen(s) - 1;
    char* solution = (char*) malloc(MAX_LEN*sizeof(char));
    
    *solution = *s;
    int sol_lenght = 1;

    while(1) {
        if(start >= end) {
            break; 
        }
        while(start != end && *start != *end) {
            end--;
        }
        if(start == end) {
            start++;
            end = s + strlen(s) - 1;
            continue;
        }
        char* temp_start = start;
        char* temp_end = end;
        char* last_end = end;
        while(temp_start < temp_end) {
            temp_start++;
            temp_end--;
            // Maybe there exists a palindrome substring, so we reset positions
            if(*temp_start != *temp_end) {
                temp_start = start;
                temp_end = --last_end;
            }
        }
        if(temp_start >= temp_end) {
            if(sol_lenght > last_end - start + 1) {
                // If we have found a new palindrome but it's shorter than the one we found earlier
                start++;
                end = s + strlen(s) - 1;
                continue;
            }
            // Copying (part of) original string to solution string and keeping track of solution size
            sol_lenght = last_end - start + 1;
            char* write_start = start;
            for(int i = 0;i < sol_lenght; i++) {
                *(solution + i) = *(write_start++);
            }
            start += sol_lenght;
            *(solution + sol_lenght) = '\0';
            end = s + strlen(s) - 1;
            continue;
        }
        start++;
        end = s + strlen(s) - 1;
    }
    return solution;
}

int main() {
	char c[MAX_LEN] = "daaaaaad\0";
	char* solution = longestPalindrome(c);
	printf("The longest palindrome: %s\n", solution);
        free(solution);
	return 0;
}
