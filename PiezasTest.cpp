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

// BEGIN Piezas::dropPiece HAPPY TESTS

TEST(PiezasTest, dropPiece_0_0_is_X)
{
    Piezas game;
    ASSERT_EQ(game.dropPiece(0), X);
}

TEST(PiezasTest, dropPiece_1_0_is_O)
{
    Piezas game;
    game.dropPiece(0);
    ASSERT_EQ(game.dropPiece(0), O);
}

TEST(PiezasTest, dropPiece_0_1_is_X)
{
    Piezas game;
    ASSERT_EQ(game.dropPiece(1), X);
}

TEST(PiezasTest, dropPiece_2_3_is_X)
{
    Piezas game;
    game.dropPiece(3);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(3), X);
}

TEST(PiezasTest, dropPiece_2_3_is_O)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(3);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(3), O);
}

TEST(PiezasTest, dropPiece_fillBoardInOrder_is_O)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(1);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(3);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(3), O);
}

TEST(PiezasTest, dropPiece_fillBoardRandom_is_O)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(3);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(1), O);
}

TEST(PiezasTest, dropPiece_halfBoard_is_O)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(0);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(1), O);
}

// BEGIN Piezas::dropPiece SAD TESTS

TEST(PiezasTest, dropPiece_3_2_is_Blank)
{
    Piezas game;
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);
    ASSERT_EQ(game.dropPiece(2), Blank);
}

TEST(PiezasTest, dropPiece_fillBoardOneOver_is_Blank)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(3);
    game.dropPiece(3);
    game.dropPiece(3);
    ASSERT_EQ(game.dropPiece(3), Blank);
}

TEST(PiezasTest, dropPiece_0_4_is_Invalid)
{
    Piezas game;
    ASSERT_EQ(game.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPiece_0_neg1_is_Invalid)
{
    Piezas game;
    ASSERT_EQ(game.dropPiece(-1), Invalid);
}

// BEGIN Piezas::pieceAt HAPPY TESTS

TEST(PiezasTest, pieceAt_0_0)
{
    Piezas game;
    game.dropPiece(1);
    ASSERT_EQ(game.pieceAt(0, 1), X);
}

TEST(PiezasTest, pieceAt_1_1)
{
    Piezas game;
    game.dropPiece(1);
    game.dropPiece(1);
    ASSERT_EQ(game.pieceAt(1, 1), O);
}

TEST(PiezasTest, pieceAt_2_2)
{
    Piezas game;
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);
    ASSERT_EQ(game.pieceAt(2, 2), X);
}

TEST(PiezasTest, pieceAt_3_2)
{
    Piezas game;
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);
    ASSERT_EQ(game.pieceAt(2, 2), X);
}

TEST(PiezasTest, pieceAt_halfBoardRandom_pieceAt_0_3)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(1);
    ASSERT_EQ(game.pieceAt(0, 3), X);
}

TEST(PiezasTest, pieceAt_fillBoardRandom_pieceAt_2_0)
{
    Piezas game;
    game.dropPiece(0);
    game.dropPiece(3);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(2);
    game.dropPiece(0);
    game.dropPiece(3);
    game.dropPiece(1);
    ASSERT_EQ(game.pieceAt(2, 0), O);
}

// BEGIN Piezas::reset TESTS

TEST(PiezasTest, reset_board_check)
{
    Piezas game;
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(3);
    game.reset();
	ASSERT_EQ(game.pieceAt(0, 0), Blank);
	ASSERT_EQ(game.pieceAt(0, 1), Blank);
	ASSERT_EQ(game.pieceAt(0, 2), Blank);
	ASSERT_EQ(game.pieceAt(0, 3), Blank);
    ASSERT_EQ(game.pieceAt(1, 0), Blank);
	ASSERT_EQ(game.pieceAt(1, 1), Blank);
	ASSERT_EQ(game.pieceAt(1, 2), Blank);
	ASSERT_EQ(game.pieceAt(1, 3), Blank);
    ASSERT_EQ(game.pieceAt(2, 0), Blank);
	ASSERT_EQ(game.pieceAt(2, 1), Blank);
	ASSERT_EQ(game.pieceAt(2, 2), Blank);
	ASSERT_EQ(game.pieceAt(2, 3), Blank);
}