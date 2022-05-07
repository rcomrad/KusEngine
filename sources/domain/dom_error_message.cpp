#include "domain/dom_error_message.hpp"

std::ostream* dom::ErrorMessages::mLogStream    =  &std::cout;
std::ostream* dom::ErrorMessages::mErrorStream  =  &std::cout;

sint_8 dom::ErrorMessages::mLogBlockCount       =  0;

dom::ErrorMessages mGreatCrutch;

dom::ErrorMessages::ErrorMessages()
{
    #if     defined(LOGS_DEFAULT_OUTPUT)
        mLogStream = &std::cout;
    #elif   defined(LOGS_TO_COUT_OUTPUT)
        mLogStream = &std::cout;
    #elif   defined(LOGS_TO_FILE_OUTPUT)
        mLogStream = new std::ofstream(LOGS_PATH + "out.log");
    #endif

    #if     defined(ERRORS_DEFAULT_OUTPUT)
        mErrorStream = &std::cout;
    #elif   defined(ERRORS_TO_COUT_OUTPUT)
        mErrorStream = &std::cout;
    #elif   defined(ERRORS_TO_FILE_OUTPUT)
        mErrorStream = new std::ofstream(ERRORS_PATH + "out.err");
    #elif   defined(ERRORS_TO_LOG_OUTPU)
        mErrorStream = mLogStream;
    #endif
}

void 
dom::ErrorMessages::writeLogEndl()
{
    (*mLogStream) << '\n';
}

#ifdef BILL_WINDOWS
str_val
dom::ErrorMessages::GetLastErrorAsString()
{
    //setlocale(LC_ALL, "Russian");

    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    //std::wstring message(messageBuffer, size);
    std::string message;
    for (int i = 0; i < size; ++i)
    {
        message.push_back(messageBuffer[i]);
    }

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}
#endif // !BILL_WINDOWS