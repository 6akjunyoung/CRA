#include "pch.h"
#include "../CleanCode_2Prac_sortprinter/SortMachine.cpp"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  SortMachine objSortMachine;
  std::string sortnames[2] = { "selection", "bubble" };
  
  for (int i = 0; i < 2; i++)
  {
	  objSortMachine.selectSort(SortFactory::generate(sortnames[i]));
	  std::cout << "Arrange" << std::endl;
	  for (int i = 0; i < 10; i++)
	  {
		  objSortMachine.insert(std::rand() % 5000);
	  }
	  objSortMachine.show();

	  std::cout << "Act";
	  objSortMachine.sort();

	  std::cout << " & Assert" << std::endl;
	  objSortMachine.show();

	  objSortMachine.clear();
	  std::cout << std::endl;
  }
}