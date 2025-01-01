project(SandBox)

# Create the executable
add_executable(SandBox src/SandBox.cpp)

# Link the static library (libmath)
target_link_libraries(SandBox PRIVATE VanK)

# Define the path to SDL3.dll
set(SDL3_DLL_PATH "${CMAKE_SOURCE_DIR}/VanK/Vendor/SDL3/lib/x64/SDL3.dll")

# Copy SDL3.dll to the executable output directory
add_custom_command(TARGET SandBox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_DLL_PATH}"
        $<TARGET_FILE_DIR:SandBox>  # Copy it to the directory where the .exe is built
)

# Define the path to SDL3-Image.dll
set(SDL3-Image_DLL_PATH "${CMAKE_SOURCE_DIR}/VanK/Vendor/SDL3-Image/lib/x64/SDL3_image.dll")

# Copy SDL3-Image.dll to the executable output directory
add_custom_command(TARGET SandBox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3-Image_DLL_PATH}"
        $<TARGET_FILE_DIR:SandBox>  # Copy it to the directory where the .exe is built
)