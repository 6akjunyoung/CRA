#pragma once

class Result
{
public:
    static const int STATUS_SUCCESS = 0;
    static const int STATUS_INVALID_OP1 = 1;
    static const int STATUS_INVALID_OP2 = 2;
    static const int STATUS_INVALID_OPCODE = 3;
    static const int STATUS_NO_RESULT = -1;

    static const int RESULT_INVALID = 65535;

    void setStatus(int status) {
        this->status = status;
    }

    void setResult(int result) {
        this->result = result;
    }

    int getStatus() {
        return status;
    }

    int getResult() {
        return result;
    }

private:
    int status = STATUS_NO_RESULT;
    int result = RESULT_INVALID;
};