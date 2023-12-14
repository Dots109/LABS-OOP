#pragma once

#include "Factory.hpp"
#include <unordered_map>

inline std::unordered_map<NpcType, std::shared_ptr<FightVisitor>> visitors = {
    {DragonType, std::make_shared<DragonVisitor>()},
    {PegasType, std::make_shared<PegasVisitor>()},
    {KnightType, std::make_shared<KnightVisitor>()}
};

class DataMethods {
    public:
        static void save_array(const set_t& array, const std::string& filename);
        static set_t load_array(const std::string& filename);
        static int throwTheDice();
};