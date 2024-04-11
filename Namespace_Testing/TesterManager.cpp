#include "TesterManager.h"

#include "../Namespace_Utilities/Helper.h"

#include "../Namespace_User/UserTester.h"
#include "../Namespace_User/UserManagerTester.h"

namespace Testing
{

void TesterManager::Run()
{
    int totalTests = 0, totalPass = 0, totalFail = 0;

    User::UserTester            userTester;            userTester.Start( totalTests, totalPass, totalFail );
    User::UserManagerTester     userManagerTester;     userManagerTester.Start( totalTests, totalPass, totalFail );

    std::cout << std::endl << std::string( 80, '-' ) << std::endl;
    std::cout << "TOTAL TESTS, ALL: " << totalTests << std::endl;
    std::cout << "TOTAL PASS,  ALL: " << totalPass << std::endl;
    std::cout << "TOTAL FAIL,  ALL: " << totalFail << std::endl;
}

}
