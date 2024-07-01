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
            std::cerr << "파일이 열려 있지 않습니다." << std::endl;
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
            std::cerr << "파일을 열 수 없습니다: " << fileName << std::endl;
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