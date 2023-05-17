# Install script for directory: /home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libxml2/libxml" TYPE FILE FILES
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/c14n.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/catalog.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/chvalid.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/debugXML.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/dict.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/encoding.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/entities.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/globals.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/hash.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/HTMLparser.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/HTMLtree.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/list.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/nanoftp.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/nanohttp.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/parser.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/parserInternals.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/pattern.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/relaxng.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/SAX.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/SAX2.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/schemasInternals.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/schematron.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/threads.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/tree.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/uri.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/valid.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xinclude.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xlink.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlIO.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlautomata.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlerror.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlexports.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlmemory.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlmodule.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlreader.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlregexp.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlsave.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlschemas.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlschemastypes.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlstring.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlunicode.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xmlwriter.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xpath.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xpathInternals.h"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/include/libxml/xpointer.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so.2.12.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2.so.2.12.0"
    "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so.2.12.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libxml2.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xprogramsx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/xmlcatalog")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog"
         OLD_RPATH "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlcatalog")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xprogramsx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/xmllint")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint"
         OLD_RPATH "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmllint")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/python/libxml2mod.so.2.12.0")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/python" TYPE SHARED_LIBRARY FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2mod.so.2.12.0")
  if(EXISTS "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0"
         OLD_RPATH "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/python/libxml2mod.so.2.12.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/python/libxml2mod.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/python/libxml2mod.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/python/libxml2mod.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/python/libxml2mod.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/python" TYPE SHARED_LIBRARY FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2mod.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/python/libxml2mod.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/python/libxml2mod.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/python/libxml2mod.so"
         OLD_RPATH "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/python/libxml2mod.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/python/drv_libxml2.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/python" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/python/drv_libxml2.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/python/libxml2.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/python" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocumentationx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/doc/xml2-config.1")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocumentationx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/doc/xmlcatalog.1")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocumentationx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/doc/xmllint.1")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocumentationx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libxml2" TYPE DIRECTORY FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/doc/" REGEX "/Makefile\\.[^/]*$" EXCLUDE REGEX "/[^/]*\\.1$" EXCLUDE REGEX "/[^/]*\\.py$" EXCLUDE REGEX "/[^/]*\\.res$" EXCLUDE REGEX "/[^/]*\\.xml$" EXCLUDE REGEX "/[^/]*\\.xsl$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2-config.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml2-config-version.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0/libxml2-export.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0/libxml2-export.cmake"
         "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CMakeFiles/Export/lib64/cmake/libxml2-2.12.0/libxml2-export.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0/libxml2-export-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0/libxml2-export.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CMakeFiles/Export/lib64/cmake/libxml2-2.12.0/libxml2-export.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/libxml2-2.12.0" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/CMakeFiles/Export/lib64/cmake/libxml2-2.12.0/libxml2-export-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libxml2/libxml" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml/xmlversion.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/pkgconfig" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/libxml-2.0.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/xml2-config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2/libxml.m4")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/csmajs/ahude001/final-project-ahude001-dshao009-jshen075-jrive141/src/libxml2-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
