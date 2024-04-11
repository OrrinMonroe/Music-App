#ifndef _PROGRAMMANAGER
#define _PROGRAMMANAGER

#include "../Namespace_User/UserManager.h"

#include <string>
#include <vector>

namespace Application
{

class ProgramManager
{
public:
    static void Setup();
    static void Cleanup();
    static void RunCommand( std::string domain, std::string action, std::vector<std::string> arguments );

private:
    static User::UserManager s_userManager;
};

}

#endif
