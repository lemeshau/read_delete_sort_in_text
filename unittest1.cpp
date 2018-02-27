#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../ConsoleApplication3/editor.h"
//#include "../ConsoleApplication3/editor.cpp"
#include "editor.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1

{		
	TEST_CLASS(toLowStringTest)
	{
	public:

		TEST_METHOD(stringlowVSallhigh)
		{
			edit a;
			Assert::AreEqual<string>("assd", a.toLow("ASSD"));
		}
		TEST_METHOD(stringlowVSnotallhigh)
		{
			edit a;
			Assert::AreEqual<string>("assd", a.toLow("AsSd"));
		}
		TEST_METHOD(stringlowVSnotequal)
		{
			edit a;
			Assert::AreEqual<string>("assd", a.toLow("QwEq"));
		}
		TEST_METHOD(stringnumVSnum)
		{
			edit a;
			Assert::AreEqual<string>("123", a.toLow("123"));
		}
	};

	TEST_CLASS(toLowVectorTest)
	{
	public:

		TEST_METHOD(vectorcharlowVSnotallhigh)
		{
			edit a;
			vector<string> vec1{ { 'A',' ','c' },{ 'E','1','g' } };
			vector<string> vec2{ { 'a',' ','c' },{ 'e','1','g' } };
			for (int i = 0; i < vec1.size(); i++) {
				for (int j = 0; j < vec1[i].length(); j++) {
					Assert::AreEqual<char>(vec2[i][j], a.toLow(vec1)[i][j]);
				}
			}
		}
		TEST_METHOD(vectorcharlowVSnotequal)
		{
			edit a;
			vector<string> vec1{ { 'd','Q','c' },{ 'E','1','g','o' } };
			vector<string> vec2{ { 'a',' ','c' },{ 'e','1','g' } };
			for (int i = 0; i < vec1.size(); i++) {
				for (int j = 0; j < vec1[i].length(); j++) {
					Assert::AreEqual<char>(vec2[i][j], a.toLow(vec1)[i][j]);
				}
			}
		}
		TEST_METHOD(vectorstringDifSize)
		{
			edit a;
			vector<string> vec1, vec2;
			vec1.push_back("abcd");
			vec1.push_back("efgh");
			vec2.push_back("abcd");
			for (int i = 0; i < vec1.size(); i++) {
				Assert::AreEqual<string>(vec2[i], a.toLow(vec1)[i]);
			}
		}
	};
	TEST_CLASS(readfileTest)
	{
	public:

		TEST_METHOD(stringTypeReturn)
		{
			edit a;
			vector<string> vec1;
			Assert::AreEqual(typeid(vec1).name(), typeid(a.readFile("asd")).name());
		}
		TEST_METHOD(noneStringTypeReturn)
		{
			edit a;
			vector<int> vec1;
			Assert::AreEqual(typeid(vec1).name(), typeid(a.readFile("asd")).name());
		}
	
	};
}