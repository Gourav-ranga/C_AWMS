/*----------------------------------------------------------------------
   Title                :- Ancestor Wikipedia Management System.
   Programmer           :- Gourav Ranga.
   Date of starting     :- 17-03-2017.
  ----------------------------------------------------------------------*/

#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<sstream>

using namespace std;


/*-------------------------------Home_Page class criteria-----------------------------------*/
class Home_Page
{
 private:
 
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 int columns, rows,midx;
 HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
 COORD CursorPosition;
 public:
 void Banner();
 void Choice();
 void Admin_Login();
 void User_Login();
 friend void gotoXY(int);
 friend void gotoX(int);
 Home_Page();
};

/*--------------------------------------SET AT X POSITION------------------------------------*/
void Send_Xy(int Pos_X,int Pos_Y)
{
 COORD CursorPosition;
 HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
 
 CursorPosition.X=Pos_X;
 CursorPosition.Y=Pos_Y;
 SetConsoleCursorPosition(console,CursorPosition);

}

/*---------------------------------------SetCursorPosition------------------------------------*/
void gotoXY(int pos_y)
{
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 int pos_x;
 COORD CursorPosition;
 HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);

 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
 pos_x= (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2.5;
 //pos_y= csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
 
 if(pos_y==5)
 {
  CursorPosition.X=(pos_x+12);
  CursorPosition.Y=pos_y;
  SetConsoleCursorPosition(console,CursorPosition);
 }
 else
 CursorPosition.X=pos_x;
 CursorPosition.Y=pos_y;
 SetConsoleCursorPosition(console,CursorPosition);
}


/*---------------------Default Constructor for Class Home_Page---------------------------*/
Home_Page::Home_Page()
{
 columns=rows=0;
}

