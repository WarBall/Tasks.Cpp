#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Human
{
private:
    string _name;
    string _profession;
public:
    Human(string & name, string profession)
    {
        this->_name = name;
        this->_profession = profession;
    }
    string getName() { return _name; }
    string getProfession() { return _profession; }

    virtual string iAm() = 0;
};

class Blacksmith : public Human
{
private:
    string _work;
public:
    Blacksmith(string & name, string profession, string & work) : Human(name, profession) 
    {
        this->_work = work;
    }
    string getWork() { return _work; }
    string iAm() override
    {
        string iAm = "Имя: " + this->getName() + '\t' + "Профессия: " + this->getProfession() + '\t' + "Работает над: "+ this->getWork() + '\n';
        return iAm;
    }
};

class Farmer : public Human
{
private:
    string _work;
public:
    Farmer(string & name, string profession, string & work) : Human(name, profession)
    {
        this->_work = work;
    }
    string getWork() { return _work; }
    string iAm() override
    {
        string iAm = "Имя: " + this->getName() + '\t' + "Профессия: " + this->getProfession() + '\t' + "Обрабатывает: " + this->getWork() + '\n';
        return iAm;
    }
};

class Fisherman : public Human
{
private:
    string _work;
public:
    Fisherman(string & name, string profession, string & work) : Human(name, profession)
    {
        this->_work = work;
    }
    string getWork() { return _work; }
    string iAm() override
    {
        string iAm = "Имя: " + this->getName() + '\t' + "Профессия: " + this->getProfession() + '\t' + "Ловит: " + this->getWork() + '\n';
        return iAm;
    }
};

class Factory
{
public:
    virtual Human* createHuman(string name, string work) = 0;
    virtual ~Factory() {}
};

class BlacksmithFactory : public Factory
{
public:
    Human* createHuman(string name,string work) 
    {
        return new Blacksmith(name,"Кузнец", work);
    }
};

class FarmerFactory : public Factory
{
public:
    Human* createHuman(string name,string work)
    {
        return new Farmer(name,"Фермер", work);
    }
};

class FishermanFactory : public Factory
{
public:
    Human* createHuman(string name,string work)
    { 
        return new Fisherman(name,"Рыбак", work);
    }
};

int main()
{
    Factory* blacksmith_factory = new BlacksmithFactory;
    Factory* farmer_factory = new FarmerFactory;
    Factory* fisherman_factory = new FishermanFactory;
    
    string name, work; char hum; bool ex = true;
    vector<Human*> village;
    
    do
    { 
        char goOut;
        cout << "Кто вам нужен староста? \na)Кузнец \nb)Фермер \nc)Рыбак \n";
        cin >> hum;

        switch (hum)
        {
        case 'a':
            cout << "Как зовут этого кузнеца и что он должен сделать?\n";
            cin >> name >> work;
            village.push_back(blacksmith_factory->createHuman(name, work));
            break;
        case 'b':
            cout << "Как зовут этого фермера и что он должен сделать?\n";
            cin >> name >> work;
            village.push_back(farmer_factory->createHuman(name, work));
            break;
        case 'c':
            cout << "Как зовут этого рыбака и что он должен сделать?\n";
            cin >> name >> work;
            village.push_back(fisherman_factory->createHuman(name, work));
            break;
        }

        cout << "Ещё есть работа?(y/n)\n";
        std::cin >> goOut;
        goOut == 'y' ? ex = true : ex = false;

    } while (ex);

    ofstream out("village.txt", ios::app);
    if (out.is_open()) 
    {
        for (Human* p : village)
            out << p->iAm();       
    }
}


