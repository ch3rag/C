/*

For a string S let the unique set of characters that occur in it one or more times be C. Consider a permutation of the elements of C as (c1,c2,c3...). Let f(c) be the number of times c occurs in S.

If any such permutation of the elements of C satisfies f(ci)=f(ci−1)+f(ci−2) for all i≥3, the string is said to be a dynamic string.

Note that if the number of distinct characters in the string is less than 3, i.e. if |C|<3, then the string is always dynamic.

*/

#include <stdio.h>
#include <string.h>

int check (int a , int b , int c) {
	if(a == (b+c)) {
		return 0;
	} else if(b == (a+c)) {
		return 0;
	} else if(c == (a+b)) {
		return 0;
	} else return 1;
}

int main() {
	int testCases;
	printf("Enter Number Of Test Cases : ");
	scanf("%d", &testCases);
	char testString[10][10000];

	for(int i = 0 ; i < testCases ; i++) {
		scanf("%s", testString[i]);
	}

	for(int i = 0 ; i < testCases ; i++) {

		int  charCount[26] = {0}, distinctChar = 0, sequence[26] = {0}, flag = 1;

		for(int len = strlen(testString[i]) - 1 ; len >= 0 ; len--) {
			charCount[(testString[i][len] - 97)]++;
		}
		
		
		for(int i = 0 ; i < 26 ; i++) {
			if(charCount[i] != 0) {
				sequence[distinctChar++] = charCount[i];
			}
		}

		if(distinctChar < 3) {
			printf("Dynamic\n");
		} else {

			for(int i = 2 ; i < distinctChar ; i++) {

				if(check(sequence[i], sequence[i-1], sequence[i-2])) {
					printf("Not\n");
					flag = 0;
					break;
				}

			}

			if(flag == 1) {

			printf("Dynamic\n");

			}
		}
	}
}
