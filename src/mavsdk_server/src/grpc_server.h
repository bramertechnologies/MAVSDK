// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to templates/grpc_server.h.j2
#pragma once

#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>

#ifdef ENABLE_PROTO_REFLECTION
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#endif

#include <memory>

#include "mavsdk.h"
#include "core/core_service_impl.h"

#ifdef ACTION_ENABLED
#include "plugins/action/action.h"
#include "action/action_service_impl.h"
#endif

#ifdef ACTION_SERVER_ENABLED
#include "plugins/action_server/action_server.h"
#include "action_server/action_server_service_impl.h"
#endif

#ifdef ARM_AUTHORIZER_SERVER_ENABLED
#include "plugins/arm_authorizer_server/arm_authorizer_server.h"
#include "arm_authorizer_server/arm_authorizer_server_service_impl.h"
#endif

#ifdef CALIBRATION_ENABLED
#include "plugins/calibration/calibration.h"
#include "calibration/calibration_service_impl.h"
#endif

#ifdef CAMERA_ENABLED
#include "plugins/camera/camera.h"
#include "camera/camera_service_impl.h"
#endif

#ifdef CAMERA_SERVER_ENABLED
#include "plugins/camera_server/camera_server.h"
#include "camera_server/camera_server_service_impl.h"
#endif

#ifdef COMPONENT_INFORMATION_ENABLED
#include "plugins/component_information/component_information.h"
#include "component_information/component_information_service_impl.h"
#endif

#ifdef COMPONENT_INFORMATION_SERVER_ENABLED
#include "plugins/component_information_server/component_information_server.h"
#include "component_information_server/component_information_server_service_impl.h"
#endif

#ifdef FAILURE_ENABLED
#include "plugins/failure/failure.h"
#include "failure/failure_service_impl.h"
#endif

#ifdef FOLLOW_ME_ENABLED
#include "plugins/follow_me/follow_me.h"
#include "follow_me/follow_me_service_impl.h"
#endif

#ifdef FTP_ENABLED
#include "plugins/ftp/ftp.h"
#include "ftp/ftp_service_impl.h"
#endif

#ifdef FTP_SERVER_ENABLED
#include "plugins/ftp_server/ftp_server.h"
#include "ftp_server/ftp_server_service_impl.h"
#endif

#ifdef GEOFENCE_ENABLED
#include "plugins/geofence/geofence.h"
#include "geofence/geofence_service_impl.h"
#endif

#ifdef GIMBAL_ENABLED
#include "plugins/gimbal/gimbal.h"
#include "gimbal/gimbal_service_impl.h"
#endif

#ifdef GRIPPER_ENABLED
#include "plugins/gripper/gripper.h"
#include "gripper/gripper_service_impl.h"
#endif

#ifdef INFO_ENABLED
#include "plugins/info/info.h"
#include "info/info_service_impl.h"
#endif

#ifdef LOG_FILES_ENABLED
#include "plugins/log_files/log_files.h"
#include "log_files/log_files_service_impl.h"
#endif

#ifdef MANUAL_CONTROL_ENABLED
#include "plugins/manual_control/manual_control.h"
#include "manual_control/manual_control_service_impl.h"
#endif

#ifdef MISSION_ENABLED
#include "plugins/mission/mission.h"
#include "mission/mission_service_impl.h"
#endif

#ifdef MISSION_RAW_ENABLED
#include "plugins/mission_raw/mission_raw.h"
#include "mission_raw/mission_raw_service_impl.h"
#endif

#ifdef MISSION_RAW_SERVER_ENABLED
#include "plugins/mission_raw_server/mission_raw_server.h"
#include "mission_raw_server/mission_raw_server_service_impl.h"
#endif

#ifdef MOCAP_ENABLED
#include "plugins/mocap/mocap.h"
#include "mocap/mocap_service_impl.h"
#endif

#ifdef OFFBOARD_ENABLED
#include "plugins/offboard/offboard.h"
#include "offboard/offboard_service_impl.h"
#endif

#ifdef PARAM_ENABLED
#include "plugins/param/param.h"
#include "param/param_service_impl.h"
#endif

#ifdef PARAM_SERVER_ENABLED
#include "plugins/param_server/param_server.h"
#include "param_server/param_server_service_impl.h"
#endif

#ifdef RTK_ENABLED
#include "plugins/rtk/rtk.h"
#include "rtk/rtk_service_impl.h"
#endif

