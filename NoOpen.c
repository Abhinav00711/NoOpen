#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
int printRandoms() 
{ 
    int num;
    num = (rand() % (2)); 
    return num;
}
int main()
{
	SetConsoleTitle("NoOpen");
	char str[20],ch,t='Y',a;  
	int i=0,j,key[8],len,n=0,s=0,n1=0,n2=0,d=0;
	system("COLOR B4");
	//Reading Password
	printf("\n Enter a Password :: ");
	while(a!=13)
	{
		a=getch();
		if(a!=13 && a!=8)  //13 for enter & 8 for backspace
		{
			putch('*');
			str[i] = a;
			i++;
		}
	}
	str[i] = '\0';
	printf("\nProcessing Password");
	for(i=0;i<3;i++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n\nPress any key to Continue...");
	//Initialising Lenght,Binary and String variable
	len=strlen(str);
	int bin[len][8],enc[len][8],dec[len][8];
	char c[len];
	//Converting to Binary
	for(i=0;i<len;i++) 
	{
    	ch = str[i];
		for(j=7;j>=0;--j)
		{
	    	if(ch & (1 << j)) 
			{
			    bin[i][j]=1;
			} 
			else 
			{
			    bin[i][j]=0;
			}
		}
	}
	//Generating random key
	srand(time(0)); 
	for(i=0;i<8;i++)
	{
		key[i]=printRandoms(); 
	}
	while(getch())
	{
		do
		{
		system("cls");
		system("COLOR 20");
		printf("\n\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		printf("\n\t1.Encode Password\n\t2.Decode Password(XOR Only)\n\t3.Exit");
		printf("\n\n\tEnter Your Choice :: ");
		scanf("%d",&n2);
		if(n2==1)
		{
			d=1;
		}
		if(d==0)
		{
			printf("You have to Encode first in order to Decode:)");
			Sleep(2000);
		}
		fflush(stdin);
		}while(d==0);
		switch(n2)
		{
			case 1:
				{
					system("cls");
					system("COLOR 74");
					while(t=='Y'||t=='y')
					{
						t='Y';
						printf("\n\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						printf("\n\t1.Binary Value\n\t2.Display Key\n\t3.Encode\n\t4.Go Back");
						printf("\n\n\tEnter Your Choice :: ");
						switch(getche())
						{
							case '1':
								{
									//Printing Binary Value
									printf("\n Binary Value :: ");
						            for(i=0;i<len;i++)  
						            {
							            for(j=7;j>=0;j--)
							            {
								            printf("%d",bin[i][j]);
							            }    
						            }
								    break;
								}
							case '2':
								{
								    //Printing key
						            printf("\n Key :: ");
					                for(i=0;i<8;i++)
					                    {
					    	                printf("%d",key[i]);
						                }	
						            break;    
								}
							case '3':
							 	{
									n=1;
									//Encoding using XOR Operator
						   			for(i=0;i<len;i++)
						   			{
						        		for(j=7;j>=0;j--)
						            	{	
						            		enc[i][j]=0;
											enc[i][j]=bin[i][j]^key[j];
										}
									}
									//Converting to String
					 	            for(i=0;i<len;i++)
					                {
							            s=0;
							            for(j=7;j>=0;j--)
							            {
							                s=s+(enc[i][j]*pow(2,j));
						                }
						                c[i]=s;
						            }
									//Printing Encoded Value
									printf("\n Encoded Value :: ");
						            for(i=0;i<len;i++)  
						            {
							            for(j=7;j>=0;j--)
							            {
								            printf("%d",enc[i][j]);
							            }    
						            }
						            printf("\n Encoded Password :: %s",c);
									break;
								}
							case '4':
								{
									if(n==0)
									{
										printf("\nPlease Encode first to be safe:)");
									}
									else
									{
										t='N';
									}
									break;
								}
							default:
							    {
							        printf("\nInvalid...");
									break;	
								}
					    }
					}
					break;
	            }
	        case 2:
			    {
			    	system("cls");
					system("COLOR 74");
					//Decoding XOR Encoded Value
			    	for(i=0;i<len;i++)
			    	{
			    		for(j=7;j>=0;j--)
			    		{
			    			dec[i][j]=0;
			    			dec[i][j]=enc[i][j]^key[j];
						}
					}
					//Converting to String
					for(i=0;i<len;i++)
			    	{
			    		s=0;
			    		c[i]=0;
						for(j=7;j>=0;j--)
			    		{
			    			s=s+(dec[i][j]*pow(2,j));
						}
						c[i]=s;
					}
					//Printing Decoded Value
					printf("\n Decoded Value :: ");
					for(i=0;i<len;i++)
			    	{
			    		for(j=7;j>=0;j--)
			    		{
			    			printf("%d",dec[i][j]);
						}
					}
					printf("\n Decoded Password :: %s",c);
			    	break;
				}
			case 3:
				{
					printf("\n\t Good Bye");
					for(i=0;i<10;i++)
					{
						Sleep(300);
						printf(".");
					}
					exit(0);
				}
			default:
				{
					printf("\nInvalid...");
					break;
				}
	    }
    }
	return 0;
}
