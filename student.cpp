#include <iostream>
using namespace std;

class student{
	private:
	
		string name;
		int id;
		float grade;
		static int count;
	
	public:
	
		student(){
			name;
			id;
			grade;
			count++;
		}
		student(string n,int i,float g){
			name = n;
			id = i;
			grade =g;		
			count++;
		}
		
	public:
		
		void displayInfo(){
			cout<<"Studen Name: "<<name<<endl;
			cout<<"Studen ID: "<<id<<endl;
			cout<<"Studen Grade: "<<grade<<endl;
			cout<<""<<endl;
		}
		void setGrade(float g){
			if(g>=0 && g<=100)
			grade = g;
			else
			cout<<"invalid grade"<<endl;
		}
		float getGrade(){
			return grade;
		}
		static void displayCount(){
			cout<<"Number of Students: "<<count<<endl;
		}
		
		friend void updateGrade(student &s,float newGrade);		
};

		void updateGrade(student &s,float newGrade){
			if(newGrade>=0 && newGrade<=100)
			s.grade = newGrade;
			else
			cout<<"invalid grade ipdate"<<endl;
		}
		
		int student::count = 0;

class instructor{
	private:
		
		string Name;
		int instID;
	
	public:
	
	instructor(){
		Name;
		instID;
	}
	instructor(string N,int I){
		Name = N;
		instID = I;
	}
	
		public:
		
		void displayInstInfo(){
			cout<<"Instructor Name: "<<Name<<endl;
			cout<<"Instructor ID: "<<instID<<endl;
		cout<<""<<endl;
		}		

	void updateGrade(student &s,float newGrade){
		::updateGrade(s, newGrade);
	}
};

class GraduateStudent : public student{
	
		public:
			
			string researchTopic;
			
			GraduateStudent(string n,int i,float g,string t):student(n,i,g){
				researchTopic = t;
	}

		void diplayResearchInfo(){
		displayInfo();
	
		cout<<"Research Topic: "<<researchTopic<<endl;
		cout<<""<<endl;
	}
};

int main(){

	student s1("Yahya",2401255,70);
	instructor inst1("Eng.Clark ",1); 
	GraduateStudent g1("Abdo",2501244,71,"Software Eng");

	s1.displayInfo();
	inst1.displayInstInfo();
	g1.diplayResearchInfo();

	s1.setGrade(90);
	s1.displayInfo();
//	cout<<"New Grade: ";
//	cout<<s1.getGrade()<<endl;
	cout<<" "<<endl;
	
	inst1.updateGrade(g1,80);	
	g1.displayInfo();

	student s2("ali",1234,0);
	s2.displayInfo();
	
	inst1.updateGrade(s2,10);	
	s2.displayInfo();
	
	student::displayCount();
	return 0;
}
