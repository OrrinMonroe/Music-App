#ifndef _USER_TESTER
#define _USER_TESTER

#include "../Namespace_Testing/TesterBase.h"
#include "User.h"

#include <string>

namespace User
{

class UserTester : public Testing::TesterBase
{
    public:
    UserTester()
        : TesterBase( "TEST_RESULT-UserTester.html" )
    {
        // Tell it which functions to run as part of the test set
        AddTest(Testing::TestListItem("Test_SetId",          std::bind(&UserTester::Test_SetId, this)));
        AddTest(Testing::TestListItem("Test_SetName",        std::bind(&UserTester::Test_SetName, this)));
        AddTest(Testing::TestListItem("Test_AddPlaylistId",  std::bind(&UserTester::Test_AddPlaylistId, this)));
        AddTest(Testing::TestListItem("Test_GetId",          std::bind(&UserTester::Test_GetId, this)));
        AddTest(Testing::TestListItem("Test_GetName",        std::bind(&UserTester::Test_GetName, this)));
        AddTest(Testing::TestListItem("Test_GetPlaylistIds", std::bind(&UserTester::Test_GetPlaylistIds, this)));
    }

    virtual ~UserTester() { /* This does nothing but is required */ }

    private:
    int Test_SetId();
    int Test_SetName();
    int Test_AddPlaylistId();
    int Test_GetId();
    int Test_GetName();
    int Test_GetPlaylistIds();
};

int UserTester::Test_SetId()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Use SetId, check that value is set." );
    {
        User testUser;
        testUser.SetId( 123 );
        Set_Comments( "testUser.SetId( 123 );" );
        if ( !Set_Outputs( "testUser.m_userId", 123, testUser.m_userId ) )  { TestFail(); }
        else                                                                { TestPass(); }

    } FinishTest();

    StartTest( "Use SetId, check that value is set." );
    {
        User testUser;
        testUser.SetId( 1337 );
        Set_Comments( "testUser.SetId( 1337 );" );
        if ( !Set_Outputs( "testUser.m_userId", 1337, testUser.m_userId ) )  { TestFail(); }
        else                                                                 { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserTester::Test_SetName()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Use SetName, check that value is set." );
    {
        User testUser;
        testUser.SetName( "Rachel" );
        Set_Comments( "testUser.SetName( \"Rachel\" );" );
        if ( !Set_Outputs( "testUser.m_name", "Rachel", testUser.m_name ) )    { TestFail(); }
        else                                                                   { TestPass(); }

    } FinishTest();

    StartTest( "Use SetName, check that value is set." );
    {
        User testUser;
        testUser.SetName( "Rai" );
        Set_Comments( "testUser.SetName( \"Rai\" );" );
        if ( !Set_Outputs( "testUser.m_name", "Rai", testUser.m_name ) )    { TestFail(); }
        else                                                                { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserTester::Test_AddPlaylistId()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Use AddPlaylistId, make sure it was added to the User" );
    {
        User testUser;
        testUser.AddPlaylistId( 123 );
        Set_Comments( "testUser.AddPlaylistId( 123 );" );

        bool itemFound = false;
        for ( auto& id : testUser.m_playlistIds )
        {
            if ( id == 123 )
            {
                itemFound = true;
                break;
            }
        }

        if ( !Set_Outputs( "ID found in m_playlistIds", true, itemFound ) )  { TestFail(); }
        else                                                                 { TestPass(); }

    } FinishTest();

    StartTest( "Use AddPlaylistId twice, make sure everyting was added to the User" );
    {
        User testUser;
        testUser.AddPlaylistId( 1337 );
        testUser.AddPlaylistId( 777 );
        Set_Comments( "testUser.AddPlaylistId( 1337 );" );
        Set_Comments( "testUser.AddPlaylistId( 777 );" );

        bool found1337 = false;
        bool found777 = false;
        for ( auto& id : testUser.m_playlistIds )
        {
            if ( id == 1337 )
            {
                found1337 = true;
            }
            else if ( id == 777 )
            {
                found777 = true;
            }
        }

        if ( !Set_Outputs( "1337 found in m_playlistIds", true, found1337 ) )       { TestFail(); }
        else if ( !Set_Outputs( "777 found in m_playlistIds", true, found777 ) )    { TestFail(); }
        else                                                                        { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserTester::Test_GetId()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Set the m_userId, then check GetId." );
    {

        User testUser;
        testUser.m_userId = 321;
        Set_Comments( "testUser.m_userId = 321;" );
        if ( !Set_Outputs( "testUser.GetId()", 321, testUser.GetId() ) )    { TestFail(); }
        else                                                                { TestPass(); }

    } FinishTest();

    StartTest( "Set the m_userId, then check GetId." );
    {

        User testUser;
        testUser.m_userId = 654;
        Set_Comments( "testUser.m_userId = 654;" );
        if ( !Set_Outputs( "testUser.GetId()", 654, testUser.GetId() ) )    { TestFail(); }
        else                                                                { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserTester::Test_GetName()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Set the m_name, then check GetName." );
    {

        User testUser;
        testUser.m_name = "Karlach";
        Set_Comments( "testUser.m_name = \"Karlach\";" );
        if ( !Set_Outputs( "testUser.GetName()", "Karlach", testUser.GetName() ) )  { TestFail(); }
        else                                                                        { TestPass(); }

    } FinishTest();

    StartTest( "Set the m_name, then check GetName." );
    {

        User testUser;
        testUser.m_name = "Wyll";
        Set_Comments( "testUser.m_name = \"Wyll\";" );
        if ( !Set_Outputs( "testUser.GetName()", "Wyll", testUser.GetName() ) )  { TestFail(); }
        else                                                                        { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

int UserTester::Test_GetPlaylistIds()
{
    StartTestSet( std::string( __func__ ), { /* Prereq functions */ } );
    // Tests begin -------------------------------------------------

    StartTest( "Set PlaylistIDs directly, check that the list is retrieved." );
    {
        User testUser;
        std::vector<int> playlistIds = { 1, 3, 5 };
        testUser.m_playlistIds = playlistIds;
        std::vector<int> retrieved = testUser.GetPlaylistIds();

        bool allMatch = true;
        if ( playlistIds.size() == retrieved.size() )
        {
            for ( size_t i = 0; i < retrieved.size(); i++ )
            {
                if ( playlistIds[i] != retrieved[i] )
                {
                    allMatch = false;
                    break;
                }
            }
        }
        else
        {
            allMatch = false;
        }

        if ( !Set_Outputs( "testUser.GetPlaylistIds() returns all", true, allMatch ) )  { TestFail(); }
        else                                                                            { TestPass(); }

    } FinishTest();

    // Tests end ---------------------------------------------------
    FinishTestSet();
    return TestResult();
}

}

#endif
