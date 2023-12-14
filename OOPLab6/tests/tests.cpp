#include "../headers/NPC.hpp"
#include "../headers/Dragon.hpp"
#include "../headers/Knight.hpp"
#include "../headers/Pegas.hpp"
#include "../headers/Factory.hpp"
#include "../headers/Observers.hpp"

#include <gtest/gtest.h>

TEST(NPC_class_tests, getters) {
    std::shared_ptr<NPC> ptr = std::make_shared<Dragon>(2,2);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->get_x_value() == 2 && ptr->get_y_value() == 2);
}

TEST(NPC_class_tests, is_close_method_1) {
    std::shared_ptr<NPC> ptr1 = std::make_shared<Knight>(0,0);
    std::shared_ptr<NPC> ptr2 = std::make_shared<Pegas>(10,10);
    ASSERT_TRUE(ptr1->is_close(ptr2, 20));
}

TEST(NPC_class_tests, is_close_method_2) {
    std::shared_ptr<NPC> ptr1 = std::make_shared<Knight>(0,0);
    std::shared_ptr<NPC> ptr2 = std::make_shared<Pegas>(10,10);
    ASSERT_FALSE(ptr1->is_close(ptr2, 2));
}

TEST(Dragon_tests, Dragon_visitor_test_1) {
    DragonVisitor visitor;
    std::shared_ptr<Dragon> ptr = std::make_shared<Dragon>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Dragon_tests, Dragon_visitor_test_2) {
    DragonVisitor visitor;
    std::shared_ptr<Pegas> ptr = std::make_shared<Pegas>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(Dragon_tests, Dragon_visitor_test_3) {
    DragonVisitor visitor;
    std::shared_ptr<Knight> ptr = std::make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Dragon_class_tests, default_constructor_and_destructor) {
    Dragon s;
    s.~Dragon();
}

TEST(Dragon_class_tests, int_constructor) {
    Dragon s(2,2);
    ASSERT_TRUE(s.gettype() == 0 && s.get_x_value() == 2 && s.get_y_value() == 2);
}

TEST(Dragon_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<KnightVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(Dragon_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<DragonVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Dragon_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Pegas>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<PegasVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Pegas_tests, Pegas_visitor_test_1) {
    PegasVisitor visitor;
    std::shared_ptr<Dragon> ptr = std::make_shared<Dragon>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Pegas_tests, Pegas_visitor_test_2) {
    PegasVisitor visitor;
    std::shared_ptr<Pegas> ptr = std::make_shared<Pegas>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Pegas_tests, Pegas_visitor_test_3) {
    PegasVisitor visitor;
    std::shared_ptr<Knight> ptr = std::make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Pegas_class_tests, default_constructor_and_destructor) {
    Pegas d;
    d.~Pegas();
}

TEST(Pegas_class_tests, int_constructor) {
    Pegas d(2,2);
    ASSERT_TRUE(d.gettype() == 1 && d.get_x_value() == 2 && d.get_y_value() == 2);
}

TEST(Pegas_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Pegas>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<KnightVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Pegas_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Pegas>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<DragonVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(Pegas_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Pegas>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Pegas>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<PegasVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Knight_tests, Knight_visitor_test_1) {
    KnightVisitor visitor;
    std::shared_ptr<Dragon> ptr = std::make_shared<Dragon>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(Knight_tests, Knight_visitor_test_2) {
    KnightVisitor visitor;
    std::shared_ptr<Pegas> ptr = std::make_shared<Pegas>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Knight_tests, Knight_visitor_test_3) {
    KnightVisitor visitor;
    std::shared_ptr<Knight> ptr = std::make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Knight_class_tests, default_constructor_and_destructor) {
    Knight o;
    o.~Knight();
}

TEST(Knight_class_tests, int_constructor) {
    Knight o(2,2);
    ASSERT_TRUE(o.gettype() == 2 && o.get_x_value() == 2 && o.get_y_value() == 2); 
}

TEST(Knight_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Knight>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<DragonVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Knight_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Knight>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Pegas>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<PegasVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Knight_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Knight>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<KnightVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Factory_tests, create_1) {
    std::shared_ptr<NPC> ptr = Factory::Create(DragonType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_2) {
    std::shared_ptr<NPC> ptr = Factory::Create(KnightType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 2 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_3) {
    std::shared_ptr<NPC> ptr = Factory::Create(PegasType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 1 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_throw) {
    std::shared_ptr<NPC> ptr;
    ASSERT_ANY_THROW(ptr = Factory::Create(NpcType(534), 2, 2));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}