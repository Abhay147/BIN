#include<stdio.h>
#include<conio.h>
void write(void)
{
		FILE *fs;
		struct marks
		{
			char name[30];
			int sno,sube,subh,subm,subs,subp;
		}m;
		m.sno=1;
		fs=fopen("Marks.txt","wb");
		while(m.sno<=5)
		{
			fflush(stdin);
			puts("Enter your name: ");
			gets(m.name);
			puts("Enter your Eng. Marks: ");
			scanf("%d",&m.sube);
			puts("Enter your Hindi Marks: ");
			scanf("%d",&m.subh);
			puts("Enter your Maths Marks: ");
			scanf("%d",&m.subm);
			puts("Enter your Science Marks: ");
			scanf("%d",&m.subs);
			puts("Enter your Social Marks: ");
			scanf("%d",&m.subp);
			fwrite(&m,sizeof(m),1,fs);
			m.sno++;
		}
		 fclose(fs);
		 getch();
}
void read(void)
{
	FILE *fs;
	struct marks
		{
			char name[30];
			int sno,sube,subh,subm,subs,subp;
		}m;
	clrscr();
	fs = fopen("Marks.txt","rb");
	while(fread(&m,sizeof(m),1,fs) == 1)
	printf("\n%d-%s-%d-%d-%d-%d-%d",m.sno,m.name,m.sube,m.subh,m.subm,m.subs,m.subp);
}
void main()
{
	//write();
	read();
}






