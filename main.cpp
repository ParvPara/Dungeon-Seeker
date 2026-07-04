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
};

class Enemy {

private:
  std::string enemyType;
  int enemyHealth;

  public:
    Enemy(std::string type, int health) : enemyType(type), enemyHealth(health) {
      
    }

};

int main() {

  Player hero("hero", 100);
  hero.printStatus();

  return 0;
}