#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\vladt\source\repos\PR6.4 OOP\PR6.4 OOP\6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix<int> m(2);
			m[0] = 1, m[1] = 3;
			int a;
			a = m.findmaxel();
			Assert::AreEqual(a, 3);
		}
	};
}
