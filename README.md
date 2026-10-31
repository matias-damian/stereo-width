A C++17 library for adjusting stereo width using mid/side processing.

## Example

```cpp
#include <stereo_width/StereoWidth.hpp>

float left[] = {0.2f, 0.4f, -0.1f};
float right[] = {0.1f, 0.3f, 0.2f};

stereo_width::StereoWidth stereo;
stereo.setWidth(1.5f);
stereo.process(left, right, 3);
```
