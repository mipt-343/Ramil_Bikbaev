#include <iostream>
#include <list>

#include "Unit.h"
#include "Dragon.h"
#include "Hero.h"
#include "Troll.h"
#include "enemy.h"

using namespace std;

void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Dragon health: " << dragon.getHealth() << endl;
}

void playGame(list<Enemy*> &enemyList)
{
    Hero hero;
    bool gameOver = false;
    for (list<Enemy*>::iterator enemy = enemyList.begin();
            enemy != enemyList.end(); enemy++)
    {

        cout << "You have met a new " //<< (*enemy)->color()
                << " enemy. Fight!" << endl;

        while ((*enemy)->isAlive() && hero.isAlive())
        {
            hero.attack(**enemy);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            hero.addScores(Enemy::c_killScores);
            cout << "Ough! You have killed a enemy!" << endl;
        }
    }
    if (gameOver)
    {
        cout << "Game over! Your score is: " << hero.getScores() << endl;
    }
    else
    {
        cout << "You win! Your score is: " << hero.getScores() << endl;
    }
}

list<Enemy*> generateDragonList()
{
    list<Enemy*> enemyList;
    enemyList.push_back(new Troll());
    enemyList.push_back(new GreenDragon());
    enemyList.push_back(new RedDragon());
    enemyList.push_back(new BlackDragon());
    return enemyList;
}

int main()
{
    list<Enemy*> enemyList = generateDragonList();
    playGame(enemyList);
    return 0;
}
