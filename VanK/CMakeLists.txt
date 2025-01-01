project(VanK)

# Automatically include all .cpp and .h files from the src/ directory
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

# Create the static library
add_library(VanK STATIC ${SRC_FILES})

# Export the include directory for other targets
target_include_directories(VanK PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#### 3 Party libs SDL3 ####
target_include_directories(VanK PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/SDL3/include)

# Optionally specify the version of SDL3 you are using
set(SDL3_VERSION 3.1.6)

# Link the SDL3 static library
target_link_libraries(VanK PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/SDL3/lib/x64/SDL3.lib")

#### 3 Party libs GLM ####
target_include_directories(VanK PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/GLM)

# Optionally specify the version of GLM you are using
set(GLM_VERSION 1.0.1)

#### 3 Party libs SDL3 Image ####
target_include_directories(VanK PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/SDL3-Image/include)

# Optionally specify the version of GLM you are using
set(SDL3-Image_VERSION 3.1.0)
# Link the SDL3-Image static library
target_link_libraries(VanK PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/SDL3-Image/lib/x64/SDL3_image.lib")

#### 3rd Party libs ImGui ####
# Add ImGui as a dependency (you'll need the ImGui files)
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/IMGUI/imgui")
if(NOT EXISTS ${IMGUI_DIR}/imgui.h)
    message(FATAL_ERROR "ImGui not found. Ensure it's in the Vendor folder.")
endif()
include_directories(${IMGUI_DIR})

# Add ImGui source files to the project
target_sources(VanK PRIVATE
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)