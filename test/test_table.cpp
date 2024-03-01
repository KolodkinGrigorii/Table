#include "table.h"
#include <gtest.h>
using namespace std;
TEST(Table, insert_elem_in_table)
{
    Table<int, int> t;
    auto iter = t.insert(2, 5);
    int et = 5;
    int res = iter->second;
    EXPECT_EQ(et, res);
}

TEST(TableTest, InsertAndFind) {
    Table<int, std::string> table;
    auto iter = table.insert(1, "One");
    EXPECT_EQ(iter->first, 1);
    EXPECT_EQ(iter->second, "One");
    auto foundIter = table.find(1);
    EXPECT_EQ(foundIter->first, 1);
    EXPECT_EQ(foundIter->second, "One");
}

TEST(TableTest, Remove) {
    Table<int, std::string> table;
    table.insert(1, "One");
    table.insert(2, "Two");
    table.insert(3, "Three");
    bool removed = table.remove(2);
    EXPECT_TRUE(removed);
    auto iter = table.find(2);
    EXPECT_EQ(iter, table.end());
}

TEST(TableTest, OperatorBracket) {
    Table<int, std::string> table;
    table.insert(1, "One");
    table.insert(2, "Two");
    table.insert(3, "Three");
    EXPECT_EQ(table[1], "One");
    EXPECT_EQ(table[2], "Two");
    EXPECT_EQ(table[3], "Three");
}

TEST(TableTest, InsertAndFind1) {
    Table<int, std::string> table;
    auto iter = table.insert(1, "Hello");
    auto foundIter = table.find(1);
    EXPECT_EQ(iter->first, 1);
    EXPECT_EQ(iter->second, "Hello");
    EXPECT_EQ(foundIter->first, 1);
    EXPECT_EQ(foundIter->second, "Hello");
    auto iter1 = table.insert(2, "World");
    auto foundIter1 = table.find(2);
    EXPECT_EQ(iter1->first, 2);
    EXPECT_EQ(iter1->second, "World");
    EXPECT_EQ(foundIter1->first, 2);
    EXPECT_EQ(foundIter1->second, "World");
}

TEST(TableTest, Remove1) {
    Table<int, std::string> table;
    table.insert(1, "Hello");
    table.insert(2, "World");
    bool removed = table.remove(1);
    EXPECT_TRUE(removed);
    auto iter = table.find(1);
    EXPECT_EQ(iter, table.end());
}

TEST(TableTest, BracketOperator) {
    Table<int, std::string> table;
    table.insert(1, "Hello");
    table.insert(2, "World");
    EXPECT_EQ(table[1], "Hello");
    EXPECT_EQ(table[2], "World");
}

TEST(TableTest, CopyConstructor) {
    Table<int, std::string> table1;
    table1.insert(1, "one");
    table1.insert(2, "two");
    Table<int, std::string> table2(table1);
    auto it = table2.find(2);
    ASSERT_NE(it, table2.end());
    EXPECT_EQ(it->second, "two");
}

TEST(TableTest, AssignmentOperator) {
    Table<int, std::string> table1;
    table1.insert(1, "Hello");
    table1.insert(2, "World");
    Table<int, std::string> table2;
    table2 = table1;
    auto iter = table2.find(2);
    ASSERT_NE(iter, table2.end());
    EXPECT_EQ(iter->second, "World");
}

TEST(SortTableTest, InsertAndFind) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(3, "three");
    table.insert(2, "two");
    auto it = table.find(2);
    ASSERT_NE(it, table.end());
    EXPECT_EQ(it->second, "two");
}

TEST(SortTableTest, Remove) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");
    ASSERT_TRUE(table.remove(2));
    ASSERT_FALSE(table.remove(4));
}

TEST(SortTableTest, IndexOperator) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");
    table.insert(3, "three");
    EXPECT_EQ(table[2], "two");
}

TEST(SortTableTest, CopyConstructor) {
    SortTable<int, std::string> table1;
    table1.insert(1, "one");
    table1.insert(2, "two");
    SortTable<int, std::string> table2(table1);
    auto it = table2.find(2);
    ASSERT_NE(it, table2.end());
    EXPECT_EQ(it->second, "two");
}

TEST(SortTableTest, AssignmentOperator) {
    SortTable<int, std::string> table1;
    table1.insert(1, "one");
    table1.insert(2, "two");
    SortTable<int, std::string> table2;
    table2 = table1;
    auto it = table2.find(2);
    ASSERT_NE(it, table2.end());
    EXPECT_EQ(it->second, "two");
}

TEST(SortTableTest, EmptyTable) {
    SortTable<int, int> table;
    EXPECT_EQ(table.begin(), table.end());
}

TEST(SortTableTest, InsertAndFind1) {
    SortTable<int, std::string> table;
    table.insert(5, "Five");
    table.insert(2, "Two");
    table.insert(8, "Eight");
    auto it = table.find(5);
    EXPECT_EQ(it->second, "Five");
    it = table.find(2);
    EXPECT_EQ(it->second, "Two");
    it = table.find(8);
    EXPECT_EQ(it->second, "Eight");
}

TEST(SortTableTest, Remove1) {
    SortTable<int, int> table;
    table.insert(1, 10);
    table.insert(2, 20);
    table.insert(3, 30);
    EXPECT_TRUE(table.remove(2));
    EXPECT_FALSE(table.remove(5));
    auto it = table.find(2);
    EXPECT_EQ(it, table.end());
}

TEST(SortTableTest, OperatorBracket) {
    SortTable<int, std::string> table;
    table.insert(1, "One");
    table.insert(2, "Two");
    table.insert(3, "Three");
    EXPECT_EQ(table[1], "One");
    EXPECT_EQ(table[2], "Two");
    EXPECT_EQ(table[3], "Three");
}

TEST(SortTableTest, Iterator) {
    SortTable<int, int> table;
    table.insert(12, 120);
    table.insert(5, 50);
    table.insert(8, 80);
    int sum = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        sum += it->second;
    }
    EXPECT_EQ(sum, 250);
}

TEST(SortTableTest, InsertTest) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(3, "three");
    table.insert(2, "two");
    auto it = table.begin();
    ASSERT_EQ(1, it->first);
    ASSERT_EQ("one", it->second);
    it++;
    ASSERT_EQ(2, it->first);
    ASSERT_EQ("two", it->second);
    it++;
    ASSERT_EQ(3, it->first);
    ASSERT_EQ("three", it->second);
}

TEST(SortTableTest, FindTest) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(3, "three");
    table.insert(2, "two");
    auto found = table.find(2);
    ASSERT_EQ(2, found->first);
    ASSERT_EQ("two", found->second);
    found = table.find(4);
    ASSERT_EQ(table.end(), found);
}

TEST(SortTableTest, RemoveTest) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(3, "three");
    table.insert(2, "two");
    ASSERT_TRUE(table.remove(2));
    auto found = table.find(2);
    ASSERT_EQ(table.end(), found);
}

TEST(SortTableTest, AccessOperatorTest) {
    SortTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(3, "three");
    table.insert(2, "two");
    ASSERT_EQ("two", table[2]);
}
