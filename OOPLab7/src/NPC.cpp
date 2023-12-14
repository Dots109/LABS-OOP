#include "../headers/NPC.hpp"


NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y), alive(true) {}

NPC::NPC(NpcType t, std::istream& in) : type(t) {
    in >> x;
    in >> y;
}

void NPC::move(int shiftX, int shiftY, int maxX, int maxY)
{
    std::lock_guard<std::mutex> lock(fightNF);
    if ((x + shiftX >= 0) && (x + shiftX <= maxX)) {
        x += shiftX;
    }

    if ((y + shiftY >= 0) && (y + shiftY <= maxY)) {
        y += shiftY;
    }
}

bool NPC::isAlive()
{
    std::lock_guard<std::mutex> lock(fightNF);
    return alive;
}

void NPC::mustDie()
{
    std::lock_guard<std::mutex> lock(fightNF);
    alive = false;
}

void NPC::subscribe(const std::shared_ptr<IFightObserver>& observer) {
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC>& defender, bool win) {
    for (auto& o : observers) {
        o->on_fight(shared_from_this(), defender, win);
    }
}

bool NPC::isClose(const std::shared_ptr<NPC>& other) {
    std::lock_guard<std::mutex> lock(fightNF);
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(rangeAttack, 2)) {
        return true;
    } 
    return false;
}

int NPC::get_x_value() {
    std::lock_guard<std::mutex> lock(fightNF);
    return x;
}

int NPC::get_y_value() {
    std::lock_guard<std::mutex> lock(fightNF);
    return y;
}

NpcType& NPC::gettype() {
    std::lock_guard<std::mutex> lock(fightNF);
    return type;
}

int NPC::getRangeMove() {
    std::lock_guard<std::mutex> lock(fightNF);
    return rangeMove;
}

int NPC::getAttackRange() {
    std::lock_guard<std::mutex> lock(fightNF);
    return rangeAttack;
}

void NPC::save(std::ostream& os) {
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream& operator << (std::ostream& os, NPC& npc) {
    os << "{x:" << npc.x << ", y:" << npc.y << "}";
    return os;
}