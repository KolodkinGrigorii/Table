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
