#include <string>

using namespace std;

#define interface struct

interface DBAPI
{
public:
	virtual string getDBName() = 0;
};

class DatabaseAPI : public DBAPI{
public:
	string getDBName() {
		return name;
	}

private:
	string name = "MySon_DB";
};

class LogSystem {
public:
	LogSystem(DBAPI* db) {
		DB = db;
	}

	string getLogMessage(string content) {
		string msg = "";
		msg += string("[") + DB->getDBName() + string("] ");
		msg += content + string("\n");
		return msg;
	}

private:
	DBAPI* DB;
};