#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4 іт/6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My64
{
	TEST_CLASS(My64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			float arr[size];
			Create(arr, size, -10, 10);

			// Check that all elements are within the specified range
			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(arr[i] >= -10 && arr[i] <= 10);
			}
		}
	};
}
	
