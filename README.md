<div align="center">
    <h1>Crucible</h1>
</div>

This is a game. I don't know what kind of game it is yet.

## Building

You'll need [conan](https://conan.io/), cmake, and a modern c++ compiler.

```
mkdir build
cd build
conan install ..
conan build ..
```

This will produce executables in `build/bin`.

## Testing

```
mkdir build
cd build
conan install .. -o build_tests=True
conan build ..
```