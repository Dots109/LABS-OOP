#include "headers/Dragon.hpp"
#include "headers/Knight.hpp"
#include "headers/Pegas.hpp"
#include "headers/Factory.hpp"
#include "headers/Observers.hpp"
#include "headers/FightManager.hpp"
#include <thread>
#include <chrono>
#include <mutex>

#define MAX_X 200
#define MAX_Y 200

using namespace std::chrono_literals;

std::ostream& operator << (std::ostream& os, const set_t& array) {
    for (auto& elem : array) {
        if(elem->isAlive()){
            elem->print();
        }
    }
    return os;
}

int main() {
    std::mutex print;
    srand(time(NULL));

    set_t array;

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 150; ++i) {
        array.insert(Factory::Create(NpcType(std::rand() % 3),
        std::rand() % 200,
        std::rand() % 200));
    }
    std::cout << std::endl << array << std::endl;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array]()
                            {
            while (true)
            {
                if(timer >= MAX_TIME) {
                    break;
                }
                // move phase
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->isAlive()){
                            int randNumbMinX = (std::rand() % 2) * 2 - 1;
                            int randNumbMinY = (std::rand() % 2) * 2 - 1;

                            int distance = std::rand() % npc->getRangeMove();

                            int shiftX = distance * randNumbMinX;
                            int shiftY = (npc->getRangeMove() - distance) * randNumbMinY;
                            npc->move(shiftX, shiftY, MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->isAlive() && other->isAlive())
                            if (npc->isClose(other)) {
                                FightManager::get().addEvent({npc, other});
                            }
                std::this_thread::sleep_for(1s);
            } });

    while (true)
    {
        if(timer >= MAX_TIME) {
            break;
        }
        const int grid{40}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            
            std::array<char, grid * grid> fields{0};
            std::lock_guard<std::mutex> lck(print);
            for (std::shared_ptr<NPC> npc : array)
            {
                int i = npc->get_x_value() / step_x;
                int j = npc->get_y_value() / step_y;
                if (npc->isAlive())
                {
                    switch (npc->gettype())
                    {
                    case DragonType:
                        fields[i + grid * j] = 'D';
                        break;
                    case KnightType:
                        fields[i + grid * j] = 'K';
                        break;
                    case PegasType:
                        fields[i + grid * j] = 'P';
                        break;

                    default:
                        break;
                    }
                }
                else {
                    fields[i + grid * j] = '+';
                    }
            }
            
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::cout.flush();
        }
        std::this_thread::sleep_for(1s);
        ++timer;
        std::cout << "\n\n\n" << timer << "\n\n\n";
    };

    move_thread.join();
    fight_thread.join();

    std::cout << "\n" << array << std::endl;

    return 0;
}