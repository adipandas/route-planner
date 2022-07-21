# route-planner

Simple Route-planning on the map using A*star search.

<img src="map.png" width="600" height="450" />

## Cloning

```
git clone git@github.com:adipandas/route-planner.git --recurse-submodules
```

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

### Notes
This repo does not have the cmake file corresponding to IO2D. To install it on linux, you can refer to the link [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md) and follow the step  below.

* You can clone the repository at any location you like on your machine. Preferrably outside this repository.

```
sudo apt update
sudo apt install build-essential
sudo apt install cmake
sudo apt install libcairo2-dev
sudo apt install libgraphicsmagick1-dev
sudo apt install libpng-dev

git clone git@github.com:cpp-io2d/P0267_RefImpl.git --recurse-submodules
cd P0267_RefImpl
mkdir Debug
cd Debug
cmake --config Debug "-DCMAKE_BUILD_TYPE=Debug" ..
cmake --build .
sudo make install
```

``sudo make install`` should copy the necessary files at places where Cmake can find them.


## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
cd route-planner
mkdir build && cd build
```

From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```

### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```

Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

## References

The template for this project is provided by UDACITY and it is available on GitHub at [this link](https://github.com/udacity/CppND-Route-Planning-Project).

It think this is a preetty neat project to understand the application of simple planning/search algorithms. :smiley:
