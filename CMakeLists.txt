cmake_minimum_required(VERSION 3.5)
project(cli11-demo)
set(CMAKE_CXX_STANDARD 11)

find_package(CLI11 CONFIG)

# --------------------------------------------------------------------------
execute_process(
    COMMAND bash -c "basename $(git rev-parse --show-toplevel)"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE REPO_NAME
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_REPO_NAME=\"${REPO_NAME}\")
message(STATUS "    Git Repo Name : " ${REPO_NAME})
# --------------------------------------------------------------------------
execute_process(COMMAND git rev-parse --abbrev-ref HEAD
    OUTPUT_VARIABLE GIT_BRANCH
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_GIT_BRANCH=\"${GIT_BRANCH}\")
message(STATUS "  Git Repo Branch : " ${GIT_BRANCH})
# --------------------------------------------------------------------------
execute_process(COMMAND git describe --abbrev=7 --dirty --always --tags
    OUTPUT_VARIABLE GIT_TAG
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_GIT_TAG=\"${GIT_TAG}\")
message(STATUS "     Git Repo Tag : " ${GIT_TAG})
# --------------------------------------------------------------------------
execute_process(COMMAND git rev-parse HEAD
    OUTPUT_VARIABLE GIT_COMMIT
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_GIT_COMMIT=\"${GIT_COMMIT}\")
message(STATUS "       Git Commit : " ${GIT_COMMIT})
# --------------------------------------------------------------------------
execute_process(COMMAND git show -s --format='%an' HEAD
    OUTPUT_VARIABLE GIT_COMMIT_AUTHOR
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_GIT_COMMIT_AUTHOR=\"${GIT_COMMIT_AUTHOR}\")
message(STATUS "Git Commit Author : " ${GIT_COMMIT_AUTHOR})
# --------------------------------------------------------------------------
execute_process(COMMAND git show -s --format='%ae' HEAD
    OUTPUT_VARIABLE GIT_COMMIT_EMAIL
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-D_GIT_COMMIT_EMAIL=\"${GIT_COMMIT_EMAIL}\")
message(STATUS " Git Commit Email : " ${GIT_COMMIT_EMAIL})
# --------------------------------------------------------------------------

# ---------------------------------------------------------------------------
add_executable(
    cli11-positional-option
    src/cli11-positional-option.cpp
)

# ---------------------------------------------------------------------------
add_executable(
    cli11-dash-option
    src/cli11-dash-option.cpp
)

# ---------------------------------------------------------------------------
add_executable(
    cli11-version
    src/cli11-version.cpp
)
