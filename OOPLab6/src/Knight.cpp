#include "../headers/Knight.hpp"

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

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

Knight::Knight(std::istream& in) : NPC(KnightType, in) {}

void Knight::save(std::ostream& out) {
    out  << KnightType << std::endl;
    NPC::save(out);
}

bool Knight::accept(const std::shared_ptr<FightVisitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Knight> defender = std::dynamic_pointer_cast<Knight>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fight_notify(defender, result);

    return result;
}

std::ostream& operator << (std::ostream& out, Knight& Knight) {
    out << "Knight: " << *static_cast<NPC*>(&Knight) << std::endl;
    return out;
}

void Knight::print() {
    std::cout << *this;
}