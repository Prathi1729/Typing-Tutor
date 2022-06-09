#include<iostream>
#include<stdio.h>
#include<iomanip.h> 
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<time.h>
using namespace std;
void tips(void);
void practice(void);
void test(void);

int main()
{
	char choice;
	
	while(1)
	{
		clrscr();
		gotoxy(33,5);
		cout<<"Typing Tutor";
		gotoxy(30,8);
		cout<<"__________________";
		cout<<"1 - Typing Tips";
		gotoxy(30,10);
		cout<<"2 - Typing Practice";
		gotoxy(30,12);
		cout<<"3 - Typing Test";
		gotoxy(30,14);
		cout<<"4 - Exit";
		gotoxy(30,30);
		
		choice=getch();
		switch(choice)
		{
			case('1'): tips();
					    break;
			case('2'): practice();
					    break;
			case('3'): test();
					    break;
			case('4'): clrscr();
					    exit(1);
					    break;
			default: gotoxy(30,30);
						clreol();
						cout<<"Invalid choice";
						gotoxy(30,31);
						cout<<"Press any key to continue...";
						getch();
		}
	}
}

void tips(void)
{
	clrscr();
	gotoxy(2,3);
	cout<<"Typing tips";
	
	gotoxy(2,4);
	cout<<"________________";
	
	gotoxy(2,4);
	cout<<"1.First and foremost, make sure that you are seated comfortably with the ";
	gotoxy(5,7);
	cout<<"Keyboard placed at appropriate height.";
	
	gotoxy(2,9);
	cout<<"2. Use all your fingers while typing, with the thumb being used for pressing";
	gotoxy(5,10);
	cout<<"the space bar.";
	gotoxy(2,12);
	cout<<"3. Explore the various keys present on the keyboard and gradually try to build ";
	gotoxy(5,13);
	cout<<"your finger memory.";
	
	gotoxy(2,18);
	cout<<"5. Practice as much as you can to build your typing skills.";
	
	gotoxy(30,30);
	cout<<"Press any key to go back...";
	getch();
}

void practice(void)
{
	char ch1,ch2;
	int count,noc;
	fstream fptr1,fptr2;
	
	while(1)
	{
		count=0;
		noc=0;
		clrscr();
		fptr1.open("practice.txt",ios::in);
		
		gotoxy(2,2);
		while(fptr1)
		{
			fptr1.get(ch1);
			cout<<ch1;
			noc++;
		}
	fptr1.close();
	
	fptr2.open("type.txt",ios::out);
	
	gotoxy(2,8);
	
	time_t t1;
	time(&t1);
	
	for(int i=0;i<44;i++)
	{
		ch2=getche();
		fptr2.put(ch2);
	}
	
	time_t t2;
	time(&t2);
	
	fptr2.close();
	
	fptr1.open("practice.txt",ios::in);
	fptr2.open("type1.txt",ios::in);
	
	gotoxy(25,25);
	cout<<"Typing Practice Results...";
	
	gotoxy(25,27);
	int flag=0;
	int flag2=0;
	int flag3=0;
	for(i=0;i<<4;i++)
	{
		fptr1.get(ch1);
		fptr1.get(ch2);
		if(flag==5)
		{
			while(1)
			{
				if(flag2==0)
					fptr1.get(ch1);
				if(flag3==0)
					fptr2.get(ch2);
				if(ch1==' ')
					flag2=1;
				if(ch2==' ')
					flag3=1;
				if(flag2==1 && flag3==1)
					break;
			}
			
			flag=0;
		}
		
		if(ch1==ch2)
		{
			flag=0;
			textcolor(WHITE);
			cprintf("%c",ch2);
		}
		else
		{
			count++;
			flag++;
			textcolor(RED);
			cprintf("%c",ch2);
		}
	}
	
	textcolor(WHITE);
	gotoxy(25,29);
	cout<<setprecision(2);
	cout<<"Speed - "<<(9*60)/difftime(t2,t1)<<"words per min";
	
	gotoxy(25,31);
	cout<<"Accuracy - "<<(float((noc-count))/float(noc))*100.00<<" %";
	fptr1.close();
	fptr2.close();
	
	while(1)
	{
		gotoxy(25,34);
		cout<<"Practice Again? (Y/N)";
		ch1=getch();
		if(toupper(ch1)=='Y')
			break;
		else if(toupper(ch1)=='N')
			return;
	}
	}
}

void test(void)
{
	char ch1,ch2;
	int count,noc;
	fstream fptr1,fptr2;
	
	while(1)
	{
		count=0;
		noc=0;
		clrscr();
		
		fptr1.open("test.txt",ios::in);
		gotoxy(1,2);
		while(fptr1)
		{
			fptr1.get(ch1);
			cout<<ch1;
			if(ch1=='\n')
				cout<<"\n";
			noc++;
		}
	fptr1.close();
	
	fptr2.open("type2.txt",ios::in);
	
	gotoxy(1,13)
	cprintf("Type the above text");
	
	gotoxy(1,17);
	
	time_t t1;
	time(&t1);
	
	for(int i=0;i<405;i++)
	{
		ch2=getche();
		fptr2.put(ch2);
	}
	time_t t2;
	time(&t2);
	
	fptr2.close();
	
	fptr1.open("test.txt",ios::in);
	fptr2.open("type2.txt",ios::in);
	
	gotoxy(1,26);
	cprintf("Typing Test Results...");
	
	gotoxy(1,29);
	int flag=0;
	int flag2=0;
	int flag3=0;
	for(i=0;i<405;i++)
	{
		fptr1.get(ch1);
		fptr2.get(ch2);
		if(flag==5)
		{
			while(1)
			{
				if(flag2==0)
					fptr1.get(ch1);
				if(flag3==0)
					fptr2.get(ch2);
				if(ch1==' ')
					flag2=1;
				if(ch2==' ')
					flag3=1;
				if(flag2==1 && flag3==1)
					break;
			}
		flag=0;
		}
	
	if(ch1==ch2)
	{
		flag=0;
		textcolor(WHITE);
		cprintf("%c",ch2);
	}
	else
	{
		count++;
		flag++;
		textcolor(RED);
		cprintf("%c",ch2);
	}
	}
	textcolor(WHITE);
		gotoxy(1,37);
		
		cout<<setprecision(2);
		cout<<"Speed - "<<(71*60)/difftime(t2,t1)<<"words per min";
		
		gotoxy(1,39);
		cout<<"Accuracy - "<<float((noc-count))/float(noc)*100.00<<"%";
		
		fptr1.close();
		fptr2.close();
		
		while(1)
		{
			gotoxy(1,42);
			cout<<"Take test again? (Y/N)";
			ch1=getch();
			if(toupper(ch1)=='Y')
				break;
			else if(toupper(ch1)=='N')
				return;
		}
	}
}


















