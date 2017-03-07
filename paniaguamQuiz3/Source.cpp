#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUM_STUDENTS = 20;				//number of students

struct studentType							//decaration of struct
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

void studentInfo(studentType*);				//read students data into array
void setGrade(studentType*);				//assign grade
void highTestScore(int&, studentType*);		//finds highest score
void outputData(studentType*, int);			//outputs student data

int main()
{
	studentType students[NUM_STUDENTS];		//array of student structs
	int highScore = 0;			

	studentInfo(students);
	setGrade(students);
	highTestScore(highScore, students);
	outputData(students, highScore);
	
	return 0;
}

void studentInfo(studentType* std)
{
	ifstream inputFile;
	string fileName = "data.txt";

	inputFile.open(fileName);				//open input file

	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		inputFile >> std[i].studentFName >> std[i].studentLName >> std[i].testScore;		//input student data
	}

	inputFile.close();
}

void setGrade(studentType* std)
{
	for (int i = 0; i < NUM_STUDENTS; i++)	//set grade
	{
		if (std[i].testScore >= 90)
		{
			std[i].grade = 'A';
		}
		else if (std[i].testScore >= 80)
		{
			std[i].grade = 'B';
		}
		else if (std[i].testScore >= 70)
		{
			std[i].grade = 'C';
		}
		else if (std[i].testScore >= 60)
		{
			std[i].grade = 'D';
		}
		else
		{
			std[i].grade = 'F';
		}
	}
}

void highTestScore(int &score, studentType* std)
{
	score = std[0].testScore;				

	for (int i = 1; i < NUM_STUDENTS; i++)		//find highest test score
	{
		if (std[i].testScore > score)
		{
			score = std[i].testScore;
		}
	}

}

void outputData(studentType* std, int hghScore)
{
	ofstream outFile;
	string name;

	outFile.open("out.txt");					//create output file

	outFile << left << setw(20) << "Student Name" << right << setw(15) << "Test Score" << setw(8) << "Grade" << endl;
	for (int i = 0; i < NUM_STUDENTS; i++)														//output each student's data
	{
		name = std[i].studentLName + ", " + std[i].studentFName;
		outFile << left << setw(20) << name << right << setw(11) << std[i].testScore << setw(10) << std[i].grade << endl;
	}

	outFile << "\nHighest score is " << hghScore << endl;
	outFile << "Students with the highest score are: " << endl;
	for (int i = 0; i < NUM_STUDENTS; i++)														//output students with highest score
	{
		if (std[i].testScore == hghScore)
		{
			outFile << std[i].studentLName << ", " << std[i].studentFName << endl;
		}
	}

	outFile.close();
}