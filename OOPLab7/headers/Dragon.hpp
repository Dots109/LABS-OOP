#pragma once

#include "NPC.hpp"

#define ATTACK_RANGE_D 30
#define MOVE_RANGE_D 50

struct DragonVisitor : public FightVisitor {
    bool visit(const std::shared_ptr<Dragon>&) const override;
    bool visit(const std::shared_ptr<Pegas>&) const override;
    bool visit(const std::shared_ptr<Knight>&) const override;
};

class Dragon : public NPC {
    public:
        Dragon();
        Dragon(int, int);
        Dragon(std::istream&);

        void save(std::ostream&) override;
        bool accept(const std::shared_ptr<FightVisitor>&, const std::shared_ptr<NPC>&) const override;
        friend std::ostream& operator << (std::ostream&, Dragon&);
        void print() override;

        ~Dragon() = default;
};