#ifdef SERVER_UTILITY_ENABLED
#include "plugins/server_utility/server_utility.h"
#include "server_utility/server_utility_service_impl.h"
#endif

#ifdef SHELL_ENABLED
#include "plugins/shell/shell.h"
#include "shell/shell_service_impl.h"
#endif

#ifdef TELEMETRY_ENABLED
#include "plugins/telemetry/telemetry.h"
#include "telemetry/telemetry_service_impl.h"
#endif

#ifdef TELEMETRY_SERVER_ENABLED
#include "plugins/telemetry_server/telemetry_server.h"
#include "telemetry_server/telemetry_server_service_impl.h"
#endif

#ifdef TRANSPONDER_ENABLED
#include "plugins/transponder/transponder.h"
#include "transponder/transponder_service_impl.h"
#endif

#ifdef TUNE_ENABLED
#include "plugins/tune/tune.h"
#include "tune/tune_service_impl.h"
#endif

#ifdef WINCH_ENABLED
#include "plugins/winch/winch.h"
#include "winch/winch_service_impl.h"
#endif

namespace mavsdk {
namespace mavsdk_server {

class GrpcServer {
public:
    GrpcServer(Mavsdk& mavsdk) :
        _core(mavsdk),

#ifdef ACTION_ENABLED
        _action_lazy_plugin(mavsdk),
        _action_service(_action_lazy_plugin),
#endif

#ifdef ACTION_SERVER_ENABLED
        _action_server_lazy_plugin(mavsdk),
        _action_server_service(_action_server_lazy_plugin),
#endif

#ifdef ARM_AUTHORIZER_SERVER_ENABLED
        _arm_authorizer_server_lazy_plugin(mavsdk),
        _arm_authorizer_server_service(_arm_authorizer_server_lazy_plugin),
#endif

#ifdef CALIBRATION_ENABLED
        _calibration_lazy_plugin(mavsdk),
        _calibration_service(_calibration_lazy_plugin),
#endif

#ifdef CAMERA_ENABLED
        _camera_lazy_plugin(mavsdk),
        _camera_service(_camera_lazy_plugin),
#endif

#ifdef CAMERA_SERVER_ENABLED
        _camera_server_lazy_plugin(mavsdk),
        _camera_server_service(_camera_server_lazy_plugin),
#endif

#ifdef COMPONENT_INFORMATION_ENABLED
        _component_information_lazy_plugin(mavsdk),
        _component_information_service(_component_information_lazy_plugin),
#endif

#ifdef COMPONENT_INFORMATION_SERVER_ENABLED
        _component_information_server_lazy_plugin(mavsdk),
        _component_information_server_service(_component_information_server_lazy_plugin),
#endif

#ifdef FAILURE_ENABLED
        _failure_lazy_plugin(mavsdk),
        _failure_service(_failure_lazy_plugin),
#endif

#ifdef FOLLOW_ME_ENABLED
        _follow_me_lazy_plugin(mavsdk),
        _follow_me_service(_follow_me_lazy_plugin),
#endif

#ifdef FTP_ENABLED
        _ftp_lazy_plugin(mavsdk),
        _ftp_service(_ftp_lazy_plugin),
#endif

#ifdef FTP_SERVER_ENABLED
        _ftp_server_lazy_plugin(mavsdk),
        _ftp_server_service(_ftp_server_lazy_plugin),
#endif

#ifdef GEOFENCE_ENABLED
        _geofence_lazy_plugin(mavsdk),
        _geofence_service(_geofence_lazy_plugin),
#endif

#ifdef GIMBAL_ENABLED
        _gimbal_lazy_plugin(mavsdk),
        _gimbal_service(_gimbal_lazy_plugin),
#endif

#ifdef GRIPPER_ENABLED
        _gripper_lazy_plugin(mavsdk),
        _gripper_service(_gripper_lazy_plugin),
#endif

#ifdef INFO_ENABLED
        _info_lazy_plugin(mavsdk),
        _info_service(_info_lazy_plugin),
#endif

#ifdef LOG_FILES_ENABLED
        _log_files_lazy_plugin(mavsdk),
        _log_files_service(_log_files_lazy_plugin),
#endif

#ifdef MANUAL_CONTROL_ENABLED
        _manual_control_lazy_plugin(mavsdk),
        _manual_control_service(_manual_control_lazy_plugin),
#endif

#ifdef MISSION_ENABLED
        _mission_lazy_plugin(mavsdk),
        _mission_service(_mission_lazy_plugin),
#endif

#ifdef MISSION_RAW_ENABLED
        _mission_raw_lazy_plugin(mavsdk),
        _mission_raw_service(_mission_raw_lazy_plugin),
#endif

#ifdef MISSION_RAW_SERVER_ENABLED
        _mission_raw_server_lazy_plugin(mavsdk),
        _mission_raw_server_service(_mission_raw_server_lazy_plugin),
#endif

#ifdef MOCAP_ENABLED
        _mocap_lazy_plugin(mavsdk),
        _mocap_service(_mocap_lazy_plugin),
#endif

#ifdef OFFBOARD_ENABLED
        _offboard_lazy_plugin(mavsdk),
        _offboard_service(_offboard_lazy_plugin),
#endif

#ifdef PARAM_ENABLED
        _param_lazy_plugin(mavsdk),
        _param_service(_param_lazy_plugin),
#endif

#ifdef PARAM_SERVER_ENABLED
        _param_server_lazy_plugin(mavsdk),
        _param_server_service(_param_server_lazy_plugin),
#endif

#ifdef RTK_ENABLED
        _rtk_lazy_plugin(mavsdk),
        _rtk_service(_rtk_lazy_plugin),
#endif

#ifdef SERVER_UTILITY_ENABLED
        _server_utility_lazy_plugin(mavsdk),
        _server_utility_service(_server_utility_lazy_plugin),
#endif

#ifdef SHELL_ENABLED
        _shell_lazy_plugin(mavsdk),
        _shell_service(_shell_lazy_plugin),
#endif

#ifdef TELEMETRY_ENABLED
        _telemetry_lazy_plugin(mavsdk),
        _telemetry_service(_telemetry_lazy_plugin),
#endif

#ifdef TELEMETRY_SERVER_ENABLED
        _telemetry_server_lazy_plugin(mavsdk),
        _telemetry_server_service(_telemetry_server_lazy_plugin),
#endif

#ifdef TRANSPONDER_ENABLED
        _transponder_lazy_plugin(mavsdk),
        _transponder_service(_transponder_lazy_plugin),
#endif

#ifdef TUNE_ENABLED
        _tune_lazy_plugin(mavsdk),
        _tune_service(_tune_lazy_plugin),
#endif

#ifdef WINCH_ENABLED
        _winch_lazy_plugin(mavsdk),
        _winch_service(_winch_lazy_plugin)
#endif

