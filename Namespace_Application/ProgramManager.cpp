#include "ProgramManager.h"
#include "../Namespace_Utilities/Logger.h"
#include "../Namespace_Utilities/Helper.h"
#include "../Namespace_Utilities/Preprocessor.h"
#include "../Namespace_User/UserManager.h"
#include "../Namespace_Metadata/StatusCodeManager.h"

namespace Application
{

// Static members
User::UserManager ProgramManager::s_userManager;

void ProgramManager::Setup()
{
    Utilities::Logger::Setup( false );
    Metadata::StatusCodeManager::Setup();
    s_userManager.Setup( "data/users/users.txt" );
}

void ProgramManager::Cleanup()
{
    s_userManager.Cleanup();
    Utilities::Logger::Cleanup();
}

void ProgramManager::RunCommand( std::string domain, std::string action, std::vector<std::string> arguments )
{
    Utilities::Logger::Push( "ProgramManager::" + std::string(__func__) );
    Utilities::Logger::Out( "Received command: " + domain + "/" + action + "/" + Utilities::Helper::VectorToString( arguments ), "ProgramManager::RunCommand" );

    Metadata::StatusCode result;

    if ( domain == "users" )
    {
        if ( action == "create" )
        {
            s_userManager.CreateUser( result, arguments );
        }
        else if ( action == "get" )
        {
            std::vector<User::User> users = s_userManager.GetUsers( result, arguments );
            s_userManager.DisplayTable( users );
        }
    }

    std::string debugStatus = "REQUEST: ["
        + domain + "/" + action + "/" + Utilities::Helper::VectorToString( arguments )
        + "], RESULT: [" + Utilities::Helper::ToString( result.code ) + "/" + result.name + "/" + result.message + "]";

    std::cout << debugStatus << std::endl;

    Utilities::Logger::Out( debugStatus, "ProgramManager::RunCommand" );

    Utilities::Logger::Pop();
}

}
