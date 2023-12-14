#include "../headers/Dragon.hpp"
#include "../headers/DataMethods.hpp"


bool DragonVisitor::visit(const std::shared_ptr<Dragon>& defender) const {
    return false;
}

bool DragonVisitor::visit(const std::shared_ptr<Pegas>& defender) const {
    return true;
}

bool DragonVisitor::visit(const std::shared_ptr<Knight>& defender) const {
    return false;
}

Dragon::Dragon() : NPC(DragonType, 0, 0) {}

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) 
{
    rangeAttack = ATTACK_RANGE_D;
    rangeMove = MOVE_RANGE_D;
}

Dragon::Dragon(std::istream& in) : NPC(DragonType, in) 
{
    rangeAttack = ATTACK_RANGE_D;
    rangeMove = MOVE_RANGE_D;
}

void Dragon::save(std::ostream& out) {
    out << DragonType << std::endl;
    NPC::save(out);
}

bool Dragon::accept(const std::shared_ptr<FightVisitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Dragon> defender = std::dynamic_pointer_cast<Dragon>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    if (result)
    {
        int pointAttacker = DataMethods::throwTheDice();
        int pointDefender = DataMethods::throwTheDice();

        if (pointAttacker > pointDefender)
        {
            defender->mustDie();
            attacker->fight_notify(defender, result);
        }

    }


    return result; 
}

std::ostream& operator << (std::ostream& out, Dragon& Dragon) {
    out << "Dragon: " << *static_cast<NPC*>(&Dragon) << std::endl;
    return out;
}

void Dragon::print() {

    std::cout << *this;
}