#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>

class Data
{
	public:
   char username[30];
   long accountID;
   char name[30];
   char highschool [30];
   long phno;
   void Create_Account()
   {
      long veri;
   	cout<<"Let us start with your basic details \n";
      cout<<"Name: ";
      gets (name);
      cout<<"Desired Username: ";
      gets (username);
      cout<<"Desired AccountID (NUMBERS ONLY): ";
      cin>>accountID;
      cout<<"Re-enter AccountID for verification: ";
      cin>>veri;
      while (accountID!=veri)
      {
      	cout<<"IDs do not match!\n";
         cout<<"Re-enter AccountID for verification: ";
         cin>>veri;
      }
      cout<<"Current Highschool: ";
      gets (highschool);
      cout<<"Phone Number: ";
      cin>>phno;
      cout<<"Account Created!";
   }
   long return_accountID()
   {
   	return accountID;
   }
};
void write_Account ()
{
	Data dat;
   fstream file;
   file.open ("Data.txt", ios::app);
   dat.Create_Account();
   file.write ((char*)&dat, sizeof(Data));
   file.close();
}
bool Login(int x)
{
	Data dat;
   fstream File;
   bool log=false;
   File.open ("Data.txt", ios::in|ios::out);
   while(!File.eof())
   {
   	File.read((char*)&dat, sizeof(Data));
      if (dat.return_accountID()==x)
      {
      	cout<<"Login Successful\n";
         log=true;
         break;
      }
   }
   return log;
}

class uni
{
	int score;
	char name[50];
	int finaid;
	public:
	void input()
	{
	cout<<"Enter name \n";
	gets(name);
	cout<<"enter score \n";
	cin>>score;
	cout<<"Enter finaid \n";
	cin>>finaid;
	}
};

class student
{
	private:
	int math,phy,eng,compsci,chem; //subject scores
	char name[20];
	char minsub[8];                // subject name of worst scores
	int min;                       // min score to be excluded from gpa
	int extracurr[5];
	int noext;
	int sat;
	float gpa;                     // gpa calculated on the best 4 marks
	int ap[5];                     // grades of ap classes
	int achiev[5];                 // no of achievements
	int noap;                      // no of ap classes
	int noac;                      // no of extracurricular activities
	char opt;                      // miscellaneous use for binary operations
	float score;                   // comprehensive score based on gpa,achievements,and ap classes
	float achievscore;
	float apscore;
	float extrascore;
	float satscore;
	public:
	student()
	{
		min=math=phy=noap=noac=eng=compsci=chem=0;
		score=achievscore=satscore=apscore=extrascore=0.0;
		opt='n';
		for(int i=0;i<4;i++)
		{
			strcpy(minsub,"null");
		}
		for(int i=0;i<5;i++)
		{
			ap[i]=0;
			achiev[i]=0;
			extracurr[i]=0;
		}
	}
	void enterdetails()
	{
		cout<<"Enter Student's name \n";
		gets(name);
		cout<<"Enter student's mathematics marks (out of 100) \n";
		cin>>math;
		cout<<"Enter student's physics marks (out of 100) \n";
		cin>>phy;
		cout<<"Enter student's chemistry marks (out of 100) \n";
		cin>>chem;
		cout<<"Enter student's english marks (out of 100) \n";
		cin>>eng;
		cout<<"Enter student's computer science marks (out of 100) \n";
		cin>>compsci;
		cout<<"Enter student's SAT score(out of 1600) \n";
		cin>>sat;
		cout<<"Has the student participated in any extracurricular activity \n";
		cin>>opt;
		if((opt=='y')||(opt=='Y'))
		{
			cout<<"Enter the number of such activities \n";
			cin>>noext;
			for(int i=0;i<noext;i++)
			{
				cout<<"Enter 1 if the activity is Organizational, 2 if the activity is volunteering, and 3 for others \n";
				cin>>extracurr[i];
			}
   	}
		cout<<"Has the student taken any AP classes?y/n \n";
		cin>>opt;
		if((opt=='Y')||(opt=='y'))
		{
			cout<<"How many ap classes has the student taken (maximum 5) \n";
			cin>>noap;
			for(int i=0;i<noap;i++)
			{
				cout<<"Enter marks(out of 5) for AP Test No:"<<(i+1)<<"\n";
				cin>>ap[i];
			}
   	}
		cout<<"Does the student possess any award which is at least state level? y/n \n";
		cin>>opt;
		if(opt=='y')
		{
			cout<<"Enter number of achievements (maximum 5) \n";
			cin>>noac;
			for(int i=0;i<noac;i++)
			{
				cout<<"Enter 1 if the activity is International, Enter 2 if the activity is National level, and Enter 3 if the activity is State level \n";;
				cin>>achiev[i];
			}
		}
	}


