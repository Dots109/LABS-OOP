#pragma once

#include "NPC.hpp"

#define ATTACK_RANGE_P 10
#define MOVE_RANGE_P 30

struct PegasVisitor : public FightVisitor {
    bool visit(const std::shared_ptr<Dragon>&) const override;
    bool visit(const std::shared_ptr<Pegas>&) const override;
    bool visit(const std::shared_ptr<Knight>&) const override;
};

class Pegas : public NPC {
    public:
        Pegas();
        Pegas(int, int);
        Pegas(std::istream&);

        void save(std::ostream&) override;
        bool accept(const std::shared_ptr<FightVisitor>&, const std::shared_ptr<NPC>&) const override;
        friend std::ostream& operator << (std::ostream&, Pegas&);
        void print() override;

        ~Pegas() = default;
};