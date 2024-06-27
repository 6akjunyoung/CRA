#pragma once

#include <string>
#include "Result.cpp"

class ALU
{
    static const int INVALID_OPERAND = -1;

    int operand1 = INVALID_OPERAND;
    int operand2 = INVALID_OPERAND;
    std::string OPCODE = "";

public:
    void setOperand1(int operand1) {
        this->operand1 = operand1;
    }

    void setOperand2(int operand2) {
        this->operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }

    void enableSignal(Output* r) {
        int result = 0;

        if (false == isCalcValid())
        {
            r->setOutput(getStatus(), static_cast<int>(OUTPUT_RESULT::INVALID));
            return;
        }

        result = calcOperand();

        r->setOutput(OUTPUT_STATUS::SUCCESS, result);

        return;
    }

private:
    int calcOperand()
    {
        int result = 0;

        if (OPCODE == "ADD") {
            result = operand1 + operand2;
        }
        else if (OPCODE == "MUL") {
            result = operand1 * operand2;
        }
        else if (OPCODE == "SUB") {
            result = operand1 - operand2;
        }
        return result;
    }

    OUTPUT_STATUS getStatus(void)
    {
        if (INVALID_OPERAND == operand1)
        {
            return OUTPUT_STATUS::INVALID_OP1;
        }

        if (INVALID_OPERAND == operand2)
        {
            return OUTPUT_STATUS::INVALID_OP2;
        }

        if (("ADD" != OPCODE) && ("MUL" != OPCODE) && ("SUB" != OPCODE))
        {
            return OUTPUT_STATUS::INVALID_OPCODE;
        }

        return OUTPUT_STATUS::SUCCESS;
    }

    bool isCalcValid(void)
    {
        if ((INVALID_OPERAND == operand1) ||
            (INVALID_OPERAND == operand2) ||
            (("ADD" != OPCODE) && ("MUL" != OPCODE) && ("SUB" != OPCODE)))
        {
            return false;
        }
        return true;
    }
};