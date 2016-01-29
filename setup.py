from distutils.core import setup, Extension

c_ext = Extension("factorial", ["_factorial.c", "factorial.c"])

setup(
    ext_modules=[c_ext],
)
