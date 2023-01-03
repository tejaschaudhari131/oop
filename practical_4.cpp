#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Student
{
	private:
		int roll;
		float marks;
		char name[20];
	public:
		void accept()
		{
			cout<<"\nEnter Roll no:";
			cin>>roll;
			cout<<"\nEnter Marks of Student:";
			cin>>marks;
			cout<<"\nEnter Name of Student:";
			cin>>name;
		}
		void display()
		{
			cout<<"\nName:"<<name;
			cout<<"\nRoll no:"<<roll;
			cout<<"\nMarks are:"<<marks;
		}
};

int main()
{
	int ch,n,i;
	fstream f;
	Student s[10];
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1.Create:";
		cout<<"\n2.Write:";
		cout<<"\n3.Read:";
		cout<<"\n4.Append:";
		cout<<"\n5.Exit:";
		cout<<"\nEnter Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.open("file.txt",ios::out);
				cout<<"\nFile is successfully created.";
				f.close();
				break;
			case 2:
				f.open("file.txt",ios::out);
				cout<<"\nHow many students do you want to enter:";
				cin>>n;
				for(i=0;i<n;i++)
				{
					s[i].accept();
					f.write((char*)& s,sizeof(s));
				}
				f.close();
				break;
			case 3:
				f.open("file.txt",ios::in);
				for(i=0;i<n;i++)
				{
					f.read((char*)& s,sizeof(s));
					s[i].display();
				}
				f.close();
				break;
			case 4:
				f.open("file.txt",ios::app);				
				s[i].accept();
				f.write((char*)& s,sizeof(s));				
				n++;
				f.close();
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
