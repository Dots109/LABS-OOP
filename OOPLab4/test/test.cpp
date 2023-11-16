#include "../header/figure.h"
#include "../header/square.h"
#include "../header/triangle.h"
#include "../header/octagon.h"
#include "../header/functionDArray.h"

#include <gtest/gtest.h>

TEST(test_01, DynamicArrayConstructorLongLong)
{
    DArray<long long> intArray1;
    DArray<long long> intArray2{1, 2, 3, 4};
    DArray<long long> intArray3(intArray2);
    DArray<long long> intArray4(std::move(intArray2));

    ASSERT_TRUE((intArray1 == intArray2) && (intArray3 == intArray4));
}

TEST(test_02, DynamicArrayConstructorFloat)
{
    DArray<float> floatArray1;
    DArray<float> floatArray2{0.5, 1.33333, 123213123.2, 0.0003};
    DArray<float> floatArray3(floatArray2);
    DArray<float> floatArray4(std::move(floatArray2));

    ASSERT_TRUE((floatArray1 == floatArray2) && (floatArray3 == floatArray4));
}

TEST(test_03, DynamicArrayConstructorLongDouble)
{
    DArray<std::pair<long double, long double>> pairLDArray1;
    DArray<std::pair<long double, long double>> pairLDArray2{{0.5, 1.33333}, {123213123.2, 0.0003}};
    DArray<std::pair<long double, long double>> pairLDArray3(pairLDArray2);
    DArray<std::pair<long double, long double>> pairLDArray4(std::move(pairLDArray2));

    ASSERT_TRUE((pairLDArray1 == pairLDArray2) && (pairLDArray3 == pairLDArray4));
}

TEST(test_04, DynamicArrayPushBackInt)
{
    DArray<int> intArray1{1, 2, 3};
    DArray<int> intArray2;

    intArray1.pushBack(4);
    intArray2.pushBack(1);
    intArray2.pushBack(2);
    intArray2.pushBack(3);
    intArray2.pushBack(4);
    
    ASSERT_TRUE(intArray1 == intArray2);
}

TEST(test_05, DynamicArrayPushBacPushBackDouble)
{
    DArray<std::pair<double,double>> array1{{0.5, 1}, {3.25, 0.3}};
    DArray<std::pair<double,double>> array2;

    array1.pushBack({0.5, 0.005});
    array2.pushBack({0.5, 1});
    array2.pushBack({3.25, 0.3});
    array2.pushBack({0.5, 0.005});
    
    ASSERT_TRUE(array1 == array2);
}

TEST(test_06, DynamicArrayDeleteToIndexInt)
{
    DArray<int> intArray1{1, 2, 3};
    DArray<int> intArray2{2};

    intArray1.deleteToIndex(2);
    intArray1.deleteToIndex(0);

    
    ASSERT_TRUE(intArray1 == intArray2);
}

TEST(test_07, DynamicArrayDeleteToIndexPair)
{
    DArray<std::pair<int, int>> array1{{1, 2}, {3, 0}, {1111, 5555}};
    DArray<std::pair<int, int>> array2{{3, 0}};

    array1.deleteToIndex(2);
    array1.deleteToIndex(0);

    
    ASSERT_TRUE(array1 == array2);
}

TEST(test_08, DynamicArrayOperatorSquareBracketsInt)
{
    DArray<int> array1{0, 1, 2, 3};
    int indValue2 = 2;
    int indValue0 = 0;
    
    ASSERT_TRUE((array1[0] == indValue0) && (array1[2] == indValue2));
}

TEST(test_09, DynamicArrayOperatorSquareBracketsPair)
{
    DArray<std::pair<int, int>> array1{{1, 2}, {3, 0}, {1111, 5555}};
    std::pair<int, int> indValue0 = {1, 2};
    std::pair<int, int> indValue3 = {1111, 5555};
    
    ASSERT_TRUE((array1[0] == indValue0) && (array1[2] == indValue3));
}

TEST(test_10, DynamicArrayOperatorAssigment)
{
    DArray<int> arr01{0, 1, 2, 3};
    DArray<int> arr02 = arr01;
    DArray<int> arr03 = std::move(arr02);
    
    DArray<std::pair<int, int>> arr11{{1, 2}, {3, 0}, {1111, 5555}};
    DArray<std::pair<int, int>> arr12 = arr11;
    DArray<std::pair<int, int>> arr13 = std::move(arr12);    

    ASSERT_TRUE((arr01 == arr03) && (arr11 == arr13));
}

