#include<stdio.h>
#include<stdlib.h>
float degree_of_membershipA(int age)
{
    if (age <=20)       
	return 1;
    else if(age<=30)    
	return (float)(30-age)/10;
    else                
	return 0;
}
float degree_of_membershipB(int age)
{
    if (age <=15)       
	return 1;
    else if(age<=35)    
	return (float)(35-age)/20;
    else                
	return 0;
}
void fuzzy_union(char Name[40][40],float MembershipA[40], float MembershipB[40])
    {
        float union_Set[20];
        int i,j;
        for(i=0;i<5;i++)
        {
            if(MembershipA[i]>MembershipB[i])
            {
                union_Set[i]=MembershipA[i];
            }
            else if(MembershipA[i]< MembershipB[i])
            {
                union_Set[i]= MembershipB[i];
            }
            else
            {
            union_Set[i]=MembershipA[i];
            }
        }
        printf("The result of the union fuzzy operation is : \n {");
        for(i=0;i<5;i++)
		{
            if(i<4)
			{
                printf("%.2f/%s,",union_Set[i],Name[i]);
            }
            else if(i == 4)
			{
                printf("%.2f/%s",union_Set[i],Name[i]);

            }
        }
        printf("}\n\n");
    }
void fuzzy_intersection(char Name[40][40],float MembershipA[40], float MembershipB[40])
    {
        float intersection_set[20];
        int i,j;
        for(i=0;i<5;i++)
        {
            if(MembershipA[i]>MembershipB[i])
            {
                intersection_set[i]=MembershipB[i];
            }
            else if(MembershipA[i]< MembershipB[i])
            {
                intersection_set[i]= MembershipA[i];
            }
            else
            {
                intersection_set[i]=MembershipA[i];
            }
        }
        printf("The result of the intersection fuzzy operation is : \n {");
        for(i=0;i<5;i++)
		{
            if(i<4){
                printf("%.2f/%s, ",intersection_set[i],Name[i]);
            }
            else if(i==4)
			{
                printf("%.2f/%s",intersection_set[i],Name[i]);
            }
        }
        printf("}\n");
    }
void fuzzy_complement(char Name[40][40],float MembershipA[40], float MembershipB[40])
	{
        float complement_SetA[20],complement_SetB[20];
        int i,j;
        for(i=0;i<5;i++)
        {
            complement_SetA[i]=1-MembershipA[i];
            complement_SetB[i]=1-MembershipB[i];
        }
        printf("The result of the Complement fuzzy operation of first set is : \n {");
        for(i=0;i<5;i++)
		{
            if(i<4)
			{
                printf("%.2f/%s, ",complement_SetA[i],Name[i]);
            }
            else if(i==4)
			{
                printf("%.2f/%s",complement_SetA[i],Name[i]);
            }
        }
        printf("}\n");
        printf("The result of the Complement fuzzy operation of second set is : \n {");
        for(i=0;i<5;i++)
		{
            if(i<4)
			{
                printf("%.2f/%s, ",complement_SetB[i],Name[i]);
            }
            else if(i==4)
			{
                printf("%.2f/%s",complement_SetB[i],Name[i]);
            }        
		}
        printf("}\n");
    }
int main()
{
    int age[40],i=0;
    char name[40][40];
    float membershipA[20],membershipB[20];
    for(i=0;i<5;i++)
	{
        printf("Enter the name: ");     
		scanf("%s",name[i]);
        printf("Enter age: ");          
		scanf("%d",&age[i]);
    }
    for(i=0;i<5;i++)
	{
        membershipA[i]= degree_of_membershipA(age[i]);
        membershipB[i]= degree_of_membershipB(age[i]);
    }
    printf("First Set is: \n {");
    for(i=0;i<5;i++)
	{
        if(i<4)
		{
            printf("%.2f/%s, ",membershipA[i],name[i]);
        }
        else if(i==4)
		{
            printf("%.2f/%s",membershipA[i],name[i]);
        }   
	}
    printf("}\n");
    printf("Second Set is: \n {");
    for(i=0;i<5;i++)
	{
        if(i<4)
		{
            printf("%.2f/%s, ",membershipB[i],name[i]);
        }
        else if(i==4)
		{
            printf("%.2f/%s",membershipB[i],name[i]);
        }
    }
    printf("}\n");
    fuzzy_union(name, membershipA, membershipB);
    fuzzy_intersection(name,membershipA,membershipB);
    fuzzy_complement(name,membershipA,membershipB);
}

