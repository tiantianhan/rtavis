# Raytraycer Avis

A simple raytracer in C++, based on [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley. Includes makefile that compiles a commandline program, rtavis. rtavis outputs a .ppm file with the rendered image. So far only tested on 64-bit Windows. See below for usage.

## Example image
![Example Image](/demo/example_image.jpg)

## Current raytracer features
* Supported materials: 
  * Diffuse
  * Metal
  * Dielectric (glass)
* Shadows
* Anti-aliasing

## Usage
```
.\rtavis out_file_path image_width [-spp samples_per_pixel] [-depth max_ray_recursion_depth]
```
Example command to create the example image: `.\rtavis example_image.ppm 1000 -spp 100 -20`

Note that a separate step was needed to convert .ppm to .jpg

## Major Limitations & Known Issues
1. Only .ppm images are supported
2. Camera is fixed at (0, 0, 0)
3. Objects in the scene can only be changed by editing the source code
4. Only Sphere objects supported
5. Noise not eliminated

## Downloads
[Windows 64bit Executable](/demo/rtavis.exe)  
run `.\rtavis` in commandline or see above for usage

## Setup guide 
Currently only tested on Windows, 64bit
1. Install MinGW-w64
2. (Optional) Add `...mingw64\bin` to the `PATH` variable
3. (Optional) Create a `make` command in a .bat file that calls `mingw32-make.exe`
4. In the terminal, run `make` (or `...mingw64\bin\mingw32-make.exe`) in the top-level rtavis folder.
5. In the terminal, Run `.\rtavis` for usage

# License
[MIT](https://opensource.org/licenses/MIT)

- Feel free to use to start your own project
- Feedback very welcome :)
