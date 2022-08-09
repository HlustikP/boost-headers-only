Collection of the Boost header-only libraries created from Boost's main branch for easy-to-use project inclusion.

## Usage

### Method 1: Cloning
Clone the repository either into your project's include folder or into a central place for all your projects to include it.  With cmake:
```cmake
target_include_directories(your_project path/to/boost-headers-only/repo)
```

### Method 2: Git Submodule
Another way of adding the Boost headers only libraries to your project is to add it as a submodule.
Inside your project, if you dont have an include directory, create one:
```bash
mkdir include
```
Now add the repo as a submodule:
```bash
git submodule add https://github.com/HlustikP/boost-headers-only.git ./include
git submodule update --init --recursive
```
Whats left is to add `./include/` as an include directory to your project.

### Method 3: CMake FetchContent
Disclaimer: Requires at least `cmake 3.11`.
Another cmake method is to let cmake handle the fetching of the repository.
```cmake
# enable FetchContent
include(FetchContent)

FetchContent_Declare(Boost
 GIT_REPOSITORY https://github.com/HlustikP/boost-headers-only.git
 GIT_TAG        main
 )

FetchContent_MakeAvailable(Boost)
```