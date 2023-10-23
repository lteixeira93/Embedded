#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
		Student(string firstName, string lastName, int id, vector <int> scores) :
		Person {firstName, lastName, id}, testScores {scores}
		{}

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
		char calculate(void)
		{
			vector <int> v {get_scores()};
			int count {0}, average {0};

			for (size_t i{0}; i < v.size(); i++)
			{
				count++;
			}

			for (size_t i{0}; i < v.size(); i++)
			{
				average += v.at(i);
			}

			average /= count;
			// auto average = accumulate(v.begin(), v.end(), 0) / count; // cpp11

			if (average >= 90 && average <= 100)
			{
				return 'O';
			}
			else if (average >= 80 && average < 90)
			{
				return 'E';
			}
			else if (average >= 70 && average < 80)
			{
				return 'A';
			}
			else if (average >= 55 && average < 70)
			{
				return 'P';
			}else if (average >= 40 && average < 55)
			{
				return 'D';
			}
			else {
				return 'T';
			}
		}

		/*	
        *   Function Name: get_scores
        *   Return: Get scores from private vector.
        */
        // Write your function here
		vector<int> get_scores(void) {
			return this->testScores;
		}
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	delete s;
	return 0;
}