#pragma once

#include <iostream>
#include <fstream>
#include <mutex>


#include "NPC.hpp"


class TextObserver : public IFightObserver {
    private:
    std::mutex obsT;
        TextObserver() {};
    public:
        static std::shared_ptr<IFightObserver> get();
        void on_fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;
};

class FileObserver : public IFightObserver {
    private:
        FileObserver() {};
        std::string NPCname(const NpcType& type);
        std::ofstream fs;
        std::mutex obsF;
    public:
        static std::shared_ptr<IFightObserver> get();
        void on_fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;
};