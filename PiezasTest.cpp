/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest,check_row_win)
{
Piezas test;
Piece actual;
test.dropPiece(0);
test.dropPiece(1);
test.dropPiece(0);
test.dropPiece(2);
test.dropPiece(0);
test.dropPiece(3);
test.dropPiece(1);
test.dropPiece(2);
test.dropPiece(3);
test.dropPiece(1);
test.dropPiece(2);
test.dropPiece(3);

actual = test.gameState();

ASSERT_EQ(actual,X);
}

TEST(PiezasTest,piece_at_both_neg)
{
Piezas test;
Piece actual = test.pieceAt(-1,-1);
ASSERT_EQ(actual,Invalid);
}

TEST(PiezasTest,piece_at_both_over)
{
Piezas test;
Piece actual = test.pieceAt(6,4);
ASSERT_EQ(actual,Invalid);
}
TEST(PiezasTest,piece_at_over_col)
{
Piezas test;
Piece actual = test.pieceAt(1,5);
ASSERT_EQ(actual,Invalid);
}
TEST(PiezasTest,piece_at_over_row)
{
Piezas test;
Piece actual = test.pieceAt(5,1);
ASSERT_EQ(actual,Invalid);
}

TEST(PiezasTest,piece_at_neg_row)
{
Piezas test;
Piece actual = test.pieceAt(-1,1);
ASSERT_EQ(actual,Invalid);
}


TEST(PiezasTest,correct_drop)
{
Piezas test;
Piece actual = test.dropPiece(0);
ASSERT_EQ(actual,X);
}

TEST(PiezasTest,out_of_area_drop_over)
{
Piezas test;
Piece actual = test.dropPiece(9);
ASSERT_EQ(actual,Invalid);
}
TEST(PiezasTest,out_of_area_drop_under)
{
Piezas test;
Piece actual = test.dropPiece(-1);
ASSERT_EQ(actual,Invalid);
}

TEST(PiezasTest,piece_at_col_neg)
{
Piezas test;
Piece actual = test.pieceAt(1,-1);
ASSERT_EQ(actual,Invalid);
}


TEST(PiezasTest,full_drop)
{
Piezas test;
Piece actual = test.dropPiece(0);
actual = test.dropPiece(0);
actual = test.dropPiece(0);
ASSERT_EQ(actual,Blank);
}
