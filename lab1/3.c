#include<stdio.h>
int floorValue(float num)
{
	if (num == (int)(num))
	{
		return num;
	}
	else if (num>=0)
	{
		return (int)(num/1);
	}
	else
	{
		return (int)(num-1);
	}
}
int CeilValue(float num)
{
	if (num == (int)(num))
	{
        return num;
    }
	    else if(num>=0)
	    {
            return (int)((num/1)+1);
        }
        else
		{
            return (int)(num);
        }
}

int main()
{
	float x;
	int ceil,floor;
	printf("Enter the number: ");
	scanf("%f",&x);
	ceil = CeilValue(x);
	floor = floorValue(x);
	printf("The Ceiling value of %.2f: %d\n",x,ceil); 
	printf("The Floor value of   %.2f: %d\n", x ,floor);	
	if ( (int)(x) != x)
	{	
	    printf("\n|-(%d)\n|\n|-(%.2f)\n|\n|-(%d)\n\n",ceil,x,floor);
	}
}
