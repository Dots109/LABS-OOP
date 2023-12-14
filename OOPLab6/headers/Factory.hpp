#pragma once

#include "NPC.hpp"
#include "Pegas.hpp"
#include "Knight.hpp"
#include "Dragon.hpp"
#include "Observers.hpp"

class Factory {
    public:
        static std::shared_ptr<NPC> Create(const NpcType& type, int x, int y);
};