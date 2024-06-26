#include "pch.h"
#include "../Refactoring_1_ALU/ALU.cpp";
#include "../Refactoring_1_ALU/Result.cpp";

TEST(ALU, ADDTest) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}