TEST(test_11, FigureCalculateLengthOfSideTest)
{
    Square<int> sq{ {4, 4}, {0, 4}, {0, 0}, {4, 0} };
    ASSERT_TRUE(sq.calculateLengthOfSide() - 4 < EPS);
}

TEST(test_12, FigureCalculateLengthOfSideTest)
{
    Octagon<double> oc{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    ASSERT_TRUE(oc.calculateLengthOfSide() - 4.592196623 < EPS);
}

TEST(test_13, FigureCalculateLengthOfSideTest)
{
    Triangle<long long int> tr{ {0, 0}, {1, 0}, {0, 1} };
    ASSERT_TRUE(tr.calculateLengthOfSide() - 1 < EPS);
}

TEST(test_14, SquareConstructorTestInt)
{
    Square<int> sq{{4, 4}, {0, 4}, {0, 0}, {4, 0}};
    Square<int> sq1{{4, 4}, {0, 4}, {0, 0}, {4, 0}};
    Square<int> sq4(sq);
    Square<int> sq5(sq);
    Square<int> sq6(std::move(sq));
    ASSERT_TRUE(sq1 == sq1 && sq4 == sq5 && sq6 == sq5);
}

TEST(test_15, SquareConstructorTestDouble)
{
    Square<double> sq{{4, 4}, {0, 4}, {0, 0}, {4, 0}};
    Square<double> sq1{{4, 4}, {0, 4}, {0, 0}, {4, 0}};
    Square<double> sq4(sq1);
    Square<double> sq5(sq1);
    Square<double> sq6(std::move(sq));
    ASSERT_TRUE(sq1 == sq4 && sq4 == sq5 && sq6 == sq5);
}

TEST(test_16, SquareCalculateGeomCenterIntTest)
{
    Square<int> sq{ {4, 4}, {0, 4}, {0, 0}, {4, 0} };
    std::pair<int, int> b = {2, 2};
    std::pair<int, int> a = sq.calculateGeomCentr();
    ASSERT_TRUE(a.first - b.first < EPS && a.second - b.second < EPS);
}

TEST(test_17, SquareCalculateGeomCenterDoubleTest)
{
    Square<double> sq{ {4.71, 4.71}, {0.0, 4.71}, {0.0, 0.0}, {4.71, 0.0} };
    std::pair<double, double> b = {2.355, 2.355};
    std::pair<double, double> a = sq.calculateGeomCentr();
    ASSERT_TRUE(a.first - b.first < EPS && a.second - b.second < EPS);
}

TEST(test_18, SquareCalculateGeomCenterLongIntTest)
{
    Square<long long int> sq{ {3000, 3000}, {0, 3000}, {0, 0}, {3000, 0} };
    std::pair<long long int, long long int> b = {1500, 1500};
    std::pair<long long int, long long int> a = sq.calculateGeomCentr();
    ASSERT_TRUE(a.first - b.first < EPS && a.second - b.second < EPS);
}

TEST(test_19, SquareIntOperatorDoubleTest)
{
    Square<int> sq{ {4, 4}, {0, 4}, {0, 0}, {4, 0} };
    ASSERT_TRUE((double)sq - 16 < EPS);
}

TEST(test_20, SquareDoubleOperatorDoubleTest)
{
    Square<double> sq{ {4.123, 4.123}, {0, 4.123}, {0, 0}, {4.123, 0} };
    ASSERT_TRUE((double)sq - 16.999129 < EPS);
}

TEST(test_21, TriangleConstructorTest)
{
    Triangle<double> tr{{0, 0}, {9, 0}, {4.5, 9 * sqrt(3) / 2}};
    Triangle<double> tr1{{0, 0}, {9, 0}, {4.5, 9 * sqrt(3) / 2}};
    Triangle<double> tr4(tr);
    Triangle<double> tr5(tr);
    Triangle<double> tr6(std::move(tr1));
    Triangle<double> tr7(std::move(tr4));
    ASSERT_TRUE(tr == tr5 && tr5 == tr6 && tr6 == tr7);
}

TEST(test_22, TriangleCalculateGeomCenterDoubleTest)
{
    Triangle<double> tr{ {0.0, 1.0}, {1.0, 0.0}, {0.5, 2.0} };
    std::pair<double, double> a = {0.5, 1.0};
    std::pair<double, double> b = tr.calculateGeomCentr();
    ASSERT_TRUE(a.first - b.first < EPS && a.second - b.second < EPS);
}

TEST(test_23, TriangleIntOperatorDoubleTest)
{
    Triangle<double> tr{ {0, 0}, {10, 0}, {5, 5 * sqrt(3)} };
    ASSERT_TRUE((double)tr - 43.3013 < EPS);
}

TEST(test_24, OctagonConstructorTestInt)
{
    Octagon<int> oc{{4, 3}, {3, 4}, {1, 4}, {0, 3}, {0, 1}, {1, 0}, {3, 0}, {4, 1}};
    Octagon<int> oc1{{4, 3}, {3, 4}, {1, 4}, {0, 3}, {0, 1}, {1, 0}, {3, 0}, {4, 1}};
    Octagon<int> oc4(oc);
    Octagon<int> oc5(oc);
    Octagon<int> oc6(std::move(oc));
    ASSERT_TRUE(oc1 == oc5 && oc1 == oc6 && oc6 == oc5);
}

TEST(test_25, OctagonConstructorTestDouble)
{
    Octagon<double> oc{{12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3},
        {3.20445, -1.55291}, {6, -5.19615}, {10.5529, -5.79555},
        {14.1962, -3}, {14.7956, 1.55291}};
    Octagon<double> oc1{{12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3},
        {3.20445, -1.55291}, {6, -5.19615}, {10.5529, -5.79555},
        {14.1962, -3}, {14.7956, 1.55291}};
    Octagon<double> oc4(oc1);
    Octagon<double> oc5(oc1);
    Octagon<double> oc6(std::move(oc));
    ASSERT_TRUE(oc1 == oc5 && oc1 == oc6 && oc6 == oc5);
}

TEST(test_26, OctagonCalculateGeomCenterDoubleTest)
{
    Octagon<double> oct{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    std::pair<double, double> a = {9.00001125, 0.0};
    std::pair<double, double> b = oct.calculateGeomCentr();
    ASSERT_TRUE(a.first - b.first < pow(10, -3) && a.second - b.second < pow(10, -3));
}

TEST(test_27, OctagonDoubleOperatorDoubleTest)
{
    Octagon<double> oct{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    ASSERT_TRUE((double)oct - 101.8231740336 < pow(10, -3));
}

TEST(test_28, ArrayFigureTests)
{
    Octagon<double> oc{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    Triangle<double> tr{ {0, 0}, {10, 0}, {5, 5 * sqrt(3)} };
    Square<double> sq{{4, 4}, {0, 4}, {0, 0}, {4, 0}};

    DArray<Figure<double>*> array;
    array.pushBack(&sq);
    array.pushBack(&tr);
    array.pushBack(&oc);
    array.pushBack(&oc);

    EXPECT_EQ(array.getSize(), 4);
} 

TEST(test_29, ArrayFigureTestsCalcAllAreaFigurs)
{
    Octagon<double> oc{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    Triangle<double> tr{ {0, 0}, {10, 0}, {5, 5 * sqrt(3)} };
    Square<double> sq{{4, 4}, {0, 4}, {0, 0}, {4, 0}};

    DArray<Figure<double>*> array;
    array.pushBack(&sq);
    array.pushBack(&tr);
    array.pushBack(&oc);

    ASSERT_TRUE(round(calcualteAllArea(array)) == round(161.124));
}

TEST(test_30, ArrayFigureTestsEqualOperator)
{
    Octagon<double> oc{ {12, 5.19615}, {7.44709, 5.79555}, {3.80385, 3}, {3.20445, -1.55291}, {6, -5.19615},
    {10.5529, -5.79555}, {14.1962, -3}, {14.7956, 1.55291} };
    Triangle<double> tr{ {0, 0}, {10, 0}, {5, 5 * sqrt(3)} };
    Square<double> sq{{4, 4}, {0, 4}, {0, 0}, {4, 0}};
    DArray<Figure<double>*> array{&sq, &tr, &oc};
    DArray<Figure<double>*> arrayCopy(array);
    DArray<Figure<double>*> arrayCopy2;
    arrayCopy2.pushBack(&oc);
    arrayCopy2.pushBack(&tr);
    arrayCopy2.pushBack(&sq);

    ASSERT_FALSE(!(array == arrayCopy) && (array == arrayCopy2));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}