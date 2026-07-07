#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Player
{
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

class Enemy
{

private:
  std::string enemyType;
  int enemyHealth;

public:
  Enemy(std::string type, int health) : enemyType(type), enemyHealth(health) {}
  void takeDamage(int Damage) { enemyHealth = enemyHealth - Damage; }

  int getHealth() const { return enemyHealth; }
};

void encounter(Player &hero, Enemy &enemy)
{
  hero.takeDamage(10);
  enemy.takeDamage(20);
}

void printMap(const std::vector<std::vector<char>> &map)
{
  for (const auto &row : map)
  {
    for (char cell : row)
    {
      std::cout << cell << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{

  Player hero("hero", 100);
  Enemy enemy("Demon Lord", 100);

  std::vector<std::vector<char>> map(5, std::vector<char>(5, '.'));
  map[1][1] = 'P';
  map[3][3] = 'E';
  printMap(map);
  int playerX = 1;
  int playerY = 1;
  while (hero.getHealth() > 0)
  {
    char input;
    printMap(map);
    std::cout << "Enter move (W/A/S/D) to move, Q to quit";
    std::cin >> input;
    if (input == 'Q' || input == 'q')
    {
      break;
    }
    switch (input)
    {
    case 'W':
    case 'w':
      if (playerY > 0)
      {
        map[playerY][playerX] = '.';
        playerY = playerY - 1;
        map[playerY][playerX] = 'P';
      }

      break;

    case 'A':
    case 'a':
      if (playerX > 0)
      {
        map[playerY][playerX] = '.';
        playerX = playerX - 1;
        map[playerY][playerX] = 'P';
      }
      break;

    case 'S':
    case 's':
      if (playerY < 4)
      {
        map[playerY][playerX] = '.';
        playerY = playerY + 1;
        map[playerY][playerX] = 'P';
      }

      break;

    case 'D':
    case 'd':
      if (playerX < 4)
      {
        map[playerY][playerX] = '.';
        playerX = playerX + 1;
        map[playerY][playerX] = 'P';
      }

      break;

    default:
      break;
    }
    if(playerX == 3 && playerY == 3 && enemy.getHealth() > 0) {
      encounter(hero, enemy);
      std::cout << "A battle has occured between the Hero and the Demon Lord!" << std::endl;
      std::cout << hero.getHealth() << std::endl;
      std::cout << enemy.getHealth();
    }
  }
  return 0;
}