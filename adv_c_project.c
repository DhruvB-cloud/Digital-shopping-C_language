//supermarket Managment System
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//int j=0;
int num[10],qq[10];

struct pro
{
	int id;
	char name[10];
	char cat[10];
	int qua;
	int cost;
}p[10];
                                     ///////////////Module 2////////////////
									///////////Program used for declaration of elemets of the store
void asi()
{
	int i;
	for (i=0;i<10;i++)
	{
		p[i].id=i;
		p[i].qua=(rand() % 20) + 1; //Random function is used to declare the quantity of the item, in the range of 0-20
		p[i].cost=(rand()%20)+1;    //Random function is used to declare the cost of the item in the range of 0-20
	}
									/////////////Declaration of name of the product
    strcpy(p[0].name,"Chips");
    strcpy(p[1].name,"Biscuits");
    strcpy(p[2].name,"Globe");
    strcpy(p[3].name,"Hand Bag");
    strcpy(p[4].name,"Novel");
    strcpy(p[5].name,"cough syrup");
    strcpy(p[6].name,"Shoes");
    strcpy(p[7].name,"Slipper");
    strcpy(p[8].name,"syringe");
    strcpy(p[9].name,"Tablet");
    strcpy(p[0].cat,"Edible");
    strcpy(p[1].cat,"Edible");
	strcpy(p[2].cat,"Decor");
	strcpy(p[3].cat,"Luggage");
	strcpy(p[4].cat,"Decor");
	strcpy(p[5].cat,"Medic");
	strcpy(p[6].cat,"Footware");
	strcpy(p[7].cat,"Footware");
	strcpy(p[8].cat,"Medic");
	strcpy(p[9].cat,"Medic");
}

         							/////Final Output for the customers displaying the details of the product they bought//////
int bill()
{
	int i,tot=0;
	char po='n';
	printf("Your Bill details are \n\n");
	printf("Product_name           product_quantity        product_price\n\n");
	for (i=0;num[i]!=0;i++)
	{
		printf("%s                        %d                  %d      \n",p[num[i]].name,qq[i],p[i].cost *qq[i]);
		tot+=p[i].cost*qq[i];
	}
	printf("\nWant to add a poly-bag? (5 Rs) (y/n)\n\n");
	scanf("%s",&po);
	
	if (po='n')
		printf("Total number of items bought by you %d     \n Total bil %d\n\n\n\n\n",i,tot);
	else
		printf("Total number of items bought by you %d     \n Total bil %d\n\n\n\n\n",i,tot+5);
		return 0;
};

int add(int ab, int cd)
{
    int i,j=0;
	num[j]=ab;
	qq[j]=cd;
	for (i=0;i<10;i++)
	{
		if(p[i].id==ab)
			p[i].qua-=cd;
	}
	return 0;
};

int cus()
{
	int i,id,q;
	char c[10],ch='y';
	for(i=0;i<10;i++)
    printf("%d -> %s\n",i+1,p[i].cat);
	printf("Enter the category name to choose from :");
	scanf("%s",&c);
	printf("The category contains\n\n");
	printf("Product ID     Product name     Product quantity     Product price\n\n");
	for (i=0;i<10;i++)
		if((strcmp(p[i].cat,c)==0) && p[i].qua!=0)                                                      /////////////
			printf("   %d           %s          %d                  %d \n",p[i].id,p[i].name,p[i].qua,p[i].cost);
	while(ch=='y')
	{
	printf("Enter the Product ID of the product you want to buy : ");
	scanf("%d ",&id);
	printf("Enter the product quantity : ");
	scanf("%d ",&q);
	for (i=0;i<10;i++)
	{
		if (p[i].id==id)
		{
			if (p[i].qua>=q)
			{
 				add(p[i].id,p[i].qua);
				printf("Product have been added to your cart\n\n");
			}
			else
				printf("The quantity entered is invalid\n");
		}
	}
	printf("\nwant to shop more? (y/n)\n");
	scanf("%s\n\n",&ch);
	}
    bill();
   return 0;
}

int dis()
{
	int i;
		printf("No 		prodct_ID 		product_Name 	Product_quantity\n");
	for (i=0;i<10;i++)
		printf(" %d 		 %d 	    	%s 			 	%d 		\n",i,p[i].id,p[i].name,p[i].qua);
	return 0;
}

int sub()
{
	int i,d,q,ch;
	char s='y';
	while(s=='y')
	{
	printf("\t\t\tWelcome seller\n\n\n\n");
	printf("press 1 to add a quantity\n");
	printf("press 2 to delete a product\n");
	printf("press 3 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	printf("Enter the product ID\n");
				scanf("%d",&d);
				printf("Enter the quantity\n");
				scanf("%d",&q);
				for (i=0;i<10;i++)
					if(p[i].id==d)
						p[i].qua+=q;
				break;
		case 2: printf("Enter the product ID\n");
				scanf("%d",&d);
				for(i=0;i<10;i++)
					if (p[i].id==d)
						p[i].qua=0;
				break;
		case 3:
				break;
		default: printf("wrong number entered\n");
	}
	printf("Want to enter more(Y/N)");
	scanf("%s",&s);

}
	return 0;
};

int rema()
{
	int i,j;
	printf("The Quantity sold today are\n");
		printf("Sr.no        ID 		Name 		sold_quantity 		cost\n");
	for (i=0;num[i]=0;i++)
		printf("%d 		    %d   		%s 		  	%d 					%d  \n",i,p[i].id,p[i].name,20- p[i].qua,p[i].cost);
	return 0;
}

int emploee()
{
	FILE *fptr;
        fptr = fopen("employee_details.txt", "w");
        fprintf(fptr, "Name    Age   Address  \n");
	char a,b,d='y';
	int ab;
	while(d=='y')
	{
		printf("Enter the name : ");
		scanf("%s\n\n",a);
		printf("Enter the Age : ");
		scanf("%s\n\n",ab);
		printf("enter address : ");
		scanf("%s\n\n",b);
		fprintf(fptr,"%s",a);
		fprintf(fptr,"%s",ab);
		fprintf(fptr,"%s",b);
			fclose(fptr);
	}
	return 0;
}

int show()
{
	char c;
	FILE *file_pointer;
	file_pointer = fopen("employee_details.txt", "r");
        while ((c = getc(file_pointer)) != EOF)
            printf("%c", c);
     fclose(file_pointer);
	return 0;
}

int sman()
{
	int ch,v,a;
	printf("\n\nWelcome Manager\n\n");
	printf("Select the option you want to choose\n");
	printf("1. To view all the product remaining\n");
	printf("2. To view the total sale \n");
	printf("3. To enter a new employee detail \n");
	printf("4. to viw emploee list\n");
	printf("5. To exit to main menu\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: dis();
				break;
		case 2: rema();
				break;
		case 3: emploee();
				break;
		case 4: show();
				break;
		case 5:
				break;
		default: printf("Wrong number entered \n");
	}
	return 0;
}


int main()
{
	asi();

	int i=0,c=0;
	char cho='y',use,pass;
	while(cho=='y')
	{
		printf("                              Welcome to the super market                   \n\n\n\n");
		printf("                             Press 1 if you are a Customer 					\n");
		printf("                             Press 2 if you are a seller					\n");
		printf("                             Press 3 if you are the manager					\n");
		printf("                             Press 4 if you want to exit the shop			\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: cus();
					printf("Thank you for your visit\n");
					break;
			case 2: sub();
					break;
			case 3: sman();
					break;
			case 4: cho='n';
					break;
			default:
					printf("Wrong number selected\n");
		}
		//clrscr();
	}

	return 0;
}
