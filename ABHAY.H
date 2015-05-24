#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

void draw_box(int tx,int ty,int bx,int by,int num);
void write_text(int x,int y,char str[]);
void load_dots(int x, int y, int num, int time);
int select_option(int x, int y, int no_opt, int gap);
char* text_box(int x,int y,int no_char);
char* pass_box(int x,int y,int no_char,char ch);
void disp_msg(char str[]);
void clear_block(int tx, int ty, int bx, int by);
char* para_box(int tx,int ty, int bx, int by, int no_char);
void matrix(int len);
void show_date(int x, int y);
void load_circle(int x, int y, int times,char str[]);
int wrap_text(int x, int y, int max, char str[]);

void draw_box(int tx,int ty,int bx,int by,int num)
{
	int i;
	if(num == 1)
	{
		gotoxy(tx,ty);printf("%c",218);
		gotoxy(bx,ty);printf("%c",191);
		gotoxy(tx,by);printf("%c",192);
		gotoxy(bx,by);printf("%c",217);
		for(i = tx+1 ; i < bx ; i++)
		{
			gotoxy(i,ty);printf("%c",196);
			gotoxy(i,by);printf("%c",196);
		}
		for(i = ty+1 ; i < by ; i++)
		{
			gotoxy(tx,i);printf("%c",179);
			gotoxy(bx,i);printf("%c",179);
		}
	}
	else if(num ==  2)
	{
		gotoxy(tx,ty);printf("%c",201);
		gotoxy(bx,ty);printf("%c",187);
		gotoxy(tx,by);printf("%c",200);
		gotoxy(bx,by);printf("%c",188);
		for(i = tx+1 ; i < bx ; i++)
		{
			gotoxy(i,ty);printf("%c",205);
			gotoxy(i,by);printf("%c",205);
		}
		for(i = ty+1 ; i < by ; i++)
		{
			gotoxy(tx,i);printf("%c",186);
			gotoxy(bx,i);printf("%c",186);
		}

	}
}

void write_text(int x,int y,char str[])
{
	gotoxy(x,y);
	cprintf("%s",str);
}

void load_dots(int x, int y, int num, int time)
{
	int i,j;
	for(i = 0 ; i < time; i++)
	{
		for(j = 0 ; j < num ; j ++)
		{
			gotoxy(x+j,y);
			printf(".");
			delay(100*j);
		}
		for(j = 0; j < num ; j++)
		{
			gotoxy(x+j,y);
			printf(" ");
		}
	}

}

int select_option(int x, int y, int no_opt, int gap)
{
	int i,curr_opt = 0,j;
	char ch;
	gotoxy(x,y);
	printf("%c",26);
	for(;;)
	{
		for(j = 0 ; j < no_opt ; j++)
		{
			gotoxy(x,y+j+(j*gap));
			printf(" ");
			if(j == curr_opt)
			printf("\b%c",26);

		}
		ch = getch();
		if(ch == 80)
		{
			curr_opt++;
			curr_opt %= no_opt;
		}
		else if(ch == 72)
		{
			curr_opt--;
			if(curr_opt < 0)
				curr_opt = no_opt-1;
			else
				curr_opt %= no_opt;
		}
		else if(ch == 13)
			return curr_opt;
		else if(ch == 27)
			return 27;
	}
}

char* text_box(int x, int y, int no_char)
{
	int i,j;
	char str[100];
	draw_box(x-1,y-1,x+no_char+1,y+1,1);
	gotoxy(x,y);
	for(i = 0; i < no_char; i++)
	{
		str[i] = getch();
		if(str[i] == 27)
		{
			str[0] = 27;
			break;
		}
		if(str[i] == 13)
		{
			if(i == 0)
			{
				i--;
				continue;
			}
			else
			{
				str[i] = '\0';
				break;
			}
		}
		else if(str[i] == 8)
		{
			if(i == 0)
			{
				i = -1;
				continue;
			}
			i -= 2;
			printf("\b \b");
		}
		if(i < no_char-1)
		{
			gotoxy(x,y+2);
			printf("                      ");
			gotoxy(x+i,y);
		}
		else if(i >= no_char-1)
		{
			gotoxy(x,y+2);
			printf("Max characters reached");
			gotoxy(x+no_char-1,y);
			i = no_char-2;
			continue;
		}
		if(i >= 0)
			printf("%c",str[i]);
	}
	return str;
}


char* pass_box(int x, int y, int no_char, char ch)
{
	int i,j;
	char str[100];
	draw_box(x-1,y-1,x+no_char+1,y+1,1);
	gotoxy(x,y);
	for(i = 0; i < no_char; i++)
	{
		str[i] = getch();
		if(str[i] == 27)
		{
			str[0] = 27;
			break;
		}
		if(str[i] == 13)
		{
			if(i == 0)
			{
				i--;
				continue;
			}
			else
			{
				str[i] = '\0';
				break;
			}
		}
		else if(str[i] == 8)
		{
			if(i == 0)
			{
				i = -1;
				continue;
			}
			i -= 2;
			printf("\b \b");
		}
		if(i < no_char-1)
		{
			gotoxy(x,y+2);
			printf("                      ");
			gotoxy(x+i,y);
		}
		else if(i >= no_char-1)
		{
			gotoxy(x,y+2);
			printf("Max characters reached");
			gotoxy(x+no_char-1,y);
			i = no_char-2;
			continue;
		}
		if(i >= 0)
			printf("%c",ch);
	}
	return str;
}

