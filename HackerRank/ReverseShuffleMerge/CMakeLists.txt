add_library(
    ReverseShuffleMerge
)
target_sources(
    ReverseShuffleMerge
    PRIVATE
    ReverseShuffleMerge.cpp
)

target_include_directories(
    ReverseShuffleMerge 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ReverseShuffleMerge
    EXPORT HackerRank-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ReverseShuffleMerge/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ReverseShuffleMerge
)