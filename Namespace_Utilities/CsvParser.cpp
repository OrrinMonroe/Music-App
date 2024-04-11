#include "CsvParser.h"

#include <iostream>
using namespace std;

namespace Utilities
{

CsvDocument CsvParser::Parse( string filepath )
{
    ifstream input( filepath );
    if ( input.fail() )
    {
        cout << "ERROR: Couldn't open \"" << filepath << "\"!" << endl;
        throw runtime_error( "File not found!" );
    }

    CsvDocument doc;

    // First row should be header
    string strHeader;
    getline( input, strHeader );

    // Split up by comma
    doc.header = Helper::Split( strHeader, "," );

    // Get remaining data
    string row;
    int rowCount = 0;
    while ( getline( input, row ) )
    {
        doc.rows.push_back( CsvParser::CsvSplit( row, ',' ) );
    }

    input.close();

    return doc;
}

void CsvParser::Save( string filepath, const CsvDocument& doc )
{
    ofstream output( filepath );

    // Output header
    bool first = true;
    for ( const auto& colHead : doc.header )
    {
        if ( first ) { first = false; }
        else { output << ","; }
        output << colHead;
    }
    output << endl;

    // Output data
    for ( const auto& row : doc.rows )
    {
        bool first = true;
        for ( const auto& cell : row )
        {
            if ( first ) { first = false; }
            else { output << ","; }
            output << cell;
        }
        output << endl;
    }
}

vector<string> CsvParser::CsvSplit( string str, char delim )
{
    vector<string> data;

    int begin = 0;

    bool singleQuote = false;
    bool doubleQuote = false;

    for ( unsigned int i = 0; i < str.size(); i++ )
    {

        if ( str[i] == '\'' )
        {
            singleQuote = !singleQuote;
        }
        else if ( str[i] == '"' )
        {
            doubleQuote = !doubleQuote;
        }
        else if ( str[i] == delim )
        {
            if ( singleQuote || doubleQuote )
            {
                // We're inside quotes, ignore this bastard.
            }
            else
            {
                // OK we wanna pull this data
                int length = i - begin;
                string substring = str.substr( begin, length );
                data.push_back( substring );
                begin = i+1;
            }
        }
    }

    // Pull the last chunk
    int length = str.size() - begin;
    string substring = str.substr( begin, length );
    data.push_back( substring );


    return data;
}

} // namespace end
