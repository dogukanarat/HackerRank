add_subdirectory(ReverseShuffleMerge)

install(
    EXPORT HackerRank-config
    NAMESPACE HackerRank::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
