#include <stdio.h>
#include <string.h>
int main() {
	char num[100000];
	
	while ( scanf("%s",num) && num[0] != '0' ){
		int N = 1;
		int len = strlen(num);
		
		for (int i=0; i<len/2; i++){
			if (num[i] != num[len-i-1]){
				N = 0;
				break;
			}			
		}
		
		if (N == 0) {
			printf("no\n");
		} else if (N==1){
			printf("yes\n");
		}
	}
	
	return 0;
}
