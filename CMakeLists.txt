project (kiphone)

find_package(KDE4 REQUIRED)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

MACRO_OPTIONAL_FIND_PACKAGE(Gpod)
MACRO_OPTIONAL_FIND_PACKAGE(Gdk)
MACRO_OPTIONAL_FIND_PACKAGE(GLIB2)
MACRO_OPTIONAL_FIND_PACKAGE(GObject)

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 ${KDE4_INCLUDES}
)

include(MacroOptionalFindPackage)
INCLUDE(MacroLibrary)

set(kiphone_SRCS
    main.cpp
    mainwindow.cpp
    xiphonereader.cpp
   )

kde4_add_ui_files(kiphone_SRCS mainwindow.ui)

kde4_add_executable(kiphone ${kiphone_SRCS})

target_link_libraries(kiphone
                      ${GOBJECT_LIBRARIES}
                      ${GLIB2_LIBRARIES}
                      ${KDE4_KDEUI_LIBS}
                      ${GPOD_LIBRARIES}
                      ${GDK_LIBRARIES}
                     )

install(TARGETS kiphone DESTINATION ${BIN_INSTALL_DIR})
install(FILES kiphone.rc
        DESTINATION ${DATA_INSTALL_DIR}/kiphone)