void disp_msg(char str[])
{
	int len=strlen(str);
	clrscr();
	draw_box(1,1,79,25,2);
	write_text(37-(len/2),12,str);
	delay(300);
}

void clear_block(int tx, int ty, int bx, int by)
{
	int i,j;
	for(i = 0 ; i < by-ty ; i++)
	{
		for(j = 0 ; j < bx-tx ; j++)
		{
			gotoxy(tx+j,ty+i);
			printf(" ");
		}
	}
}

char* para_box(int tx, int ty, int bx, int by, int no_char)
{
	int i;
	char str[10000];
	draw_box(tx-1,ty-1,bx,by,1);
	for(i = 0; i < 10000; i++)
	{
		gotoxy(bx-5,ty-1);
		printf("%4d",no_char-i-1);
		gotoxy(tx+(i % (bx-tx)),ty+(i/(bx-tx)));
		fflush(stdin);
		str[i] = getch();
		if(str[i] == 27)
		{
			str[0] = 27;
			return str;
		}
		if(str[i] == 8)
		{
			if(i <= 0)
			{
				i = -1;
				continue;
			}
			else
			{
				if(i % (bx-tx) == 0)
					gotoxy(tx+(bx-tx),ty+(i/(bx-tx))-1);
				else
					gotoxy(tx+(i % (bx-tx)),ty+(i/(bx-tx)));
				printf("\b \b");
				i-=2;
			}
		}
		else if(str[i] == 13)
		{
			if(i <= 0)
			{
				i = -1;
				continue;
			}
			else
			{
				str[i] = '\0';
				break;
			}
		}
		if(i < no_char-1 && i >= 0)
		{
			gotoxy(tx,by+2);
			printf("                      ");
			gotoxy(tx+(i % (bx-tx)),ty+(i/(bx-tx)));
			printf("%c",str[i]);
		}
		else if(i >= no_char-1)
		{
			gotoxy(tx,by+2);
			printf("Max characters reached");
			gotoxy(tx+(i % (bx-tx)),ty+(i/(bx-tx)));
			i = no_char-2;
			continue;
		}
	}
	return str;
}
void matrix(int len)
{
	int i,j,k;
	textcolor(3);
	for(k = 0 ; k < len ; k++)
	for(i = 0 ; i < 30000 ; i++,j++)
	{
		cprintf("%d ",j);
	}
	textcolor(7);
	clrscr();
}

void show_date(int x,int y)
{
	struct date d;
	char date[11];
	getdate(&d);
	sprintf(date,"%d-%d-%d",d.da_day,d.da_mon,d.da_year);
	write_text(x,y,date);
}

/* void load_circle(int x, int y, int times, int pause, char ch[])
{
	int i,j;
	for(j = 0 ; j < times; j++)
	{
		for(i = 0 ; i < 10 ; i++)
		{
			textcolor(8);
			write_text(x+3,y+0,ch);
			write_text(x+5,y+0,ch);
			write_text(x+7,y+1,ch);
			write_text(x+8,y+2,ch);
			write_text(x+7,y+3,ch);
			write_text(x+5,y+4,ch);
			write_text(x+3,y+4,ch);
			write_text(x+1,y+3,ch);
			write_text(x+0,y+2,ch);
			write_text(x+1,y+1,ch);
			textcolor(7);
			switch(i)
			{
			case 0:
				write_text(x+3,y+0,ch);
				break;
			case 1:
				write_text(x+5,y+0,ch);
				break;
			case 2:
				write_text(x+7,y+1,ch);
				break;
			case 3:
				write_text(x+8,y+2,ch);
				break;
			case 4:
				write_text(x+7,y+3,ch);
				break;
			case 5:
				write_text(x+5,y+4,ch);
				break;
			case 6:
				write_text(x+3,y+4,ch);
				break;
			case 7:
				write_text(x+1,y+3,ch);
				break;
			case 8:
				write_text(x+0,y+2,ch);
				break;
			case 9:
				write_text(x+1,y+1,ch);
				break;
			}
			gotoxy(79,25);
			delay(pause);
		}
	}
}  */
void load_circle(int x, int y, int times,char str[])
{
	int gdriver = DETECT,gmode,error;
	int i;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	clrscr();
	cleardevice();
	//circle(50,50,50);
	//setcolor(15);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
	for(i = (8*times); i > 0 ; i--)
	{

		outtextxy(x-(strlen(str)*17),y-25,str);
		arc(x,y,i*45-25,(i*45)+45,20);
		arc(x,y,i*45-25,(i*45)+45,19);
		arc(x,y,i*45-25,(i*45)+45,18);
		arc(x,y,i*45-25,(i*45)+45,17);
		arc(x,y,i*45-25,(i*45)+45,16);
		delay(100);
		cleardevice();
	}

}

/* void wrap_text(int x, int y, int max, char str[])
{
	int len =strlen(str);
	int i;
	for(i = 0; i < len ; i++)
	{
		gotoxy(x+(i%max),y+(i/max));
		printf("%c",str[i]);
	}
} */

int wrap_text(int x, int y, int max, char str[])
{
	int i,j;
	int count=1,buffer=0;
	gotoxy(x,y);
	for(i = 0; i < strlen(str); i++)
	{
		printf("%c",str[i]);
		if((i+buffer)%max == 0 && i > 1)
		{
			for(j = 0; str[i-j] != ' '; j++)
			{
				printf("\b \b");
			}
			buffer+=j;
			gotoxy(x-1,++y);
			count++;
			for( ; j != 0; j--)
			{
				printf("%c",str[i-j]);
			}
			printf("%c",str[i-j]);
		}
	}
	return count;
}