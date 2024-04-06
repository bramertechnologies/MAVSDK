// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/arm_authorizer/arm_authorizer.proto)

#include "arm_authorizer/arm_authorizer.grpc.pb.h"
#include "plugins/arm_authorizer/arm_authorizer.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename ArmAuthorizer = ArmAuthorizer, typename LazyPlugin = LazyPlugin<ArmAuthorizer>>

class ArmAuthorizerServiceImpl final : public rpc::arm_authorizer::ArmAuthorizerService::Service {
public:
    ArmAuthorizerServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    static rpc::arm_authorizer::ArmAuthorizerDecision translateToRpcArmAuthorizerDecision(
        const mavsdk::ArmAuthorizer::ArmAuthorizerDecision& arm_authorizer_decision)
    {
        switch (arm_authorizer_decision) {
            default:
                LogErr() << "Unknown arm_authorizer_decision enum value: "
                         << static_cast<int>(arm_authorizer_decision);
            // FALLTHROUGH
            case mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionAccepted:
                return rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_ACCEPTED;
            case mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionTemporarilyRejected:
                return rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_TEMPORARILY_REJECTED;
            case mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionDenied:
                return rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_DENIED;
        }
    }

    static mavsdk::ArmAuthorizer::ArmAuthorizerDecision translateFromRpcArmAuthorizerDecision(
        const rpc::arm_authorizer::ArmAuthorizerDecision arm_authorizer_decision)
    {
        switch (arm_authorizer_decision) {
            default:
                LogErr() << "Unknown arm_authorizer_decision enum value: "
                         << static_cast<int>(arm_authorizer_decision);
            // FALLTHROUGH
            case rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_ACCEPTED:
                return mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionAccepted;
            case rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_TEMPORARILY_REJECTED:
                return mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionTemporarilyRejected;
            case rpc::arm_authorizer::ARM_AUTHORIZER_DECISION_DECISION_DENIED:
                return mavsdk::ArmAuthorizer::ArmAuthorizerDecision::DecisionDenied;
        }
    }

    static rpc::arm_authorizer::CommandAnswer
    translateToRpcCommandAnswer(const mavsdk::ArmAuthorizer::CommandAnswer& command_answer)
    {
        switch (command_answer) {
            default:
                LogErr() << "Unknown command_answer enum value: "
                         << static_cast<int>(command_answer);
            // FALLTHROUGH
            case mavsdk::ArmAuthorizer::CommandAnswer::Accepted:
                return rpc::arm_authorizer::COMMAND_ANSWER_ACCEPTED;
            case mavsdk::ArmAuthorizer::CommandAnswer::Failed:
                return rpc::arm_authorizer::COMMAND_ANSWER_FAILED;
        }
    }

    static mavsdk::ArmAuthorizer::CommandAnswer
    translateFromRpcCommandAnswer(const rpc::arm_authorizer::CommandAnswer command_answer)
    {
        switch (command_answer) {
            default:
                LogErr() << "Unknown command_answer enum value: "
                         << static_cast<int>(command_answer);
            // FALLTHROUGH
            case rpc::arm_authorizer::COMMAND_ANSWER_ACCEPTED:
                return mavsdk::ArmAuthorizer::CommandAnswer::Accepted;
            case rpc::arm_authorizer::COMMAND_ANSWER_FAILED:
                return mavsdk::ArmAuthorizer::CommandAnswer::Failed;
        }
    }

    grpc::Status SubscribeArmAuthorization(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::arm_authorizer::SubscribeArmAuthorizationRequest* /* request */,
        grpc::ServerWriter<rpc::arm_authorizer::ArmAuthorizationResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        const mavsdk::ArmAuthorizer::ArmAuthorizationHandle handle =
            _lazy_plugin.maybe_plugin()->subscribe_arm_authorization(
                [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex, &handle](
                    const uint32_t arm_authorization) {
                    rpc::arm_authorizer::ArmAuthorizationResponse rpc_response;

                    rpc_response.set_system_id(arm_authorization);

                    std::unique_lock<std::mutex> lock(*subscribe_mutex);
                    if (!*is_finished && !writer->Write(rpc_response)) {
                        _lazy_plugin.maybe_plugin()->unsubscribe_arm_authorization(handle);

                        *is_finished = true;
                        unregister_stream_stop_promise(stream_closed_promise);
                        stream_closed_promise->set_value();
                    }
                });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status RespondArmAuthorization(
        grpc::ServerContext* /* context */,
        const rpc::arm_authorizer::RespondArmAuthorizationRequest* request,
        rpc::arm_authorizer::RespondArmAuthorizationResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "RespondArmAuthorization sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->respond_arm_authorization(
            translateFromRpcArmAuthorizerDecision(request->arm_authorizer_decision()));

        if (response != nullptr) {
            response->set_allocated_command_answer(translateToRpcCommandAnswer(result).release());
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk