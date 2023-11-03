#include "../header/square.h"
#include "../header/triangle.h"
#include "../header/octagon.h"
#include "../header/arrayFig.h"
#include "../header/figure.h"

#include <gtest/gtest.h>

TEST(test_00, SquareConstructorTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Square sq1(test1);
    Square sq4(sq);
    Square sq5(sq);
    Square sq6(std::move(sq));
    Square sq7(std::move(sq));
    ASSERT_TRUE(sq == sq1 && sq4 == sq5 && sq6 == sq7);
}

TEST(test_01, SquareOperatorCopyLvalueTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Square sq1 = sq;
    ASSERT_TRUE(sq == sq1);
}

TEST(test_02, SquareOperatorCopyRvalueTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Square sq1 = std::move(sq);
    ASSERT_TRUE(sq == sq1);
}

TEST(test_03, SquareOperatorEqualTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Square sq1(test1);
    ASSERT_TRUE(sq == sq1);
}

TEST(test_04, SquareCalculateGeomCenterTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Coord a;
    a.x = 2;
    a.y = 2;
    Coord b = sq.calculateGeomCentr();
    ASSERT_TRUE(a.x - b.x < pow(10, -3) && a.y - b.y < pow(10, -3));
}

TEST(test_05, FigureCalculateLengthOfSideTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    ASSERT_TRUE(sq.calculateLengthOfSide() - 4 < pow(10, -3));
}

TEST(test_06, checkValidPointsSquareTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    ASSERT_TRUE(sq.checkValidPointsSquare(test1));
}

TEST(test_07, checkValidPointsSquareTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 2};
    Coord s4 = {4, 1};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    ASSERT_THROW(Square sq(test1), std::invalid_argument);
}

TEST(test_08, OperatorDoubleTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);

    ASSERT_TRUE((double)sq - 16 < pow(10, -3));
}

TEST(test_10, TriangleConstructorTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 0};
    Coord t2 = {9, 0};
    Coord t3 = {4.5, 9*sqrt(3)/2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Triangle tr1(test1);
    Triangle tr2(test1);
    Triangle tr3(test1);
    Triangle tr4(tr);
    Triangle tr5(tr);
    Triangle tr6(std::move(tr));
    Triangle tr7(std::move(tr));
    ASSERT_TRUE(tr == tr1 && tr4 == tr5 && tr6 == tr7);
}

TEST(test_11, checkValidPointsTriangleTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    ASSERT_TRUE(tr.checkValidPointsTriangle(test1));
}

TEST(test_12, checkValidPointsTriangleTest)
{
    std::vector<Coord> test1;
    Coord t1 = {3, 0};
    Coord t2 = {1, 0};
    Coord t3 = {0, 5};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    ASSERT_THROW(Triangle tr(test1), std::invalid_argument);
}

TEST(test_13, TriangleOperatorCopyLvalueTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Triangle tr1 = tr;
    ASSERT_TRUE(tr == tr1);
}

TEST(test_14, TriangleOperatorCopyRvalueTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Triangle tr1 = std::move(tr);;
    ASSERT_TRUE(tr == tr1);
}

TEST(test_15, TriangleOperatorEqualTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Triangle tr1(test1);
    ASSERT_TRUE(tr == tr1);
}

TEST(test_16, TriangleCalculateGeomCenterTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Coord a;
    a.x = 0.5;
    a.y = 1;
    Coord b = tr.calculateGeomCentr();
    ASSERT_TRUE(a.x - b.x < pow(10, -3) && a.y - b.y < pow(10, -3));
}

TEST(test_17, FigureCalculateLengthOfSideTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 0};
    Coord t2 = {1, 0};
    Coord t3 = {0, 1};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    ASSERT_TRUE(tr.calculateLengthOfSide() - 1 < pow(10, -3));
}

TEST(test_18, OperatorDoubleTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 0};
    Coord t2 = {10, 0};
    Coord t3 = {5, 5*sqrt(3)};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    ASSERT_TRUE(round((double)tr) == round(43.3013));
}

TEST(test_19, TestConstructorAngleSquare_60Degrees)
{
    std::vector<Coord> test1;
    Coord s1 = {9, 9.73205};
    Coord s2 = {6.26795, 9};
    Coord s3 = {7, 6.26795};
    Coord s4 = {9.73205, 7};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);

    Square sq (test1);
    Square sqC(test1);
    ASSERT_TRUE(sq == sqC);
}

TEST(test_20, TestAreaANDLengthSideAngleSquare_60Degrees)
{
    std::vector<Coord> test1;
    Coord s1 = {9, 9.73205};
    Coord s2 = {6.26795, 9};
    Coord s3 = {7, 6.26795};
    Coord s4 = {9.73205, 7};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);

    Square sq (test1);

    double areaS = double(sq);
    ASSERT_TRUE(round(areaS) == round(7.99999) && round(sq.calculateLengthOfSide()) == round(2.82843));
}

TEST(test_21, TestConstructorAngleTriangle_60Degrees)
{
    std::vector<Coord> test1;
    Coord t1 = {10, 11.4641};
    Coord t2 = {4, 8};
    Coord t3 = {10, 4.5359};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);

    Triangle tr(test1);
    Triangle trC(test1);
    ASSERT_TRUE(tr == trC);
}

TEST(test_22, TestAreaANDLengthSideAngleTriangle_60Degrees)
{
    std::vector<Coord> test1;
    Coord t1 = {10, 11.4641};
    Coord t2 = {4, 8};
    Coord t3 = {10, 4.5359};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);

    Triangle tr(test1);

    double areaT = double(tr);
    ASSERT_TRUE(round(areaT) == round(20.7846) && round(tr.calculateLengthOfSide()) == round(6.9282));
}

TEST(test_23, TestConstructorAngleOctagon_60Degrees)
{
    std::vector<Coord> vec1;
    Coord oc1= {12, 5.19615};
    Coord oc2= {7.44709, 5.79555};
    Coord oc3= {3.80385, 3};
    Coord oc4= {3.20445, -1.55291};
    Coord oc5= {6, -5.19615};
    Coord oc6= {10.5529, -5.79555};
    Coord oc7= {14.1962, -3};
    Coord oc8= {14.7956, 1.55291};
    
    vec1.push_back(oc1);
    vec1.push_back(oc2);
    vec1.push_back(oc3);
    vec1.push_back(oc4);
    vec1.push_back(oc5);
    vec1.push_back(oc6);
    vec1.push_back(oc7);
    vec1.push_back(oc8);
    Octagon oc(vec1);
    Octagon ocC(vec1);
    ASSERT_TRUE(oc == ocC);
}

TEST(test_24, TestAreaANDLengthSideAngleOctagon_60Degrees)
{
    std::vector<Coord> vec1;
    Coord oc1= {12, 5.19615};
    Coord oc2= {7.44709, 5.79555};
    Coord oc3= {3.80385, 3};
    Coord oc4= {3.20445, -1.55291};
    Coord oc5= {6, -5.19615};
    Coord oc6= {10.5529, -5.79555};
    Coord oc7= {14.1962, -3};
    Coord oc8= {14.7956, 1.55291};
    
    vec1.push_back(oc1);
    vec1.push_back(oc2);
    vec1.push_back(oc3);
    vec1.push_back(oc4);
    vec1.push_back(oc5);
    vec1.push_back(oc6);
    vec1.push_back(oc7);
    vec1.push_back(oc8);
    Octagon oc(vec1);

    double areaO = double(oc);
    ASSERT_TRUE(round(areaO) == round(101.823) && round(oc.calculateLengthOfSide()) == round(4.5922));
}

TEST(test_25, OctagonConstructorTest)
{
    std::vector<Coord> test1;
    Coord t1 = {1, 0};
    Coord t2 = {0.707,0.707};
    Coord t3 = {0,1};
    Coord t4 = {-0.707, 0.707};
    Coord t5 = {-1,0};
    Coord t6 = {-0.707, -0.707};
    Coord t7 = {0,-1};
    Coord t8 = {0.707,-0.707};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    test1.push_back(t4);
    test1.push_back(t5);
    test1.push_back(t6);
    test1.push_back(t7);
    test1.push_back(t8);
    Octagon oc(test1);
    Octagon oc1(test1);
    Octagon oc2(test1);
    Octagon oc3(test1);
    Octagon oc4(oc);
    Octagon oc5(oc);
    Octagon oc6(std::move(oc));
    Octagon oc7(std::move(oc));
    ASSERT_TRUE(oc == oc1 && oc4 == oc5 && oc6 == oc7);
}

TEST(test_26, checkValidPointsOctagonTest)
{
    std::vector<Coord> test1;
    Coord oc1 = {6, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {1, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {0, 1};
    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    
    ASSERT_THROW(Octagon oc(test1), std::invalid_argument);
}

TEST(test_27, OctagonOperatorCopyLvalueTest)
{
    std::vector<Coord> test1;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);

    Octagon oc(test1);
    Octagon ocC = oc;

    ASSERT_TRUE(oc == ocC);
}

TEST(test_28, OctagonOperatorCopyRvalueTest)
{
    std::vector<Coord> test1;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    Octagon oc(test1);
    Octagon ocC = std::move(oc);

    ASSERT_TRUE(oc == ocC);
}

TEST(test_29, OctagonOperatorEqualTest)
{
    std::vector<Coord> test1;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    Octagon oc(test1);
    Octagon ocC(oc);

    ASSERT_TRUE(oc == ocC);
}

TEST(test_30, OctagonCalculateGeomCenterTest)
{
    std::vector<Coord> test1;
    Coord oc1= {5, 4};
    Coord oc2= {4, 5};
    Coord oc3= {2, 5};
    Coord oc4= {1, 4};
    Coord oc5= {1, 2};
    Coord oc6= {2, 1};
    Coord oc7= {4, 1};
    Coord oc8= {5, 2};

    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    Octagon oc(test1);

    Coord a;
    a.x = 3;
    a.y = 3;
    Coord b = oc.calculateGeomCentr();

    ASSERT_TRUE(a.x - b.x < pow(10, -3) && a.y - b.y < pow(10, -3));
}

TEST(test_31, OctagonCalculateLengthOfSideTest)
{
    std::vector<Coord> test1;
    Coord oc1= {5, 4};
    Coord oc2= {4, 5};
    Coord oc3= {2, 5};
    Coord oc4= {1, 4};
    Coord oc5= {1, 2};
    Coord oc6= {2, 1};
    Coord oc7= {4, 1};
    Coord oc8= {5, 2};

    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    Octagon oc(test1);

    ASSERT_TRUE(oc.calculateLengthOfSide() - 2 < pow(10, -3));
}

TEST(test_32, OctagonOperatorDoubleTest)
{
    std::vector<Coord> test1;
    Coord oc1= {5, 4};
    Coord oc2= {4, 5};
    Coord oc3= {2, 5};
    Coord oc4= {1, 4};
    Coord oc5= {1, 2};
    Coord oc6= {2, 1};
    Coord oc7= {4, 1};
    Coord oc8= {5, 2};

    test1.push_back(oc1);
    test1.push_back(oc2);
    test1.push_back(oc3);
    test1.push_back(oc4);
    test1.push_back(oc5);
    test1.push_back(oc6);
    test1.push_back(oc7);
    test1.push_back(oc8);
    Octagon oc(test1);

    ASSERT_TRUE(round((double)oc) == round(9.65685));
}

TEST(test_33, ArrayFigureConstructorTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    
    Square sq(test1);

    std::vector<Coord> test2;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test2.push_back(t1);
    test2.push_back(t2);
    test2.push_back(t3);

    Triangle tr(test2);

    std::vector<Coord> test3;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test3.push_back(oc1);
    test3.push_back(oc2);
    test3.push_back(oc3);
    test3.push_back(oc4);
    test3.push_back(oc5);
    test3.push_back(oc6);
    test3.push_back(oc7);
    test3.push_back(oc8);

    Octagon oc(test3);

    ArrayFig a;
    a.pushBack(&sq);
    a.pushBack(&tr);
    a.pushBack(&oc);

    EXPECT_EQ(a.getSize(), 3);
}

TEST(test_34, ArrayFigureDeleteToIndexANDPushTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    
    Square sq(test1);

    std::vector<Coord> test2;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test2.push_back(t1);
    test2.push_back(t2);
    test2.push_back(t3);

    Triangle tr(test2);

    std::vector<Coord> test3;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test3.push_back(oc1);
    test3.push_back(oc2);
    test3.push_back(oc3);
    test3.push_back(oc4);
    test3.push_back(oc5);
    test3.push_back(oc6);
    test3.push_back(oc7);
    test3.push_back(oc8);

    Octagon oc(test3);

    ArrayFig a;
    a.pushBack(&sq);
    a.pushBack(&tr);
    a.pushBack(&oc);

    a.deleteToIndex(2);
    a.deleteToIndex(1);

    a.pushBack(&oc);

    EXPECT_EQ(a.getSize(), 2);
}

TEST(test_35, ArrayFigureDeleteToIndexANDPushTest)
{
    std::vector<Coord> test1;
    Coord s1 = {4, 4};
    Coord s2 = {0, 4};
    Coord s3 = {0, 0};
    Coord s4 = {4, 0};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    
    Square sq(test1);

    std::vector<Coord> test2;
    Coord t1 = {0, 1};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, 2};
    test2.push_back(t1);
    test2.push_back(t2);
    test2.push_back(t3);

    Triangle tr(test2);

    std::vector<Coord> test3;
    Coord oc1 = {4, 3};
    Coord oc2 = {3, 4};
    Coord oc3 = {1, 4};
    Coord oc4 = {0, 3};
    Coord oc5 = {0, 1};
    Coord oc6 = {1, 0};
    Coord oc7 = {3, 0};
    Coord oc8 = {4, 1};
    test3.push_back(oc1);
    test3.push_back(oc2);
    test3.push_back(oc3);
    test3.push_back(oc4);
    test3.push_back(oc5);
    test3.push_back(oc6);
    test3.push_back(oc7);
    test3.push_back(oc8);

    Octagon oc(test3);

    ArrayFig a;
    a.pushBack(&sq);
    a.pushBack(&tr);
    a.pushBack(&oc);

    EXPECT_EQ(round((double)a), round(26.5229));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}