	void calgpa()
	{
		if((math<=chem)&&(math<=eng)&&(math<=compsci)&&(math<=phy))
		{
			strcpy(minsub,"Mathematics");
			gpa=((math+chem+phy+eng)/4);
		}
		else if((chem<=math)&&(chem<=eng)&&(chem<=compsci)&&(chem<=phy))
		{
			min=chem;
			strcpy(minsub,"Chemistry");
			gpa=((math+compsci+phy+eng)/4);
		}
		else if((phy<=math)&&(phy<=eng)&&(phy<=compsci)&&(phy<=chem))
		{
			min=phy;
			strcpy(minsub,"physics");
			gpa=((math+chem+compsci+eng)/4);
		}
		else if((eng<=math)&&(eng<=chem)&&(eng<=compsci)&&(eng<=phy))
		{
			min=eng;
			strcpy(minsub,"English");
			gpa=((math+chem+phy+compsci)/4);
   	}
		else if((compsci<=chem)&&(compsci<=eng)&&(compsci<=math)&&(compsci<=phy))
		{
			min=compsci;
			strcpy(minsub,"Computer Science");
			gpa=(math+chem+phy+eng)/6;
   	}
		cout<<"Do you wish to see a GPA report y/n \n";
		cin>>opt;
		if((opt=='y')||(opt=='Y'))
		{
			cout<<"Student name: ";
			puts(name);
			cout<<"\n Worst subject is ";
			puts(minsub);
			cout<<" in which marks obtained: "<<min<<endl;
			cout<<"GPA calculated using top 4 subjects(out of 100): "<<gpa<<endl;
		}
	}
	void scorecal()
	{
		for(int i=0;i<noac;i++)
		{
			if(achiev[i]==1)
			achievscore+=20;
			else if(achiev[i]==2)
			achievscore+=10;
			else
			achievscore+=5;
		}
		for(int i=0;i<noext;i++)
		{
			if(extracurr[i]==1)
			extrascore+=20;
			else if(extracurr[i]==2)
			extrascore+=10;
			else
			extrascore+=5;
   	}
		for(int i=0;i<noap;i++)
		{
			apscore+=(ap[i]*4);
		}
		satscore=(sat*100/1600);
		score=((gpa*25/100)+(achievscore*20/100)+(apscore*10/100)+(satscore*20/100)+(extrascore*25/100));
		cout<<"The student's comprehensive score is :"<<score<<endl;
	}
};

void main()
{
   fstream file;
   Data dat;
   cout<<"Welcome to CollegeSimply India! The perfect guide for Indian students aspiring to study abroad"<<endl;
   getch();
   int c, cs1;
   cout<<"Press 1 if you're a new user\n";
   cout<<"Press 2 if you're an existing user\n";
   cout<<"Enter your choice: ";
   cin>>c;
   switch (c)
   {
   	case 1:
      write_Account();
      break;
      case 2:
      bool che;
      long acid;
      cout<<"Account ID: ";
      cin>>acid;
      che = Login(acid);
      if (che==false)
      {
      	cout<<"Login Failed!";
      }
      while (che==true)
      {
      	cout<<"1. Check your college compatibility score\n";
         cout<<"2. View the entire college list\n";
         cout<<"3. Submit your CollegeSimply Application to the \n";
         cout<<"Enter your choice: ";
         cin>>cs1;
         switch (cs1)
         {
         	case 1:
            break;
            case 2:
            char x[500];
            file.open ("University_List.txt", ios::in);
            while (!file.eof())
            {
            	file.getline (x, 400, '\n');
               puts(x);
            }
            file.close();
            break;
            default:
            cout<<"Invalid Input!";
            break;
      	}
      }
      break;
     	default:
      cout<<"Invalid Input!";
      break;

   }
	student obj;
	obj.enterdetails();
	obj.calgpa();
	obj.scorecal();
	uni obj1;
	fstream obj2("university.txt",ios::out);
	obj2.read((char*)&obj1,sizeof(obj1));
	system("pause");
}
