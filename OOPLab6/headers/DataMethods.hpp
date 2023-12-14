#pragma once

#include "NPC.hpp"
#include "Dragon.hpp"
#include "Knight.hpp"
#include "Pegas.hpp"
#include "Factory.hpp"

class DataMethods {
    public:
        static void save_array(const set_t& array, const std::string& filename);
        static set_t load_array(const std::string& filename);
};