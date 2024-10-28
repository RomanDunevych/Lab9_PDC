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
			// Ініціалізуємо граф
			initializeGraph();

			std::ofstream outFile("input.txt");  
			outFile << "0 1\n";
			outFile.close();


			loadGraphFromFile("input.txt");

		
			Assert::AreEqual(1, adjList[0][0]);  
			Assert::AreEqual(0, adjList[1][0]);  
		}

		// Тестування додавання ребра
		TEST_METHOD(TestAddEdge)
		{
			// Ініціалізуємо граф
			initializeGraph();

			// Додаємо ребра
			addEdge(0, 1);
			addEdge(1, 2);

			// Перевіряємо, чи правильно додані ребра
			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(0, adjList[1][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
		}

		// Тестування BFS
		TEST_METHOD(TestBFS)
		{
			// Ініціалізуємо граф і додаємо ребра
			initializeGraph();
			addEdge(0, 1);
			addEdge(0, 2);
			addEdge(1, 3);
			addEdge(2, 4);

			// Запускаємо BFS з вершини 0
			BFS(0);

			// Перевіряємо BFS-номери (очікуваний порядок обходу: 0, 1, 2, 3, 4)
			Assert::AreEqual(1, bfsNumber[0]);  // Вершина 0 має BFS-номер 1
			Assert::AreEqual(2, bfsNumber[1]);  // Вершина 1 має BFS-номер 2
			Assert::AreEqual(3, bfsNumber[2]);  // Вершина 2 має BFS-номер 3
			Assert::AreEqual(4, bfsNumber[3]);  // Вершина 3 має BFS-номер 4
			Assert::AreEqual(5, bfsNumber[4]);  // Вершина 4 має BFS-номер 5
		}
	};
}
