#include "gtest/gtest.h"
#include "Student.h"


class TestStudent : public ::testing::Test
{
protected:
    Student *ps;
    Student *ps2;
    void SetUp() override
    {
        ps = new Student();
        ps2 = new Student(2, "toto");
    }

    void TearDown() override
    {
        delete ps;
        delete ps2;
    }
};


TEST_F(TestStudent, ID)
{
    EXPECT_TRUE(ps->GetID() == 0);
    EXPECT_TRUE(ps->GetName() == "");
    EXPECT_TRUE(ps2->GetID() == 2);
    EXPECT_TRUE(ps2->GetName() == "toto");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
