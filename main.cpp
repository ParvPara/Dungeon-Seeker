#include <string>
#include <iostream>

class Player {
private:
  std::string playerName;
  int playerHealth;

public:
  Player(std::string name, int health)
      : playerName(name), playerHealth(health) {};
  void printStatus() { std::cout << playerName;
    std::cout << playerHealth;
};
};

int main() { 
  
  Player hero("hero", 100);
  hero.printStatus();

  return 0; }