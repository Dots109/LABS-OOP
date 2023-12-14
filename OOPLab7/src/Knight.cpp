#include "../headers/Knight.hpp"
#include "../headers/DataMethods.hpp"

bool KnightVisitor::visit(const std::shared_ptr<Dragon>& defender) const {
    return true;
}

bool KnightVisitor::visit(const std::shared_ptr<Pegas>& defender) const {
    return false;
}

bool KnightVisitor::visit(const std::shared_ptr<Knight>& defender) const {
    return false;
}

Knight::Knight() : NPC(KnightType, 0, 0) {}

Knight::Knight(int x, int y) : NPC(KnightType, x, y) 
{
    rangeAttack = ATTACK_RANGE_K;
    rangeMove = MOVE_RANGE_K;
}

Knight::Knight(std::istream& in) : NPC(KnightType, in) 
{
    rangeAttack = ATTACK_RANGE_K;
    rangeMove = MOVE_RANGE_K;
}

void Knight::save(std::ostream& out) {
    out  << KnightType << std::endl;
    NPC::save(out);
}

bool Knight::accept(const std::shared_ptr<FightVisitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Knight> defender = std::dynamic_pointer_cast<Knight>(npc_ptr);

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

std::ostream& operator << (std::ostream& out, Knight& Knight) {
    out << "Knight: " << *static_cast<NPC*>(&Knight) << std::endl;
    return out;
}

void Knight::print() {
    std::cout << *this;
}