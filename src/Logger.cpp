#include "Logger.h"
#include <memory>
#include "Poco/SplitterChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/AutoPtr.h"
using std::unique_ptr;
using Poco::SplitterChannel;
using Poco::ConsoleChannel;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::FileChannel;
using Poco::AutoPtr;
TV_NAME_SPACE_BEGIN
Logger::Logger()
{
    AutoPtr<FileChannel> file_channel(new FileChannel());
    file_channel->setProperty("rotation" ,"10M");
    file_channel->setProperty("archive" ,"timestamp");
    file_channel->setProperty("path" ,"./tvirus.log");
    AutoPtr<PatternFormatter> pattern_formatter (new PatternFormatter("%E(%L-%H-%M-%S):%p:%P:%I:%U:%u#%t"));
    AutoPtr<FormattingChannel> formatter_channle(new FormattingChannel(pattern_formatter , file_channel));
    Poco::Logger::root().setChannel(formatter_channle);
    Poco::Logger::root().setLevel(8);
}
void Logger::Debug(std::string content)
{
    poco_debug(Poco::Logger::root(),content);
}
void Logger::Info(std::string content)
{
    poco_information(Poco::Logger::root(),content);
}
void Logger::Warn(std::string content)
{
    poco_warning(Poco::Logger::root(),content);
}
void Logger::Error(std::string content)
{
    poco_error(Poco::Logger::root(),content);
}
void Logger::Crit(std::string content)
{
    poco_critical(Poco::Logger::root(),content);
}
TV_NAME_SPACE_END
