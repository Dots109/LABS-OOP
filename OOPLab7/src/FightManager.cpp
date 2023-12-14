#include "../headers/FightManager.hpp"
#include <optional>

FightManager &FightManager::get()
{
    static FightManager inst;

    return inst;
}

void FightManager::addEvent(FightEvent &&event)
{
    std::lock_guard<std::shared_mutex> lock(_mtx);
    _events.push(event);
}

void FightManager::operator()()
{
    while (true)
    {
        if(timer >= MAX_TIME) {
            return;
        }
        std::optional<FightEvent> event;

        {
            std::lock_guard<std::shared_mutex> lock(_mtx);
            if (!_events.empty())
            {
                event = _events.back();
                _events.pop();
            }
        }

        if (event)
        {
            if (event->attacker->isAlive() && event->defender->isAlive())
            {
                event->defender->accept(visitors[event->attacker->gettype()], event->attacker);
            }
        }
    }
}