/*---------------------Defintition for Home Page-----------------------------------------*/
void Home_Page::Banner()
{
 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
 midx    = (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2.5;
 columns = (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2.8;
 //rows    =  csbi.srWindow.Bottom - csbi.srWindow.Top + 6;

 
 CursorPosition.X=columns;
 CursorPosition.Y=5;
 SetConsoleCursorPosition(console,CursorPosition);

 cout<<("Ancestor Wikipedia Management System");
 
 system("color 7");
 CursorPosition.X=(columns-4);
 CursorPosition.Y=4;
 SetConsoleCursorPosition(console,CursorPosition);
 printf("*********************************************");
 

 
 CursorPosition.X=(columns-4);
 CursorPosition.Y=6;
 SetConsoleCursorPosition(console,CursorPosition);
 printf("*********************************************");
 
 CursorPosition.X=(midx-3);
 CursorPosition.Y=9;
 SetConsoleCursorPosition(console,CursorPosition);

 CursorPosition.X=(midx);
 CursorPosition.Y=10;
 SetConsoleCursorPosition(console,CursorPosition);
 
 printf("Admin Login :- (1)");

 CursorPosition.X=(midx);
 CursorPosition.Y=12;
 SetConsoleCursorPosition(console,CursorPosition);
 
 printf("User  Panel :- (2)");

 CursorPosition.X=(midx);
 CursorPosition.Y=14;
 SetConsoleCursorPosition(console,CursorPosition);

 cout<<"Exit        :- (3)";
}

/*---------------------------Way of Login------------------------------------------*/
void Home_Page::Choice()
{
 CursorPosition.X=(columns-4);
 CursorPosition.Y=15;
 SetConsoleCursorPosition(console,CursorPosition);

 gotoXY(17);
 cout<<"Please!Enter your choice (1 or 2) ? : ";
}

/*---------------------------------Admin Login page-------------------------------------*/
void Home_Page::Admin_Login()
{
 system("cls");
 gotoXY(4);
 cout<<"************************************";
 fflush(stdin);

 gotoXY(5);

 cout<<"Admin Panel";
 fflush(stdin);
 gotoXY(6);
 cout<<"************************************";
 fflush(stdin);
}

/*---------------------------------User Login page--------------------------------------*/
void Home_Page::User_Login()
{
 system("cls");
 gotoXY(4);
 cout<<"************************************";

 gotoXY(5);

 cout<<"User Panel";
 gotoXY(6);
 cout<<"************************************";

 gotoXY(8);
 cout<<"<---Please!Select an Action--->";
 
 gotoXY(12);
 cout<<"(a) Create New Account :- [1]";

 gotoXY(14);
 cout<<"(b) User Login         :- [2]";
}

/*--------------------------------Admin Login Detail---------------------------------------*/
class Administrator_Login
{
 private:
 char Login_Id[40];
 char File_Login_Id[40];
 char Password[10];
 char File_Password[10];
 int  x,i,y;
 
 
 public:
 void Login_Authentication();
 friend void gotoXY(int);
};

void Administrator_Login::Login_Authentication()
{
//-----------------------------Admin Login Id validation-----------------------------//
 ifstream infile1;
 ifstream infile2;

 Admin:
 fflush(stdin);
 /*
 if(infile1!=NULL)
 {
  fclose(infile1);
 }
 */
 gotoXY(9);
 cout<<"Enter Login Id   :- ";
 gets(Login_Id);
// fflush(stdin);
 //cout<<Login_Id;
 infile1.open("D:\\AWMS\\Admin_Login\\login_id.txt");
 if(infile1.fail())
 {
  Sleep(3000);
  cout << "\Error!";
 }

 infile1.getline(File_Login_Id,30);
// cout<<File_Login_Id;
 
 x=stricmp(File_Login_Id,Login_Id);
// cout<<"value of x : "<<x;
 if(x!=0)
 {
  cout<<endl;
  gotoXY(11);
  cout<<"Invalid Id ? Try Again!"<<endl;
  Sleep(1000);
  system("cls");
  gotoXY(4);
  cout<<"************************************";
  fflush(stdin);

  gotoXY(5);

  cout<<"Admin Panel";
  fflush(stdin);
  gotoXY(6);
  cout<<"************************************";
  fflush(stdin);
  goto Admin;
  exit(1);
 }
  
//------------------------Admin password validation------------------------//
 gotoXY(11);
 cout<<"Enter password   :- ";
 i=0;
 while(i<7)
 {
  Password[i]=getch();
  i=i+1;
  cout<<"*";
 }
 
 Password[7]='\0'; 
 fflush(stdin);
 //puts(Password);
 infile2.open("D:\\AWMS\\Admin_Login\\password.txt");

 infile2.getline(File_Password,10);
 //puts(File_Password);

 
 y=stricmp(File_Password,Password);
 
 //printf("y : %d",y);
 if(y!=0)
 {
  cout<<"\nInvalid Password !"<<endl;
  Sleep(1000);
  exit(1);
 }
 infile2.close();   
}

class User_Panel
{
 private:
 string     Login_Id="";
 string     Sub_Login_Id="";
 char       F_O_P_Login_Id[35];
 string     File_Login_Id="";
 int        len;
 string     First_Name="";  //string 1
 char       Middle_Name[20];
 char       Last_Name[20];
 char       Sex[6];
 char       Full_Name[30];
 char       Type_Property[15];
 char       Seller[30];
 char       Land_Location[50];
 char       Value[90];
 int        No_Land;
 int        Age,width,length;
 string     Date;   //string 2
 string     Month;  //string 3
 string     Year;   //string- 4
 string     Appl_First_Name="";
 string     Appl_Middle_Name="";
 string     Appl_Last_Name="";
 string     Land_Reg_Login_Id="";
 string     Org_Land_Db_File="";
 char       Address[40];
 char       City[15];
 char       State[15];
 char       Land_Reg_Id[50];
 char       App_Address[40]; 
 char       str_con_chr[50];
 string     Mob_No="";	//string 5
 char       Religion[15];
 char       Path_chr[50]="E:\\AWMS\\Land_Reg_Login_Id\\";
 string     Full_Path="";
 string     Path="D:\\AWMS\\User_Reg_Data_Base\\";
 string     Path1="D:\\AWMS\\User_Login\\";
 string     Path2="D:\\AWMS\\Land_Data_Base\\";
 string     Path3="D:\\AWMS\\Land_Reg_Login_Id\\";
 string     Land_Reg_Login_Id_File="";
 string     Applicant_String="";
 string     Land_Full_Path="";
 string     Temp_Land_Reg_Id="";
 ofstream   OutFile;
 string     Only_Login_Id;
 ifstream   InFile;
 ifstream   InFile1;
 ifstream   GetData;
 

 public:
 void   User_Reg_Data();
 void   Create_New_Account();
 void   Make_File();             // Path :- E:\AWMS\Reg_Data_Base
 void   Make_File1();            //Path  :- E:\AWMS\User_Login
 void   Store_User_Reg_Data();
 void   Stor_Login_Id();
 friend void User_Login_Banner();
 void   Log_In(); 
 friend void gotoXY(int);
 friend void Send_Xy(int,int);
 friend void User_Facility_Banner();
 friend void Land_Registry_Banner();
 void   Show_Land_Registry_Details();
 void   Register_Land_Registry_Details();
};

/*-------------------------------User Registration Data---------------------------------*/

void User_Panel::User_Reg_Data()
{
  gotoXY(8);
  fflush(stdin);
  cout<<"Enter Your First Name      : ";
  cin>>First_Name;  
  fflush(stdin);

  gotoXY(10);
  cout<<"Enter Your Middle Name     : ";
  gets(Middle_Name);
  fflush(stdin); 

  gotoXY(12);
  cout<<"Enter Your Last Name       : ";
  gets(Last_Name);
  fflush(stdin);

  gotoXY(14);
  cout<<"Enter Your Sex             : ";
  gets(Sex);
  fflush(stdin);

  gotoXY(16);
  cout<<"Enter Your DOB(DD/MM/YYYY) : ";
  cout<<"(a) Date : ";
  cin>>Date;
  fflush(stdin);

  Send_Xy(112,16);
  cout<<"(b) Month : ";
  cin>>Month;
  fflush(stdin);

  Send_Xy(127,16);
  cout<<"(c) Year : ";
  cin>>Year;
  fflush(stdin);

  gotoXY(18);
  cout<<"Enter Your Addresss        : ";
  gets(Address);
  fflush(stdin);

  gotoXY(20);
  cout<<"Enter Your City            : ";
  gets(City);
  fflush(stdin);

  gotoXY(22);
  cout<<"Enter Your State           : ";
  gets(State);
  fflush(stdin);

  gotoXY(24);
  cout<<"Enter Your MOB(Mandatory)  : ";
  cin>>Mob_No;
  fflush(stdin);

  gotoXY(26);
  cout<<"Enter Your Religion        : ";
  fflush(stdin);
  gets(Religion);

}
/*--------------------------------Create user new Account-------------------------------*/

void User_Panel::Create_New_Account()
{
 system("cls");  
 gotoXY(4);
 
 cout<<"**********************************************";

 gotoXY(5);
 cout<<"User Registration Form ";

 gotoXY(6);
 cout<<"**********************************************";
}

/*---------------------------------Make Reg_Data File-------------------------------------------*/

void User_Panel::Make_File()
{
  Full_Path=Path+First_Name+Date+Month+Year+Mob_No+".txt";
  OutFile.open(Full_Path.c_str(),ios::ate);
  fflush(stdin);
}

/*--------------------------------Store User Registration Data--------------------------*/
void User_Panel::Store_User_Reg_Data()
{
 OutFile<<"First_Name  : "<<First_Name<<endl;
 
 OutFile<<"Middle_Name : "<<Middle_Name<<endl;

 OutFile<<"Last_Name   : "<<Last_Name<<endl;
 

 OutFile<<"Sex         : "<<Sex<<endl;

 OutFile<<"DOB         : "<<Date<<"-"<<Month<<"-"<<Year<<endl;

 OutFile<<"First_Name  : "<<First_Name<<endl;

 OutFile<<"Address     : "<<Address<<endl;

 OutFile<<"City        : "<<City<<endl;

 OutFile<<"State       : "<<State<<endl;

 OutFile<<"MOB         : "<<Mob_No<<endl;

 OutFile<<"Religion    : "<<Religion<<endl;

 OutFile.close();
}
/*--------------------------------Make User Login Id file---------------------------*/
void User_Panel::Make_File1()
{
 Full_Path=Path1+First_Name+Date+Month+Year+Mob_No+".txt";
 
 OutFile.open(Full_Path.c_str(),ios::ate);
 fflush(stdin);
}

/*--------------------------------Stor User Login Id-----------------------------------*/

void User_Panel::Stor_Login_Id()
{
 Only_Login_Id=First_Name+Date+Month+Year+Mob_No;
 OutFile<<"Login Id : "<<Only_Login_Id<<"@AWMS.in"<<endl;
 OutFile.close();

 gotoXY(30);
 cout<<"User Login Id : "<<Only_Login_Id<<"@AWMS.in"<<endl;
 exit(1);
}
/*-------------------------------Create User Login Banner------------------------------*/
void User_Login_Banner()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"*************************************";
 
 Send_Xy(70,5);
 cout<<"USER LOGIN PAGE";

 Send_Xy(60,6);
 cout<<"*************************************";
}


/*--------------------------------Give Permission to User to Log In---------------------*/
void User_Panel::Log_In()
{
 Send_Xy(60,8);
 cout<<"Login Id : ";
 fflush(stdin);
 cin>>Login_Id;
 fflush(stdin);


 len=Login_Id.length();
 
 len=len-8;
 
 Sub_Login_Id=Login_Id.substr(0,len);
 
 Full_Path=Path1+Sub_Login_Id+".txt";
 //cout<<"Full path : "<<Full_Path;
 fflush(stdin); 

 InFile.open(Full_Path.c_str(),ios::in);
 
 InFile.seekg(11);
 int p=InFile.tellg();
 //cout<<"Position : "<<p<<endl;
 
 InFile.getline(F_O_P_Login_Id,35); 
 
/*cout<<"File Output Login Id : ";
 puts(F_O_P_Login_Id);*/
 
 int cmp;

 char *Str_To_Char=(char *)Login_Id.c_str();
 
 //cout<<"Str_To_Char : "<<Str_To_Char<<endl;

 cmp=stricmp(F_O_P_Login_Id,Str_To_Char);

 //cout<<"cmp : "<<cmp<<endl;
 if(cmp!=0)
 {
  Send_Xy(60,12);
  cout<<"Invalid Id !";
  exit(1);
 }
}

/*--------------------------------------User Facility Banner-----------------------------------*/
void User_Facility_Banner()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"*************************************";
 
 Send_Xy(70,5);
 cout<<"USER FACILITY";

 Send_Xy(60,6);
 cout<<"*************************************";

 Send_Xy(60,8);
 cout<<"(a). Land Registry         : [1]";
 
 Send_Xy(60,10);
 cout<<"(b). Show Registry Details : [2]";
}

