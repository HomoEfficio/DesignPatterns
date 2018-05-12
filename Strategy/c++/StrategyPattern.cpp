#include <iostream>
#include <memory>
using namespace std;

class IMoveStrategy
{
public:
    virtual void Move() = 0;
};

class FlyingStrategy : public IMoveStrategy
{
public:
    void Move() override
    {
        cout << "FLYING..." << endl;
    }
};

class WalkingStrategy : public IMoveStrategy
{
public:
    void Move() override
    {
        cout << "WALKING..." << endl;
    }
};

class IAttackStrategy
{
public:
    virtual void Attack() = 0;
};

class KickStrategy : public IAttackStrategy
{
public:
    KickStrategy() { cout << "KickStrategy Constructor Is Invoked!!!" << endl; }
    void Attack() override
    {
        cout << "kick!!!" << endl;
    }
};

class PunchStrategy : public IAttackStrategy
{
public:
    void Attack() override
    {
        cout << "punch!!!" << endl;
    }
};

class Fighter
{
    private:
        IMoveStrategy* moveStrategy;
        IAttackStrategy* attackStrategy;

    public:
        Fighter() : moveStrategy(0) {}
        ~Fighter()
        {
            if (this->moveStrategy)
            {
                delete this->moveStrategy;
                cout << "moveStrategy is deleted" << endl;
            }
            if (this->attackStrategy)
            {
                delete this->attackStrategy;
                cout << "attackStrategy is deleted" << endl;
            }
        }

        void SetMoveStrategy(IMoveStrategy* moveStrategy)
        {
            if (this->moveStrategy) delete this->moveStrategy;
            this->moveStrategy = moveStrategy;
        }

        void SetAttackStrategy(IAttackStrategy* attackStrategy)
        {
            if (this->attackStrategy) delete this->attackStrategy;
            this->attackStrategy = attackStrategy;
        }

        void Move()
        {
            this->moveStrategy->Move();
        }

        void Attack()
        {
            this->attackStrategy->Attack();
        }
};

int main()
{
    // Fighter* fighter = new Fighter();
    unique_ptr<Fighter> fighter(new Fighter());

//    FlyingStrategy* flyingStrategy = new FlyingStrategy();
//    WalkingStrategy* walkingStrategy = new WalkingStrategy();
//
//    KickStrategy* kickStrategy = new KickStrategy();
//    PunchStrategy* punchStrategy = new PunchStrategy();

//    FlyingStrategy* flyingStrategy;
//    WalkingStrategy* walkingStrategy;
//
//    KickStrategy* kickStrategy;
//    PunchStrategy* punchStrategy;

    FlyingStrategy* flyingStrategy = new FlyingStrategy();
    WalkingStrategy* walkingStrategy;

    KickStrategy* kickStrategy;
    PunchStrategy* punchStrategy;

    KickStrategy kickStrategy1;

//    KickStrategy& kickStrategy2 = kickStrategy;
    
    cout << "===== Flying + Kick =====" << endl;
    fighter->SetMoveStrategy(flyingStrategy);
    fighter->SetAttackStrategy(kickStrategy);

    fighter->Move();
    fighter->Attack();

    // delete fighter;
}