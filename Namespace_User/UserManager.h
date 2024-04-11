#ifndef _USERMANAGER
#define _USERMANAGER

#include "../Namespace_Metadata/StatusCode.h"
#include "User.h"
#include <vector>
#include <string>

namespace User
{

class UserManager
{
public:
    static void Setup( std::string dataPath );
    static void Cleanup();

    static void DisplayTable( const std::vector<User>& userList = m_userList );
    static size_t GetUserCount();
    static int CreateUser( std::string name );
    static void UpdateUser( int id, const User& newUser );
    static User GetUser( size_t id );
    static bool IsValidId( size_t id );

    static void LoadData();
    static void SaveData();

    // API stuff; ignore
    static void CreateUser( Metadata::StatusCode& result, const std::vector<std::string>& arguments );
    static std::vector<User> GetUsers( Metadata::StatusCode& result, const std::vector<std::string>& arguments );

private:
    static std::string m_dataPath;
    static std::vector<User> m_userList;

    friend class UserManagerTester;
};

}

#endif
