#ifndef TROLL_H_INCLUDED
#define TROLL_H_INCLUDED

#include "enemy.h"
#include <string>
#include <cstdlib>
#include <sstream>

class Troll: public Enemy
{
protected:
    bool simple(int a)
{
    if (a == 2) {
        return 1;}
    if (a == 0 || a == 1 || a % 2 == 0)
    {
        return 0;
    }
    int i;
    for (i = 3; (i*i <= a)&&(a % i); i += 2) {}
    return (i*i > a);
}
    static const int c_TrollHealth = 50;
    static const int c_TrollAttack = 10;
    int my_answer;
public:
    static const int c_killScores = 100;

    Troll()
        :Enemy(c_TrollHealth, c_TrollAttack)
    {}

    std::string getQuest()
    {
        int num = 1 + rand()%100;

        stringstream question;
        question << "Is a " << num << " simple?" ;
        my_answer = simple(num);
        return question.str();
    }

    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
};

#endif
