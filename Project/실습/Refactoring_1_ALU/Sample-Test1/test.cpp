#include <iostream>

#include "pch.h"
#include "../Refactoring_1_ALU/ALU.cpp"
#include "../Refactoring_1_ALU/Result.cpp"

using namespace std;

enum class eALU_OPCODE : int
{
	ADD = 0,
	MUL,
	SUB,
	MAX
};

class ALUTest : public testing::Test
{
protected:
	ALU m_objALU;
	Result m_stResult;
	const string ALU_OPCODE[static_cast<int>(eALU_OPCODE::MAX)] = { "ADD", "MUL", "SUB" };
};

TEST_F(ALUTest, ADDTest) {

	m_objALU.setOperand1(10);
	m_objALU.setOperand2(20);
	m_objALU.setOPCODE("ADD");

	m_objALU.enableSignal(&m_stResult);

	EXPECT_EQ(30, m_stResult.getResult());
	EXPECT_EQ(0, m_stResult.getStatus());
}

TEST_F(ALUTest, MULTest) {
	m_objALU.setOperand1(10);
	m_objALU.setOperand2(20);
	m_objALU.setOPCODE("MUL");

	m_objALU.enableSignal(&m_stResult);

	EXPECT_EQ(200, m_stResult.getResult());
	EXPECT_EQ(0, m_stResult.getStatus());
}

TEST_F(ALUTest, SUBTest) {
	m_objALU.setOperand1(10);
	m_objALU.setOperand2(20);
	m_objALU.setOPCODE("SUB");

	m_objALU.enableSignal(&m_stResult);

	EXPECT_EQ(-10, m_stResult.getResult());
	EXPECT_EQ(0, m_stResult.getStatus());
}

TEST_F(ALUTest, FailTestOp1) {
	m_objALU.setOperand1(-1);
	m_objALU.setOperand2(20);

	for (auto opcode : ALU_OPCODE)
	{
		m_objALU.setOPCODE(opcode);

		m_objALU.enableSignal(&m_stResult);

		EXPECT_EQ(65535, m_stResult.getResult());
		EXPECT_EQ(1, m_stResult.getStatus());
	}
}

TEST_F(ALUTest, FailTestOp2)
{
	m_objALU.setOperand1(10);
	m_objALU.setOperand2(-1);

	for (auto opcode : ALU_OPCODE)
	{
		m_objALU.setOPCODE(opcode);

		m_objALU.enableSignal(&m_stResult);

		EXPECT_EQ(65535, m_stResult.getResult());
		EXPECT_EQ(2, m_stResult.getStatus());
	}
}

TEST_F(ALUTest, FailTestOpcode)
{
	m_objALU.setOperand1(10);
	m_objALU.setOperand2(20);

	m_objALU.setOPCODE("INVALID");

	m_objALU.enableSignal(&m_stResult);

	EXPECT_EQ(65535, m_stResult.getResult());
	EXPECT_EQ(3, m_stResult.getStatus());
}