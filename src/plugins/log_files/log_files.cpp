// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/log_files/log_files.proto)

#include <iomanip>

#include "log_files_impl.h"
#include "plugins/log_files/log_files.h"

namespace mavsdk {

using ProgressData = LogFiles::ProgressData;
using Entry = LogFiles::Entry;

LogFiles::LogFiles(System& system) : PluginBase(), _impl{new LogFilesImpl(system)} {}

LogFiles::~LogFiles() {}

void LogFiles::get_entries_async(const GetEntriesCallback callback)
{
    _impl->get_entries_async(callback);
}

std::pair<LogFiles::Result, std::vector<LogFiles::Entry>> LogFiles::get_entries() const
{
    return _impl->get_entries();
}

void LogFiles::download_log_file_async(
    uint32_t id, std::string path, DownloadLogFileCallback callback)
{
    _impl->download_log_file_async(id, path, callback);
}

bool operator==(const LogFiles::ProgressData& lhs, const LogFiles::ProgressData& rhs)
{
    return ((std::isnan(rhs.progress) && std::isnan(lhs.progress)) || rhs.progress == lhs.progress);
}

std::ostream& operator<<(std::ostream& str, LogFiles::ProgressData const& progress_data)
{
    str << std::setprecision(15);
    str << "progress_data:" << '\n' << "{\n";
    str << "    progress: " << progress_data.progress << '\n';
    str << '}';
    return str;
}

bool operator==(const LogFiles::Entry& lhs, const LogFiles::Entry& rhs)
{
    return (rhs.id == lhs.id) && (rhs.date == lhs.date) && (rhs.size_bytes == lhs.size_bytes);
}

std::ostream& operator<<(std::ostream& str, LogFiles::Entry const& entry)
{
    str << std::setprecision(15);
    str << "entry:" << '\n' << "{\n";
    str << "    id: " << entry.id << '\n';
    str << "    date: " << entry.date << '\n';
    str << "    size_bytes: " << entry.size_bytes << '\n';
    str << '}';
    return str;
}

const char* LogFiles::result_str(LogFiles::Result result)
{
    switch (result) {
        case LogFiles::Result::Unknown:
            return "Unknown error";
        case LogFiles::Result::Success:
            return "Request succeeded";
        case LogFiles::Result::Progress:
            return "Progress update";
        case LogFiles::Result::NoLogfiles:
            return "No log files found";
        case LogFiles::Result::Timeout:
            return "A timeout happened";
        case LogFiles::Result::InvalidArgument:
            return "Invalid argument";
        case LogFiles::Result::FileOpenFailed:
            return "File open failed";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, LogFiles::Result const& result)
{
    switch (result) {
        case LogFiles::Result::Unknown:
            return str << "Result Unknown";
        case LogFiles::Result::Success:
            return str << "Result Success";
        case LogFiles::Result::Progress:
            return str << "Result Progress";
        case LogFiles::Result::NoLogfiles:
            return str << "Result No Logfiles";
        case LogFiles::Result::Timeout:
            return str << "Result Timeout";
        case LogFiles::Result::InvalidArgument:
            return str << "Result Invalid Argument";
        case LogFiles::Result::FileOpenFailed:
            return str << "Result File Open Failed";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk