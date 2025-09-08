#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int    age;
	// Your code here
	string haircolor;
	int weight;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
	cout << "He weighs " << person->weight << "kg and his hair is " << person->haircolor << endl;
}


int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.weight = 80;
	person.haircolor = "black";

	cout << "Meet " << person.name << endl;
	print(&person);

	// Your code here

	Person Kira;
	Kira.name = "Light Yagami";
	Kira.age = 20;
	Kira.weight = 70;
	Kira.haircolor = "brown";
	print(&Kira);


	return 0;
}
