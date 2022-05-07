#include "domain/dom_file_manager.hpp"

void
dom::copyFile
(
    str_const_ref aFromFileName,
    str_const_ref aToFileName
)
{
    START_LOG_BLOCK("Copying file");
    WRITE_LOG("From : ", aFromFileName);
    WRITE_LOG("To   : ", aToFileName);

    std::ifstream fromFile(aFromFileName);
    std::ofstream toFile(aToFileName);

    if (!fromFile.is_open()) 
    {
        WRITE_ERROR("DOMAIN", "FILE_MANAGER", "FM#_0", "CANT_OPEN_FILE_FOR_READING", aFromFileName);
    }
    if (!toFile.is_open()) 
    {
        WRITE_ERROR("DOMAIN", "FILE_MANAGER", "FM#_0", "CANT_OPEN_FILE_FOR_WRITING", aToFileName);
    }

    std::string s;
    while (std::getline(fromFile, s, '\0')) 
    {
        toFile << s << '\n';
    }

    END_LOG_BLOCK();
    WRITE_LOG_ENDL;
}

dom::File::File(str_const_ref aFileName) :
    mOut    (aFileName)
{}

dom::File::~File()
{
    mOut.close();
}

void 
dom::File::write(const std::vector<std::string>& aMessage)
{
    for(const auto& i : aMessage) mOut << i << mDelimiter;
    mOut << '\n';
}

void
dom::File::setDelimiter(str_const_ref aDelimiter)
{
    mDelimiter = aDelimiter;
}

void
dom::File::writeEndl()
{
    mOut << '\n';
}

void
dom::File::close()
{
    mOut.close();
}