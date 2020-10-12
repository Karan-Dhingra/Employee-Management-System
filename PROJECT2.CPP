#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
void welcome();
void password();
void loading();
void thankyou();
void heading()
{
  settextstyle(1,0,2);
  setcolor(4);
  outtextxy(130,50,"EMPLOYEE MANAGEMENT SYSTEM");
}
void design()
{
  setbkcolor(1);
  setcolor(15);
  setfillstyle(6,4);
  rectangle(30,30,610,450);
  floodfill(11,11,15);
  setfillstyle(6,4);
  rectangle(10,10,630,470);
  floodfill(1,1,15);
}
void add();
void del();
void view();
void modify();
void search();
class employee
{
  int empno;
  char salary[100];
  char name[100];
  char email[100];
  char mobile[100];
  public:
  void set()
  {
     cleardevice();
     design();
     outtextxy(100,149,"Enter the employee number: ");
     gotoxy(41,10);
     cin>>empno;
     outtextxy(100,180,"Enter the name of employee: ");
     gotoxy(42,12);
     cin>>name;
     outtextxy(100,211,"Enter the salary of employee: ");
     gotoxy(43,14);
     cin>>salary;
     outtextxy(100,244,"Enter Email id of employee: ");
     gotoxy(42,16);
     cin>>email;
     outtextxy(100,276,"Enter mobile number of employee: ");
     gotoxy(46,18);
     cin>>mobile;
  }
  void show()
  {
    cleardevice();
    design();
    char ch1[100],ch2[100];
    outtextxy(100,150,"Employee number is: ");
    itoa(empno,ch1,10);
    outtextxy(280,150,ch1);
    outtextxy(100,170,"Name of employee is: ");
    outtextxy(290,170,name);
    outtextxy(100,190,"Salary of employee is: ");
    outtextxy(300,190,salary);
    outtextxy(100,210,"Email id of employee is: ");
    outtextxy(315,210,email);
    outtextxy(100,230,"Mobile no. of employee is: ");
    outtextxy(325,230,mobile);
    getch();
  }
  void change()
  {
    cleardevice();
    design();
    int choice;
    outtextxy(200,150,"******************************");
    outtextxy(200,170,"**What do you want to change**");
    outtextxy(200,190,"******************************");
    outtextxy(200,210,"**        1.Name            **");
    outtextxy(200,230,"**        2.Salary          **");
    outtextxy(200,250,"**        3.Email id        **");
    outtextxy(200,270,"**        4.Mobile no.      **");
    outtextxy(200,290,"******************************");
    outtextxy(200,310,"******************************");
    outtextxy(200,357,"Enter your choice: ");
    gotoxy(45,23);
    cin>>choice;
    cleardevice();
    design();
    switch(choice)
    {
      case 1:
      {
	outtextxy(100,148,"Enter new name: ");
	gotoxy(29,10);
	cin>>name;
	break;
      }
      case 2:
      {
	outtextxy(100,148,"Enter new salary: ");
	gotoxy(30,10);
	cin>>salary;
	break;
      }
      case 3:
      {
	outtextxy(100,148,"Enter new Email: ");
	gotoxy(30,10);
	cin>>email;
	break;
      }
      case 4:
      {
	outtextxy(100,148,"Enter new mobile no.: ");
	gotoxy(31,10);
	cin>>mobile;
	break;
      }
      default:
      outtextxy(100,148,"WRONG CHOICE");
    }
  }
  int getempno()
  {
    return empno;
  }
};
void menu()
{
  while(1)
  {
    cleardevice();
    design();
    heading();
    setcolor(15);
    settextstyle(0,0,0);
    outtextxy(128,120,"*=========================================*");
    outtextxy(128,135,"*=========================================*");
    outtextxy(128,150,"*         What do you want to do?         *");
    outtextxy(128,165,"*            1. Add the Data              *");
    outtextxy(128,180,"*            2. View the Data             *");
    outtextxy(128,195,"*            3. Modify the Data           *");
    outtextxy(128,210,"*            4. Search the Data           *");
    outtextxy(128,225,"*            5. Delete the Data           *");
    outtextxy(128,240,"*            6. Exit                      *");
    outtextxy(128,255,"*******************************************");
    int choice;
    char ch[10];
    outtextxy(128,276,"Enter your choice:  ");
    gotoxy(36,18);
    cin>>choice;
    switch(choice)
    {
      case 1: add();
      break;
      case 2: view();
      break;
      case 3: modify();
      break;
      case 4: search();
      break;
      case 5: del();
      break;
      case 6: thankyou();
      default: outtextxy(128,300,"Invalid choice try again...");
      break;
    }
    thankyou();
    getch();
  }
}
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  welcome();
  password();
  loading();
  cleardevice();
  menu();
//  getch();
  cleardevice();
  thankyou();
