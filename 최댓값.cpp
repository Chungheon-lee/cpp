#include <stdio.h>
int main(){
	int num[9];
	int max;
	int length=0;
	
	for (int i=0; i<9; i++ ){
		scanf("%d",&num[i]);
	}
	
	max = num[0];
	for (int i=1; i<9; i++ ){
		if(max < num[i]){
			max = num[i];
		}	
	}
	
	for (int i=0; i<9; i++ ){
		if(num[i] == max ){
			break;
		}
		length++;
	}
	
	printf("%d %d\n", max, length+1);
}