/*---------------------------------Land Registry Banner-------------------------------*/
void Land_Registry_Banner()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"*************************************";
 
 Send_Xy(70,5);
 cout<<"Land Registry Form";

 Send_Xy(60,6);
 cout<<"*************************************";
}

/*-------------------------------Register Land Registry Details------------------------*/
void User_Panel::Register_Land_Registry_Details()
{
 fflush(stdin);
 Send_Xy(60,8);
 cout<<"Applicant First Name                : ";
 Send_Xy(98,8);
 cin>>Appl_First_Name;
 fflush(stdin);

 Send_Xy(60,10);
 cout<<"Applicant Middle Name               :";
 Send_Xy(98,10);
 cin>>Appl_Middle_Name;
  
 Send_Xy(60,12);
 cout<<"Applicant Last Name                 :";
 Send_Xy(98,12);
 cin>>Appl_Last_Name;

 Applicant_String=Appl_First_Name+Appl_Middle_Name+Appl_Last_Name;   //Full Name of Applicant
 //cout<<Applicant_String;

 Send_Xy(60,14);
 cout<<"Number of Land Property             : ";
 cin>>No_Land;
 fflush(stdin);

 Send_Xy(60,16);
 cout<<"Type of Property(eg:-commercial)    : ";
 gets(Type_Property);
 fflush(stdin);

 Send_Xy(60,18);
 cout<<"Name Of Seller/Heritage of Ancestor : ";
 gets(Seller);
 fflush(stdin);

 Send_Xy(60,20);
 cout<<"Size of Land(Length,width) in ft.   : ";
 fflush(stdin); 

 Send_Xy(98,20);
 cout<<"(a) ";
 Send_Xy(103,20);
 cin>>length;
 fflush(stdin);

 Send_Xy(107,20);
 cout<<"(b) ";
 Send_Xy(112,20);
 cin>>width;
 fflush(stdin);

 Send_Xy(60,22);
 cout<<"Location Of Land                    : ";
 gets(Land_Location);
 fflush(stdin);

 Send_Xy(60,24);
 cout<<"Enter the Applicant date of birth   : ";
 fflush(stdin);
 Send_Xy(98,24);
 cout<<"(a) Date : ";
 fflush(stdin);
 Send_Xy(109,24);
 cin>>Date;
 fflush(stdin);

 Send_Xy(112,24);
 cout<<"(b) Month : ";
 Send_Xy(124,24);
 cin>>Month;
 fflush(stdin);

 Send_Xy(127,24);
 cout<<"(a) Year : ";
 Send_Xy(139,24);
 cin>>Year;
 fflush(stdin);

 Send_Xy(60,26);
 cout<<"Enter the Mobile Number       	: ";
 fflush(stdin);
 Send_Xy(98,26);
 cin>>Mob_No;
 fflush(stdin);

 Send_Xy(60,28);
 cout<<"Enter Permanent Address             : ";
 Send_Xy(98,28);
 gets(App_Address);
 fflush(stdin);

 Land_Full_Path=Path2+Appl_First_Name+Date+Month+Year+Mob_No+".txt";

 OutFile.open(Land_Full_Path.c_str(),ios::ate);

 OutFile<<"Applicant First Name                : "<<Appl_First_Name<<endl;
 
 OutFile<<"Applicant Middle Name               : "<<Appl_Middle_Name<<endl;

 OutFile<<"Applicant Last Name                 : "<<Appl_Last_Name<<endl;

 OutFile<<"Number of Land Property             : "<<No_Land<<endl;

 OutFile<<"Type of Property                    : "<<Type_Property<<endl;

 OutFile<<"Name Of Seller/Heritage of Ancestor : "<<Seller<<endl;

 OutFile<<"Size of Land(Length,width) in ft.   : "<<"(a) Length : "<<length<<" (b) width : "<<width<<endl;

 OutFile<<"Location of Land                    : "<<Land_Location<<endl;

 OutFile<<"Applicant date of birth             : "<<Date<<"-"<<Month<<"-"<<Year<<endl;

 OutFile<<"Applicant Mobile Number             : "<<Mob_No<<endl;

 OutFile<<"Applicant Permanent Address         : "<<App_Address<<endl;

 OutFile.close(); 
   
 Land_Reg_Login_Id=Appl_First_Name+Date+Month+Year+Mob_No;

 Land_Reg_Login_Id_File=Path3+Appl_First_Name+Date+Month+Year+Mob_No+".txt";

 OutFile.open(Land_Reg_Login_Id_File.c_str(),ios::ate);

 OutFile<<"Land Registration Id : "<<Land_Reg_Login_Id;

 OutFile.close();

 Send_Xy(60,32);
 cout<<"Note Land Registration Id : "<<Land_Reg_Login_Id;
 Send_Xy(60,33);
 cout<<"---------------------------------------------------------------";
}

