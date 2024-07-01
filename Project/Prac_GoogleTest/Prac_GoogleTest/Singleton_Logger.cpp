#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Logger
{
public:
    static Logger& getInstance()
    {
        static Logger logger("Logfile.txt");;
        return logger;
    }

    void write(const std::string& data) {
        if (outFile) {
            outFile << data << std::endl;
        }
        else {
            std::cerr << "������ ���� ���� �ʽ��ϴ�." << std::endl;
        }
    }


private:
    Logger()
    {
        Logger("Logfile.txt");
    }

    Logger(const std::string& fileName) {
        outFile.open(fileName, std::ios::app);
        if (!outFile) {
            std::cerr << "������ �� �� �����ϴ�: " << fileName << std::endl;
        }
    }

    ~Logger() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    ofstream outFile;
};
#if 0
int main()
{
    Logger& logger = Logger::getInstance();

    logger.write("hello");
    logger.write("bye");
}
#endif