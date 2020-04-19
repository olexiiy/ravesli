#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <chrono>
#include <numeric>
#include <ctime>
class IAction
{
public:
    virtual void Action() = 0;
};

class CatAction : public IAction
{
    public:
    virtual void Action() override
    {
         std::cout << "гладим кота" << std::endl;
    }
};

class TeaAction : public IAction
{
    public:
    virtual void Action() override
    {
         std::cout << "пьём чай " << std::endl;
    }
};
class DogAction : public IAction
{
    public:
    virtual void Action() override
    {
         std::cout << "гуляем с собакой" << std::endl;
    }
};

class SleepAction : public IAction
{
    public:
    virtual void Action() override
    {
         std::cout << "спим" << std::endl;
    }
};
int main()
{
    setlocale(LC_ALL, "ru_RU"); 
    srand(time(NULL));
   IAction* arr[] = 
   {    
        &CatAction(),
       &DogAction(),
       &TeaAction(),
       &SleepAction()
   };
   std::random_shuffle(std::begin(arr), std::end(arr));
    for(auto element : arr)
        element->Action();
    std::cout << std:: endl;
  std::cout << std::endl;


    return 0;
}
