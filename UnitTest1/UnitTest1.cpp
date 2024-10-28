#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9/Lab9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:


		TEST_METHOD(TestLoadGraphFromFile)
		{
			// ���������� ����
			initializeGraph();

			std::ofstream outFile("input.txt");  
			outFile << "0 1\n";
			outFile.close();


			loadGraphFromFile("input.txt");

		
			Assert::AreEqual(1, adjList[0][0]);  
			Assert::AreEqual(0, adjList[1][0]);  
		}

		// ���������� ��������� �����
		TEST_METHOD(TestAddEdge)
		{
			// ���������� ����
			initializeGraph();

			// ������ �����
			addEdge(0, 1);
			addEdge(1, 2);

			// ����������, �� ��������� ����� �����
			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(0, adjList[1][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
		}

		// ���������� BFS
		TEST_METHOD(TestBFS)
		{
			// ���������� ���� � ������ �����
			initializeGraph();
			addEdge(0, 1);
			addEdge(0, 2);
			addEdge(1, 3);
			addEdge(2, 4);

			// ��������� BFS � ������� 0
			BFS(0);

			// ���������� BFS-������ (���������� ������� ������: 0, 1, 2, 3, 4)
			Assert::AreEqual(1, bfsNumber[0]);  // ������� 0 �� BFS-����� 1
			Assert::AreEqual(2, bfsNumber[1]);  // ������� 1 �� BFS-����� 2
			Assert::AreEqual(3, bfsNumber[2]);  // ������� 2 �� BFS-����� 3
			Assert::AreEqual(4, bfsNumber[3]);  // ������� 3 �� BFS-����� 4
			Assert::AreEqual(5, bfsNumber[4]);  // ������� 4 �� BFS-����� 5
		}
	};
}
