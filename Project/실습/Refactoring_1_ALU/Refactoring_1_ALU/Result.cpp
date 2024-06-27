#pragma once

enum class OUTPUT_STATUS {
    NO_RESULT = -1,
    SUCCESS = 0,
    INVALID_OP1 = 1,
    INVALID_OP2 = 2,
    INVALID_OPCODE = 3,
};

enum class OUTPUT_RESULT
{
    INVALID = 65535,
};

class Output
{
public:
    void setOutput(OUTPUT_STATUS status, int result)
    {
        this->Status = static_cast<int>(status);
        this->Result = static_cast<int>(result);
    }

    int getStatus() {
        return Status;
    }

    int getResult() {
        return Result;
    }

private:
    int Status = static_cast<int>(OUTPUT_STATUS::NO_RESULT);
    int Result = static_cast<int>(OUTPUT_RESULT::INVALID);
};