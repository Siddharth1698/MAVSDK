#include <iostream>
#include "integration_test_helper.h"
#include "mavsdk.h"
#include "plugins/info/info.h"

using namespace mavsdk;

TEST_F(SitlTest, Info)
{
    Mavsdk dc;

    ConnectionResult ret = dc.add_udp_connection();
    ASSERT_EQ(ret, ConnectionResult::Success);

    // Wait for system to connect via heartbeat.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    ASSERT_TRUE(dc.is_connected());

    System& system = dc.system();
    auto info = std::make_shared<Info>(system);

    // FIXME: we need to wait some time until Info has determined the version.
    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (unsigned i = 0; i < 3; ++i) {
        std::pair<Info::Result, Info::Version> version_result = info->get_version();

        EXPECT_EQ(version_result.first, Info::Result::Success);

        if (version_result.first == Info::Result::Success) {
            std::cout << "Flight version: " << version_result.second.flight_sw_major << "."
                      << version_result.second.flight_sw_minor << "."
                      << version_result.second.flight_sw_patch << " ("
                      << std::string(version_result.second.flight_sw_git_hash) << ")" << std::endl;
            std::cout << "Flight vendor version: " << version_result.second.flight_sw_vendor_major
                      << "." << version_result.second.flight_sw_vendor_minor << "."
                      << version_result.second.flight_sw_vendor_patch << std::endl;
            std::cout << "OS version: " << version_result.second.os_sw_major << "."
                      << version_result.second.os_sw_minor << "."
                      << version_result.second.os_sw_patch << " ("
                      << std::string(version_result.second.os_sw_git_hash) << ")" << std::endl;

            EXPECT_NE(version_result.second.flight_sw_major, 0);
        } else {
            LogWarn() << "Version request result: " << Info::result_str(version_result.first);
        }

        std::pair<Info::Result, Info::Product> product_result = info->get_product();
        EXPECT_EQ(product_result.first, Info::Result::Success);

        if (product_result.first == Info::Result::Success) {
            std::cout << "Vendor: " << product_result.second.vendor_name << std::endl;
            std::cout << "Product: " << product_result.second.product_name << std::endl;
        } else {
            LogWarn() << "Product request result: " << Info::result_str(product_result.first);
        }

        std::pair<Info::Result, Info::Identification> identification_result =
            info->get_identification();

        EXPECT_EQ(identification_result.first, Info::Result::Success);

        if (identification_result.first == Info::Result::Success) {
            std::cout << "Hardware UID: " << identification_result.second.hardware_uid << std::endl;
        } else {
            LogWarn() << "Identification request result: "
                      << Info::result_str(identification_result.first);
        }

        std::pair<Info::Result, Info::FlightInfo> flight_info_result =
            info->get_flight_information();
        EXPECT_EQ(flight_info_result.first, Info::Result::Success);

        if (flight_info_result.first == Info::Result::Success) {
            std::cout << "Time since boot (ms): "
                      << std::to_string(flight_info_result.second.time_boot_ms) << std::endl;
            std::cout << "Flight UID: " << flight_info_result.second.flight_uid << std::endl;
        } else {
            LogWarn() << "Product request result: " << Info::result_str(flight_info_result.first);
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