//  getch();
}
void add()
{
  cleardevice();
  design();
  employee e;
  fstream f;
  f.open("employee_data.dat",ios::app|ios::binary);
  if(!f)
  {
    outtextxy(128,180,"Unable to create file try again...");
    getch();
    exit(0);
  }
  int n,i;
  outtextxy(128,180,"Enter the number of employees you want to save: ");
  gotoxy(65,12);
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cout<<"\n";
    e.set();
    f.write((char*)&e,sizeof(e));
  }
  f.close();
  outtextxy(180,390,"DATA SAVED SUCCESFULLY");
}
void view()
{
  cleardevice();
  design();
  employee e;
  fstream f;
  f.open("employee_data.dat",ios::in|ios::binary);
  if(!f)
  {
    outtextxy(128,180,"Unable to create file try again...");
    getch();
    exit(0);
  }
  int record=0;
  f.read((char*)&e,sizeof(e));
  while(!f.eof())
  {
    e.show();
    record++;
    f.read((char*)&e,sizeof(e));
    cleardevice();
  }
  f.close();
  design();
  char ch[10];
  itoa(record,ch,10);
  char ch2[]="Total Numbers of record:-  ";
  strcat(ch2,ch);
  outtextxy(100,230,ch2);
}
void search()
{
  cleardevice();
  design();
  employee e;
  fstream f;
  f.open("employee_data.dat",ios::in|ios::binary);
  if(!f)
  {
    outtextxy(128,180,"Unable to create file try again...");
    getch();
    exit(0);
  }
  int empno,flag=0;
  outtextxy(128,180,"Enter the Employee no.you want to search: ");
  gotoxy(59,12);
  cin>>empno;
  f.read((char*)&e,sizeof(e));
  while(!f.eof())
  {
    if(e.getempno()==empno)
    {
      outtextxy(140,210,"SEARCHING IS SUCCESFULL");
      e.show();
      flag=1;
      break;
    }
    f.read((char*)&e,sizeof(e));
  }
  if(flag==0)
  {
    char ch[10];
    char ch1[]="Record with employee number ";
    char ch2[]=" is not available";
    itoa(empno,ch,10);
    strcat(ch1,ch);
    strcat(ch1,ch2);
    outtextxy(140,210,ch1);
  }
  f.close();
  getch();
}
void modify()
{
  cleardevice();
  design();
  employee e;
  fstream f;
  f.open("employee_data.dat",ios::in|ios::out|ios::binary);
  if(!f)
  {
    outtextxy(128,180,"Unable to create file try again...");
    getch();
    exit(0);
  }
  int empno,flag=0;
  outtextxy(128,180,"Enter employee number you want to modify: ");
  gotoxy(58,12);
  cin>>empno;
  f.read((char*)&e,sizeof(e));
  while(!f.eof())
  {
    if(e.getempno()==empno)
    {
      e.show();
      cleardevice();
      design();
      outtextxy(128,150,"Do you want to change data");
      outtextxy(128,170,"Press Y for YES");
      outtextxy(128,190,"Press N for NO");
      outtextxy(128,212,"Write your Answer: ");
      char ch;
      gotoxy(36,14);
      cin>>ch;
      flag=1;
      if(ch=='Y'||ch=='y')
      {
	e.change();
	f.seekp(f.tellg()-sizeof(e));
	f.write((char*)&e,sizeof(e));
	outtextxy(150,170,"MODIFICATION SUCCESFULL");
	break;
      }
      else
      {
	outtextxy(150,170,"NO MODIFICATION MADE");
      }
    }
    f.read((char*)&e,sizeof(e));
  }
  if(flag==0)
  {
    outtextxy(128,200,"No record available");
  }
  f.close();
}
void del()
{
  cleardevice();
  design();
  employee e;
  fstream f;
  fstream o;
  o.open("new.dat",ios::out|ios::binary);
  f.open("employee_data.dat",ios::in|ios::binary);
  if(!f)
  {
    outtextxy(128,180,"Unable to create file try again...");
    getch();
    exit(0);
  }
  int empno,flag=0;
  char ch;
  outtextxy(40,180,"Enter the employee number of employee whoose data you want to delete: ");
  gotoxy(75,12);
  cin>>empno;
    f.read((char*)&e,sizeof(e));
    while(!f.eof())
    {
      if(e.getempno()==empno)
      {
	e.show();
	cleardevice();
	design();
	outtextxy(128,150,"DO you want to DELETE your data");
	outtextxy(128,170,"Press Y for YES ");
	outtextxy(128,190,"Press N for NO ");
	outtextxy(128,210,"Your CHOICE is: ");
	flag=1;
      }
      f.read((char*)&e,sizeof(e));
    }
    f.close();
    if(flag==0)
    {
      cleardevice();
      design();
      outtextxy(200,180,"INCORRECT EMPLOYEE NUMBER");
    }
    if(flag==1)
    {
      gotoxy(34,14);
      cin>>ch;
      if(ch=='Y'||ch=='y')
      {
	f.open("employee_data.dat",ios::in|ios::binary);
	f.read((char*)&e,sizeof(e));
	while(!f.eof())
	{
	  if(empno!=e.getempno())
	  {
	    o.write((char*)&e,sizeof(e));
	  }
	  f.read((char*)&e,sizeof(e));
	}
	f.close();
	o.close();
	remove("employee_data.dat");
	rename("new.dat","employee_data.dat");
	cleardevice();
	design();
	outtextxy(200,240,"DELETED SUCCESFULLY");
      }
      else
      {
	cleardevice();
	design();
	outtextxy(220,240,"NO RECORD FOUND");
      }
   }
}
void welcome()
{
  cleardevice();
  rectangle(30,30,610,450);
  setbkcolor(1);
  setfillstyle(8,5);
  rectangle(10,10,630,470);
  floodfill(11,11,15);
  setfillstyle(5,5);
  rectangle(10,10,630,470);
  floodfill(1,1,15);

  setcolor(15);
  settextstyle(1,0,6);
  outtextxy(50,100,"WELCOME");

  setcolor(15);
  settextstyle(1,0,3);
  outtextxy(200,200,"EMPLOYEE MANAGEMENT SYSTEM");

  setcolor(12);
  settextstyle(6,0,3);
  outtextxy(100,410,"PRESS ANY KEY TO CONTINUE...");
  getch();
}
void password()
{
  cleardevice();
  setcolor(15);
  setfillstyle(8,4);
  rectangle(30,30,610,450);
  floodfill(11,11,15);
  setfillstyle(12,4);
  rectangle(10,10,630,470);
  floodfill(1,1,15);
  setbkcolor(1);
  setcolor(4);
  char ch2[100];
//  int flag=0;
  settextstyle(7,0,2);
  outtextxy(110,150,"WRITE PASSWORD TO UNLOCK THIS FILE");
  outtextxy(110,248,"Please Confirm Your Identity");
  char ch1[]="password";
  gotoxy(57,17);
  int i=0,d;
  while(i<8)
  {
    ch2[i]=getch();
    cout<<"*";
    i++;
  }
  ch2[8]=NULL;
  d=strcmp(ch1,ch2);
  if(d==0)
  {
    cleardevice();
    setcolor(15);
    setfillstyle(8,4);
    rectangle(30,30,610,450);
    floodfill(11,11,15);
    setfillstyle(12,4);
    rectangle(10,10,630,470);
    floodfill(1,1,15);
    setbkcolor(1);
    settextstyle(7,0,4);
    outtextxy(180,200,"Identity Confirmed");
  }
  else
  {
    cleardevice();
    setcolor(15);
    setfillstyle(8,4);
    rectangle(30,30,610,450);
    floodfill(11,11,15);
    setfillstyle(12,4);
    rectangle(10,10,630,470);
    floodfill(1,1,15);
    setbkcolor(1);
    settextstyle(7,0,4);
    outtextxy(130,170,"Identity Not Confirmed");
    outtextxy(130,220,"Try again Later . . . ");
    getch();
    exit(0);
  }
  setcolor(15);

  getch();
}
void loading()
{
  cleardevice();
  int i,x=37;
  char ch[10];
  setbkcolor(1);
  setcolor(15);
  setfillstyle(1,15);
  rectangle(10,10,630,470);
  floodfill(1,1,15);
  setfillstyle(1,15);
  rectangle(30,30,610,450);
  floodfill(1,1,15);
  for(i=1;i<=100;i++)
  {
    cleardevice();
    setfillstyle(4,4);
    rectangle(10,10,630,470);
    floodfill(1,1,15);
    setfillstyle(4,4);
    rectangle(30,30,610,450);
    floodfill(11,11,15);
    settextstyle(1,0,4);
    outtextxy(200,40,"PLEASE WAIT");
    outtextxy(100,220,"LOADING...");
    itoa(i,ch,10);
    char ch2[]="%";
    strcat(ch,ch2);
    outtextxy(40,260,ch);
    setfillstyle(1,15);
    rectangle(35,300,x,330);
    floodfill(36,301,15);
    x=x+5;
    delay(100);
  }
  outtextxy(100,340,"LOADING COMPLETE");
  outtextxy(100,400,"Press any Key to CONTINUE");
  getch();
}
void thankyou()
{
  cleardevice();
  setbkcolor(1);
  setfillstyle(7,4);
  rectangle(10,10,630,470);
  floodfill(1,1,15);
  setfillstyle(7,4);
  rectangle(30,30,610,450);
  floodfill(11,11,15);
  settextstyle(10,0,3);
  outtextxy(65,100,"THANK YOU FOR WATCHING");
  settextstyle(1,0,3);
  outtextxy(150,200,"MADE BY:-  Karan Dhingra");
  getch();
  exit(0);
}


