#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct StudentGrade
{
    StudentGrade(std::string name, char grade) : _name(name), _grade(grade) {}

    std::string _name;
    char _grade;
};


template <typename C, class T> bool findit(const C& c, T val)
{
    auto result = c.find(val);

    return result != c.end() ? true : false;
};



int main()
{
    std::map<std::string, char> journal;


    StudentGrade stud_1("Dima", ' ');
    StudentGrade stud_2("Pavel", ' ');
    StudentGrade stud_3("Deni", ' ');
    StudentGrade stud_4("Jeni", ' ');
    
    journal.insert(std::pair<std::string, char>(stud_1._name,stud_1._grade));
    journal.insert(std::pair<std::string, char>(stud_2._name, stud_2._grade));
    journal.insert(std::pair<std::string, char>(stud_3._name, stud_3._grade));
    journal.insert(std::pair<std::string, char>(stud_4._name, stud_4._grade));

    std::cout << "Журнал студентов: \n";
    for(auto& i: journal)
    {
        std::cout << i.first << std::endl;
    }

    char ex = 'n';
    
    do
    {
        std::cout << "Кому вы хотите поставить оценку?\n";
        std::string name;
        std::cin >> name;
        if (findit(journal, name))
        {
            std::cout << "Какую оценку?(A,B,C,D,F)\n";
            char grade;
            std::cin >> grade;
            journal.at(name) = grade;
        }
        
        std::cout << "Выход?(y/n)\n";
        std::cin >> ex;

    } while (ex != 'y');

}


