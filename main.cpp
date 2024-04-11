#include "Namespace_Application/ProgramManager.h"
#include "Namespace_Application/MenuApp.h"
#include "Namespace_Testing/TesterManager.h"
#include "Namespace_Utilities/Helper.h"

#include <iostream>
#include <vector>
#include <string>

void InputApi( std::string& domain, std::string& action, std::vector<std::string>& arguments );

int main( int argCount, char* args[] )
{
    Application::MenuApplication app; app.Run();
//    std::string domain = "";
//    std::string action = "";
//    std::vector<std::string> arguments;
//
//    Application::ProgramManager::Setup();
//
//    if ( argCount > 1 )
//    {
//        // COMMAND LINE ARGUMENTS PROVIDED, SO TREAT AS AN API CALL
//        domain = std::string( args[1] );
//        action = std::string( args[2] );
//
//        for ( int i = 3; i < argCount; i++ )
//        {
//            arguments.push_back( std::string( args[i] ) );
//        }
//    }
//    else
//    {
//        // NO COMMAND LINE ARGUMENTS GIVEN, SO GIVE USER A MENU
//        Utilities::Helper::Header( "MAIN MENU" );
//        int choice = Utilities::Helper::ShowMenuGetInt( { "QUIT", "API", "TESTS", "PROGRAM" }, true, false );
//
//        switch( choice )
//        {
//            case 0: {                                                           } break; // QUIT
//            case 1: { InputApi( domain, action, arguments );                    } break; // API
//            case 2: { Testing::TesterManager::Run();                            } break; // TESTS
//            case 3: { Application::MenuApplication app; app.Run();              } break; // PROGRAM
//        }
//
//        std::cout << std::endl << "Goodbye!" << std::endl;
//        return 0;
//    }
//
//    Application::ProgramManager::RunCommand( domain, action, arguments );
//    Application::ProgramManager::Cleanup();

    return 0;
}

void InputApi( std::string& domain, std::string& action, std::vector<std::string>& arguments )
{
    std::cout << "EXPECTED: domain action [argument(s)]" << std::endl;
    std::cout << "EXAMPLE: users create NAME" << std::endl;
    std::cout << "See documentation for more information." << std::endl;

    std::cin.ignore();
    std::cout << "Enter DOMAIN: ";
    getline( std::cin, domain );
    domain = Utilities::Helper::ToLower( domain );

    std::cout << "Enter ACTION: ";
    getline( std::cin, action );
    action = Utilities::Helper::ToLower( action );

    std::string buffer = "";
    while ( buffer != "done" )
    {
        std::cout << "Enter argument #" << arguments.size() << " or DONE to end: ";
        getline( std::cin, buffer );
        buffer = Utilities::Helper::ToLower( buffer );

        if ( buffer != "done" )
        {
            arguments.push_back( buffer );
        }
    }
}




