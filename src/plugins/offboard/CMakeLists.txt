add_library(mavsdk_offboard
    offboard.cpp
    offboard_impl.cpp
)

target_link_libraries(mavsdk_offboard
    mavsdk
)

set_target_properties(mavsdk_offboard
    PROPERTIES COMPILE_FLAGS ${warnings}
)

target_include_directories(mavsdk_offboard PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/mavsdk>
    )

install(TARGETS mavsdk_offboard
    EXPORT mavsdk-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(FILES
    include/plugins/offboard/offboard.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mavsdk/plugins/offboard
)
