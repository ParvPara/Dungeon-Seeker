#include <iostream>
#include <string>

class Player {
private:
  std::string playerName;
  int playerHealth;

public:
  Player(std::string name, int health)
      : playerName(name), playerHealth(health) {}
  void printStatus() { std::cout << playerName << playerHealth; }
  void takeDamage(int Damage) {
      playerHealth = playerHealth - Damage;
    }
};

class Enemy {

private:
  std::string enemyType;
  int enemyHealth;

  public:
    Enemy(std::string type, int health) : enemyType(type), enemyHealth(health) {

    }
    void takeDamage(int Damage) {
      enemyHealth = enemyHealth - Damage;
    }

};

int main() {

  Player hero("hero", 100);
  hero.printStatus();

  return 0;
}