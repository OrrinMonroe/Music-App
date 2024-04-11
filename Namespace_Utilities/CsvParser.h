#ifndef _CSV_PARSER_HPP
#define _CSV_PARSER_HPP

#include "Helper.h"

#include <string>
#include <fstream>
#include <vector>

namespace Utilities
{

struct CsvDocument
{
    std::vector<std::string> header;
    std::vector< std::vector< std::string > > rows;
};

class CsvParser
{
    public:
    static CsvDocument Parse( std::string filepath );
    static void Save( std::string filepath, const CsvDocument& doc );
    static std::vector<std::string> CsvSplit( std::string str, char delim );
};

} // namespace end

#endif
