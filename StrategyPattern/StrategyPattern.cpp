// StrategyPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum criteria { LessMoney = 0, LessTime, familyFun };

//Abstract base class
class TravelStrategy
{
private:
public:
    virtual ~TravelStrategy() {}
    virtual void travel() = 0;
};

//Concreate class
class BusTravel : public TravelStrategy
{
public:
    void travel()
    {
        cout << "Wish you happy bus travel!" << endl;
    }
};

//Concreate class
class TrainTravel : public TravelStrategy
{
public:
    void travel()
    {
        cout << "Wish you happy train travel!" << endl;
    }
};

//Concreate class
class FlightTravel : public TravelStrategy
{
public:
    void travel()
    {
        cout << "Wish you happy flight travel!" << endl;
    }
};

//strategy context class
class TravelPlannerContext
{
private:
    //Abstract base strategy class pointer
    TravelStrategy *ptrTravelStrategy_;
    //To set criteria
    criteria my_criteria;
    
public:
    TravelPlannerContext()
    {
        ptrTravelStrategy_ = NULL;
    }

    ~TravelPlannerContext()
    {
        if (ptrTravelStrategy_ != NULL)
        {
            delete ptrTravelStrategy_;
        }        
    }
    
    void setCriteria(criteria cta)
    {
        my_criteria = cta;
    }

    criteria getCriteria()
    {
        return my_criteria;
    }

    void PlanTravel()
    {
        if (my_criteria == LessMoney)
        {
            ptrTravelStrategy_ = new BusTravel();
        }
        else if (my_criteria == LessTime)
        {
            ptrTravelStrategy_ = new FlightTravel();
        }
        else if (my_criteria == familyFun)
        {
            ptrTravelStrategy_ = new TrainTravel();
        }

        if (ptrTravelStrategy_ != NULL)
            ptrTravelStrategy_->travel();
    }
};

//client
int main()
{
    TravelPlannerContext objTravelPlannerContext;
    //If less money, I prefer bus travel
    objTravelPlannerContext.setCriteria(LessMoney);
    objTravelPlannerContext.PlanTravel();
    //if for family fun I prefer train travel
    objTravelPlannerContext.setCriteria(familyFun);
    objTravelPlannerContext.PlanTravel();
    //if less time I prefer flight travel
    objTravelPlannerContext.setCriteria(LessTime);
    objTravelPlannerContext.PlanTravel();

    return 0;
}



