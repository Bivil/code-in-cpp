#include<stdio.h>

int main()
{
	int i;
	struct poly
	{
		int a[10],d;
	};
	struct poly p1,p2,p3;
	for(i=0;i<10;i++)
	{
		p1.a[i]=0;
		p2.a[i]=0;
	}
	printf("Enter the degree of First polinomial: ");
	scanf("%d",&p1.d);
	for(i=p1.d;i>=0;i--)
	{
        printf("Enter the coefficient of x^%d : ",i);
		scanf("%d",&p1.a[i]);
    }
    printf("The First Polinomial is: ");
	for(i=p1.d;i>0;i--)
	{
		if(i<p1.d && i>=0)
			printf("+");
		printf(" %dx^%d",p1.a[i],i);
	}
		printf("+%d",p1.a[0]);
    printf("\n\nEnter the degree of Second polinomial: ");
	scanf("%d",&p2.d);
	for(i=p2.d;i>=0;i--)
	{
        printf("Enter the coefficient of x^%d : ",i);
		scanf("%d",&p2.a[i]);
    }
    printf("The second polinomial is: ");
	for(i=p2.d;i>0;i--)
	{
		if(i<p2.d && i>=0)
			printf("+");
		printf(" %dx^%d",p2.a[i],i);
	}
       printf("+%d",p2.a[0]);
	if(p1.d>p2.d) p3.d=p1.d;
	else p3.d=p2.d;
	for(i=0;i<=p3.d;i++)
		p3.a[i]=p1.a[i]+p2.a[i];
	printf("\n\nThe sum is:");
	for(i=p3.d;i>0;i--)
	{
		if(i<p3.d && i>=0)
			printf("+");
		printf(" %dx^%d",p3.a[i],i);
	}
	   printf("+%d",p3.a[0]);
	printf("\n");
    getchar();
}
