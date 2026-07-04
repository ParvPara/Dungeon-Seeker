#include <iostream>
#include <ostream>
#include <string>

class Player {
private:
  std::string playerName;
  int playerHealth;

public:
  Player(std::string name, int health)
      : playerName(name), playerHealth(health) {}
  void printStatus() { std::cout << playerName << playerHealth; }
  void takeDamage(int Damage) { playerHealth = playerHealth - Damage; }
  int getHealth() const { return playerHealth; }
};

class Enemy {

private:
  std::string enemyType;
  int enemyHealth;

public:
  Enemy(std::string type, int health) : enemyType(type), enemyHealth(health) {}
  void takeDamage(int Damage) { enemyHealth = enemyHealth - Damage; }

  int getHealth() const { return enemyHealth; }
};

void encounter(Player &hero, Enemy &enemy) {
  hero.takeDamage(10);
  enemy.takeDamage(20);
}

int main() {

  Player hero("hero", 100);
  hero.printStatus();
  Enemy enemy("Demon Lord", 100);

  std::cout << "Before encounter" << std::endl;
  std::cout << "Hero HP: " << hero.getHealth() << std::endl;
  std::cout << "Enemy HP: " << enemy.getHealth() << std::endl;

  encounter(hero, enemy);

  std::cout << "After encounter" << std::endl;
  std::cout << "Hero HP: " << hero.getHealth() << std::endl;
  std::cout << "Enemy HP: " << enemy.getHealth() << std::endl;

  return 0;
}