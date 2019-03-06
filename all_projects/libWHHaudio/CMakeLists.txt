IF(WIN32)
    MESSAGE(STATUS "System:Windows")
    If(MSVC)
        MESSAGE(STATUS "Build platform:Microsoft Visual Studio")

        file(GLOB LIBWHHAUDIO_EXPORT_FILES "../../include/*.h")
        file(GLOB LIBWHHAUDIO_DEV_H "src/src_dev_manager/*.h")
        file(GLOB LIBWHHAUDIO_AUDIO_RENDER_H "src/src_audio_render/*.h")

        file(GLOB LIBWHHAUDIO_SOURCE_FILES "src/*.cpp")
        file(GLOB LIBWHHAUDIO_SOURCE_DEV "src/src_dev_manager/*.cpp")
        file(GLOB LIBWHHAUDIO_SOURCE_RENDER "src/src_audio_render/*.cpp")

        source_group("export" FILES ${LIBWHHAUDIO_EXPORT_FILES})
        source_group("header_src_audio_manager" FILE ${LIBWHHAUDIO_DEV_H})
        source_group("header_src_audio_render" FILE ${LIBWHHAUDIO_AUDIO_RENDER_H})

        source_group("source" FILES ${LIBWHHAUDIO_SOURCE_FILES})
        source_group("source_src_audio_manager" FILE ${LIBWHHAUDIO_SOURCE_DEV})
        source_group("source_src_audio_render" FILE ${LIBWHHAUDIO_SOURCE_RENDER})

        include_directories("../../include/"
                            "../../dependency/winsdk/Include/10.0.17134.0/")

        add_library(libWHHaudio SHARED ${LIBWHHAUDIO_EXPORT_FILES}
                                       ${LIBWHHAUDIO_SOURCE_FILES}
                                       ${LIBWHHAUDIO_DEV_H}
                                       ${LIBWHHAUDIO_AUDIO_RENDER_H}
                                       ${LIBWHHAUDIO_SOURCE_DEV}
                                       ${LIBWHHAUDIO_SOURCE_RENDER}
                                       )

        set_property(TARGET libWHHaudio PROPERTY FOLDER "libWHHaudio/")

        IF(CMAKE_CL_64)
            set(VSPLAT_FOLDER x64)
        ELSE()
            set(VSPLAT_FOLDER x86)
        ENDIF()

        set_property(TARGET libWHHaudio PROPERTY RUNTIME_OUTPUT_DIRECTORY "../../bin/${VSPLAT_FOLDER}/")
        set_property(TARGET libWHHaudio PROPERTY ARCHIVE_OUTPUT_DIRECTORY "../../lib/${VSPLAT_FOLDER}/")

        MESSAGE(STATUS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
    ENDIF()
ELSEIF(APPLE)
ELSEIF(UNIX)
ENDIF()