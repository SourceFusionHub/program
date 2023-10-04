package main

import (
    "image"
    "image/color"
    "image/png"
    "os"
    "math/cmplx"
)

const (
    width, height = 1024, 1024
    xmin, ymin, xmax, ymax = -2, -2, 2, 2
    maxIterations = 256
)

func mandelbrot(z complex128) color.Color {
    var v complex128
    for n := uint8(0); n < maxIterations; n++ {
        v = v*v + z
        if cmplx.Abs(v) > 2 {
            return color.RGBA{255 - n, 0, n, 255}
        }
    }
    return color.Black
}

func main() {
    img := image.NewRGBA(image.Rect(0, 0, width, height))
    for py := 0; py < height; py++ {
        y := float64(py)/height*(ymax-ymin) + ymin
        for px := 0; px < width; px++ {
            x := float64(px)/width*(xmax-xmin) + xmin
            z := complex(x, y)
            img.Set(px, py, mandelbrot(z))
        }
    }
    outputFile, err := os.Create("mandelbrot.png")
    if err != nil {
        panic(err)
    }
    defer outputFile.Close()

    if err := png.Encode(outputFile, img); err != nil {
        panic(err)
    }
}
