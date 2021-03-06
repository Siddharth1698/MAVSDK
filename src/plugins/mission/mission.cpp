// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mission/mission.proto)

#include <iomanip>

#include "mission_impl.h"
#include "plugins/mission/mission.h"

namespace mavsdk {

using MissionItem = Mission::MissionItem;
using MissionPlan = Mission::MissionPlan;
using MissionProgress = Mission::MissionProgress;

Mission::Mission(System& system) : PluginBase(), _impl{new MissionImpl(system)} {}

Mission::~Mission() {}

void Mission::upload_mission_async(MissionPlan mission_plan, const ResultCallback callback)
{
    _impl->upload_mission_async(mission_plan, callback);
}

Mission::Result Mission::upload_mission(MissionPlan mission_plan) const
{
    return _impl->upload_mission(mission_plan);
}

Mission::Result Mission::cancel_mission_upload() const
{
    return _impl->cancel_mission_upload();
}

void Mission::download_mission_async(const DownloadMissionCallback callback)
{
    _impl->download_mission_async(callback);
}

std::pair<Mission::Result, Mission::MissionPlan> Mission::download_mission() const
{
    return _impl->download_mission();
}

Mission::Result Mission::cancel_mission_download() const
{
    return _impl->cancel_mission_download();
}

void Mission::start_mission_async(const ResultCallback callback)
{
    _impl->start_mission_async(callback);
}

Mission::Result Mission::start_mission() const
{
    return _impl->start_mission();
}

void Mission::pause_mission_async(const ResultCallback callback)
{
    _impl->pause_mission_async(callback);
}

Mission::Result Mission::pause_mission() const
{
    return _impl->pause_mission();
}

void Mission::clear_mission_async(const ResultCallback callback)
{
    _impl->clear_mission_async(callback);
}

Mission::Result Mission::clear_mission() const
{
    return _impl->clear_mission();
}

void Mission::set_current_mission_item_async(int32_t index, const ResultCallback callback)
{
    _impl->set_current_mission_item_async(index, callback);
}

Mission::Result Mission::set_current_mission_item(int32_t index) const
{
    return _impl->set_current_mission_item(index);
}

std::pair<Mission::Result, bool> Mission::is_mission_finished() const
{
    return _impl->is_mission_finished();
}

void Mission::subscribe_mission_progress(MissionProgressCallback callback)
{
    _impl->mission_progress_async(callback);
}

Mission::MissionProgress Mission::mission_progress() const
{
    return _impl->mission_progress();
}

std::pair<Mission::Result, bool> Mission::get_return_to_launch_after_mission() const
{
    return _impl->get_return_to_launch_after_mission();
}

Mission::Result Mission::set_return_to_launch_after_mission(bool enable) const
{
    return _impl->set_return_to_launch_after_mission(enable);
}

void Mission::import_qgroundcontrol_mission_async(
    std::string qgc_plan_path, const ImportQgroundcontrolMissionCallback callback)
{
    _impl->import_qgroundcontrol_mission_async(qgc_plan_path, callback);
}

std::pair<Mission::Result, Mission::MissionPlan>
Mission::import_qgroundcontrol_mission(std::string qgc_plan_path) const
{
    return _impl->import_qgroundcontrol_mission(qgc_plan_path);
}

std::ostream& operator<<(std::ostream& str, Mission::MissionItem::CameraAction const& camera_action)
{
    switch (camera_action) {
        case Mission::MissionItem::CameraAction::None:
            return str << "Camera Action None";
        case Mission::MissionItem::CameraAction::TakePhoto:
            return str << "Camera Action Take Photo";
        case Mission::MissionItem::CameraAction::StartPhotoInterval:
            return str << "Camera Action Start Photo Interval";
        case Mission::MissionItem::CameraAction::StopPhotoInterval:
            return str << "Camera Action Stop Photo Interval";
        case Mission::MissionItem::CameraAction::StartVideo:
            return str << "Camera Action Start Video";
        case Mission::MissionItem::CameraAction::StopVideo:
            return str << "Camera Action Stop Video";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Mission::MissionItem& lhs, const Mission::MissionItem& rhs)
{
    return ((std::isnan(rhs.latitude_deg) && std::isnan(lhs.latitude_deg)) ||
            (std::fabs(rhs.latitude_deg - lhs.latitude_deg) < 1e-07)) &&
           ((std::isnan(rhs.longitude_deg) && std::isnan(lhs.longitude_deg)) ||
            (std::fabs(rhs.longitude_deg - lhs.longitude_deg) < 1e-07)) &&
           ((std::isnan(rhs.relative_altitude_m) && std::isnan(lhs.relative_altitude_m)) ||
            rhs.relative_altitude_m == lhs.relative_altitude_m) &&
           ((std::isnan(rhs.speed_m_s) && std::isnan(lhs.speed_m_s)) ||
            rhs.speed_m_s == lhs.speed_m_s) &&
           (rhs.is_fly_through == lhs.is_fly_through) &&
           ((std::isnan(rhs.gimbal_pitch_deg) && std::isnan(lhs.gimbal_pitch_deg)) ||
            rhs.gimbal_pitch_deg == lhs.gimbal_pitch_deg) &&
           ((std::isnan(rhs.gimbal_yaw_deg) && std::isnan(lhs.gimbal_yaw_deg)) ||
            rhs.gimbal_yaw_deg == lhs.gimbal_yaw_deg) &&
           (rhs.camera_action == lhs.camera_action) &&
           ((std::isnan(rhs.loiter_time_s) && std::isnan(lhs.loiter_time_s)) ||
            rhs.loiter_time_s == lhs.loiter_time_s) &&
           ((std::isnan(rhs.camera_photo_interval_s) && std::isnan(lhs.camera_photo_interval_s)) ||
            rhs.camera_photo_interval_s == lhs.camera_photo_interval_s);
}

std::ostream& operator<<(std::ostream& str, Mission::MissionItem const& mission_item)
{
    str << std::setprecision(15);
    str << "mission_item:" << '\n' << "{\n";
    str << "    latitude_deg: " << mission_item.latitude_deg << '\n';
    str << "    longitude_deg: " << mission_item.longitude_deg << '\n';
    str << "    relative_altitude_m: " << mission_item.relative_altitude_m << '\n';
    str << "    speed_m_s: " << mission_item.speed_m_s << '\n';
    str << "    is_fly_through: " << mission_item.is_fly_through << '\n';
    str << "    gimbal_pitch_deg: " << mission_item.gimbal_pitch_deg << '\n';
    str << "    gimbal_yaw_deg: " << mission_item.gimbal_yaw_deg << '\n';
    str << "    camera_action: " << mission_item.camera_action << '\n';
    str << "    loiter_time_s: " << mission_item.loiter_time_s << '\n';
    str << "    camera_photo_interval_s: " << mission_item.camera_photo_interval_s << '\n';
    str << '}';
    return str;
}

bool operator==(const Mission::MissionPlan& lhs, const Mission::MissionPlan& rhs)
{
    return (rhs.mission_items == lhs.mission_items);
}

std::ostream& operator<<(std::ostream& str, Mission::MissionPlan const& mission_plan)
{
    str << std::setprecision(15);
    str << "mission_plan:" << '\n' << "{\n";
    str << "    mission_items: [";
    for (auto it = mission_plan.mission_items.begin(); it != mission_plan.mission_items.end();
         ++it) {
        str << *it;
        str << (it + 1 != mission_plan.mission_items.end() ? ", " : "]\n");
    }
    str << '}';
    return str;
}

bool operator==(const Mission::MissionProgress& lhs, const Mission::MissionProgress& rhs)
{
    return (rhs.current == lhs.current) && (rhs.total == lhs.total);
}

std::ostream& operator<<(std::ostream& str, Mission::MissionProgress const& mission_progress)
{
    str << std::setprecision(15);
    str << "mission_progress:" << '\n' << "{\n";
    str << "    current: " << mission_progress.current << '\n';
    str << "    total: " << mission_progress.total << '\n';
    str << '}';
    return str;
}

const char* Mission::result_str(Mission::Result result)
{
    switch (result) {
        case Mission::Result::Unknown:
            return "Unknown error";
        case Mission::Result::Success:
            return "Request succeeded";
        case Mission::Result::Error:
            return "Error";
        case Mission::Result::TooManyMissionItems:
            return "Too many mission items in the mission";
        case Mission::Result::Busy:
            return "Vehicle is busy";
        case Mission::Result::Timeout:
            return "Request timed out";
        case Mission::Result::InvalidArgument:
            return "Invalid argument";
        case Mission::Result::Unsupported:
            return "Mission downloaded from the system is not supported";
        case Mission::Result::NoMissionAvailable:
            return "No mission available on the system";
        case Mission::Result::FailedToOpenQgcPlan:
            return "Failed to open the QGroundControl plan";
        case Mission::Result::FailedToParseQgcPlan:
            return "Failed to parse the QGroundControl plan";
        case Mission::Result::UnsupportedMissionCmd:
            return "Unsupported mission command";
        case Mission::Result::TransferCancelled:
            return "Mission transfer (upload or download) has been cancelled";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Mission::Result const& result)
{
    switch (result) {
        case Mission::Result::Unknown:
            return str << "Result Unknown";
        case Mission::Result::Success:
            return str << "Result Success";
        case Mission::Result::Error:
            return str << "Result Error";
        case Mission::Result::TooManyMissionItems:
            return str << "Result Too Many Mission Items";
        case Mission::Result::Busy:
            return str << "Result Busy";
        case Mission::Result::Timeout:
            return str << "Result Timeout";
        case Mission::Result::InvalidArgument:
            return str << "Result Invalid Argument";
        case Mission::Result::Unsupported:
            return str << "Result Unsupported";
        case Mission::Result::NoMissionAvailable:
            return str << "Result No Mission Available";
        case Mission::Result::FailedToOpenQgcPlan:
            return str << "Result Failed To Open Qgc Plan";
        case Mission::Result::FailedToParseQgcPlan:
            return str << "Result Failed To Parse Qgc Plan";
        case Mission::Result::UnsupportedMissionCmd:
            return str << "Result Unsupported Mission Cmd";
        case Mission::Result::TransferCancelled:
            return str << "Result Transfer Cancelled";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk