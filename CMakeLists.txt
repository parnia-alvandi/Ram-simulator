cmake_minimum_required(VERSION 3.10)

# نام پروژه و نسخه
project(RAMSimulator VERSION 1.0)

# استاندارد C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# پوشه هدرها
include_directories(include)

# فایل‌های سورس
file(GLOB SOURCES "src/*.cpp")

# تعریف فایل اجرایی
add_executable(RAMSimulator ${SOURCES})
