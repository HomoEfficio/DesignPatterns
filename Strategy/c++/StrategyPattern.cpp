#include <iostream>
using namespace std;

class IMoveStrategy
{
public:
    virtual ~IMoveStrategy() {}
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
    virtual ~IAttackStrategy() {}
    virtual void Attack() = 0;
};

class KickStrategy : public IAttackStrategy
{
public:
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
            if (this->moveStrategy) delete this->moveStrategy;
            if (this->attackStrategy) delete this->attackStrategy;
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
    Fighter* fighter = new Fighter();

    FlyingStrategy* flyingStrategy = new FlyingStrategy();
    WalkingStrategy* walkingStrategy = new WalkingStrategy();

    KickStrategy* kickStrategy = new KickStrategy();
    PunchStrategy* punchStrategy = new PunchStrategy();
    
    cout << "===== Flying + Kick =====" << endl;
    fighter->SetMoveStrategy(flyingStrategy);
    fighter->SetAttackStrategy(kickStrategy);

    fighter->Move();
    fighter->Attack();
}