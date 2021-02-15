#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/gimbal/gimbal.h>

namespace py = pybind11;
void init_gimbal(py::module_& m, py::class_<mavsdk::System>& system)
{
    py::class_<mavsdk::Gimbal> gimbal(m, "Gimbal");

    gimbal.def("set_pitch_and_yaw", &mavsdk::Gimbal::set_pitch_and_yaw)
        .def("set_pitch_rate_and_yaw_rate", &mavsdk::Gimbal::set_pitch_rate_and_yaw_rate)
        .def("set_mode", &mavsdk::Gimbal::set_mode)
        .def("set_roi_location", &mavsdk::Gimbal::set_roi_location)
        .def("take_control", &mavsdk::Gimbal::take_control)
        .def("release_control", &mavsdk::Gimbal::release_control)
        .def("control", &mavsdk::Gimbal::control);

    py::enum_<mavsdk::Gimbal::GimbalMode>(gimbal, "GimbalMode")
        .value("YawFollow", mavsdk::Gimbal::GimbalMode::YawFollow)
        .value("YawLock", mavsdk::Gimbal::GimbalMode::YawLock);

    py::enum_<mavsdk::Gimbal::ControlMode>(gimbal, "ControlMode")
        .value("None", mavsdk::Gimbal::ControlMode::None)
        .value("Primary", mavsdk::Gimbal::ControlMode::Primary)
        .value("Secondary", mavsdk::Gimbal::ControlMode::Secondary);

    py::class_<mavsdk::Gimbal::ControlStatus> control_status(gimbal, "ControlStatus");
    control_status.def(py::init<>())
        .def_readwrite("control_mode", &mavsdk::Gimbal::ControlStatus::control_mode)
        .def_readwrite(
            "sysid_primary_control", &mavsdk::Gimbal::ControlStatus::sysid_primary_control)
        .def_readwrite(
            "compid_primary_control", &mavsdk::Gimbal::ControlStatus::compid_primary_control)
        .def_readwrite(
            "sysid_secondary_control", &mavsdk::Gimbal::ControlStatus::sysid_secondary_control)
        .def_readwrite(
            "compid_secondary_control", &mavsdk::Gimbal::ControlStatus::compid_secondary_control);

    py::enum_<mavsdk::Gimbal::Result>(gimbal, "Result")
        .value("Unknown", mavsdk::Gimbal::Result::Unknown)
        .value("Success", mavsdk::Gimbal::Result::Success)
        .value("Error", mavsdk::Gimbal::Result::Error)
        .value("Timeout", mavsdk::Gimbal::Result::Timeout)
        .value("Unsupported", mavsdk::Gimbal::Result::Unsupported);

    system.def(
        "gimbal",
        &mavsdk::System::gimbal,
        py::return_value_policy::reference_internal,
        py::keep_alive<1, 0>());
}