    {}

    int run();
    void wait();
    void stop();
    void set_port(int port);

private:
    void setup_port(grpc::ServerBuilder& builder);

    CoreServiceImpl<> _core;

#ifdef ACTION_ENABLED

    LazyPlugin<Action> _action_lazy_plugin;

    ActionServiceImpl<> _action_service;
#endif

#ifdef ACTION_SERVER_ENABLED

    LazyServerPlugin<ActionServer> _action_server_lazy_plugin;

    ActionServerServiceImpl<> _action_server_service;
#endif

#ifdef ARM_AUTHORIZER_SERVER_ENABLED

    LazyServerPlugin<ArmAuthorizerServer> _arm_authorizer_server_lazy_plugin;

    ArmAuthorizerServerServiceImpl<> _arm_authorizer_server_service;
#endif

#ifdef CALIBRATION_ENABLED

    LazyPlugin<Calibration> _calibration_lazy_plugin;

    CalibrationServiceImpl<> _calibration_service;
#endif

#ifdef CAMERA_ENABLED

    LazyPlugin<Camera> _camera_lazy_plugin;

    CameraServiceImpl<> _camera_service;
#endif

#ifdef CAMERA_SERVER_ENABLED

    LazyServerPlugin<CameraServer> _camera_server_lazy_plugin;

    CameraServerServiceImpl<> _camera_server_service;
#endif

#ifdef COMPONENT_INFORMATION_ENABLED

    LazyPlugin<ComponentInformation> _component_information_lazy_plugin;

    ComponentInformationServiceImpl<> _component_information_service;
#endif

#ifdef COMPONENT_INFORMATION_SERVER_ENABLED

    LazyServerPlugin<ComponentInformationServer> _component_information_server_lazy_plugin;

    ComponentInformationServerServiceImpl<> _component_information_server_service;
#endif

#ifdef FAILURE_ENABLED

    LazyPlugin<Failure> _failure_lazy_plugin;

    FailureServiceImpl<> _failure_service;
#endif

#ifdef FOLLOW_ME_ENABLED

    LazyPlugin<FollowMe> _follow_me_lazy_plugin;

