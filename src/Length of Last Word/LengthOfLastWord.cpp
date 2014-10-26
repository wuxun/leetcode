// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : wuxun
// Date   : 2014-10-26

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include "stdio.h"

int lengthOfLastWord(const char *s){
	if (s == NULL) return 0;

	int len = strlen(s);

	while(len > 0 && s[len - 1] == ' '){
		len--;
	}
	if(len == 0) return 0;

	
	for(int i=len-1; i>=0; i--){
		if(s[i] == ' '){
			return len - i - 1;
		}
	}
	return len;
}

void test(char* str){
	printf("%s\n", str);
	printf("%d\n", lengthOfLastWord(str));
	printf("--------------------\n");
}

int main (int argc, char const *argv[])
{
	char s0[] = "asf asdf";
	test(s0);
	
	char s1[] = "     ";
	test(s1);
	
	char s2[] = "thisisawholeword";
	test(s2);
	
	char s3[] = "this is a word ";
	test(s3);
	
	char s4[] = " thisisaword";
	test(s4);
	return 0;
}
