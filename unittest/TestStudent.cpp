#include "gtest/gtest.h"
#include "Student.h"


class TestStudent : public ::testing::Test
{
protected:
    Student *ps;
    void SetUp() override
    {
        ps = new Student(2, "toto");
    }

    void TearDown() override
    {
        delete ps;
    }
};


TEST_F(TestStudent, ID)
{
    EXPECT_TRUE(ps->GetID() == 2);
    EXPECT_TRUE(ps->GetName() == "toto");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