    FollowMeServiceImpl<> _follow_me_service;
#endif

#ifdef FTP_ENABLED

    LazyPlugin<Ftp> _ftp_lazy_plugin;

    FtpServiceImpl<> _ftp_service;
#endif

#ifdef FTP_SERVER_ENABLED

    LazyServerPlugin<FtpServer> _ftp_server_lazy_plugin;

    FtpServerServiceImpl<> _ftp_server_service;
#endif

#ifdef GEOFENCE_ENABLED

    LazyPlugin<Geofence> _geofence_lazy_plugin;

    GeofenceServiceImpl<> _geofence_service;
#endif

#ifdef GIMBAL_ENABLED

    LazyPlugin<Gimbal> _gimbal_lazy_plugin;

    GimbalServiceImpl<> _gimbal_service;
#endif

#ifdef GRIPPER_ENABLED

    LazyPlugin<Gripper> _gripper_lazy_plugin;

    GripperServiceImpl<> _gripper_service;
#endif

#ifdef INFO_ENABLED

    LazyPlugin<Info> _info_lazy_plugin;

    InfoServiceImpl<> _info_service;
#endif

#ifdef LOG_FILES_ENABLED

    LazyPlugin<LogFiles> _log_files_lazy_plugin;

    LogFilesServiceImpl<> _log_files_service;
#endif

#ifdef MANUAL_CONTROL_ENABLED

    LazyPlugin<ManualControl> _manual_control_lazy_plugin;

    ManualControlServiceImpl<> _manual_control_service;
#endif

#ifdef MISSION_ENABLED

    LazyPlugin<Mission> _mission_lazy_plugin;

    MissionServiceImpl<> _mission_service;
#endif

#ifdef MISSION_RAW_ENABLED

    LazyPlugin<MissionRaw> _mission_raw_lazy_plugin;

    MissionRawServiceImpl<> _mission_raw_service;
#endif

#ifdef MISSION_RAW_SERVER_ENABLED

    LazyServerPlugin<MissionRawServer> _mission_raw_server_lazy_plugin;

    MissionRawServerServiceImpl<> _mission_raw_server_service;
#endif

#ifdef MOCAP_ENABLED

    LazyPlugin<Mocap> _mocap_lazy_plugin;

    MocapServiceImpl<> _mocap_service;
#endif

#ifdef OFFBOARD_ENABLED

    LazyPlugin<Offboard> _offboard_lazy_plugin;

    OffboardServiceImpl<> _offboard_service;
#endif

#ifdef PARAM_ENABLED

    LazyPlugin<Param> _param_lazy_plugin;

    ParamServiceImpl<> _param_service;
#endif

#ifdef PARAM_SERVER_ENABLED

    LazyServerPlugin<ParamServer> _param_server_lazy_plugin;

    ParamServerServiceImpl<> _param_server_service;
#endif

#ifdef RTK_ENABLED

    LazyPlugin<Rtk> _rtk_lazy_plugin;

    RtkServiceImpl<> _rtk_service;
#endif

#ifdef SERVER_UTILITY_ENABLED

    LazyPlugin<ServerUtility> _server_utility_lazy_plugin;

    ServerUtilityServiceImpl<> _server_utility_service;
#endif

#ifdef SHELL_ENABLED

    LazyPlugin<Shell> _shell_lazy_plugin;

    ShellServiceImpl<> _shell_service;
#endif

#ifdef TELEMETRY_ENABLED

    LazyPlugin<Telemetry> _telemetry_lazy_plugin;

    TelemetryServiceImpl<> _telemetry_service;
#endif

#ifdef TELEMETRY_SERVER_ENABLED

    LazyServerPlugin<TelemetryServer> _telemetry_server_lazy_plugin;

    TelemetryServerServiceImpl<> _telemetry_server_service;
#endif

#ifdef TRANSPONDER_ENABLED

    LazyPlugin<Transponder> _transponder_lazy_plugin;

    TransponderServiceImpl<> _transponder_service;
#endif

#ifdef TUNE_ENABLED

    LazyPlugin<Tune> _tune_lazy_plugin;

    TuneServiceImpl<> _tune_service;
#endif

#ifdef WINCH_ENABLED

    LazyPlugin<Winch> _winch_lazy_plugin;

    WinchServiceImpl<> _winch_service;
#endif

    std::unique_ptr<grpc::Server> _server;

    int _port{0};
    int _bound_port{0};
};

} // namespace mavsdk_server
} // namespace mavsdk
