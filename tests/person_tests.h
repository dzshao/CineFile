#ifndef PERSON_TESTS
#define PERSON_TESTS

#include <gtest/gtest.h>
#include "../header/database/person.h"

using std::string;

TEST(PersonTests, testConstructor1) {
    Person testPerson;
    string testName = testPerson.getName();
    EXPECT_TRUE(testName.empty());
}

TEST(PersonTests, testConstructor2) {
    Person testPerson = Person("Test Person");
    string testName = testPerson.getName();
    EXPECT_EQ(testName, "Test Person");
}

TEST(PersonTests, testSetName) {
    Person testPerson;
    testPerson.setName("Test Person");
    string testName = testPerson.getName();
    EXPECT_EQ(testName, "Test Person");
}

#endif