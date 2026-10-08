#include <iostream>
using namespace std;

class Player {
protected:
    string name;
    int level;

public:
    Player(string n, int l) {
        name = n;
        level = l;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
    }
};

class Warrior : public Player {
    string weapon;

public:
    Warrior(string n, int l, string w) : Player(n, l) {
        weapon = w;
    }

    void display() {
        Player::display();
        cout << "Weapon: " << weapon << endl;
    }
};

class Wizard : public Player {
    int magicPower;

public:
    Wizard(string n, int l, int mp) : Player(n, l) {
        magicPower = mp;
    }

    void display() {
        Player::display();
        cout << "Magic Power: " << magicPower << endl;
    }
};

int main() {
    Warrior w1("Thanos", 5, "Sword");
    Wizard w2("Gandalf", 10, 100);

    cout << "Warrior Character:" << endl;
    w1.display();

    cout << "\nWizard Character:" << endl;
    w2.display();

    return 0;
}