/*---------------------------------Show User Registry Details--------------------------*/
void User_Panel::Show_Land_Registry_Details()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"*************************************************";
 fflush(stdin);
 
 Send_Xy(70,5);
 cout<<"Land Registry Authentication";
 fflush(stdin);

 Send_Xy(60,6);
 cout<<"*************************************************";
 fflush(stdin);

 Send_Xy(60,9);
 cout<<"Please!Enter Land Registry Id ? : ";
 fflush(stdin);

 Send_Xy(95,9);
 gets(Land_Reg_Id);
 fflush(stdin);

 Temp_Land_Reg_Id=Path3+((string)Land_Reg_Id)+".txt";

 fflush(stdin);

 InFile1.open(Temp_Land_Reg_Id.c_str(),ios::in);
 
 if(InFile1.fail())
 {
  Send_Xy(60,10);
  cout<<"Error! File doesn't Exist.";
  Sleep(2000);
  exit(1);
 } 

 InFile1.close();
 fflush(stdin);
 //cout<<"Pass !";
 system("cls");
 
 Org_Land_Db_File=Path2+((string)Land_Reg_Id)+".txt";

 GetData.open(Org_Land_Db_File.c_str(),ios::in);

 if(GetData.fail())
 {
  Send_Xy(60,10);
  cout<<"Error! File doesn't Exist.";
  Sleep(2000);
  exit(1);
 } 

 /*-----------------------------------------Show Land Registry Details------------------------------*/

 Send_Xy(60,4);
 cout<<"*****************************************";
 fflush(stdin);
 
 Send_Xy(70,5);
 cout<<"Land Registry Details";
 fflush(stdin);

 Send_Xy(60,6);
 cout<<"*****************************************";
 fflush(stdin);

 for(int i=0;i<12;i++)
 {
  Send_Xy(60,(i+(i+2))+8);
  GetData.getline(Value,90);
  //Send_Xy(60,8);
  cout<<Value;
  fflush(stdin);
 } 
 GetData.close();   //Close the file that show Details of Land Registry
}

