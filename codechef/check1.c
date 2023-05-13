#include <stdio.h>

int main(void) {
	// your code goes here
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++)
	{
	    int arr[13];
	    scanf("%s", arr);
	    int _1 = arr[0]*10 + arr[1];
	    int _2 = arr[3]*10 + arr[4];
        printf("%d %d", _1, _2);
	    
	    if(_1 <= 12 && _2 <= 12)
	        printf("BOTH\n");
	    else if(_1 > 12 && _2 <= 12)
	        printf("DD/MM/YYYY\n");
	    else if(_2 > 12 && _1 <= 12)
	        printf("MM/DD/YYYY\n");
	}
	return 0;
}