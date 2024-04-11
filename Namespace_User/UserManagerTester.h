#ifndef _USER_MANAGER_TESTER
#define _USER_MANAGER_TESTER

#include "../Namespace_Testing/TesterBase.h"
#include "../Namespace_Metadata/StatusCode.h"
#include "UserManager.h"
#include "User.h"

#include <string>
#include <vector>

namespace User
{

class UserManagerTester : public Testing::TesterBase
{
    public:
    UserManagerTester()
        : TesterBase( "TEST_RESULT-UserManagerTester.html" )
    {
        // Tell it which functions to run as part of the test set
        AddTest(Testing::TestListItem("Test_CreateUser",          std::bind(&UserManagerTester::Test_CreateUser, this)));
        AddTest(Testing::TestListItem("Test_GetUsers",            std::bind(&UserManagerTester::Test_GetUsers, this)));
    }

    virtual ~UserManagerTester() { /* This does nothing but is required */ }

    private:
    int Test_CreateUser();
    int Test_GetUsers();
//    int Test_LoadData();
//    int Test_SaveData();
};

int UserManagerTester::Test_CreateUser()
{
    StartTestSet( std::string( __func__ ), { "User class" /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Call CreateUser, ensure that new User is created." );
    {
        UserManager testManager;
        Metadata::StatusCode result;
        testManager.CreateUser( result, { "Astarion" } );
        User createdUser = testManager.m_userList[0];
        Set_Comments( "testManager.CreateUser( result, { \"Astarion\" } );" );
        if ( !Set_Outputs( "createdUser.GetName()", "Astarion", createdUser.GetName() ) ) { TestFail(); }
        else if ( !Set_Outputs( "StatusCode", 200, result.code ) )                        { TestFail(); }
        else                                                                              { TestPass(); }

    } FinishTest();

    StartTest( "Call CreateUser twice, ensure that new User is created." );
    {
        UserManager testManager;
        Metadata::StatusCode result;
        testManager.CreateUser( result, { "Gale" } );
        testManager.CreateUser( result, { "Wyll" } );
        User createdUser1 = testManager.m_userList[0];
        User createdUser2 = testManager.m_userList[1];
        Set_Comments( "testManager.CreateUser( result, { \"Gale\" } );" );
        Set_Comments( "testManager.CreateUser( result, { \"Wyll\" } );" );
        if      ( !Set_Outputs( "createdUser1.GetName()", "Gale", createdUser1.GetName() ) ) { TestFail(); }
        else if ( !Set_Outputs( "createdUser2.GetName()", "Wyll", createdUser2.GetName() ) ) { TestFail(); }
        else if ( !Set_Outputs( "StatusCode", 200, result.code ) )                           { TestFail(); }
        else                                                                                 { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserManagerTester::Test_GetUsers()
{
    StartTestSet( std::string( __func__ ), { "User class" /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Call GetUsers to retrieve all users" );
    {
        UserManager testManager;
        Metadata::StatusCode result;
        User testUser1, testUser2;
        testUser1.SetName( "Astarion" );
        testUser1.SetId( 2 );
        testUser2.SetName( "Gale" );
        testUser2.SetId( 4 );
        testManager.m_userList.push_back( testUser1 );
        testManager.m_userList.push_back( testUser2 );
        std::vector<User> retrievedUsers = testManager.GetUsers( result, {} );
        Set_Comments( "testManager.GetUsers( result, {} );" );
        if      ( !Set_Outputs( "retrievedUsers[0].GetName()", "Astarion",  retrievedUsers[0].GetName() ) )  { TestFail(); }
        else if ( !Set_Outputs( "retrievedUsers[1].GetName()", "Gale",      retrievedUsers[1].GetName() ) )  { TestFail(); }
        else if ( !Set_Outputs( "StatusCode", 200, result.code ) )                                           { TestFail(); }
        else                                                                                                 { TestPass(); }

    } FinishTest();

    StartTest( "Call GetUsers to retrieve a single user" );
    {
        UserManager testManager;
        Metadata::StatusCode result;
        User testUser1, testUser2;
        testUser1.SetName( "Astarion" );
        testUser1.SetId( 2 );
        testUser2.SetName( "Gale" );
        testUser2.SetId( 4 );
        testManager.m_userList.push_back( testUser1 );
        testManager.m_userList.push_back( testUser2 );
        std::vector<User> retrievedUsers = testManager.GetUsers( result, { "4" } );
        Set_Comments( "testManager.GetUsers( result, { \"4\" } );" );
        if      ( !Set_Outputs( "retrievedUsers.size()", 1, retrievedUsers.size() ) )                        { TestFail(); }
        else if ( !Set_Outputs( "retrievedUsers[0].GetName()", "Gale",      retrievedUsers[0].GetName() ) )  { TestFail(); }
        else if ( !Set_Outputs( "StatusCode", 200, result.code ) )                                           { TestFail(); }
        else                                                                                                 { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

}

#endif
