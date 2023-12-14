#include "../headers/Pegas.hpp"

bool PegasVisitor::visit(const std::shared_ptr<Dragon>& attacker) const {
    return false;
}

bool PegasVisitor::visit(const std::shared_ptr<Pegas>& attacker) const {
    return false;
}

bool PegasVisitor::visit(const std::shared_ptr<Knight>& attacker) const {
    return false;
}

Pegas::Pegas() : NPC(PegasType, 0, 0) {}

Pegas::Pegas(int x, int y) : NPC(PegasType, x, y) {}

Pegas::Pegas(std::istream& in) : NPC(PegasType, in) {}

void Pegas::save(std::ostream& out) {
    out << PegasType << std::endl;
    NPC::save(out);
}

bool Pegas::accept(const std::shared_ptr<FightVisitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Pegas> defender = std::dynamic_pointer_cast<Pegas>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fight_notify(defender, result);

    return result;
}

std::ostream& operator << (std::ostream& out, Pegas& Pegas) {
    out << "Pegas: " << *static_cast<NPC*>(&Pegas) << std::endl;
    return out;
}

void Pegas::print() {
    std::cout << *this;
}