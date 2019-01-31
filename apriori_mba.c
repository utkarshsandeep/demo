#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,j,k;
char ch;
char nx;
int data[100][6];
FILE *fp;
fp=fopen("mba_data2.txt","r");

if(fp==NULL)
{
    printf("File not found");
    exit(0);
    return(1);
}

while(!feof(fp))
{
    //printf("%c",ch);
    ch=fgetc(fp);
    //printf("%c",ch);
    if(ch!=',' && ch!='\n' && ch!=' ')
    {
        //printf("xyx");
        nx=fgetc(fp);
        if(nx!=',' && nx!='\n' && nx!=' ')
        {
            //printf("%d %d ",i,j);
            data[i][j]= (nx-'0')+((ch-'0')*10);
            //printf("%d\n",data[i][j]);
        }
        else
        {
            //printf("%d %d ",i,j);
            data[i][j]=ch-'0';
            //printf("%d\n",data[i][j]);
        }
        j++;
    }
    if(ch=='\n')
    {
        i++;
        j=0;
    }
}
fclose(fp);
const char unique[47][20]={"cleaner", "salt", "curd", "beverages", "snack", "meat", "milk", "dessert", "water", "bags", "vegetables", "flour", "beef", "potato", "yogurt", "rice", "chicken", "sauce", "bread", "newspapers", "berries", "cream", "spices", "cereals", "butter", "onions", "margarine", "fruit", "gum", "cake", "waffles", "pork", "cheese", "wine", "detergent", "chocolate", "eggs", "pastry", "coffee", "oil", "sugar", "juice", "soda", "beer", "soup", "fish", "grapes"};
int values[47]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47};

int b[47];
float c[47];
for(k=0;k<47;k++)
{
	int count=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<6;j++)
		{
			if(values[k]==data[i][j])
			{
				count++;
			}
		}
	}
	b[k]=count;
	c[k]=(float)b[k]/100;
}
printf("Enter minimum support");
float min_support;
scanf("%f",&min_support);
if(min_support>1||min_support<0)
{
	printf("Enter corect support");
	exit(0);
}
printf("\n");
int temp1,temp2;
printf("\n Occurence of each item\n");
printf("\nItem ID\tIts occurence\n");
for(i=0;i<47;i++)
{
	printf("%d\t%d\n",values[i],b[i]);
}
printf("\n\n\n");
printf("\n Support of each item\n");
printf("\nItem ID\tIts support\n");
for(i=0;i<47;i++)
{
	printf("%d\t%.4f\n",values[i],c[i]);
}
for(i=0;i<47;i++)
{
	for(j=0;j<46;j++)
	{
		if(c[j]<c[j+1])
		{
			temp1=c[j];
			c[j]=c[j+1];
			c[j+1]=temp1;
			temp2=values[j];
			values[j]=values[j+1];
			values[j+1]=temp2;
		}
	}
}
int x=47;
for(i=0;i<47;i++)
{
	if(min_support>=c[i])
	{
		x=i+1;
		break;
	}
}
printf("\n\n\n");
printf("\n Support of items having more than min_support\n");
printf("\nItem ID\tIts support\n");
for(i=0;i<x;i++)
{
	printf("%d\t%.4f\n",values[i],c[i]);
}
}
