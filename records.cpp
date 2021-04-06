#include <iostream>
#include <vector>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <algorithm> // min_element(), max_element(), sort()

using namespace std;

class Student
{
    private:
        string name_;
        int number_;
        vector<int> grades_;
        const int num_courses_;
        //Generates a renadom string filled with letters and numbers
        static string gen_name() { 
            const char *arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            string name;
            int size = rand()%6 + 6;//Generate a reandom size of string
            //Loop adds the random characters to a string
            for (int i = 0; i < size; i++){
                int index = rand()%63;
                name += arr[index];
            }

            return name;
        } 
        //Generate a random int between 201100000 and 201600000
        static int gen_number() { 
            return rand()%500000 + 201100000;
        } 
        //Generate a random in between 70 and 100
        static int gen_grade() { 
            return rand()%30 + 70;
        }
        
    
    public:
        //Default constructor
        Student() : name_(gen_name()), number_(gen_number()), num_courses_(5)
        {
            for (int i=0; i<num_courses_; ++i) {
                grades_.push_back(gen_grade());//Loads the grades
            }
        }

        string get_name(){
            return name_;
        }

        int get_number(){
            return number_;
        }
        //Adds up all of the grades
        double compute_average() { 
            double average = 0;
            int sum = 0;

            for(int i = 0; i < 5; i++){
                sum += grades_[i];
            }
            average =  (sum) / (5);
            return average;
        } 
         
        void operator= (const Student& s1){
            name_ = s1.name_;
            number_= s1.number_;
            grades_.clear();

            for(int i = 0; i < 5; i++){
                grades_.push_back(s1.grades_[i]);
            }
        }

        friend ostream& operator<<(ostream& os, const Student& s) {
            os << "Name = " << s.name_ << ", Number = " << s.number_;
            return os;
        }

        void print_grades(ostream& os) const
        {
            for (int i=0; i<num_courses_; ++i) {
            os << grades_[i] << ", ";
            }
        }
};
//Sorts by name
bool sortName(Student student1, Student student2){
    if(student1.get_name().compare(student2.get_name())<0){
          return true;
    }
    return false;
}
//Sorts by average
bool sortAverage(Student student1, Student student2){
    if(student1.compute_average() < student2.compute_average()){
        return true;
    }
    return false;
}

bool sort(int i, int j) { return (i<j); }

void printRecord(int x, vector<Student> studentVec){
     for(int i = 0; i < x; i++){
        Student s1 = studentVec[i];
        cout << s1 << endl;
        cout <<"Grades:"<<endl;

        s1.print_grades(cout);
        cout << "\nAverage Grade:" << s1.compute_average() << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<Student> studentVec;//Creating vec varialbe

    int numStudent = atoi(argv[1]);//Gettting the number of students
    //Construct all of the student
    for(int i = 0; i < numStudent; i++){    
        Student s1;
        studentVec.push_back(s1);
    }

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Student records:"<<endl;
    cout <<"------------------------------------------------------"<< endl;
    //Print student records
    printRecord(numStudent, studentVec);
    
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Student records by name:"<<endl;
    cout <<"------------------------------------------------------"<< endl;

    sort(studentVec.begin(), studentVec.end(), sortName);

    printRecord(numStudent, studentVec);

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Student records by grade:"<<endl;
    cout <<"------------------------------------------------------"<< endl;

    sort(studentVec.begin(), studentVec.end(), sortAverage);

    printRecord(numStudent, studentVec);


    cout<<"------------------------------------------------------"<<endl;
    cout<<"Student records with highedt grade:"<<endl;
    cout <<"------------------------------------------------------"<< endl;

    Student s1 = studentVec.at(numStudent - 1);
    cout << s1 << endl;
    cout<<"Grades:"<<endl;

    s1.print_grades(cout);

    cout<<"\nAverage Grade:"<<s1.compute_average()<<endl;

    return 0;
}