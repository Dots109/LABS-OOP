#pragma once

#include "NPC.hpp"

#define ATTACK_RANGE_K 10
#define MOVE_RANGE_K 30

struct KnightVisitor : public FightVisitor {
    bool visit(const std::shared_ptr<Dragon>&) const override;
    bool visit(const std::shared_ptr<Pegas>&) const override;
    bool visit(const std::shared_ptr<Knight>&) const override;
};

class Knight : public NPC {
    public:
        Knight();
        Knight(int, int);
        Knight(std::istream&);

        void save(std::ostream&) override;
        bool accept(const std::shared_ptr<FightVisitor>&, const std::shared_ptr<NPC>&) const override;
        friend std::ostream& operator << (std::ostream&, Knight&);
        void print() override;

        ~Knight() = default;
};