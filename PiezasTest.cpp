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