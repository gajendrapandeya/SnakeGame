#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int height=20,width=40,i,j,k;
int x,y,fruitx,fruity,gameover,score=0,key;
int tailx[100],taily[100],tail=0;
int base()
{
	system("cls");
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(i==0||i==height-1||j==0||j==width-1)
			printf("*");
		else
		{
			if(i==x && j==y)
			printf("O");
			else if(i==fruitx && j==fruity)
			printf("#");
			else
		    {
		    	int v=0;
		    	for(k=0;k<tail;k++)
		    	{
		    		if(i==tailx[k] && j==taily[k])
		    		{
					printf("o");
		    		v=1;
		    	}
				}
				if (v==0)
				printf(" ");
		}
		}
	}
	if(i==0)
     printf("\t\tScore:%d",score); 
	printf("\n");
	}
}
int setup()
{
	gameover=0;
	x=height/2;
	y=width/2;
	start1:
	fruitx=rand()%20;
	if(fruitx==0)
	goto start1;
	start2:
	fruity=rand()%40;
	if(fruity==0)
	goto start2;
	
}
int input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				key=1;
				break;
				case 'w':
					key=2;
					break;
					case 's':
						key=3;
						break;
						case 'd':
						key=4;
						break;
						case 'p':
							gameover=1;
							break;
						}
				}
				if(x<=0||x>=height || y>=width|| y<=0)
				{
				gameover=1;
			}
			for(i=0;i<tail;i++)
			{
				if(x==tailx[i] && y==taily[i])
				gameover=1;
			}
				if(x==fruitx && y==fruity)
				{
					start3:
	                fruitx=rand()%20;
	                 if(fruitx==0)
	                goto start3;
	                start4:
	                fruity=rand()%40;
	                 if(fruity==0)
	               goto start4;
					score+=10;
					tail++;
				}
		}
int logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<tail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}	
	switch (key)
	{
		case 1:
			y--;
			break;
			case 2:
				x--;
				break;
				case 3:
					x++;
					break;
					case 4:
						y++;
						break;
						default:
						break;
	}
		}		
int main()
{
	char ch;
	start5:
	setup();
	while(gameover!=1)
	{
	base();
	input();
	logic();
}
printf("\n\nYou scored %d points.\n",score);
getch();
printf("Do you want to continue?y/Y\n");
scanf("%c",&ch);
if(ch=='y'||ch=='Y')
{
	gameover=0;
	key=0;
	score=0;
	tail=0;
	goto start5;
}
}
