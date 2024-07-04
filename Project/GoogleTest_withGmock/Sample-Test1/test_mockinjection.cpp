#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../GoogleTest_withGmock/MockInjection.cpp"

#include <vector>

using namespace testing;
using namespace std;

TEST(MockInjectionTest, DataBase)
{
    DBAPI& db = DatabaseAPI();

    LogSystem app(&db);

    cout << app.getLogMessage("Very Good good");
}

class DBMock : public DBAPI {
public:
    MOCK_METHOD(string, getDBName, (), (override));
};

TEST(MockInjectionTest, DataBase2)
{
    DBMock db;

    EXPECT_CALL(db, getDBName)
        .WillRepeatedly(Return("Mock"));

    LogSystem app(&db);

    cout << app.getLogMessage("Very Good good");
}