/*------------------------------Admmin Facility Class------------------------------------*/
class Admin_Facility
{
 private:
 

 public:
 friend void Admin_Facility_Banner();
 friend void Send_Xy(int , int);
 void Show_User_Registry_Details();
};

void Admin_Facility_Banner()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"**********************************";
 fflush(stdin);

 Send_Xy(70,5);
 cout<<"Admin Facility";
 fflush(stdin);

 Send_Xy(60,6);
 cout<<"**********************************";
 fflush(stdin);

 Send_Xy(60,9);
 cout<<"(a) Show User Registration File : [1]";
 fflush(stdin);

 Send_Xy(60,11);
 cout<<"(b) Log Out from Id             : [2]";
 fflush(stdin);

 Send_Xy(60,15);
 cout<<"Please!Enter Your Choice        : ";
 fflush(stdin);
}

/*--------------------------------Show User Registry Details--------------------------*/
void Admin_Facility::Show_User_Registry_Details()
{
 system("cls");
 Send_Xy(60,4);
 cout<<"**********************************";
 fflush(stdin);

 Send_Xy(67,5);
 cout<<"User's Registry Files";
 fflush(stdin);

 Send_Xy(60,6);
 cout<<"**********************************";
 fflush(stdin);
 cout<<"\n\n";

 system("dir D:\\AWMS\\User_Login\\");
 exit(0);
}

