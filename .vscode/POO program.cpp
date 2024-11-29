#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Character {
public:
    Character(const string& charName, int charHealth)
            : name(charName), health(charHealth) {}

    virtual void attack(Character& other) = 0;
    virtual void healSelf() = 0;
    virtual string getAbilityName() const = 0;

    bool isAlive() const {
        return health > 0;
    }

    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int health;
    string name;
};

class Karatist : public Character {
private:
    vector<string> abilities;

public:
    Karatist(const string& charName, int charHealth, const vector<string>& charAbilities)
            : Character(charName, charHealth), abilities(charAbilities) {}

    void attack(Character& other) override {
        string ability;
        int damage;

        do {
            int randomIndex = rand() % abilities.size();
            ability = abilities[randomIndex];

            if (ability == "Spinning Leg Kick")
                damage = rand() % 15 + 10;
            if (ability == "High Kick")
                damage = 10;
        } while (ability == "Meditating");

        other.health -= damage;
        cout << name << " performs " << ability << " and attacks " << other.name << " for " << damage << " damage!" << endl;
    }

    void healSelf() override {
        string ability = "Meditating";
        int healAmount = rand() % 5 + 4;

        health += healAmount;
        cout << name << " uses " << ability << " and heals themselves for " << healAmount << " HP!" << endl;
    }

    string getAbilityName() const override {
        int randomIndex = rand() % abilities.size();
        return abilities[randomIndex];
    }
};

class Boxer : public Character {
private:
    vector<string> abilities;

public:
    Boxer(const string& charName, int charHealth, const vector<string>& charAbilities)
            : Character(charName, charHealth), abilities(charAbilities) {}

    void attack(Character& other) override {
        string ability;
        int damage;

        do {
            int randomIndex = rand() % abilities.size();
            ability = abilities[randomIndex];

            if (ability == "Mike Tyson Combo")
                damage = rand() % 15 + 10;
            if (ability == "Uppercut")
                damage = 10;
        } while (ability == "Energy Drink");

        other.health -= damage;
        cout << name << " performs " << ability << " and attacks " << other.name << " for " << damage << " damage!" << endl;
    }

    void healSelf() override {
        string ability = "Energy Drink";
        int healAmount = rand() % 5 + 4;

        health += healAmount;
        cout << name << " uses " << ability << " and heals themselves for " << healAmount << " HP!" << endl;
    }

    string getAbilityName() const override {
        int randomIndex = rand() % abilities.size();
        return abilities[randomIndex];
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void waitForEnter() {
    cout << "Press Enter to continue...";
    clearInputBuffer();
}
int main() {
    srand(time(0)); // Seed the random number generator

    string name1 = "Karatist";
    string name2 = "Boxer";
    int health1, health2;

    cout << "Enter health for Karatist: ";
    cin >> health1;
    clearInputBuffer(); // Clear input buffer

    cout << "Enter health for Boxer: ";
    cin >> health2;
    clearInputBuffer(); // Clear input buffer

    vector<string> karatistAbilities = {"High Kick", "Meditating", "Spinning Leg Kick"};
    vector<string> boxerAbilities = {"Uppercut", "Energy Drink", "Mike Tyson Combo"};

    Karatist karatist(name1, health1, karatistAbilities);
    Boxer boxer(name2, health2, boxerAbilities);

    Character* character1 = &karatist;
    Character* character2 = &boxer;

    int round = 1;
    while (character1->isAlive() && character2->isAlive() && round <= 10) {
        cout << "Round " << round << endl;

        // Player 1's turn
        cout << character1->getName() << "'s turn:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;

        int choice;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        clearInputBuffer();

        if (choice == 1) {
            character1->attack(*character2);
        } else if (choice == 2) {
            character1->healSelf();
        } else {
            cout << "Invalid choice. Skipping player's turn." << endl;
        }

        if (!character2->isAlive())
            break;

        // Player 2's turn
        cout << character2->getName() << "'s turn:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;

        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        clearInputBuffer();

        if (choice == 1) {
            character2->attack(*character1);
        } else if (choice == 2) {
            character2->healSelf();
        } else {
            cout << "Invalid choice. Skipping player's turn." << endl;
        }

        round++;
    }

    if (character1->isAlive() && character2->isAlive()) {
        cout << "The game ended in a tie after 10 rounds!" << endl;
    } else if (character1->isAlive()) {
        cout << character1->getName() << " wins!" << endl;
    } else if (character2->isAlive()) {
        cout << character2->getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
