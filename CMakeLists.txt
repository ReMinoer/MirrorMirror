cmake_minimum_required( VERSION 2.8 )

project( MirrorMirror )

find_package( OpenCV REQUIRED )

add_executable(
        MirrorMirror
        src/main.cpp
        src/MirrorMirrorEngine.hpp
        src/MirrorMirrorEngine.cpp
        src/Indexer.hpp
        src/Indexer.cpp
        src/IIndexer.hpp
        src/IDescriptor.hpp
        src/Descriptors/DescriptorBase.hpp
        src/Descriptors/DescriptorBase.cpp
        src/Descriptors/SiftDescriptor.hpp
        src/Descriptors/SiftDescriptor.cpp
)

target_link_libraries( MirrorMirror ${OpenCV_LIBS} )