# Raytraycer Avis

A simple raytracer in C++, based on [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley. Includes makefile that compiles a commandline program, rtavis. rtavis takes in a csv file specifying a scene with position, size, and material of sphere models and outputs a .ppm file with the rendered image. So far only tested on 64-bit Windows. See below for usage.

## Example image 1
![Example Image 1](/demo/example_image.jpg)

## Example image 2
![Example Image 2](/demo/example_image2.jpg)

## Current raytracer features
* Supported materials: 
  * Lambertian
  * Metal
  * Dielectric (glass)
* Supported shapes:
  * Sphere
* Shadows
* Anti-aliasing

## Usage
```
.\rtavis image_width [-i input_csv_file.csv] [-o output_image_name.jpg] [-spp samples_per_pixel] [-depth max_ray_recursion_depth]
```
Example command to create the example image: `.\rtavis 1000 -i demo\example_scene1.csv -o example_image.ppm -spp 100 -depth 20`

Note that a separate step was needed to convert .ppm to .jpg

## Limitations & Known Issues
1. Only .ppm images are supported as outputs
2. Camera is fixed at (0, 0, 0)
3. Only Sphere objects are supported

## Downloads
[Windows 64bit Executable](/demo/rtavis.exe)  
run `.\rtavis` in commandline or see above for usage

## Setup guide 
Currently only tested on Windows, 64bit
1. Install MinGW-w64
2. (Optional) Add `[path to mingw64]\mingw64\bin` to the `PATH` variable
3. (Optional) Create a `make` command in a .bat file that calls `mingw32-make.exe`
4. In the terminal, run `make` (or `[path to mingw64]\mingw64\bin\mingw32-make.exe`) in the top-level rtavis folder.
5. In the terminal, Run `.\rtavis` for usage

# License
[MIT](https://opensource.org/licenses/MIT)

- Feel free to use to start your own project
- Feedback very welcome :)
