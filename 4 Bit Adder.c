#include <stdio.h>


int main () {
	
	char bin1[5];
	char bin2[5];
	printf("Enter two 4 bit binary numbers:\n");
	scanf("%s", bin1);
	scanf("%s", bin2);
	
	int cin = 0;
	char n1;
	char n2;
	char sumbin[5];
	int overflow;
	int sum = 0;
	
	for(int i=3;i>=0;i--)
	{
		n1 = bin1[i];
		n2 = bin2[i];
		if(n1 == '0' && n2 == '0' && cin == 1)
		{
			sumbin[i] = '1';
			cin = 0;
		}
		if(n1 == '0' && n2 == '0' && cin == 0)
		{
			sumbin[i] = '0';
			cin = 0;
		}
		if(n1 == '1' && n2 == '1' && cin == 1)
		{
			sumbin[i] = '1';
			cin = 1;
		}
		if(n1 == '1' && n2 == '1' && cin == 0)
		{
			sumbin[i] = '0';
			cin = 1;
		}
		if(n1 == '1' && n2 == '0' && cin == 1)
		{
			sumbin[i] = '0';
			cin = 1;
		}
		if(n1 == '1' && n2 == '0' && cin == 0)
		{
			sumbin[i] = '1';
			cin = 0;
		}
		if(n1 == '0' && n2 == '1' && cin == 1)
		{
			sumbin[i] = '0';
			cin = 1;
		}
		if(n1 == '0' && n2 == '1' && cin == 0)
		{
			sumbin[i] = '1';
			cin = 0;
		}
			
	}
	sumbin[4] = '\0';
	overflow = cin;
	printf("The binary sum of %s and %s is: %s\n", bin1, bin2, sumbin);
	if(overflow != 0)
	printf("Overflow: %d\n", overflow);
	return 0;
}
