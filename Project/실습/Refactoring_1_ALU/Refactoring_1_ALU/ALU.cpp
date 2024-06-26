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

    void enableSignal(Result* r) {
        int status = getStatus();
        r->setStatus(status);

        if (Result::STATUS_SUCCESS != status)
        {
            r->setResult(Result::RESULT_INVALID);
            return;
        }

        if (OPCODE == "ADD") {
            r->setResult(operand1 + operand2);
        }
        else if (OPCODE == "MUL") {
            r->setResult(operand1 * operand2);
        }
        else if (OPCODE == "SUB") {
            r->setResult(operand1 - operand2);
        }
        return;
    }

private:
    int getStatus(void)
    {
        if (INVALID_OPERAND == operand1)
        {
            return Result::STATUS_INVALID_OP1;
        }

        if (INVALID_OPERAND == operand2)
        {
            return Result::STATUS_INVALID_OP2;
        }

        if (("ADD" != OPCODE) && ("MUL" != OPCODE) && ("SUB" != OPCODE))
        {
            return Result::STATUS_INVALID_OPCODE;
        }

        return Result::STATUS_SUCCESS;
    }
};