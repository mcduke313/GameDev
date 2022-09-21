#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Student {
private:
	string firstName;
	string lastName;
	int grade;
public:
	Student(string str1, string str2, int num)
	{
		firstName = str1;
		lastName = str2;
		grade = num;
	}
	void setFirstName(string str)
	{
		firstName = str;
	}
	void setLastName(string str)
	{
		lastName = str;
	}
	void setGrade(int i)
	{
		grade = i;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	int getGrade()
	{
		return grade;
	}
};

int main()
{
	//create vector
	vector<Student> myList;

	//read document
	ifstream myfile("example.txt");

	string currentLine;

	if (myfile.is_open())
	{
		while (getline(myfile, currentLine))
		{
			vector<string> parts;

			stringstream s_stream(currentLine);

			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ' ');
				parts.push_back(substr);
			}
			int j = stoi(parts[2]);
			Student obj(parts[0],parts[1], j);
			myList.push_back(obj);
		}
	}
	else
	{
		cout << "Unable to open file";
	}


	for (int i = 0; i < myList.size(); i++)
	{
		for (int j = i + 1; j < myList.size(); j++)
		{
			if (myList[i].getGrade() < myList[j].getGrade())
			{
				Student obj1 = myList[i];
				Student obj2 = myList[j];

				myList.erase(myList.begin() + i);
				myList.insert(myList.begin() + i, obj2);

				myList.erase(myList.begin() + j);
				myList.insert(myList.begin() + j, obj1);
			}
		}
	}

	for (int i = 0; i < myList.size(); i++)
	{
		cout << myList[i].getFirstName() << " " << myList[i].getLastName() << " " << myList[i].getGrade() << endl;
	}
}