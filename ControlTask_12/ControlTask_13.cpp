#include <iostream>
#include <string>
#include <windows.h>

#define Random rand() % 55 + 15

class Weapon
{
public:
    virtual void use() = 0;
};

class Bow : public Weapon
{
public:
    void use() override
    {
        std::cout << "атака из лука!" << std::endl;
    }
};

class Crossbow : public Weapon
{
public:
    void use() override
    {
        std::cout << "атака из арбалета!" << std::endl;
    }
};

class Sword : public Weapon
{
public:
    void use() override
    {
        std::cout << "атака мечом!" << std::endl;
    }
};

class Mace : public Weapon
{
public:
    void use() override
    {
        std::cout << "атака булавой!" << std::endl;
    }
};

class Warrior 
{
private:
    std::string _name, _gender;
    int _age = Random;
    Weapon* _weap;
public:

    Warrior(std::string name,std::string gender,Weapon* weap) : _name(name),_gender(gender),_weap(weap){}
     void getDate()
    {
        std::cout << "\nИмя: " << _name;
        std::cout << "\nПол: " << _gender;
        std::cout << "\nВозрвст: " << _age;
    }
    void Attack()
    {
        _weap->use();
    }
};


int main()
{
    std::string name, gender;
    Weapon *wep = nullptr;
    char weapon;
    std::cout << "Ваши имя и пол? \n";
    std::cin >> name >> gender;

    std::cout << "Какое оружее преппочитаете(a,b,c,d)? \n";
    std::cout << "a) Лук\n" << "b) Арбалет\n" << "c) Меч\n" << "d) Булова\n" ;
    std::cin >> weapon;

    switch (weapon)
    {
    case 'a':
        wep = new Bow;
        break;

    case 'b':
        wep = new Crossbow;
        break;

    case 'c':
        wep = new Sword;
        break;

    case 'd':
        wep = new Mace;
        break;

    default:
        break;
    }

    Warrior war(name, gender, wep);

    std::cout << "Ваши данные\n";
    war.getDate();

    std::cout << std::endl;

    std::cout << "Вы встрети мостра и совершили ";
    war.Attack();

    delete wep;
}
