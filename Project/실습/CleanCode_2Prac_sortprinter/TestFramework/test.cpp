#include "pch.h"
#include "../CleanCode_2Prac_sortprinter/SortMachine.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  SortMachine objSortMachine;

  std::cout << "Arrange" << std::endl;
  objSortMachine.show();

  for (int i = 0; i < 10; i++)
  {
	objSortMachine.insert(std::rand() % 41);
  }
  objSortMachine.show();

  std::cout << "Act" << std::endl;
  objSortMachine.sort(SortFactory::generate("bubble"));
  objSortMachine.show();

  std::cout << "Assert" << std::endl;
  objSortMachine.clear();
  objSortMachine.show();
}