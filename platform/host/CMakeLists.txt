# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

add_library(host console.cpp)

theCore_create_json_validator_runner(
    NAME host_validate
    JSON ${THECORE_TARGET_CONFIG_FILE}
    SCHEMA ${CMAKE_CURRENT_LIST_DIR}/schemas/host.schema.json
    SUBOBJECT "platform"
    WORKDIR ${CMAKE_CURRENT_LIST_DIR}/schemas
)

# Check if console must be enabled.
if(thecore_cfg.platform.console)
    set(THECORE_CONFIG_USE_CONSOLE 1 CACHE STRING "host console" FORCE)
endif()

# Export platform definitions

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/templates/defines.in.hpp
    ${CMAKE_CURRENT_BINARY_DIR}/export/aux/platform_defines.hpp
)

# Platform-generated code

configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/templates/generated.in.hpp
    ${CMAKE_CURRENT_BINARY_DIR}/export/aux/generated.hpp
)

target_include_directories(host PUBLIC
    export export/platform ${CMAKE_CURRENT_BINARY_DIR}/export/)
target_link_libraries(host PUBLIC types)
target_link_libraries(host PUBLIC platform_common)

add_dependencies(host host_validate)
