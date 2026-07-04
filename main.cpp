#include <string>
#include <iostream>

using namespace std;

class Player {
private:
  std::string playerName;
  int playerHealth;

public:
  Player(std::string name, int health)
      : playerName(name), playerHealth(health) {};
  void printStatus() { cout << playerName;
    cout << playerHealth;
};

int main() { return 0; }