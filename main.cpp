#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>

class Entity
{
protected:
  std::string name;
  int health;

public:
  Entity(std::string name, int health) : name(name), health(health) {}

  virtual ~Entity() {}
  virtual void takeDamage(int damage)
  {
    health = health - damage;
  }
  virtual int getHealth() const { return health; }
  virtual std::string getName() const { return name; }
};

std::ostream &operator<<(std::ostream &os, const Entity &entity)
{
  os << entity.getName() << "(HP: " << entity.getHealth() << ")";
  return os;
}

class Player : public Entity
{
public:
  Player(std::string name, int health)
      : Entity(name, health) {}
  void printStatus() { std::cout << *this << std::endl; }
};

class Enemy : public Entity
{

public:
  Enemy(std::string type, int health) : Entity(type, health) {}
};

void encounter(Entity &hero, Entity &enemy)
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

  std::vector<std::unique_ptr<Entity>> entities;

  entities.push_back(std::make_unique<Player>("Hero", 100));
  entities.push_back(std::make_unique<Enemy>("Demon Lord", 100));

  std::vector<std::vector<char>> map(5, std::vector<char>(5, '.'));
  map[1][1] = 'P';
  map[3][3] = 'E';
  printMap(map);
  int playerX = 1;
  int playerY = 1;
  while (entities[0]->getHealth() > 0)
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
    if (playerX == 3 && playerY == 3 && entities[1]->getHealth() > 0)
    {
      encounter(*entities[0], *entities[1]);
      std::cout << "A battle has occured between the Hero and the Demon Lord!" << std::endl;
      std::cout << *entities[0] << std::endl;
      std::cout << *entities[1];
    }
  }
  return 0;
}