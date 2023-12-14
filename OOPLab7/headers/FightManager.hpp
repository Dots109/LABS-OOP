#pragma once

#include "DataMethods.hpp"
#include <queue>
#include <shared_mutex>

inline int timer = 0;
#define MAX_TIME 30


struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager 
{
public:
    FightManager() = default;

    static FightManager & get();
    void addEvent(FightEvent && event);
    void operator()();

private:
    std::queue<FightEvent> _events;
    std::shared_mutex _mtx;
};