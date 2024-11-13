set_cmake_folder_context(TARGET_FOLDER_NAME)

add_custom_target(CoreObjectsDelphiBindings ALL)
add_dependencies(CoreObjectsDelphiBindings daq::coreobjects)

if (OPENDAQ_PACKAGE_ENABLE)
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/"
            DESTINATION ${CMAKE_INSTALL_PREFIX}/bindings/delphi
            FILES_MATCHING PATTERN "*.pas"
            PATTERN "CMakeFiles" EXCLUDE
            PATTERN "Win32" EXCLUDE
            PATTERN "x64" EXCLUDE
            PATTERN "__history" EXCLUDE
            PATTERN "__recovery" EXCLUDE
    )
endif()