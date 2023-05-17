# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_DEB "OFF")
set(CPACK_BINARY_FREEBSD "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_NSIS "OFF")
set(CPACK_BINARY_RPM "OFF")
set(CPACK_BINARY_STGZ "ON")
set(CPACK_BINARY_TBZ2 "OFF")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_TXZ "OFF")
set(CPACK_BINARY_TZ "ON")
set(CPACK_BUILD_SOURCE_DIRS "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2;/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENTS_ALL "Unspecified;development;documentation;programs;runtime")
set(CPACK_COMPONENT_DEVELOPMENT_DEPENDS "runtime")
set(CPACK_COMPONENT_PROGRAMS_DEPENDS "runtime")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_DEPENDS "libxml2")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_NAME "libxml2-dev")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_SECTION "libdevel")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://gitlab.gnome.org/GNOME/libxml2")
set(CPACK_DEBIAN_PACKAGE_NAME "libxml2")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PROGRAMS_PACKAGE_DEPENDS "libxml2")
set(CPACK_DEBIAN_PROGRAMS_PACKAGE_NAME "libxml2-utils")
set(CPACK_DEBIAN_PROGRAMS_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_NAME "libxml2")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_RECOMMENDS "libxml2-utils")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_SECTION "libs")
set(CPACK_DEB_COMPONENT_INSTALL "ON")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "libxml2 built using CMake")
set(CPACK_GENERATOR "STGZ;TGZ;TZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build;libxml2;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "libxml2-2.12.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "libxml2 2.12.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_NSIS_URL_INFO_ABOUT "https://gitlab.gnome.org/GNOME/libxml2")
set(CPACK_OUTPUT_CONFIG_FILE "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "xml@gnome.org")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "libxml2 built using CMake")
set(CPACK_PACKAGE_DISPLAY_NAME "libxml2 2.12.0")
set(CPACK_PACKAGE_FILE_NAME "libxml2-2.12.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "libxml2-2.12.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "libxml2-2.12.0")
set(CPACK_PACKAGE_NAME "libxml2")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "2.12.0")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "12")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/Copyright")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_COMPONENT_INSTALL "ON")
set(CPACK_RPM_PACKAGE_GROUP "Development/Libraries")
set(CPACK_RPM_PACKAGE_NAME "libxml2")
set(CPACK_RPM_PACKAGE_URL "https://gitlab.gnome.org/GNOME/libxml2")
set(CPACK_RPM_development_PACKAGE_NAME "libxml2-devel")
set(CPACK_RPM_development_PACKAGE_REQUIRES "libxml2")
set(CPACK_RPM_programs_PACKAGE_NAME "libxml2-utils")
set(CPACK_RPM_programs_PACKAGE_REQUIRES "libxml2")
set(CPACK_RPM_runtime_PACKAGE_NAME "libxml2")
set(CPACK_RPM_runtime_PACKAGE_SUGGESTS "libxml2-utils")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
