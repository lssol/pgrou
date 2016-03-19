project(GeometryQt)

add_definitions(-D__BUILD_DESKTOP__)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find Qt5 libraries
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Svg REQUIRED)

include_directories(
${Qt5Core_INCLUDE_DIRS}
${Qt5Gui_INCLUDE_DIRS}
${Qt5Widgets_INCLUDE_DIRS}
${Qt5Svg_INCLUDE_DIRS}
)
#pour avoir les fichier de MyScript (IHM seulement) dans visual studio
file(GLOB_RECURSE GEOM_QT_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src *.h)
file(GLOB_RECURSE GEOM_QT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src *.cpp)
#pour inclure les fichier de prgou  dans visual studio
file(GLOB_RECURSE GEOM_QT_main ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master *.cpp) #pour le main

file(GLOB_RECURSE GEOM_QT_coreh ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core *.h)  #les .h de core
file(GLOB_RECURSE GEOM_QT_core ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core *.cpp)  #les .cpp de core
file(GLOB_RECURSE GEOM_QT_core_catalogueh ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/catalogue *.h)  #les .h de core/catalogue
file(GLOB_RECURSE GEOM_QT_core_catalogue ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/catalogue *.cpp)  #les .cpp de core/catalogue
file(GLOB_RECURSE GEOM_QT_core_datah ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/data *.h)   #core/data
file(GLOB_RECURSE GEOM_QT_core_data ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/data *.cpp)  
file(GLOB_RECURSE GEOM_QT_core_graphh ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/graph *.h)   #core/graph
file(GLOB_RECURSE GEOM_QT_core_graph ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/core/graph *.cpp)  

file(GLOB_RECURSE GEOM_QT_sharedh ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/shared *.h)     #shared
file(GLOB_RECURSE GEOM_QT_shared ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/shared *.cpp)

file(GLOB_RECURSE GEOM_QT_apish ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/apis *.h)    #apis
file(GLOB_RECURSE GEOM_QT_apis ${CMAKE_CURRENT_SOURCE_DIR}/pgrou-master/src/apis *.cpp)

#file(GLOB_RECURSE GEOM_QT_api ${CMAKE_CURRENT_SOURCE_DIR}//pgrou-master/src/apis *.cpp)
set(GEOM_QT ${GEOM_QT_HDRS} ${GEOM_QT_SRCS} ${GEOM_QT_main} ${GEOM_QT_coreh} ${GEOM_QT_core} ${GEOM_QT_core_catalogueh} ${GEOM_QT_core_catalogue} ${GEOM_QT_core_datah} ${GEOM_QT_core_data} ${GEOM_QT_core_graphh}${GEOM_QT_core_graph} ${GEOM_QT_sharedh} ${GEOM_QT_shared} ${GEOM_QT_apish}  ${GEOM_QT_apis} )  
#pas oublier de remettre les noms juste au-dessus

if(APPLE)
  add_executable (GeometryQt ${GEOM_QT})
elseif (NOT APPLE)
  add_executable (GeometryQt WIN32 ${GEOM_QT})
  add_definitions(-DVO_MSE_FUNC_THROUGH_POINTERS)
endif()

add_definitions(-DATK_UTF16)
add_definitions(${Qt5Core_DEFINES} ${Qt5Gui_DEFINES} ${Qt5Widgets_DEFINES} ${Qt5Svg_DEFINES} -DQT_PLUGIN)

target_include_directories(GeometryQt
  PUBLIC
  # Qt
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Gui_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Svg_INCLUDE_DIRS}
  # SDK
  ${CMAKE_CURRENT_SOURCE_DIR}/../external_include/MyScriptSDK
  ${CMAKE_CURRENT_SOURCE_DIR}/../external_include/MyScriptWrappers
  # ATKCore
  ${CMAKE_CURRENT_SOURCE_DIR}/../external_include/ATKCore/lib/cpp/public
  #ATKGeom
  ${CMAKE_CURRENT_SOURCE_DIR}/../external_include/ATKGeom/lib/cpp/public
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(EXT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../external_lib)

target_link_libraries(GeometryQt ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5Svg_LIBRARIES} ${EXT_LIB_DIR}/ATKCore.lib ${EXT_LIB_DIR}/ATKGeom.lib ${EXT_LIB_DIR}/MyScriptDocument.CPP.lib ${EXT_LIB_DIR}/MyScriptGesture.CPP.lib ${EXT_LIB_DIR}/MyScriptInk.CPP.lib ${EXT_LIB_DIR}/MyScriptShape.CPP.lib ${EXT_LIB_DIR}/MyScriptEngine.CPP.lib)

if(WIN32)
  target_link_libraries (GeometryQt Qt5::WinMain)
  if(MSVC)
	set_target_properties(GeometryQt PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE") # works for all build modes
  endif(MSVC)
endif(WIN32)

if(CMAKE_GENERATOR MATCHES "Visual" OR CMAKE_GENERATOR MATCHES "Xcode")
  foreach (configuration ${CMAKE_CONFIGURATION_TYPES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../Resources/ DESTINATION ${CMAKE_BINARY_DIR}/${configuration}/)
  endforeach()
endif()