/*---------------------------------Main program-----------------------------------------*/
main()
{
 int option;
 int choice1,choice2,choice3;
 string choice;
 int value=0;
 //char *my_string;  
 //int nbytes=100;           
 Home_Page   H1,H2,H3;
 Administrator_Login A1;
 User_Panel U1;
 Admin_Facility AD;

 loop:
 system("cls");
 H1.Banner();
 H1.Choice(); 
 getline(cin,choice);       //Random Input can be taken by User
 stringstream geek(choice);  //Convert Random Input into integer
 geek >> value;               //assign integer value to the variable "value"


 switch(value)
 {
  case 1:
  H2.Admin_Login();
  fflush(stdin);
  A1.Login_Authentication();
  fflush(stdin);
  Admin_Facility_Banner();
  fflush(stdin);  

  Send_Xy(94,15);
  cin>>choice3;  

  switch(choice3)
  {
   case 1:
   AD.Show_User_Registry_Details();
   break;

   case 2:
   exit(0);
 
   default:
   cout<<"Invalid Id !";
   Sleep(2000);
   exit(0);
  }
  break;

  case 2:
  H3.User_Login();
  break;

  case 3:
  exit(0);

  default:
  gotoXY(20);
  cout<<"Invalid option !Try again ?";
  Sleep(2000);
  goto loop;
  break;
 }
 
 gotoXY(18);
 cout<<"Please!Enter your choice : ";
 cin>>choice1;     //choice for user panel.
 
 switch(choice1)
 { 
  case 1:
  U1.Create_New_Account();
  U1.User_Reg_Data();
  fflush(stdin);
  U1.Make_File();
  fflush(stdin);
  U1.Store_User_Reg_Data();
  fflush(stdin);
  U1.Make_File1();
  U1.Stor_Login_Id();
  break;

  case 2:
  User_Login_Banner();
  U1.Log_In();
  User_Facility_Banner();
  fflush(stdin);
  break;

  default:
  cout<<"Invalid Option! Try again ? ";
  break;
 }
 fflush(stdin); 

 Send_Xy(60,14);
 cout<<"Please!Enter your choice? : ";
 cin>>choice2;

 switch(choice2)
 {
  case 1:
  Land_Registry_Banner();
  U1.Register_Land_Registry_Details();
  fflush(stdin);
  break;

  case 2:
  U1.Show_Land_Registry_Details();
  break;

  default:
  cout<<"Enter choice is Invalid !";
  break;  
 }
} 
//End of main()
