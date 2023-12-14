#include "../headers/Factory.hpp"

std::shared_ptr<NPC> Factory::Create(const NpcType& type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch(type) {
        case NpcType::DragonType:
            result = std::make_shared<Dragon>(x, y);
            break;
        case NpcType::PegasType:
            result = std::make_shared<Pegas>(x, y);
            break;
        case NpcType::KnightType:
            result = std::make_shared<Knight>(x, y);
            break;
        default:
            throw std::invalid_argument("Unknown type of NPC:");
    }

    if (result) {
        result->subscribe(TextObserver::get());
        result->subscribe(FileObserver::get());
    }

    return result;
}