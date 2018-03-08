# manta-ray

A tiny raytracing toolkit for learning purposes.

![example](https://raw.githubusercontent.com/sbuggay/manta-ray/master/demo/error%233.png)

## Usage

Building

```bash
make
```

manta-ray will write the output in [PPM format](https://en.wikipedia.org/wiki/Netpbm_format) to `stdout`.

Running

```bash
./build/manta-ray > image.ppm
```

Using something like `imagemagick` you can convert this `PPM` to a `PNG` with:

```bash
convert image.ppm image.png
```

Cleanup

```bash
make clean
```

## References

- https://www.amazon.com/gp/product/B0785N5QTC?ref=series_rw_dp_labf
- https://en.wikipedia.org/wiki/Netpbm_format