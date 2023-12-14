#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <random>
#include <fstream>
#include <set>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <time.h>

struct NPC;
struct Dragon;
struct Pegas;
struct Knight;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    DragonType = 0,
    PegasType = 1,
    KnightType = 2
};

const int NPC_COUNT = 3;

struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC>&, const std::shared_ptr<NPC>&, bool) = 0;
};

struct FightVisitor {
    virtual bool visit(const std::shared_ptr<Dragon>&) const = 0;
    virtual bool visit(const std::shared_ptr<Pegas>&) const = 0;
    virtual bool visit(const std::shared_ptr<Knight>&) const = 0;
};

class NPC : public std::enable_shared_from_this<NPC> {
    protected:
        NpcType type;
        int x;
        int y;
        std::vector<std::shared_ptr<IFightObserver>> observers;
    public:
        NPC(NpcType, int, int);
        NPC(NpcType, std::istream&);

        NpcType& gettype();
        int get_x_value();
        int get_y_value();

        void subscribe(const std::shared_ptr<IFightObserver>&);
        void fight_notify(const std::shared_ptr<NPC>&, bool);
        bool is_close(const std::shared_ptr<NPC>&, size_t) const;
        
        virtual bool accept(const std::shared_ptr<FightVisitor>&, const std::shared_ptr<NPC>&) const = 0;
        virtual void save(std::ostream&);
        virtual void print() = 0;

        friend std::ostream& operator << (std::ostream&, NPC&);

        ~NPC() = default;
};