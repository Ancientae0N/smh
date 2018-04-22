#include<stdio.h>
#include<stdlib.h>
#define KCYN  "\x1B[36m"
#define KNRM  "\x1B[0m"

int i,j,ec,fg,ec2;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;
void Create();
void Append();
void Delete();
void Display();

int main()
{
	do 
	{
	  //clrscr();
	  printf(KCYN"\n\t\t ####### Hash Editor #######");
	  printf(KNRM"\n\n\tMenu:\n\t-----\n ");
	  printf("\n\t1.Create\n\t2.Display\n\t3.Append\n\t4.Delete\n\t5.Get out!\n");
	  printf("\n\tEnter your choice: ");
	  scanf("%d",&ec);
	  switch(ec)
	  {
	   case 1:
		 Create();
		 break;
	   case 2:
		 Display();
		 break;
	   case 3:
		 Append();
		 break;
	   case 4:
		 Delete();
		 break;
	   case 5:
		 exit(0);
	   default:
		 printf("Hash editor does not accept this option, closing.....\n");
		 exit(0);
	  }
	 }while(1);
}

void Create()
{
	 fp1=fopen("temp.txt","w");
	 printf("\n\tEnter the text and press '$' to save\n\n");
	 
	 while(1)
	 {
	  	c=getchar();
	 	fputc(c,fp1);
	  	if(c == '$')
	  	{
	   	    fclose(fp1);
		    printf("\n\tEnter then new filename: ");
		    scanf("%s",fn);
		    
	            fp1=fopen("temp.txt","r");
		    fp2=fopen(fn,"w");
		    	int ch = getc(fp1);
			while(ch!=EOF && ch!='$')
	   		{
				putc(ch, fp2);
				ch = getc(fp1);
	   		}
	   		fclose(fp2);
	   		break;
	  	}
	}
}

void Display()
{
	  printf("\n\tEnter the file name: ");
	  scanf("%s",fn);
	  fp1=fopen(fn,"r");
	  
	  if(fp1==NULL)
	  {
	   	printf("\n\tFile not found!");
	   	goto end2;
	  }
	  
	  int ch = getc(fp1);
	  while(ch!=EOF)
	  {
		printf("%c", ch);
		ch = getc(fp1);
	   }
	   
	
	end1:
	  fclose(fp1);
	end2:
	  printf("\n\n\tPress any key to continue...");
	  //getch();
}

void Delete()
{
	  printf("\n\tEnter the file name: ");
	  scanf("%s",fn);
	  fp1=fopen(fn,"r");
	  
	  if(fp1==NULL)
	  {
	   printf("\n\tFile not found!");
	   goto end2;
	  }
	  
	  fclose(fp1);
	  
	  if(remove(fn)==0)
	  {
	   	printf("\n\n\tFile has been deleted successfully!");
	   	goto end2;
	  }
	  else
	   printf("\n\tError!\n");
	end2: printf("\n\n\tPress any key to continue...");
	  //getch();
}

void Append()
{
	  printf("\n\tEnter the file name: ");
	  scanf("%s",fn);
	  fp1=fopen(fn,"r");
	  
	  if(fp1==NULL)
	  {
	   	printf("\n\tFile not found!");
	   	goto end3;
	  }
	  
	  while(!feof(fp1))
	  {
	   	c=getc(fp1);
	   	printf("%c",c);
	  }

	  fclose(fp1);
	  printf("\n\tType the text and press 'Ctrl+S' to append.\n");
	  
	  fp1=fopen(fn,"a");
	  
	  while(1)
	  {
		   	c=getchar();
		   	if(c=='.')
				goto end3;
		   	if(c==13)
		   	{
				c='\n';
				printf("\n\t");
				fputc(c,fp1);
		   	}
		   	else
		   	{
				//printf("%c",c);
				fputc(c,fp1);
		   	}
	  }
	end3: fclose(fp1);
	  //getch();
}



