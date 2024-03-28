# BMP Image processing application

A C++ program to apply filters on your image.

## Installation

1) Clone this repository and switch to project folder: `git clone https://github.com/ahtson/image_processor && cd image_processor`.
2) Run the install script using `./install.sh`.

>NOTE: If you experience any issues while following step two, running `chmod +x install.sh` may help.

If you wish to uninstall the program, simply run `./uninstall.sh` to execute the uninstallation script. 

## Supported formats

All input and output data should be in [BMP](http://en.wikipedia.org/wiki/BMP_file_format) format.

This program supports 24-bit BMP format with no compression. The type of `DIB header` is `BITMAPINFOHEADER`.

## Command line arguments

`image_processor {INPUT FILE} {OUTPUT FILE}
[-{filter} [argument 1] [argument 2] ...]`

### Example of usage
`./image_processor input.bmp /tmp/output.bmp -crop 800 600 -gs -blur 0.5`

## Filters

### List of basic filters

#### Crop (-crop width height)
Crops the image.

#### Grayscale (-gs)
Converts the image to grayscale using the formula below:

![encoding](https://latex.codecogs.com/svg.image?R'%20=%20G'%20=%20B'%20=0.299%20R%20&plus;%200%20.587%20G%20&plus;%200%20.%20114%20B)

#### Negative (-neg)
Negates the colors using the formula below:

![encoding](https://latex.codecogs.com/svg.image?R'%20=%201%20-%20R,%20G'%20=%201%20-%20G,%20B'%20=%201%20-%20B)

#### Sharpening (-sharp)
Shapens the image. Utilizes the matrix below.

![encoding](https://latex.codecogs.com/svg.image?%5Cbegin%7Bbmatrix%7D%20&%20-1%20&%20%20%5C%5C-1%20&%205%20&%20-1%20%5C%5C%20&%20-1%20&%20%20%5C%5C%5Cend%7Bbmatrix%7D)

#### Edge Detection (-edge threshold)
Detects the edges. Utilizes the matrix below.

![encoding](https://latex.codecogs.com/svg.image?%5Cbegin%7Bbmatrix%7D%20&%20-1%20&%20%20%5C%5C-1%20&%204%20&%20-1%20%5C%5C%20&%20-1%20&%20%20%5C%5C%5Cend%7Bbmatrix%7D)

#### Gaussian Blur (-blur sigma)
[Gaussian blur](https://en.wikipedia.org/wiki/Gaussian_blur)
takes the value of sigma as argument.

The color of each pixel `C[x0][y0]` is calculated like this:

![encoding](https://latex.codecogs.com/svg.image?C%5Bx_0%5D%5By_0%5D%20%3D%20%5Csum_%7Bx%3D0%2Cy%3D0%7D%5E%7Bwidth-1%2C%20height-1%7DC%5Bx%5D%5By%5D%5Cfrac%7B1%7D%7B2%5Cpi%5Csigma%5E2%7De%5E%7B-%5Cfrac%7B%5Cleft%7Cx_o-x%5Cright%7C%5E2%20%26plus%3B%20%5Cleft%7Cy_o-y%5Cright%7C%5E2%7D%7B2%5Csigma%5E2%7D%7D)

### "Old photo" effect and sepia

Makes image look old.

### Crystalize

Crystalizes image

### Barrel distortion

The fish eye effect.

### Wave distortion

A wave-like distortion.

### Sabattier effect

Read [here](https://en.wikipedia.org/wiki/Sabattier_effect).

### Posterization

Converts a continuous gradation of tone to several regions of fewer tones, making image look like a poster.

## Functionality

- Representation of BMP file according to [documentation](https://www.digicamsoft.com/bmp/bmp.html)
- Reading and writing
- Filters
- Controller
- Commandline arguments parser 

